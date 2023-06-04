import threading
import math

import rclpy
from rclpy.node import Node
import rclpy.executors

from air_simple_sim_msgs.msg import SemanticObservation
from ros2_kdb_msgs.srv import QueryDatabase
from ros2_kdb_msgs.srv import InsertTriples
from rclpy.callback_groups import ReentrantCallbackGroup

import rclpy
from rclpy.node import Node

from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
import tf2_geometry_msgs


import TstML
import TstML.Executor
import ament_index_python

import json

# Ugly hack to get a new name for each node
ros_name_counter = 0
def gen_name(name):
    global ros_name_counter
    ros_name_counter += 1
    return name + str(ros_name_counter)

class MinimalClientAsync(Node): # queryclient
    def __init__(self):
        super().__init__('minimal_client_async')
        self.group = ReentrantCallbackGroup()

        self.cli = self.create_client(QueryDatabase, '/kdb_server/sparql_query', callback_group=self.group)

        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = QueryDatabase.Request()


    def send_request(self, graphname, uuid, klass):
        self.req.graphname = graphname
        self.req.format = ""
        self.req.query = f"""PREFIX gis: <http://www.ida.liu.se/~TDDE05/gis>
        PREFIX properties: <http://www.ida.liu.se/~TDDE05/properties>
         
        SELECT ?x ?y WHERE {{ <{uuid}> a <{klass}> ;
                      properties:location [ gis:x ?x; gis:y ?y ] . }}"""
        self.req.bindings = ""

        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

class InsertClient(Node):
    def __init__(self):
        super().__init__('insert_client')
        self.group = ReentrantCallbackGroup()

        self.cli = self.create_client(InsertTriples, '/kdb_server/insert_triples', callback_group=self.group)

        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = InsertTriples.Request()


    def send_insert(self, graphname, uuid, klass,x,y):
        self.req.graphname = graphname
        self.req.format = "ttl"

        self.req.content = f"""PREFIX gis: <http://www.ida.liu.se/~TDDE05/gis>
                PREFIX properties: <http://www.ida.liu.se/~TDDE05/properties>
                <{uuid}> a <{klass}>;
                      properties:location [ gis:x {x}; gis:y {y} ] . """


        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

class SemanticExecutor(TstML.Executor.AbstractNodeExecutor):
  def __init__(self, node, context):
    super(TstML.Executor.AbstractNodeExecutor, self).__init__(node,context)

    self.ros_node = Node(gen_name("record_semantic"))
    self.q = MinimalClientAsync()
    self.i = InsertClient()

    self.node_tf = Node(gen_name("tf_what"))
    self.tf_buffer = Buffer()
    self.tf_listener = TransformListener(self.tf_buffer, self.node_tf)


    self.graphname = ""
    self.topic = ""

    self.executor = rclpy.executors.MultiThreadedExecutor()
    self.executor.add_node(self.ros_node)
    self.executor.add_node(self.node_tf)

    self.thread = threading.Thread(target=self.executor.spin)
    self.thread.start()

  def finalise(self):
    self.executor.shutdown()
  
  def listener_callback(self, msg):
    klass = msg.klass
    uuid = msg.uuid
  
    

    try:
      point = msg.point
      point_transformed = self.tf_buffer.transform(point, "map", timeout=rclpy.duration.Duration(seconds=1.0))
    except TransformException as ex:
      self.node_tf.get_logger().info(f'Could not transform {msg.point.point} to {"map"}: {ex}')
      return



    # print("Observation: ",klass, uuid)
    res = self.q.send_request(self.graphname, uuid, klass)
    json_result = json.loads(res.result)
    empty = True
    for row in json_result["results"]["bindings"]: # json parsing
      empty = False


    if empty:
      print("Thing does not exists, inserting:", uuid,klass)
      res_insert = self.i.send_insert(self.graphname, uuid, klass,point_transformed.point.x,point_transformed.point.y) 
      print("Insert_sucess:",res_insert.success)
      print("Insert_msg:",res_insert.err_msgs)
    else:
      print("Thingy exists",uuid,klass)



  def start(self):
    if self.node().hasParameter(TstML.TSTNode.ParameterType.Specific, "graphname"):
        self.graphname = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "graphname")
        print("Graphname: ", self.graphname)

    if self.node().hasParameter(TstML.TSTNode.ParameterType.Specific, "topic"):
        self.topic = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "topic")
        print("Topic: ",self.topic)

    # Error 1
    self.subscription = self.ros_node.create_subscription(SemanticObservation,"/"+self.topic,self.listener_callback, 2)
    self.subscription 
        
    # When sedning error is recieved in rviz
    return TstML.Executor.ExecutionStatus.Started()




  def handle_result_callback(self, future):
    self.executionFinished(TstML.Executor.ExecutionStatus.Finished())

  def pause(self):
    self.ros_node.get_logger().info('Pause is not possible.')
    return TstML.Executor.ExecutionStatus.Running()

  def resume(self):
    return TstML.Executor.ExecutionStatus.Running()

  def stop(self):
    self._goal_handle.cancel_goal()
    return TstML.Executor.ExecutionStatus.Finished()
    
  def abort(self):
    self._goal_handle.cancel_goal()
    return TstML.Executor.ExecutionStatus.Aborted()

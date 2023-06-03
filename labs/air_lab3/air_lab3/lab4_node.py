import rclpy
import rclpy.node
import visualization_msgs.msg
import geometry_msgs.msg
import std_msgs.msg

from ros2_kdb_msgs.srv import QueryDatabase
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.node import Node
import json

class GetNodes(Node):
    def __init__(self):
        super().__init__('getnodes')
        self.group = ReentrantCallbackGroup()

        self.cli = self.create_client(QueryDatabase, '/kdb_server/sparql_query', callback_group=self.group)

        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = QueryDatabase.Request()


    def send_request(self):
        self.req.graphname = "semanticobject"
        self.req.format = "json"
        self.req.query = f"""PREFIX gis: <http://www.ida.liu.se/~TDDE05/gis>
                            PREFIX properties: <http://www.ida.liu.se/~TDDE05/properties>

                            SELECT ?obj_id ?class ?x ?y WHERE {{ ?obj_id a ?class ;
                            properties:location [ gis:x ?x; gis:y ?y ]. }}"""
        self.req.bindings = ""

        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

def create_point(x, y, z):
    msg = geometry_msgs.msg.Point()
    msg.x = x
    msg.y = y
    msg.z = z
    return msg

def create_color(r, g, b, a):
    msg = std_msgs.msg.ColorRGBA()
    msg.r = r
    msg.g = g
    msg.b = b
    msg.a = a
    return msg


def timer_callback():
    # Get all markers
    client_node = GetNodes()
    query_result = client_node.send_request()
    json_result = json.loads(query_result.result)
    marker = visualization_msgs.msg.Marker()
    marker.id     = int() # identifier the marker, should be unique
    marker.header.frame_id = "odom"
    marker.type   = visualization_msgs.msg.Marker.CUBE_LIST
    marker.action = 0
    marker.scale.x = 0.5
    marker.scale.y = 0.5
    marker.scale.z = 0.5
    marker.pose.orientation.w = 1.0
    marker.color.a = 1.0
    for row in json_result["results"]["bindings"]:
        print("id:",row['obj_id']['value']," class:",row['class']['value']," (x,y)",row['x']['value'],row['y']['value'])
        marker.points.append(create_point(float(row['x']['value']), float(row['y']['value']), 0.0))
        if str(row['class']['value']) == "table":
            marker.colors.append(create_color(1.0, 0.5, 0.5, 1.0))
        else:
            marker.colors.append(create_color(0.5, 1.0, 0.5, 1.0))
            

    marker_array = visualization_msgs.msg.MarkerArray()
    marker_array.markers = [marker]

    display_marker_pub.publish(marker_array)

def main():
    print("atleast running the lab4_node")
    global display_marker_pub
    rclpy.init()
    node = rclpy.node.Node('visualise_semantic_objects')

    display_marker_pub = node.create_publisher(visualization_msgs.msg.MarkerArray, 'semantic_sensor_visualisation', 10)
    timer = node.create_timer(0.5, timer_callback)

    rclpy.spin(node)

if __name__ == '__main__':
    main()

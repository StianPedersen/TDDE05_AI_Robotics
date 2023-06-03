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
def timer_callback():
    client_node = GetNodes()

    query_result = client_node.send_request()

    json_result = json.loads(query_result.result)

    whole = {"children":[],"common_params":{},"name":"seq","params":{"repeat-count": 1}}

    # print(json_result)
    for row in json_result["results"]["bindings"]:
        if str(row['class']['value']) == "human":
            whole['children'].append({'children':[],
            'common_params':{},
            'name':'drive-to',
            'params':{'p':{"rostype":"Point","x":float(row['x']['value']),"y":float(row['y']['value']),"z":0,}}
            })       

    y = json.dumps(whole,indent = 2)
    with open("drive_to_humans.json", "w") as outfile:
        outfile.write(y)
        print("file_written")

def main():
    rclpy.init()
    node = rclpy.node.Node('create_tst')
    timer_callback()
    # timer = node.create_timer(10.0, timer_callback)
    # rclpy.spin_once(node)

    




if __name__ == '__main__':
    main()

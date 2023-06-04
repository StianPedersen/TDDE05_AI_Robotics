from air_lab_interfaces.srv import ExecuteTst
from std_srvs.srv import Empty
import rclpy
from rclpy.node import Node
import TstML
import ament_index_python
import TstML.Executor
from .undock import UndockExecutor
from .dock import DockExecutor
from .drive_to import DriveToExecutor
from .explore import ExploreExecutor
from .record_semantic import SemanticExecutor

from rclpy.callback_groups import ReentrantCallbackGroup

class MinimalService(Node):
    def __init__(self):
        super().__init__('minimal_service')

        self.group = ReentrantCallbackGroup()

        self.srv = self.create_service(ExecuteTst, '/execute_tst', self.test_Execution)
        self.srv = self.create_service(Empty, '/pause', self.callback_pause, callback_group=self.group) ## Change pause -> srd_srvs/Empty
        self.srv = self.create_service(Empty, '/resume', self.callback_resume, callback_group=self.group)
        self.srv = self.create_service(Empty, '/stop', self.callback_stop, callback_group=self.group)
        self.srv = self.create_service(Empty, '/abort', self.callback_abort, callback_group=self.group)

        
        
        # Initialise TstML and a load a TstML file
        self.tst_registry = TstML.TSTNodeModelsRegistry()
        self.tst_registry.loadDirectory(ament_index_python.get_package_prefix("air_tst") +  "/share/air_tst/configs")

        # Create a registry with node executors
        self.tst_executor_registry = TstML.Executor.NodeExecutorRegistry()

        # Setup the executors
        self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("seq"),TstML.Executor.DefaultNodeExecutor.Sequence)
        self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("conc"),TstML.Executor.DefaultNodeExecutor.Concurrent)
        self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("undock"),UndockExecutor)
        self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("dock"),DockExecutor)

        self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("drive-to"),DriveToExecutor)
        
        self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("explore"),ExploreExecutor)

        self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("record-semantic"),SemanticExecutor)



        


    def test_Execution(self, request, response):

        if request.tst_file:
            response.success = True 

        if response.success != True:
            response.my_error = "Failed to load file"
        else:
            response.my_error = "Sucessfully loaded file"
            self.tst_node = TstML.TSTNode.load(request.tst_file, self.tst_registry)
        
        # in tst_executor_registry

        self.tst_executor = TstML.Executor.Executor(self.tst_node,self.tst_executor_registry)

        # Start execution
        self.tst_executor.start()
        # Block until the execution has finished
        status = self.tst_executor.waitForFinished()

        # Display the result of execution
        if status.type() == TstML.Executor.ExecutionStatus.Type.Finished:
            response.my_error = "Execution successful"
        elif status.type() == TstML.Executor.ExecutionStatus.Type.Failed:
            response.my_error= "Execution failed: {}".format(status.message())
        else:
            response.my_error="Execution failed!"
        return response

    def callback_pause(self, request, response):
        # Check the request
        print("reached pause function")
        self.tst_executor.pause()
        response = "Trying to pause"
        return response
        # Send the response

    def callback_resume(self, request, response):
        # Check the request
        print("reached resume function")
        self.tst_executor.resume()
        response = "Trying to resume"
        return response

    def callback_stop(self, request, response):
        # Check the request
        print("reached stop function")
        self.tst_executor.stop()
        response = "Trying to stop"
        return response
        # Send the response
    
    def callback_abort(self, request, response):
        # Check the request
        print("reached abort function")
        self.tst_executor.abort()
        response = "Trying to abort"
        return response
        # Send the response


def main():
    rclpy.init()
    print("Main reached!")
    minimal_service = MinimalService()

    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(minimal_service)
    executor.spin()

    rclpy.shutdown()


if __name__ == '__main__':
    main()
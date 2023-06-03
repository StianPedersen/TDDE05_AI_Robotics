from setuptools import setup

package_name = 'air_lab3'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='stilo759',
    maintainer_email='stilo759@student.liu.se',
    description='Python client server tutorial',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'tst_executor = air_lab3.tst_executor:main',
            'execute_tst = air_lab3.lab3_node:main',
            'create_tst = air_lab3.simple_tst_gen:main',
            'visualize=air_lab3.lab4_node:main', 
            'pause = air_lab3.lab3_node:main',
            'resume = air_lab3.lab3_node:main',
            'stop = air_lab3.lab3_node:main',
            'abort= air_lab3.lab3_node:main'
        ],
    },
)

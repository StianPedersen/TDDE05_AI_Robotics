from setuptools import setup

package_name = 'air_lab2'

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
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'lab2_node = air_lab2.lab2_node:main',
            'random_exploration = air_lab2.random_exploration:main'
        ],
    },
)

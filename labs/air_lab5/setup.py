from setuptools import setup

package_name = 'air_lab5'

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
            'lab5_node = air_lab5.lab5_node:main',
            'text = air_lab5.text_to_goals:main',
            'decision = air_lab5.decision:main'
        ],
    },
)

# Lab 1: Intro to ROS 2

## Written Questions

### Q1: During this assignment, you've probably ran these two following commands at some point: ```source /opt/ros/foxy/setup.bash``` and ```source install/local_setup.bash```. Functionally what is the difference between the two?

Answer: "source /opt/ros/foxy/setup.bash" sets up the enviroment variables for ros while "source install/local_setup.bash" sets up you program to be run

### Q2: What does the ```queue_size``` argument control when creating a subscriber or a publisher? How does different ```queue_size``` affect how messages are handled?

Answer: the queue_size is the size of the queue held for that topic since we are flooding teh topic a higher queue size is preferable to ensure that data is transfered correctly. with a larger queue it makes the system a little less responsive since the que is first in first out.

### Q3: Do you have to call ```colcon build``` again after you've changed a launch file in your package? (Hint: consider two cases: calling ```ros2 launch``` in the directory where the launch file is, and calling it when the launch file is installed with the package.)

Answer: when calling the launch file using "ros2 launch [filename]" you dont have to rebuild teh package for the changes to take affect however, when using "ros2 launch [package] [launchfile]" you must rebuild for the changes to take affect.

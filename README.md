# Arduino_final_project
## Video of the project :
### https://youtu.be/qDvWahnEAdI
## BOM Link : https://docs.google.com/spreadsheets/d/1_GYeWjBXVv_4aekasxN6_g4DxXadq2Kq5P1_7F1olAA/edit#gid=518350444
## Line Follower Robot - description + making of
   A line follower robot is a robot supposed to follow a black line drawn over a white background, via the usage of multiple infrared sensors (in this case I've used a line of 8 sensors). Based on the readings from the sensors (1 means that the sensor is over a black surface, 0 means that the sensor is over a white surface) , using a PID controller (in this case I've only implemented the P, since it was enough for the DC motors that I've used) I've programmed the robot so that it follows the line.<br>
   The principle on which the infrared sensors work is the fact that an infrared sensor is basically a photodiode that emits infrared radiation paired with a sensor that receives infrared radiation and the fact that a black surface absorbs light, whilst a white surface reflects the lights, so theoretically the sensors shouldn't receive any radiation from the sensor that are covering the black line . Based on this fact, we can deduce where the robot is at all times compared to the black line.<br>
   One of the most difficult parts of the project was calibrating the infrared sensors (making sure they are at just the perfect distance from the ground) as the sensor was one that had a very specific distance, and as soon as the sensor moved, the readings started not being accurate (some of the sensors from the line would work, while others would not, because of the shape of the robot). The fix that I did in order to be able to recalibrate the sensors each time (usually everytime I carried the robot from and back to college, the sensors would go nuts) was to attach a spring together with two nuts and a bolt, developing a flexible holding system that could be adjusted on the fly, every time the sensors would start showing wrong data.<br>
   The programming part wasn't too difficult as I've only implemented the P from PID, however it took quite a while to find the correct ratios .

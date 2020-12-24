# Multifunction-PID-Control-Autonomous-Mobile-Robot

Developed the robot to follow a black/white line by a PID loop with the automatic calibration(take the highest and lowest analog value of line sensor’s after comparing all the sensors value and select the average of the highest and lowest value as the threshold value) of the line sensors (12 TCRT 5000 sensors); tuned the P, I , D parameters of the robot for a smooth and high precision line following; developed several logics to follow the line on sharp turns, switch between black and white lines and on confusing lines; applied another PID loop and tuned the P, D parameters to smoothly follow a cave/wall  and to take any necessary sharp turns after detecting the wall position by 3 sonar sensors; developed an algorithm to avoid obstacles on its path and return to its normal path by measuring the distance of the obstacle using the sonar sensor; improved the robot to detect the color of an object (self-made color sensor RGB) by the reflection method (measures the light intensity by LDR from the reflection, stores the value for different colors and after comparing the most intensity of light it’s decides the color of the object); used the color sensor LED for indicating directions while taking turns; used ATmega2560 microcontroller, L298 motor driver for 2 gear motors, 3S+1S lipo battery with a buck converter to power the microcontroller and the motor driver.
Tools: C/C++


This is the demonstration video :https://www.youtube.com/watch?v=0KFR2EsdOnM <br/>

[![Multifunction-PID-Control-Autonomous-Mobile-Robot](https://img.youtube.com/vi/0KFR2EsdOnM/0.jpg)](https://www.youtube.com/watch?v=0KFR2EsdOnM)

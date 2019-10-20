
# 使用键盘控制树莓派
主函数在src中，电机控制使用的是 Raspbian 自带的<WiringPi>库 ，具体的输出口可以根据自己情况在/inlcude/Motor_Control.cpp中调整。
  WiringPi的端口序号在 pinout.xyz 网站上查看

# delay（）说明
如果是接的普通键盘就需要把主函数中的所有delay去掉，此时只要按住按键即可运动，松开停止。
但是如果是接手机，正常情况下是只能连续按才行，所以用delay（）达到连续的效果。

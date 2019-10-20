#include <stdio.h>
#include <termio.h>
#include "../include/Motor_Control.h"
#include <iostream>

using namespace std;
int scanKeyboard()
{
int in;
struct termios new_settings;
struct termios stored_settings;
tcgetattr(0,&stored_settings);
new_settings = stored_settings;
new_settings.c_lflag &= (~ICANON);
new_settings.c_cc[VTIME] = 0;
tcgetattr(0,&stored_settings);
new_settings.c_cc[VMIN] = 1;
tcsetattr(0,TCSANOW,&new_settings);
 
in = getchar();
 
tcsetattr(0,TCSANOW,&stored_settings);
return in;
}


int main()
{
	Motor_Control MC;
	int ch;
	while (true){
		ch = scanKeyboard();//使用_getch()函数获取按下的键值
		if(ch ==119) 
		{
		MC.forward();//W
		delay(200);
		}
		
		if(ch ==97)
		{
		MC.turn_left();//A
		delay(200);
		} 
			
		if(ch ==115)

		{
		MC.backward();//S
		delay(200);
		} 
		if(ch ==100)
		{
		MC.turn_right();//D
		delay(200);
		} 
		if (ch == 27){ break; }//当按下ESC时循环，ESC键的键值时27.
		MC.move_stop();
	}

	return 0;
}


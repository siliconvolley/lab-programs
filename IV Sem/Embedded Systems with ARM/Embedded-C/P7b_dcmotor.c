///////Program to test Working of DC Motor ///////// Date: 21/01/2012 

#include<lpc214x.h>

void clock_wise(void);
void anti_clock_wise(void);
unsigned int j=0;

int main()
{
	IO0DIR= 0X00000900;
	IO0SET= 0X00000100; 			//P0.8 should always high.

  	while(1)
  	{
    	clock_wise();
    	for(j=0;j<400000;j++); 		//delay
    	anti_clock_wise();
    	for(j=0;j<400000;j++); 		//delay
	} 								//End of while(1)
}									//End of Main

void clock_wise(void)
{
	IO0CLR = 0x00000900; 			//stop motor and also turn off relay
   	for(j=0;j<10000;j++); 			//small delay to allow motor to turn off 
  	IO0SET = 0X00000900;			//Selecting the P0.11 line for clockwise and turn on motor
}

void anti_clock_wise(void)
{
	IO0CLR = 0X00000900;			//stop motor and also turn off relay
  	for(j=0;j<10000;j++); 			//small delay to allow motor to turn off 
  	IO0SET = 0X00000100;			//not selecting the P0.11 line for Anti clockwise
}


// program to generate square wave with DAC interface

#include <lpc21xx.h>

void delay(void);

int main ()
{
	PINSEL0 = 0x00000000 ;						// Configure P0.0 to P0.15 as GPIO
	PINSEL1 = 0x00000000 ;						// Configure P0.16 to P0.31 as GPIO
	IO0DIR  = 0x00FF0000 ;
   
	while(1)
    {
    	IO0PIN = 0x00000000;
        delay();
        IO0PIN = 0x00FF0000;
        delay();
    }
}   

void delay(void)
{
	unsigned int i=0;
   	for(i=0;i<=95000;i++);
}
 

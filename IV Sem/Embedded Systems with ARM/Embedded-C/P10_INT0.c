// The program demonstrates About the External interrupt to the Controller 

#include<lpc214x.h>

void Extint0_Isr(void) __irq; 			//declaration of ISR

unsigned char int_flag = 0, flag = 0;

int main(void)
{
   	IO1DIR |= 0X02000000;  		  
   	IO1SET  = 0X02000000;
   	PINSEL1	=0X00000001;          		//Setup P0.16 to alternate function EINT0

   	EXTMODE	=0x01;                		//edge i.e falling egge trigger and active low
   	EXTPOLAR= 0X00;
   	VICVectAddr0 = (unsigned long) Extint0_Isr;   //Assign the EINT0 ISR function 
   	VICVectCntl0 = 0x20 | 14;      		//Assign the VIC channel EINT0 to interrupt priority 0
   	VICIntEnable |= 0x00004000;    		//Enable the EINT0 interrupt

	while(1)                            //waiting for interrupt to occur
    {
   		if(int_flag == 0x01)
		{
			if(flag == 0)
		  	{
		    	IO1CLR = 0X02000000;
		    	flag = 1;
		  	}
		  	else if(flag == 1)
		  	{
		    	IO1SET = 0x02000000;
				flag = 0;
		  	}
		  	int_flag = 0x00;
		}		  
  	}
}

void Extint0_Isr(void)__irq {           //whenever there is a low level on EINT0
	EXTINT |= 0x01;                 	//Clear interrupt
  	int_flag = 0x01;
 	VICVectAddr = 0;					//Acknowledge Interrupt
}


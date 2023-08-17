#include<lpc214x.h>

void uart_init(void);
unsigned int delay;
unsigned char *ptr;
unsigned char arr[]="HELLO WORLD\r";

int main()
{
	while(1)
	{
		uart_init();
		ptr = arr;
		while(*ptr!='\0')
		{
			U0THR=*ptr++;
			while(!(U0LSR & 0x20)== 0x20);
			for(delay=0;delay<=600;delay++);
		}
		for(delay=0;delay<=60000;delay++);
	}
}	
void uart_init(void)
{
  PINSEL0=0X0000005;  				//select TXD0 and RXD0 lines		   
	U0LCR = 0X00000083;					//enable baud rate divisor loading and
	U0DLM = 0X00;          				//select the data format
  U0DLL = 0x13;      					//select baud rate 9600 bps
  U0LCR = 0X00000003;
	
}
	
	

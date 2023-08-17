/*************************************************************************
 * Stepper motor Direction control
 * Developed by
 * Advanced Electronics Systems. Bengaluru.
 *------------------------------------------------------------------------
 * A stepper motor direction is controlled by shifting the voltage across 
 * the coils. Port lines : P0.12 to P0.15
 *************************************************************************/

 #include <LPC21xx.H>

void clock_wise(void);
 void anti_clock_wise(void);
 
 unsigned long int var1,var2;
 unsigned int i=0,j=0,k=0;

 int main(void)
 {
	PINSEL0 = 0x00FFFFFF;		//P0.12 to P0.15 GPIo
	IO0DIR |= 0x0000F000;		//P0.12 to P0.15 output

	while(1)
	{
		for(j=0;j<50;j++)       // 20 times in Clock wise Rotation
			clock_wise();
		
		for(k=0;k<65000;k++);   // Delay to show  anti_clock Rotation 
		
		for(j=0;j<50;j++)       // 20 times in  Anti Clock wise Rotation
			anti_clock_wise();

		for(k=0;k<65000;k++);   // Delay to show clock Rotation 

	} 							// End of while(1)

 } 								// End of main

 void clock_wise(void)
 {
	var1 = 0x00000800;         	//For Clockwise
    for(i=0;i<=3;i++)         	// for A B C D Stepping
	{
		var1 = var1<<1;        	//For Clockwise
       
		IO0PIN = var1;
		
        for(k=0;k<3000;k++); 	//for step speed variation         
      }

 }

 void anti_clock_wise(void)
 {
	var1 = 0x00010000;      	//For Anticlockwise
     for(i=0;i<=3;i++)      	// for A B C D Stepping
      {
        var1 = var1>>1;     	//For Anticlockwise
       

		IO0PIN = var1;
        for(k=0;k<3000;k++); 	//for step speed variation 
             
      }
 }

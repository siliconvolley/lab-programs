;/* Assembly Program to find square of Number*/								
;/* GIVEN NUMBER IS 6 (R1) THEN RESULT IS IN R3=24H(36)	*/		 		
;/* SET A BREAKPOINT AT NOP INSTRUCTION,RUN THE PROGRAM & CHECK THE RESULT*/ 	

	AREA  SQUARE , CODE, READONLY

ENTRY					;Mark first instruction to execute
					
START	
			
	LDR	R0, = TABLE1		; Load start address of Lookup table 
	
	MOV R1, #10
					; Load no whose square is to be find	
 	MOV R1, R1, LSL#0x2		; Generate address corresponding to square of given no
 	ADD R0, R0, R1			; Load address of element in Lookup table
 	LDR R3, [R0]	    		; Get square of given no in R3
.

BACK B BACK
	
;Lookup table contains Squares of nos from 0 to 10 (in hex)		

TABLE1	DCD 0X00000000		;SQUARE OF 0=0
	DCD 0X00000001		;SQUARE OF 1=1
	DCD 0X00000004		;SQUARE OF 2=4
	DCD 0X00000009		;SQUARE OF 3=9
	DCD 0X00000010		;SQUARE OF 4=16
	DCD 0X00000019		;SQUARE OF 5=25
	DCD 0X00000024		;SQUARE OF 6=36
	DCD 0X00000031		;SQUARE OF 7=49
	DCD 0X00000040		;SQUARE OF 8=64
	DCD 0X00000051		;SQUARE OF 9=81
	DCD 0X00000064		;SQUARE OF 10=100

	END	   			; Mark end of file


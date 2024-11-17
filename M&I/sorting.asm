MVI A,EFH		
STA 2050H		
MVI A,65H		
STA 2051H		
MVI A,FBH		
STA 2052H		
MVI A,87H		
STA 2053H		
MVI A,2FH		
STA 2054H		
MVI A,01H		
STA 2055H		
MVI A,9AH		
STA 2056H		
MVI A,56H		
STA 2057H		
LXI H, 2050H     	
LXI D, 2060H	          	
MVI C, 08H        		
MOV A,M           		
STAX D             		
INX H              		
INX D              		
DCR C              	
JNZ 0030    	  		
LXI H, 2060H       		
MVI B, 07H         	
MOV C,B         
LXI H, 2060H       		
MOV A,M                  
INX H              	
CMP M              		
JC 004C         		
MOV D,M          	
MOV M,A		
DCX H             		
MOV M,D		
INX H              		
DCR C            		
JNZ 0041	           
DCR B              		
JNZ 003D   	         
HLT 			
			

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

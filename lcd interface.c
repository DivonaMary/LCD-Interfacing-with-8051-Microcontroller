#include<reg51.h> 
void lcdcmd(unsigned int); 
void lcddata(unsigned char); 
void delay(int); 
void lcdinit(); 
void cmddata(unsigned int,unsigned char*); 
sbit RS= P1^0; 
sbit RW= P1^1; 
sbit EN= P1^2; 
#define lcddatapin P2 
void main() 
{ 
while(1) 
{ 
lcdinit(); 
cmddata(0x38,"LCD"); 
cmddata(0xc4,"PROGRAM"); 
} 
} 
void lcdinit() 
{ 
lcdcmd(0x38); //8 bit 2 line 
lcdcmd(0x0c); //display on cursor off 
lcdcmd(0x06); //Entry Mode 
lcdcmd(0x01); // clear LCD 
lcdcmd(0x80); // set RAM address 
} 
void lcdcmd(unsigned int comm) 
{ 
lcddatapin=comm; 
RS=0; 
RW=0; 
EN=1; 
delay(10); 
EN=0; 
} 
void lcddata(unsigned char dat) 
{ 
lcddatapin=dat; 
RS=1; 
RW=0; 
EN=1; 
delay(10); 
EN=0; 
} 
void cmddata(unsigned int comm, unsigned char*dat) 
{ 
lcdcmd(comm); 
while(*dat) 
{ 
lcddata(*dat++); 
} 
} 
void delay(int a) 
{ 
int i,j; 
for(i=0;i<=a;i++) 
for(j=0;j<=10000;j++); }
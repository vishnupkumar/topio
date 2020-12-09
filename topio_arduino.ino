#include <Servo.h>
#include <LedControl.h>

int DIN = 11;  //data in pin of led matrix
int CS =  12;  //chip select pin
int CLK = 13;  //clock pin
LedControl lc=LedControl(DIN,CLK,CS,1);
int A = 0;
int B = 1;
int C = 2;
int D = 4;
int a;
int b;
int c;
int d;

int lm1 = 7;
int lm2 = 8;
int rm1 = 9;
int rm2 = 10;

Servo leftHand;
Servo rightHand;
Servo head;
void setup()
{
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  Serial.begin(9600);
  leftHand.attach(3);
  rightHand.attach(6);
  head.attach(5);
  lc.shutdown(0,false);       
  lc.setIntensity(0,15);      //Adjust the brightness maximum is 15
  lc.clearDisplay(0); 
}
void loop()
{
  byte left_look[8]=    {0xC0,0xE0,0xF8,0x7C,0x7E,0x79,0x39,0x1E};
  byte right_look[8]=   {0x3C,0x7E,0xFF,0xFF,0xCF,0xCF,0x7E,0x3C};
  byte left_up[8]=      {0x3C,0x7E,0xF3,0xF3,0xFF,0xFF,0x7E,0x3C};
  byte right_up[8]=     {0x3C,0x7E,0xCF,0xCF,0xFF,0xFF,0x7E,0x3C};
  byte sad[8]=          {0x00,0x00,0x00,0x00,0xFF,0xFF,0x7E,0x3C};
  byte happy[8]=        {0x3C,0x42,0x81,0x99,0xA5,0x81,0x42,0x3C};
  byte surprise[8]=     {0x3C,0x42,0x99,0xA5,0xA5,0x99,0x42,0x3C};
  byte sleepy[8]=       {0x3C,0x42,0xBD,0x89,0x91,0xBD,0x42,0x3C};
  byte love[8]=         {0x0C,0x1E,0x3E,0x7C,0x7C,0x3E,0x1E,0x0C};
  //wink
  byte wink1[8]=       {0x3C,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x3C};
  byte wink2[8]=       {0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C};
  byte wink3[8]=       {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18};
  byte wink4[8]=       {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
  /*byte wink5[8]=     {0x00,0x00,0x00,0x00,0xFF,0xFF,0x7E,0x3C};
  byte wink6[8]=       {0x00,0x00,0x00,0x00,0x00,0xFF,0x7E,0x3C};
  byte wink7[8]=       {0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x3C};
  byte wink8[8]=       {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C};
  byte wink9[8]=       {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
*/
  a=digitalRead(A);
  b=digitalRead(B);
  c=digitalRead(C);
  d=digitalRead(D);
    printByte(wink1);
    delay(200);
    printByte(wink2);
    delay(200);
    printByte(wink3);
    delay(200);
    printByte(wink4);
    delay(200);
    printByte(wink3);
    delay(200);
    printByte(wink2);
    delay(200);
    printByte(wink1);
    delay(200);
  if(a==0 && b==0 && c==0 && d==1)//forward
  {
   digitalWrite(lm1,HIGH);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,HIGH);
   digitalWrite(rm2,LOW); 
  }
  else if(a==0 && b==0 && c==1 && d==0)//reverse
  {
   digitalWrite(lm1,LOW);
   digitalWrite(lm2,HIGH);
   digitalWrite(rm1,LOW);
   digitalWrite(rm2,HIGH); 
  }
  else if(a==0 && b==0 && c==1 && d==1)//right
  {
   digitalWrite(lm1,HIGH);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,LOW);
   digitalWrite(rm2,LOW); 
  }
  else if(a==0 && b==1 && c==0 && d==0)//left
  {
   digitalWrite(lm1,LOW);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,HIGH);
   digitalWrite(rm2,LOW); 
  }
  else if(a==0 && b==1 && c==0 && d==1)//dance
  {
   digitalWrite(lm1,HIGH);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,LOW);
   digitalWrite(rm2,LOW); 
   delay(1000);
   
   digitalWrite(lm1,LOW);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,HIGH);
   digitalWrite(rm2,LOW);
   delay(1000);
   
   rightHand.write(90);
   delay(15);
   rightHand.write(0);
   delay(15);
   leftHand.write(90);
   delay(15);
   leftHand.write(0);
   delay(15);
   
   digitalWrite(lm1,HIGH);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,LOW);
   digitalWrite(rm2,LOW); 
   delay(1000);
   
   digitalWrite(lm1,LOW);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,HIGH);
   digitalWrite(rm2,LOW);
   delay(1000);
   
   rightHand.write(90);
   delay(15);
   leftHand.write(90);
   delay(15);
   rightHand.write(0);
   delay(15);
   leftHand.write(0);
   delay(15);
   
  }
  else if(a==0 && b==1 && c==1 && d==0)//love
  {
    printByte(love);
  }
  else if(a==0 && b==1 && c==1 && d==1)//confused
  {
    
  }
  else if(a==1 && b==0 && c==0 && d==0)//sad
  {
    printByte(sad);
  }
  else if(a==1 && b==0 && c==0 && d==1)//hands up
  {
    
  }
  else if(a==1 && b==0 && c==1 && d==0)//shake hand
  {
    
  }
  else if(a==1 && b==0 && c==1 && d==1)//rotate head
  {
    
  }
  else if(a==1 && b==1 && c==0 && d==0)//wink eyes
  {
    printByte(wink1);
    delay(200);
    printByte(wink2);
    delay(200);
    printByte(wink3);
    delay(200);
    printByte(wink4);
    delay(200);
    printByte(wink3);
    delay(200);
    printByte(wink2);
    delay(200);
    printByte(wink1);
    delay(200);
  }
  else if(a==1 && b==1 && c==0 && d==1)//stop
  {
   digitalWrite(lm1,LOW);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,LOW);
   digitalWrite(rm2,LOW); 
  }
  else if(a==1 && b==1 && c==1 && d==0)//forward
  {
    
  }
  else if(a==1 && b==1 && c==1 && d==1)//forward
  {
    
  }
  
}
void printByte(byte character [])
{
  int i = 0;
  for(i=0; i<8; i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

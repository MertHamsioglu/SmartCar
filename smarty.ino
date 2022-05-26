int lm1=8; //left motor output 1
int lm2=9; //left motor output 2
int rm1=10;  //right motor output 1
int rm2=11;  //right motor output 2
int sl=12;    //sensor 1 input (left)
int sr=7;    //sensor 2 input (right)
int SlV=0;
int SrV=0;
int led=A0;
void setup()
{
 pinMode(lm1,OUTPUT); //set left motor forward output
 pinMode(lm2,OUTPUT); //set left motor backward output
 pinMode(rm1,OUTPUT); //set right motor forward output
 pinMode(rm2,OUTPUT); //set right motor backward output
 pinMode(led,OUTPUT);
 pinMode(sl,INPUT);   //set left sensor input
 pinMode(sr,INPUT);   //set right sensor input
 Serial.begin(9600);
sTOP();
}
void loop()
{
 SlV=digitalRead(sl);	//read left sensor
 SrV=digitalRead(sr);   //read right sensor

 if(SrV==LOW && SlV== LOW)	//if both sensors are LOW then no edge
 {
   digitalWrite(led,LOW);
   ForWard();			//go forward
 }

 if(SrV==HIGH && SlV== HIGH)   //if both sensors are HIGH then there is edge ahead
 {
   digitalWrite(led,HIGH);
   BackWard();			//go backward for 400 ms
   delay(400);				
   Right();			//go right for 550 ms
   delay(550);
   ForWard();			//go forward
   delay(200);
 }
 
 if(SrV==LOW && SlV== HIGH)	//if there is edge on the left side
 {
  digitalWrite(led,HIGH);
  BackWard();			//go backward for 400 ms
  delay(400);
  Right();			//go right for 550 ms
  delay(550);
  ForWard();			//go forward
  delay(200);
 }

 if(SrV==HIGH && SlV== LOW)	//if there is edge on the right side
 {
  digitalWrite(led,HIGH);
  BackWard();			//go backward for 400 ms
  delay(400);
  Left();			//go left for 550 ms
  delay(550);
  ForWard();			//go forward
  delay(200);
 }
}

void ForWard()
 {
  digitalWrite(lm1,HIGH);	//set forward pins for left motor
  digitalWrite(lm2,LOW);	//set forward pins for left motor
  digitalWrite(rm1,HIGH);	//set forward pins for right motor
  digitalWrite(rm2,LOW);	//set forward pins for right motor
 } 

void BackWard()
 {
  digitalWrite(lm1,LOW);	//set backward pins for left motor
  digitalWrite(lm2,HIGH);	//set backward pins for left motor
  digitalWrite(rm1,LOW);	//set backward pins for right motor
  digitalWrite(rm2,HIGH);	//set backward pins for right motor
 }

void Left()
 {
  digitalWrite(lm1,LOW);	//set backward pins for left motor
  digitalWrite(lm2,HIGH);	//set backward pins for left motor
  digitalWrite(rm1,HIGH);	//set forward pins for right motor
  digitalWrite(rm2,LOW);	//set forward pins for right motor
 } 

void Right()
 {
  digitalWrite(lm1,HIGH);	//set forward pins for left motor
  digitalWrite(lm2,LOW);	//set forward pins for left motor
  digitalWrite(rm1,LOW);	//set backward pins for right motor
  digitalWrite(rm2,HIGH);	//set backward pins for right motor
 }  

void sTOP()
 {
  digitalWrite(lm1,LOW);	//stop left motor
  digitalWrite(lm2,LOW);	//stop left motor
  digitalWrite(rm1,LOW);	//stop right motor
  digitalWrite(rm2,LOW);	//stop right motor
 }

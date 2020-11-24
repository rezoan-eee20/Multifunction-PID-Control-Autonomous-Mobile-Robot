//LINE INDICATOR LED
#define ld1 35
#define ld2 34
#define ld3 33
#define ld4 32
#define lmd 36
#define rmd 37
#define rd1 38
#define rd2 39
#define rd3 40
#define rd4 41

//MOTOR
#define LM1 5
#define LM2 6
#define RM1 3
#define RM2 4
#define E1 2
#define E2 7

//BUZZER,SWITCH,LED
#define bz 13
#define buz 11
#define green 8
#define red 9
#define sw1 50
#define sw2 51

//SONAR
#include <NewPing.h>
const int trigPinLs = 23;
const int echoPinLs = 22;
const int trigPinMs = 25;
const int echoPinMs = 24;
const int trigPinRs = 27;
const int echoPinRs = 26;
int distanceLw=0;
int distanceFw=0;
int distanceRw=0;


//LINE PID
#define Kp 6
#define Ki 0  // experiment to determine This, start by someThing small That just makes your bot follow The line at a slow speed
#define Kd 50 // experiment to determine This, slowly increase The speeds and adjust This value. ( Note: Kp < Kd) 
#define rightmaxspeed 200 // max speed of The robot
#define leftmaxspeed 200 // max speed of The robot
#define rightbasespeed 200 // This is The speed at which The motors should spin when The robot is perfectly on The line
#define leftbasespeed 200 // This is The speed at which The motors should spin when The robot is perfectly on The line

//ULTRASONIC PID
#define Kp1 5 
#define Kd1 20
#define rightmaxsped 150 
#define leftmaxsped 150 
#define rightbasesped 100 
#define leftbasesped 100

//AUTO CALIB. + PID 
int lastError=0,error=0,motorspeed=0,rightmotorspeed=0,leftmotorspeed=0;
int pth=0,th=0,C=0,W=0,J=0,R=0,S=0,P1=0,P2=0;
float Th=.5;
int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=90;
int position1=0,position2=0;

//COLOUR SENSOR
long integral=0;
#define RED 45 
#define GREEN 44 
#define SENSOROUTPUT A10
#define SAMPLE_NUM 50   
#define MILISEC 10      
#define REST 0          
double value_red = 0.0, value_green = 0.0, value_blue = 0.0, value = 0.0;
float red_factor = 1.0, green_factor = 1.0, blue_factor = 1.0;

//LINE SENSOR
const int sensor0=0;
const int sensor1=1;
const int sensor2=2;
const int sensor3=3;
const int sensor4=4;
const int sensor5=5;
const int sensor6=6;
const int sensor7=7;
const int sensor8=8;
const int sensor9=9;

int ls1=0;
int ls2=0;
int ls3=0;
int ls4=0;
int rms=0;
int lms=0;
int rs1=0;
int rs2=0;
int rs3=0;
int rs4=0;

int Ls1=0;
int Ls2=0;
int Ls3=0;
int Ls4=0;
int Rms=0;
int Lms=0;
int Rs1=0;
int Rs2=0;
int Rs3=0;
int Rs4=0;


//OBSTACLE FUNCTIONS + WALL FUNCTIONS
void distanceLW()
{
  //NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
NewPing sonar(23,22,50);
  
  //Serial.print("Ping: ");
  distanceLw=sonar.ping_cm();
  //Serial.print(distanceFw);
  //Serial.println("cm");
  if(distanceLw==0)
{
  distanceLw=25;
}
}

void distanceFW()
{
NewPing sonar(25,24,50);
  
  //Serial.print("Ping: ");
  distanceFw=sonar.ping_cm();
  //Serial.print(distanceFw);
  //Serial.println("cm");
  if(distanceFw==0)
{
  distanceFw=200;
}
}

void distanceRW()
{
NewPing sonar(27,26,50);
  
  //Serial.print("Ping: ");
  distanceRw=sonar.ping_cm();
  //Serial.print(distanceFw);
  //Serial.println("cm");
}


//LINE SENSORS
void sensor(){
  
  rs1 =analogRead(sensor0);
  rs2 =analogRead(sensor1);
  rs3 =analogRead(sensor2);
  rs4 =analogRead(sensor3);
  rms =analogRead(sensor4);
  lms =analogRead(sensor5);
  ls1 =analogRead(sensor6);
  ls2 =analogRead(sensor7);
  ls3 =analogRead(sensor8);
  ls4 =analogRead(sensor9);

Serial.println(Rms);
//delay(100);
//Serial.println(Lms);
//delay(100);
//Serial.println(Th);
//delay(500);

//Black Line
    if(rs1<th)
    {
    digitalWrite(rd1,HIGH);
    Rs1=1;
    
    }
    else
    {
    digitalWrite(rd1,LOW);
    Rs1=0;
    
    }
    if(rs2<th)
    {
    digitalWrite(rd2,HIGH);
    Rs2=1;
    
    }
    else
    {
    digitalWrite(rd2,LOW);
    Rs2=0;
   
    }
    if(rs3<th)
    {
    digitalWrite(rd3,HIGH);
    Rs3=1;
    
    }
    else
    {
    digitalWrite(rd3,LOW);
    Rs3=0;
    
    }
    if(rs4<th)
    {
    digitalWrite(rd4,HIGH);
    Rs4=1;
    
    }
    else
    {
    digitalWrite(rd4,LOW);
    Rs4=0;
    
    }
    if(rms<th)
    {
    digitalWrite(rmd,HIGH);
    Rms=1;
    
    }
    else
    {
    digitalWrite(rmd,LOW);
    Rms=0;
    
    }
    if(lms<th)
    {
    digitalWrite(lmd,HIGH);
    Lms=1;
    
    }
    else
    {
    digitalWrite(lmd,LOW);
    Lms=0;
   
    }
    if(ls1<th)
    {
    digitalWrite(ld1,HIGH);
    Ls1=1;
    
    }
    else
    {
    digitalWrite(ld1,LOW);
    Ls1=0;
    
    }
    if(ls2<th)
    {
    digitalWrite(ld2,HIGH);
    Ls2=1;
    
    }
    else
    {
    digitalWrite(ld2,LOW);
    Ls2=0;
    
    }
    if(ls3<th)
    {
    digitalWrite(ld3,HIGH);
    Ls3=1;
    
    }
    else
    {
    digitalWrite(ld3,LOW);
    Ls3=0;
    
    }
    if(ls4<th)
    {
    digitalWrite(ld4,HIGH);
    Ls4=1;
    
    }
    else
    {
    digitalWrite(ld4,LOW);
    Ls4=0;
    
    }
}




  //LINE PID FUNCTION
void forwardp()
{ 
   error = ((((Lms*10)+(Ls1*20)+(Ls2*30)+(Ls3*40))/(Lms+Ls1+Ls2+Ls3))-(((Rms*10)+(Rs1*20)+(Rs2*30)+(Rs3*40))/(Rms+Rs1+Rs2+Rs3)));
integral=integral+error;
  int motorspeed = Kp * error + Ki*integral + Kd * (error - lastError);
  lastError = error;

motorspeed=motorspeed;

  int rightmotorspeed = rightbasespeed+motorspeed;
  int leftmotorspeed = leftbasespeed-motorspeed;

  if (rightmotorspeed > rightmaxspeed ) rightmotorspeed = rightmaxspeed; // prevent The motor from going beyond max speed
  if (leftmotorspeed > leftmaxspeed ) leftmotorspeed = leftmaxspeed; // prevent The motor from going beyond max speed
  if (rightmotorspeed < 0) rightmotorspeed =0; // keep The motor speed positive
  if (leftmotorspeed < 0) leftmotorspeed =0; // keep The motor speed positive

//Serial.println(error);
//Serial.println(rightmotorspeed);

 // move forward wiTh appropriate speeds
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(E1, rightmotorspeed);
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(E2, leftmotorspeed);
}


//Line Small Pid
void forwardps()
{ 
  int error = ((((Lms*10)+(Ls1*20))/(Lms+Ls1))-(((Rms*10)+(Rs1*20))/(Rms+Rs1)));
int motorspeed = Kp * error + Kd * (error - lastError);
  lastError = error;

motorspeed=motorspeed;

  int rightmotorspeed = rightbasespeed+motorspeed;
  int leftmotorspeed = leftbasespeed-motorspeed;

  if (rightmotorspeed > rightmaxspeed ) rightmotorspeed = rightmaxspeed; // prevent The motor from going beyond max speed
  if (leftmotorspeed > leftmaxspeed ) leftmotorspeed = leftmaxspeed; // prevent The motor from going beyond max speed
  if (rightmotorspeed < 0) rightmotorspeed =0; // keep The motor speed positive
  if (leftmotorspeed < 0) leftmotorspeed =0; // keep The motor speed positive

//Serial.println(error);
//Serial.println(rightmotorspeed);

 // move forward wiTh appropriate speeds
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(E1, rightmotorspeed);
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(E2, leftmotorspeed);
}


//WALL FUNCTION
void RWforward()
{
   distanceRW();
    
position1 = distanceRw;
error = 7-position1 ;

  int motorsped = Kp1 * error + Kd1 * (error - lastError);
  lastError = error;

  int rightmotorsped = rightbasesped + motorsped;
  int leftmotorsped = leftbasesped - motorsped;
  
  if (rightmotorsped > rightmaxsped ) rightmotorsped = rightmaxsped; // prevent the motor from going beyond max speed
  if (leftmotorsped > leftmaxsped ) leftmotorsped = leftmaxsped; // prevent the motor from going beyond max speed
  if (rightmotorsped < 0) rightmotorsped = 0; // keep the motor speed positive
  if (leftmotorsped < 0) leftmotorsped = 0; // keep the motor speed positive

//Serial.println(rightmotorsped);

{
   // move forward with appropriate speeds
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(E1, rightmotorsped);
  
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(E2, leftmotorsped);
}
}

void LWforward()
{
   distanceLW();
    
position2 =  distanceLw;

error = 12-position2 ;

  int motorsped = Kp1 * error + Kd1 * (error - lastError);
  lastError = error;

  int rightmotorsped = rightbasesped - motorsped;
  int leftmotorsped = leftbasesped + motorsped;
  
    if (rightmotorsped > rightmaxsped ) rightmotorsped = rightmaxsped; // prevent the motor from going beyond max speed
  if (leftmotorsped > leftmaxsped ) leftmotorsped = leftmaxsped; // prevent the motor from going beyond max speed
  if (rightmotorsped < 0) rightmotorsped = 0; // keep the motor speed positive
  if (leftmotorsped < 0) leftmotorsped = 0; // keep the motor speed positive

//Serial.println(leftmotorsped);

{
   // move forward with appropriate speeds
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(E1, rightmotorsped);
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(E2, leftmotorsped);
}
}

//STOP FUNCTION
void stand()
{
  analogWrite(E1,255);
  analogWrite(E2,255);
   
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,HIGH);
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,HIGH);
  
}

//FORWARD FUNCTION
void forward()
{
  analogWrite(E1,100);
  analogWrite(E2,100);
   
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,LOW);
  
  }

//BACKWARD FUNCTION
void backward()
{
  analogWrite(E1,81);
  analogWrite(E2,81);
   
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,HIGH);
  
}

//SHARP RIGHT TURN 
void rightsharp()
{
  analogWrite(E1,100);
  analogWrite(E2,100);
   
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,LOW);
  
}

//SHARP LEFT TURN
void leftsharp()
{
  analogWrite(E1,100);
  analogWrite(E2,100);
   
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,HIGH);
  
}


//NORMAL RIGHT TURN
void rightsharpb2()
{
  stand();
 //delay(50);
 
for(;;)
  {
    sensor();
    
     if((Lms>Th)&&(Rms>Th))
   {
    stand();
    delay(30);
     break;
   }
    
rightsharp(); 
  }
  }

//NORMAL LEFT TURN
void leftsharpb2()
{
  stand();
 //delay(30);
  
for(;;)
  {
    sensor();
    
     if((Rms>Th)&&(Lms>Th))
   {
    
    stand();
    delay(30);
    
     break;
   }
  
  leftsharp();
 
  }
  }


  
//90 DEGREE RIGHT TURN
void rightsharpb90()
{
  for(;;)
  {
    sensor();
  
if((Rms>Th)&&(Rs1>Th)&&(Rs2>Th)&&(Rs3>Th)&&(Lms>Th)&&(Ls1>Th)&&(Ls2>Th)&&(Ls3>Th))
    {
      
      C=1;
     break;
    }
    
if((Rs2<Th)&&(Rs3<Th)&&(Rs4<Th)&&(Ls2<Th)&&(count6<1))
  {
   
  stand();
  digitalWrite(red,HIGH);
  delay(50);
  
   break;
  } 

if((Rs2<Th)&&(Rs3<Th)&&(Rs4<Th)&&(Ls2<Th)&&(count6>1))
  {
    if(((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))
  {
    count1+=1;
  }
  
  stand();
  digitalWrite(red,HIGH);
  delay(50);
  
   break;
  }
 forward();
  }

  if((C==0)&&(W==0)&&((Ls2<Th)&&(Ls3<Th)&&(Ls4<Th)&&((count1!=1))))
  {
  
if((((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th))))
  {
    
  for(;;)
  {
    sensor();
    if((Rms<Th)&&(Lms<Th))
    {
      break;
    }
    rightsharp();
  }
  }

for(;;)
  {
    sensor();
    if((Rms>Th)&&(Rs1<Th)&&(Lms>Th))
    {
      stand();
      delay(50);
      break;
    }
    rightsharp();
  }
  }


  if((C==0)&&(W==0)&&((Ls2>Th)||(Ls3>Th)||(Ls4>Th)))
  {
  
if(((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))
  {
  for(;;)
  {
    sensor();
    if((Rms<Th)&&(Lms<Th))
    {
      break;
    }
    leftsharp();
  }
  }

for(;;)
  {
    sensor();
    
     if((Ls1<Th)&&(Rms>Th)&&(Lms>Th))
   {
    stand();
    delay(50);
    
  break;
   }
  
 leftsharp();
 
  }
}

if(C==0)
{  
  if((Rs2>Th)||(Rs3>Th)||(Rs4>Th)||(Ls2>Th))
{
  for(;;)
  {
    sensor();
    if((Rs2<Th)&&(Rs3<Th)&&(Rs4<Th)&&(Ls2<Th))
{

  break;
}
 
forwardps();
  }
}
  
}

}

  

//45 DEGREE RIGHT TURN  
void rightsharpb45()
{
  for(;;)
  {
    sensor();
  
if((Rms>Th)&&(Rs1>Th)&&(Rs2>Th)&&(Rs3>Th)&&(Lms>Th)&&(Ls1>Th)&&(Ls2>Th)&&(Ls3>Th))
    {
      C=1;
     break;
    }
    

    if((Rs4<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Rs1<Th)&&(Rms<Th)&&(Ls1<Th)&&(count1>1))
       {
         
    count4+=1;
    
    stand();
    
    digitalWrite(green,HIGH);
    delay(50);
    
  break;
  }

if((Rs4<Th)&&(Rs2<Th)&&(Rs3<Th)&&(count1<2))
       {
         
    count4+=1;
    
    stand();
    
    digitalWrite(green,HIGH);
    delay(50);
    
  break;
  }

  forward();
  }

  if((C==0)&&(W==0)&&(Ls2<Th)&&(Ls3<Th)&&(Ls4<Th))
{

if(((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))
  {
  for(;;)
  {
    sensor();
    if((Rms<Th)&&(Lms<Th))
    {
      break;
    }
    rightsharp();
  }
  }

for(;;)
  {
    sensor();
    
     if((Lms>Th)&&(Rms>Th))
   {
    stand();
    delay(50);
    
  break;
   }
  
 rightsharp();
 
  }
}

if((C==0)&&(W==0)&&((Ls2>Th)||(Ls3>Th)||(Ls4>Th)))
  {
  
if(((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))
  {
  for(;;)
  {
    sensor();
    if((Rms<Th)&&(Lms<Th))
    {
      break;
    }
    leftsharp();
  }
  }

for(;;)
  {
    sensor();
    
     if((Ls1<Th)&&(Lms>Th)&&(Rms>Th))
   {
    stand();
    delay(50);
    
  break;
   }
  
 leftsharp();
 
  }
}

if(C==0)
{
  
if((Rs2>Th)||(Rs3>Th)||(Rs4>Th)||(Ls2>Th))
{
  for(;;)
  {
    sensor();
    if((Rs2<Th)&&(Rs3<Th)&&(Rs4<Th)&&(Ls2<Th))
{

  break;
}
 
forwardps();
  }
}
  
}
}


  
//CROSSOVER LINE
void crossoverb()
{
  
distanceFW();

if(distanceFw<30)
{
  stand();
  digitalWrite(buz,HIGH);
  delay(1000);
  digitalWrite(buz,LOW);
  count3+=1;
distanceFW();

if((count3==1)&&(distanceFw<30))
{
  P1=5;
}

if((count3==2)&&(distanceFw<30))
{
  P2=5;
}
if(((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))
  {
  for(;;)
  {
    sensor();
    if((Rms<Th)&&(Lms<Th))
    {
      break;
    }
    rightsharp();
  }
  }
  
   for(;;)
  {
    sensor();
    
     if((Rms>Th)&&(Lms>Th)&&(Rs1<Th))
   {
    stand();
    delay(1000);
      break;
   }
  
  
 rightsharp();
 
  }
}
  
  else
 { 
   for(;;)
  {
    sensor();
  
   
      if((Rs2<Th)&&(Ls2<Th)&&(Rs3<Th)&&(Ls3<Th))
  {
    
   digitalWrite(buz,HIGH);
    stand();
  delay(50);
  digitalWrite(buz,LOW);
    break;
  }
  
  forward();
  }

  if(((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))
  {
  for(;;)
  {
    sensor();
    if((Rms<Th)&&(Lms<Th))
    {
      break;
    }
    leftsharp();
  }
  
  for(;;)
  {
    sensor();
    
     if((Rs1<Th)&&(Rms>Th)&&(Lms>Th))
   {
    stand();
    delay(50);
      break;
   }
  
  leftsharp();
 
  }

  }
 
 
if((Rms<Th)&&(Lms<Th))
  {
  
  if((P1==0)&&(P2==0))
  {
   for(;;)
  {
    sensor();
    
     if((Rms>Th)&&(Lms>Th)&&(Rs1<Th))
   {
    count6+=1;
    stand();
    delay(50);
      break;
   }
  
  rightsharp();
 }
}
 
if((P1==5)&&(P2==5))
  {
   for(;;)
  {
    sensor();
    
     if((Rms>Th)&&(Lms>Th)&&(Ls1<Th))
   {
    stand();
    delay(50);
      break;
   }
  
  leftsharp();
 }
 }
 if((P1==5)&&(P2==0))
  {
   for(;;)
  {
    sensor();
    
     if((Rms>Th)&&(Lms>Th)&&(Ls1<Th))
   {
    stand();
    delay(50);
      break;
   }
  leftsharp();
 
  }
 
 P1-=5;
  }

   if((P1==0)&&(P2==5))
  {
   for(;;)
  {
    sensor();
    
     if((Rms>Th)&&(Lms>Th)&&(Rs1<Th))
   {
    stand();
    delay(50);
      break;
   }
  rightsharp();
 }
  
 P1+=5;
 }
  }
}
}

//BUZZER ON CROSSOVER LINE
void cross()
{
  
   for(;;)
  {
    sensor();
  
   
      if((Rs2<Th)&&(Ls2<Th))
  {
    count3+=1;
    digitalWrite(buz,HIGH);
    stand();
  delay(50);
  digitalWrite(buz,LOW);
    break;
  }
  forward();
  }
  
if(((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))
  {
  for(;;)
  {
    sensor();
    if((Rms<Th)&&(Lms<Th))
    {
      break;
    }
    rightsharp();
  }
  }
  
   for(;;)
  {
    sensor();
    
     if((Rs1<Th)&&(Rms>Th)&&(Lms>Th))
   {
    stand();
    delay(50);
      break;
   }
  
  
 rightsharp();
 
  }

  }

  
 
//RGB COLOUR FUNCTION
void colour()
{
  value_red = red_factor * color_intensity1(RED, SAMPLE_NUM, MILISEC);
  Serial.print("Red= "); Serial.println(value_red,0);
  value_green = green_factor * color_intensity2(GREEN, SAMPLE_NUM, MILISEC);
  Serial.print("     Green= "); Serial.println(value_green,0);
  
  }

double color_intensity1(char colorPin, int sample_num, int milisec)
{
  double value = 0.0;
  digitalWrite(colorPin, LOW);  
  delay(50);
  analogWrite(colorPin, 200);
  for (int i = 1; i <= sample_num; i++)
  {
    value += analogRead(SENSOROUTPUT);
    delay(milisec);
  }
  value = value / (double) sample_num;
  analogWrite(colorPin, 0);
  return value;
}
double color_intensity2(char colorPin, int sample_num, int milisec)
{
  double value = 0.0;
  digitalWrite(colorPin, LOW);  //updated "value_green" global variable
  delay(50);
  analogWrite(colorPin, 255);
  for (int i = 1; i <= sample_num; i++)
  {
    value += analogRead(SENSOROUTPUT);
    delay(milisec);
  }
  value = value / (double) sample_num;
  analogWrite(colorPin, 0);
  return value;
}


//90 DEGREE LEFT TURN
void leftsharpb90()
{
   for(;;)
  {
    sensor();


if((Rms>Th)&&(Rs1>Th)&&(Rs2>Th)&&(Rs3>Th)&&(Lms>Th)&&(Ls1>Th)&&(Ls2>Th)&&(Ls3>Th))
    {
      C=1;
     break;
    }
    

   if((Ls2<Th)&&(Ls3<Th)&&(Ls4<Th)&&(Rs2<Th)&&(count1<2))
  { 
    count2+=1;
  stand();
  digitalWrite(red,HIGH);
  delay(50);
   break;
  } 

 if((Ls2<Th)&&(Ls3<Th)&&(Ls1<Th)&&(Lms<Th)&&(Rs1<Th)&&(count1>1))
  { 
    count2+=1;
  stand();
  digitalWrite(red,HIGH);
  delay(50);
   break;
  } 

forward();
} 
  
  if((C==0)&&(W==0)&&((Rs2<Th)&&(Rs3<Th)&&(Rs4<Th)))
  {
  
if((((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))&&((count6<1)||(count1>1)))
  {
  for(;;)
  {
    sensor();
    if((Rms<Th)&&(Lms<Th))
    {
      break;
    }
    leftsharp();
  }
  }

for(;;)
  {
    sensor();
    
     if((Ls1<Th)&&(Lms>Th)&&(Rms>Th))
   {
    stand();
    delay(50);
    
  break;
   }
  
 leftsharp();
 
  }
}


if((C==0)&&(W==0)&&((Rs2>Th)||(Rs3>Th)||(Rs4>Th)))
  {
  
if(((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))
  {
  for(;;)
  {
    sensor();
    if((Rms<Th)&&(Lms<Th))
    {
      break;
    }
    rightsharp();
  }
  }

for(;;)
  {
    sensor();
    
     if((Rs1<Th)&&(Lms>Th)&&(Rms>Th))
   {
    stand();
    delay(50);
    
  break;
   }
  
 rightsharp();
 
  }
}
  
if(C==0)
{
  
  if((Ls2>Th)||(Ls3>Th)||(Ls4>Th)||(Rs2>Th)||(Rs3>Th))
{
  for(;;)
  {
    sensor();
    if((Ls2<Th)&&(Ls3<Th)&&(Ls4<Th)&&(Rs2<Th)&&(Rs3<Th))
{

  break;
}
 
forwardps();
  }
}
  
}

}
 
  
//45 DEGREE LEFT TURN
void leftsharpb45()
{
   for(;;)
  {
    sensor();

if((Rms>Th)&&(Rs1>Th)&&(Rs2>Th)&&(Rs3>Th)&&(Lms>Th)&&(Ls1>Th)&&(Ls2>Th)&&(Ls3>Th))
    {
      
      C=1;
     break;
    }
    
if((Ls4<Th)&&(Rs2<Th)&&(Ls2<Th)&&(Ls3<Th)&&(count1<2))
       {
        
    count5+=1;
    
    stand();
    
    digitalWrite(green,HIGH);
    delay(50);
    
  break;
  }

if((Ls4<Th)&&(Rs2<Th)&&(Rs1<Th)&&(Lms<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th)&&(count1>1))
       {
        
    count5+=1;
    
    stand();
    
    digitalWrite(green,HIGH);
    delay(50);
    
  break;
  }

  
  forward();
  }


if((C==0)&&(W==0)&&(Rs2<Th)&&(Rs3<Th)&&(Rs4<Th))
{

if(((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))
  {
  for(;;)
  {
    sensor();
    if((Rms<Th)&&(Lms<Th))
    {
      break;
    }
    leftsharp();
  }
  }

for(;;)
  {
    sensor();
    
     if((Rms>Th)&&(Lms>Th))
   {
    stand();
    delay(50);
    
  break;
   }
  
 leftsharp();
 
  }

}

if((C==0)&&(W==0)&&((Rs2>Th)||(Rs3>Th)||(Rs4>Th)))
  {
  
if(((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))
  {
  for(;;)
  {
    sensor();
    if((Rms<Th)&&(Lms<Th))
    {
      break;
    }
    rightsharp();
  }
  }

for(;;)
  {
    sensor();
    
     if((Rs1<Th)&&(Lms>Th)&&(Rms>Th))
   {
    stand();
    delay(50);
    
  break;
   }
  
 rightsharp();
 
  }
}


if(C==0)
{
  
if((Ls2>Th)||(Ls3>Th)||(Ls4>Th)||(Rs2>Th)||(Rs3>Th))
{
  for(;;)
  {
    sensor();
    if((Ls2<Th)&&(Ls3<Th)&&(Ls4<Th)&&(Rs2<Th)&&(Rs3<Th))
{

  break;
}
 
forwardps();
  }
}
  
}
}


//OBSTACLE FUNCTION
void obs()
{
  digitalWrite(buz,HIGH);
  stand();
   delay(1000);
  digitalWrite(buz,LOW);

  
      rightsharp();
      delay(500);
      stand();
      delay(1000);
     

forward();
delay(600);
stand();
delay(1000);

leftsharp();
delay(500);
stand();
delay(1000);

forward();
delay(800);
stand();
delay(1000);

leftsharp();
delay(500);
stand();
delay(1000);

  for(;;)
  {

sensor();

if(Rs3>Th)
{
  for(;;)
  {
    sensor();
    if(Rs3<Th)
    {
      stand();
      delay(1000);
      break;
    }
  }
  break;
}
forward();

}

     for(;;)
     {
      sensor();
      if(Rms>Th||Lms>Th)
      {
        stand();
        delay(1000);
        break;
      }
      rightsharp();
     }
      }

//WALL FUNCTION
void WALL()
{
  LWforward();

  distanceFW();

  if(distanceFw<8)
  {
    stand();
    delay(1000);
    rightsharp();
    delay(500);
    stand();
    delay(1000);
  }
}
  

void WALL1()
{
  for(;;)
  {
  RWforward();

  distanceFW();
  

  if(distanceFw<8)
  {
    stand();
    delay(1000);
    leftsharp();
    delay(500);
    stand();
    delay(1000);
  }

if((distanceRw>40)&&(distanceFw>40))
{
  break;
}

}
}

//EXCEPTIONAL LINE
void YA()
{  
for(;;)
  {
    sensor();
    
     if((Lms>Th)&&(Rms>Th))
   {
    stand();
    delay(10);
    
  break;
   }
  
 leftsharp();
 
  }

  if((Ls2>Th)||(Ls3>Th)||(Rs2>Th)||(Rs3>Th))
{
  for(;;)
  {
    sensor();
    if((Ls2<Th)&&(Ls3<Th)&&(Rs2<Th)&&(Rs3<Th))
{

  break;
}
 
forwardps();
  }
}
  
  }


void setup ()
{
  pinMode(ld1,OUTPUT);
  pinMode(ld2,OUTPUT);
  pinMode(ld3,OUTPUT);
  pinMode(ld4,OUTPUT);
  pinMode(lmd,OUTPUT);
  pinMode(rmd,OUTPUT);
  pinMode(rd1,OUTPUT);
  pinMode(rd2,OUTPUT);
  pinMode(rd3,OUTPUT);
  pinMode(rd4,OUTPUT);

  pinMode(bz,OUTPUT);
  pinMode(buz,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(sw1,INPUT_PULLUP);
  pinMode(sw2,INPUT_PULLUP);
  
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(E1,OUTPUT);
  pinMode(E2,OUTPUT);
  Serial.begin(9600);
  
  //AUTO CALIBERATION
  int val=0,mx=0,mn=0,v=0,mid=0;
 for(int p=0;p<1000;p++)
  {
    for(int i=0;i<10;i++)
{
  val=analogRead(i);
  if(val>=mx)
  mx=val;
  
  v=val;
  if(mn==0)
  mn=mx;
  
  if(v<=mn)
  mn=v;
  
  }
mid=(mx+mn)/2;
  
th=mid+200;
  }
if((mx-mid)<100)
  {
    
  digitalWrite(red,HIGH);
  delay(1000);
  digitalWrite(red,LOW);
  }

  if((mx-mid)>300)
  {
    th=mid+200;
    digitalWrite(green,HIGH);
  delay(1000);
  digitalWrite(green,LOW);
  }
  digitalWrite(bz,LOW);
  digitalWrite(bz,HIGH);
  delay(1000);
  digitalWrite(bz,LOW);
 }


void loop()
{ 
  for(;;)
  {
   
    digitalWrite(bz,LOW);
    digitalWrite(buz,LOW);
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    //SWITCH
    if(digitalRead(sw1)==LOW)
    {
      count6=2;
      digitalWrite(buz,HIGH);
      delay(1000);
    }

      
    if(digitalRead(sw2)==LOW)
    {
      count1=2;
      digitalWrite(buz,HIGH);
      delay(1000);
    }

   //SENSOR READING  
  sensor();

//FORWARD PID LOGIC
if((C==0))
{
 if(((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1>Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1>Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms>Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th)))
  {
    
    forwardp();
  }

//LINE CURVE LOGIC
 if(((Rms<Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1>Th)&&(Ls2>Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3>Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2>Th)&&(Ls3>Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2>Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1>Th)&&(Ls2>Th)&&(Ls3<Th)))
   {
        //forwardp();
       leftsharpb2(); 
   }

   //FORWARD PID LOGIC
  if(((Rms>Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1>Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms>Th)&&(Lms>Th)&&(Rs1>Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms>Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1>Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms>Th)&&(Lms<Th)&&(Rs1>Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th)))  
   {
    
    forwardp();
   }

//LINE CURVE LOGIC
  if(((Rms>Th)&&(Lms<Th)&&(Rs1>Th)&&(Rs2>Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2>Th)&&(Rs3>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2>Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1>Th)&&(Rs2>Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th)))
{
   // forwardp();
  rightsharpb2();
}

}

//LINE GAP
if(((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs4<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls4<Th))&&(C==0)&&(W==0))
  {
     
 WALL();
  }


//CROSSOVER
 
  if((C==1)&&(W==0))
  {
   C-=1;
   
  crossoverb();
    }
     
  if(((Rms>Th)&&(Lms>Th)&&(Rs1>Th)&&(Rs2>Th)&&(Ls1>Th)&&(Ls2>Th))&&(C==0)&&(W==0))
  {
   crossoverb();
  }

  if((C==0)&&(W==0))
  {
    
//30 45 60 RIGHT TURN
  if(((Rms>Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs4>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs4>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms>Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs4>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms>Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs4>Th)&&(Ls1>Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms>Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs4>Th)&&(Ls1>Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs4>Th)&&(Ls1>Th)&&(Ls2<Th)&&(Ls3<Th)))
  {
    
    rightsharpb45();
 }

//90 RIGHT TURN
if(((Rms>Th)&&(Lms>Th)&&(Rs1>Th)&&(Rs2>Th)&&(Rs3>Th)&&(Rs4>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th)&&(Ls4<Th))||((Rms>Th)&&(Lms<Th)&&(Rs1>Th)&&(Rs2>Th)&&(Rs3>Th)&&(Rs4>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th)&&(Ls4<Th))||((Rms>Th)&&(Lms>Th)&&(Rs1>Th)&&(Rs2>Th)&&(Rs3>Th)&&(Rs4>Th)&&(Ls1>Th)&&(Ls2<Th)&&(Ls3<Th)&&(Ls4<Th)))
{ 
  rightsharpb90();
    
}
    
//30 45 60 LEFT TURN
  if(((Lms>Th)&&(Rms>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls4>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th))||((Lms<Th)&&(Rms>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls4>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th))||((Lms>Th)&&(Rms<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls4>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th))||((Lms>Th)&&(Rms>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls4>Th)&&(Rs1>Th)&&(Rs2<Th)&&(Rs3<Th))||((Lms>Th)&&(Rms<Th)&&(Ls1>Th)&&(Ls2<Th)&&(Ls4>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th))||((Lms<Th)&&(Rms>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls4>Th)&&(Rs1>Th)&&(Rs2<Th)&&(Rs3<Th)))
  {
    
    leftsharpb45();
  }

//90 RIGHT TURN
 if(((Lms>Th)&&(Rms>Th)&&(Ls1>Th)&&(Ls2>Th)&&(Ls3>Th)&&(Ls4>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Rs4<Th))||((Lms>Th)&&(Rms<Th)&&(Ls1>Th)&&(Ls2>Th)&&(Ls3>Th)&&(Ls4>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Rs4<Th))||((Lms>Th)&&(Rms>Th)&&(Ls1>Th)&&(Ls2>Th)&&(Ls3>Th)&&(Ls4>Th)&&(Rs1>Th)&&(Rs2<Th)&&(Rs3<Th)&&(Rs4<Th)))
{
  leftsharpb90();
}
}
 
}

}


                            

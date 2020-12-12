#define  ld1 35
#define ld2 34
#define ld3 33
#define ld4 32
#define lmd 36
#define rmd 37
#define rd1 38
#define rd2 39
#define rd3 40
#define rd4 41



#define LM1 5
#define LM2 6
#define RM1 3
#define RM2 4
#define E1 2
#define E2 7

#define bz 13
#define buz 11
#define green 8
#define red 9
#define sw1 50
#define sw2 51

#include <NewPing.h>
const int trigPinLs = 23;
const int echoPinLs = 22;

const int trigPinMs = 25;
const int echoPinMs = 24;


const int trigPinRs = 27;
const int echoPinRs = 26;

// defines variables
int distanceLw=0;

int distanceFw=0;

int distanceRw=0;

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
  distanceLw=200;
}

}




void distanceFW()
{
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
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
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
NewPing sonar(27,26,50);
  
  //Serial.print("Ping: ");
  distanceRw=sonar.ping_cm();
  //Serial.print(distanceFw);
  //Serial.println("cm");

}

//180=7
//180=50
//200=8
//200=50
#define Kp 10
#define Ki .0001  // experiment to determine This, start by someThing small That just makes your bot follow The line at a slow speed
#define Kd 1 // experiment to determine This, slowly increase The speeds and adjust This value. ( Note: Kp < Kd) 
#define rightmaxspeed 200 // max speed of The robot
#define leftmaxspeed 200 // max speed of The robot
#define rightbasespeed 200 // This is The speed at which The motors should spin when The robot is perfectly on The line
#define leftbasespeed 200 // This is The speed at which The motors should spin when The robot is perfectly on The line
//Ultrasonic
#define Kp1 5 // experiment to determine This, start by someThing small That just makes your bot follow The line at a slow speed
#define Kd1 20
#define rightmaxsped 150 // max speed of The robot
#define leftmaxsped 150 // max speed of The robot
#define rightbasesped 100 // This is The speed at which The motors should spin when The robot is perfectly on The line
#define leftbasesped 100 // This is The speed at which The motors should spin when The robot is perfectly on The line

int lastError=0,error=0,motorspeed=0,rightmotorspeed=0,leftmotorspeed=0;
int pth=0,th=0,C=0,W=0,J=0,R=0,S=0;
float Th=.5;
int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=90;
int position1=0,position2=0;
long integral=0;
#define RED 45 //YELLOW
#define GREEN 44 //BLUE

#define SENSOROUTPUT A10

#define SAMPLE_NUM 50   //how many times there will be anlogRead to make an average. 
#define MILISEC 10      //wait between every analogRead
#define REST 0          //keep it zero
double value_red = 0.0, value_green = 0.0, value_blue = 0.0, value = 0.0;

//if you want to adjust gain of the sensor by software
//change these values from 1.0.
float red_factor = 1.0, green_factor = 1.0, blue_factor = 1.0;

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




  //Black Line
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
//Black Line Small Pid
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

//White Line




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


Serial.println(rightmotorsped);


  
  
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


Serial.println(leftmotorsped);


  
  
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

void stand()
{
  analogWrite(E1,255);
  analogWrite(E2,255);
   
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,HIGH);
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,HIGH);
  
}
void forward()
{
  analogWrite(E1,100);
  analogWrite(E2,100);
   
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,LOW);
  
}


void backward()
{
  analogWrite(E1,81);
  analogWrite(E2,81);
   
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,HIGH);
  
}
void rightsharp()
{
  analogWrite(E1,100);
  analogWrite(E2,100);
   
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,LOW);
  
}


void leftsharp()
{
  analogWrite(E1,100);
  analogWrite(E2,100);
   
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,HIGH);
  
}

void leftsharp1()
{
  analogWrite(E1,90);
  analogWrite(E2,90);
   
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,LOW);
  
}





//Black Line
void rightsharpb2()
{
  stand();
  delay(50);
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

void leftsharpb2()
{
  stand();
 delay(50); 
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


  
//Black Line
void rightsharpb90()
{
  
   for(;;)
  {
    sensor();
  


if((Rs2>Th)&&(Rs3>Th)&&(Ls2>Th)&&(Ls3>Th))
    {
      
      C=1;
     break;
    }
    

   if((Rs2<Th)&&(Rs3<Th)&&(Rs4<Th)&&(Ls2<Th)&&(S==0))
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

    
    


   if((Rs2<Th)&&(Rs3<Th)&&(Rs4<Th))
  {
    for(;;)
    {
      sensor();
      if((Rms<Th)&&(Ls2<Th)&&(Ls1<Th))
      {
        
          break;
       
      }
      forward();
    }

   if(((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))
  {
    count1+=1;
  }
  
  stand();
  digitalWrite(green,HIGH);
  delay(50);
  
 
  
   break;
  }

  
  forward();
  }

  
 if((C==0)&&(W==0)&&((Ls2<Th)&&(Ls3<Th)&&(Ls4<Th)))
  {
  

if((((Rms>Th)&&(Lms>Th))||((Rms>Th)&&(Lms<Th))||((Rms<Th)&&(Lms>Th)))&&((count1==2)||(count1==2)))
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

if((Rms<Th)&&(Lms<Th))
  {
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

  

  

void rightsharpb45()
{
  
   for(;;)
  {
    sensor();
  

if((Rs2>Th)&&(Rs3>Th)&&(Ls2>Th)&&(Ls3>Th))
    {
      C=1;
     break;
    }
    

    if((Rms<Th)&&(Rs4<Th)&&(Ls2<Th)&&(Ls1<Th))
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
    
     if((Lms>Th)&&(Rms>Th)&&(Rs1<Th))
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


  
//Black Line Crossover
void crossoverb()
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

  if((count3==1||count3==20||count3==30||count3==40||count3==50||count3==60||count3==70||count3==80||count3==90||count3==100)&&(C==0)&&(W==0))
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
    
     if((Rs1<Th)&&(Rms>Th)&&(Lms>Th))
   {
    stand();
    delay(50);
      break;
   }
  
  
 rightsharp();
 
  }

  
 
  }
 
 
  

 if((count3==10||count3==2||count3==3||count3==4||count3==5||count3==6||count3==7||count3==8||count3==9||count3==10)&&(C==0)&&(W==0))
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
    
     if((Rms>Th)&&(Lms>Th)&&(Ls1<Th))
   {
    stand();
    delay(50);
      break;
   }
  
  
 leftsharp();
 
  }
 
 
  }
 

  
}


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

  
 

void colour()
{
  value_red = red_factor * color_intensity1(RED, SAMPLE_NUM, MILISEC);
  Serial.print("Red= "); Serial.println(value_red,0);
  value_green = green_factor * color_intensity2(GREEN, SAMPLE_NUM, MILISEC);
  Serial.print("     Green= "); Serial.println(value_green,0);
  

  
  //To know the what color the object is?
  

}

/*this function takes three parameter as input:
1.the pin which will turn LED on, 2.number of samples to make an average, 3. delay between each measure.
this function outputs the average amount of light the sensor got (between 0 to 1024)
*/
double color_intensity1(char colorPin, int sample_num, int milisec)
{
  double value = 0.0;
  digitalWrite(colorPin, LOW);  //updated "value_green" global variable
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



void leftsharpb90()
{
   for(;;)
  {
    sensor();


if((Rs2>Th)&&(Rs3>Th)&&(Ls2>Th)&&(Ls3>Th))
    {
      C=1;
     break;
    }
    

   if((Ls2<Th)&&(Ls3<Th)&&(Ls4<Th)&&(Rs2<Th)&&(R==0))
  {
    
   
    
    count2+=1;
  stand();
  digitalWrite(red,HIGH);
  delay(50);
  
  
  
   break;
  } 

    
   if((Ls2<Th)&&(Ls3<Th)&&(Ls4<Th))
  {
    for(;;)
    {
      sensor();
      if((Lms<Th)&&(Rs2<Th)&&(Rs1<Th))
      {
        
          break;
       
      }
      forward();
    }

   
    count5+=1;
  stand();
  digitalWrite(green,HIGH);
  delay(50);
  

  
   break;
  }

  
  forward();
  }

  
 if((C==0)&&(W==0)&&((Rs2<Th)&&(Rs3<Th)&&(Rs4<Th)))
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
  
  
//Black Line Left 45
void leftsharpb45()
{
   for(;;)
  {
    sensor();


if((Rs2>Th)&&(Rs3>Th)&&(Ls2>Th)&&(Ls3>Th))
    {
      
      C=1;
     break;
    }
    

    if((Lms<Th)&&(Ls4<Th)&&(Rs2<Th)&&(Rs1<Th))
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
    
     if((Rms>Th)&&(Lms>Th)&&(Ls1<Th))
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





void WALL()
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
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(E1,OUTPUT);
  pinMode(E2,OUTPUT);
  Serial.begin(9600);
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
  if((mx-mid)>300)
  {
    th=mid+300;
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
  
    sensor();
    
  forwardp();
}  
  
  

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
#define LM2 4
#define RM1 7
#define RM2 6
#define E1 3
#define E2 2

#define bz 13
#define buz 11
#define green 8
#define red 9
#define sw1 50
#define sw2 51

const int trigPinLs = 23;
const int echoPinLs = 22;

const int trigPinMs = 25;
const int echoPinMs = 24;

const int trigPinRs = 27;
const int echoPinRs = 26;

// defines variables
long durationLs=0;
int distanceLw=0;

long durationMs=0;
int distanceFw=0;

long durationRs=0;
int distanceRw=0;

void distanceLW()
{
  // Clears The trigPin
digitalWrite(trigPinLs, LOW);
delayMicroseconds(2);
// Sets The trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinLs, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinLs, LOW);
// Reads The echoPin, returns The sound wave travel time in microseconds
durationLs = pulseIn(echoPinLs, HIGH);
// Calculating The distance
distanceLw= durationLs*0.034/2;
// Prints The distance on The Serial Monitor
}
void distanceFW()
{

// Clears The trigPin
digitalWrite(trigPinMs, LOW);
//delayMicroseconds(2);
// Sets The trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinMs, HIGH);
//delayMicroseconds(10);
digitalWrite(trigPinMs, LOW);
// Reads The echoPin, returns The sound wave travel time in microseconds
durationMs = pulseIn(echoPinMs, HIGH);
// Calculating The distance
distanceFw= durationMs*0.034/2;
// Prints The distance on The Serial Monitor
}
void distanceRW()
{
// Clears The trigPin
digitalWrite(trigPinRs, LOW);
delayMicroseconds(2);
// Sets The trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinRs, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinRs, LOW);
// Reads The echoPin, returns The sound wave travel time in microseconds
durationRs = pulseIn(echoPinRs, HIGH);
// Calculating The distance
distanceRw= durationRs*0.034/2;
// Prints The distance on The Serial Monitor
Serial.println(distanceRw);

}



#define Kp 7 // experiment to determine This, start by someThing small That just makes your bot follow The line at a slow speed
#define Kd 50 // experiment to determine This, slowly increase The speeds and adjust This value. ( Note: Kp < Kd) 
#define rightmaxspeed 250 // max speed of The robot
#define leftmaxspeed 250 // max speed of The robot
#define rightbasespeed 200 // This is The speed at which The motors should spin when The robot is perfectly on The line
#define leftbasespeed 200 // This is The speed at which The motors should spin when The robot is perfectly on The line

int lastError=0,error=0,motorspeed=0,rightmotorspeed=0,leftmotorspeed=0;
int pth=0,th=0,C=0,W=0,J=0,R=0,S=0;
float Th=.5;
int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=90;
long sensors_average=0;
int sensors_sum=0;
int position;
long sensors[] = {0,0,0,0,0,0,0,0,0,0};



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



    if(rs1>th)
    {
    digitalWrite(rd1,HIGH);
    Rs1=1;
    
    }
    else
    {
    digitalWrite(rd1,LOW);
    Rs1=0;
    
    }
    if(rs2>th)
    {
    digitalWrite(rd2,HIGH);
    Rs2=1;
    
    }
    else
    {
    digitalWrite(rd2,LOW);
    Rs2=0;
   
    }
    if(rs3>th)
    {
    digitalWrite(rd3,HIGH);
    Rs3=1;
    
    }
    else
    {
    digitalWrite(rd3,LOW);
    Rs3=0;
    
    }
    if(rs4>th)
    {
    digitalWrite(rd4,HIGH);
    Rs4=1;
    
    }
    else
    {
    digitalWrite(rd4,LOW);
    Rs4=0;
    
    }
    if(rms>th)
    {
    digitalWrite(rmd,HIGH);
    Rms=1;
    
    }
    else
    {
    digitalWrite(rmd,LOW);
    Rms=0;
    
    }
    if(lms>th)
    {
    digitalWrite(lmd,HIGH);
    Lms=1;
    
    }
    else
    {
    digitalWrite(lmd,LOW);
    Lms=0;
   
    }
    if(ls1>th)
    {
    digitalWrite(ld1,HIGH);
    Ls1=1;
    
    }
    else
    {
    digitalWrite(ld1,LOW);
    Ls1=0;
    
    }
    if(ls2>th)
    {
    digitalWrite(ld2,HIGH);
    Ls2=1;
    
    }
    else
    {
    digitalWrite(ld2,LOW);
    Ls2=0;
    
    }
    if(ls3>th)
    {
    digitalWrite(ld3,HIGH);
    Ls3=1;
    
    }
    else
    {
    digitalWrite(ld3,LOW);
    Ls3=0;
    
    }
    if(ls4>th)
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
  int error = ((((Lms*10)+(Ls1*20)+(Ls2*30)+(Ls3*40))/(Lms+Ls1+Ls2+Ls3))-(((Rms*10)+(Rs1*20)+(Rs2*30)+(Rs3*40))/(Rms+Rs1+Rs2+Rs3)));

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




void RWforwardp()
{
   
 distanceRW();
    

position = int(distanceRw);

int error = 5-position ;

  int motorspeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightmotorspeed = rightbasespeed + motorspeed;
  int leftmotorspeed = leftbasespeed - motorspeed;
  
    if (rightmotorspeed > rightmaxspeed ) rightmotorspeed = rightmaxspeed; // prevent The motor from going beyond max speed
  if (leftmotorspeed > leftmaxspeed ) leftmotorspeed = leftmaxspeed; // prevent The motor from going beyond max speed
  if (rightmotorspeed < 0) rightmotorspeed = 0; // keep The motor speed positive
  if (leftmotorspeed < 0) leftmotorspeed = 0; // keep The motor speed positive


Serial.println(leftmotorspeed);


  
  
   {
   // move forward wiTh appropriate speeds
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(E1, rightmotorspeed);
  
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(E2, leftmotorspeed);
}
}

void LWforwardp()
{
   
 distanceLW();
    

position = int(distanceLw);

int error = 5-position ;

  int motorspeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightmotorspeed = rightbasespeed - motorspeed;
  int leftmotorspeed = leftbasespeed + motorspeed;
  
    if (rightmotorspeed > rightmaxspeed ) rightmotorspeed = rightmaxspeed; // prevent The motor from going beyond max speed
  if (leftmotorspeed > leftmaxspeed ) leftmotorspeed = leftmaxspeed; // prevent The motor from going beyond max speed
  if (rightmotorspeed < 0) rightmotorspeed = 0; // keep The motor speed positive
  if (leftmotorspeed < 0) leftmotorspeed = 0; // keep The motor speed positive


Serial.println(leftmotorspeed);


  
  
   {
   // move forward wiTh appropriate speeds
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  analogWrite(E1, rightmotorspeed);
  
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  analogWrite(E2, leftmotorspeed);
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
  analogWrite(E1,90);
  analogWrite(E2,90);
   
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
  analogWrite(E1,90);
  analogWrite(E2,90);
   
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,LOW);
  
}


void leftsharp()
{
  analogWrite(E1,90);
  analogWrite(E2,90);
   
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
  //delay(5);
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
// delay(5); 
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
  
if((Rs2>Th))
    {
      R=1;
      
    }
if((Ls2>Th))
    {
      S=1;
     
    }


if((R==1)&&(S==1)&&(Rs2<Th)&&(Rs3<Th)&&(Ls2<Th)&&(Ls3<Th))
    {
      R-=1;
      S-=1;
      C=1;
     break;
    }
    

   if((Rs2<Th)&&(Rs3<Th)&&(Rs4>Th)&&(S==0))
  {
    for(;;)
    {
      sensor();
      if(Rs4<Th)
      {
        break;
      }
      forward();
    }
   
    R-=1;
    count1+=1;
  stand();
  digitalWrite(red,HIGH);
  delay(50);
  
  
  
   break;
  } 

    if((Rs2<Th)&&(Rs3>Th)&&(S==0))
  {
    
   
    R-=1;
    
  stand();
  delay(50);
  
  
  
   break;
  } 
    


   if((Rs2<Th)&&(Rs3<Th)&&(Rs4<Th))
  {
    for(;;)
    {
      sensor();
      if((Lms<Th)&&(Rms<Th)&&(Ls2<Th))
      {
        
          break;
       
      }
      forward();
    }

   if(S==1)
   {
    S-=1;
   }
    R-=1;
    count4+=1;
  stand();
  digitalWrite(green,HIGH);
  delay(50);
  
 
  
   break;
  }

  
  forward();
  }

  
 if((C==0)&&(W==0)&&((Ls2<Th)&&(Ls3<Th)&&(Ls4<Th)))
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
  if((Rs2>Th))
    {
      R=1;
      
    }
if((Ls2>Th))
    {
      S=1;
     
    }

if((R==1)&&(S==1)&&(Rs2<Th)&&(Rs3<Th)&&(Ls2<Th)&&(Ls3<Th))
    {
      R-=1;
      S-=1;
      C=1;
     break;
    }
    

    if((Rms<Th)&&(Lms<Th)&&(Rs4<Th)&&(Ls2<Th))
       {
        R-=1;

       if(S==1)
       {
        S-=1;
       }
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
  
   
      if((Rs2<Th)&&(Ls2<Th)&&(Rs4<Th)&&(Ls4<Th))
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

  if((count3==10||count3==20||count3==30)&&(C==0)&&(W==0))
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
 
 
  

 if((count3==40||count3==50||count3==30||count3==0)&&(C==0)&&(W==0))
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

void leftsharpb90()
{
   for(;;)
  {
    sensor();

 if((Rs2>Th))
    {
      R=1;
      
    }
if((Ls2>Th))
    {
      S=1;
     
    }

if((R==1)&&(S==1)&&(Rs2<Th)&&(Rs3<Th)&&(Ls2<Th)&&(Ls3<Th))
    {
      R-=1;
      S-=1;
      C=1;
     break;
    }
    

   if((Ls2<Th)&&(Ls3<Th)&&(Ls4>Th)&&(R==0))
  {
    for(;;)
    {
      sensor();
      if(Ls4<Th)
      {
        break;
      }
      forward();
    }
   
    S-=1;
    count2+=1;
  stand();
  digitalWrite(red,HIGH);
  delay(50);
  
  
  
   break;
  } 

    if((Ls2<Th)&&(Ls3>Th)&&(R==0))
  {
    
   
    S-=1;
    
  stand();
  delay(50);
  
  
  
   break;
  }


   if((Ls2<Th)&&(Ls3<Th)&&(Ls4<Th))
  {
    for(;;)
    {
      sensor();
      if((Rms<Th)&&(Lms<Th)&&(Rs2<Th))
      {
        
          break;
       
      }
      forward();
    }
   if(R==1)
   {
    R-=1;
   }
    S-=1;
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

if((Rs2>Th))
    {
      R=1;
      
    }
if((Ls2>Th))
    {
      S=1;
     
    }

if((R==1)&&(S==1)&&(Rs2<Th)&&(Rs3<Th)&&(Ls2<Th)&&(Ls3<Th))
    {
      R-=1;
      S-=1;
      C=1;
     break;
    }
    

    if((Lms<Th)&&(Rms<Th)&&(Ls4<Th)&&(Rs2<Th))
       {
        S-=1;
        if(R==1)
        {
          R-=1;
        }
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
  distanceFW();
  if(distanceFw<12)
  {
    for(;;)
    {
      stand();
    delay(1000);
      distanceFW();
      
      if(distanceFw<10)
  {
    for(;;)
    {
      distanceFW();
      if(distanceFw>9)
      {
        stand();
        delay(1000);
        break;
      }
      
      backward();
    }
  }
    if(distanceFw>12)
    {
      break;
    }
    
    
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

   for(int p=0;p<1000;p++)
  {
    int val=0,mx=0,mn=0,v=0,mid=0;

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
  
 
th=mid+100;
  }
  digitalWrite(bz,LOW);
  digitalWrite(bz,HIGH);
  delay(1000);
  digitalWrite(bz,LOW);
 

}

void loop()
{ 
  digitalWrite(sw2,HIGH);
    
    
    if(digitalRead(sw2)==LOW)
    {
      
      delay(100);
  
  for(;;)
  {
    digitalWrite(sw1,HIGH);
    digitalWrite(sw2,HIGH);
    digitalWrite(bz,LOW);
    digitalWrite(buz,LOW);
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    if(digitalRead(sw1)==LOW)
    {
      count1+=1;
      digitalWrite(bz,HIGH);
      delay(30);
    }
      else
    {
    digitalWrite(bz,LOW);
    }
    if(digitalRead(sw2)==LOW)
    {
      count2+=1;
      digitalWrite(bz,HIGH);
      delay(30);
    }
     else
    {
   digitalWrite(bz,LOW);
    }
  sensor();

  //Black Line








if((C==0))
{

//obs();
  
  W=0;
if(((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1>Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1>Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms>Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th)))
  {
    
    forwardp();
  }

 if(((Rms<Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1>Th)&&(Ls2>Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3>Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2>Th)&&(Ls3>Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2>Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1>Th)&&(Ls2>Th)&&(Ls3<Th)))
   {
   
       leftsharpb2(); 
   }
   
  if(((Rms>Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1>Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms>Th)&&(Lms>Th)&&(Rs1>Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms>Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1>Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms>Th)&&(Lms<Th)&&(Rs1>Th)&&(Rs2<Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th)))  
   {
    
    forwardp();
   }

  if(((Rms>Th)&&(Lms<Th)&&(Rs1>Th)&&(Rs2>Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs3>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2>Th)&&(Rs3>Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2>Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th))||((Rms<Th)&&(Lms<Th)&&(Rs1>Th)&&(Rs2>Th)&&(Rs3<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls3<Th)))
{
  
  rightsharpb2();
}

}








//Black Line Gap
if(((Rms<Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2<Th)&&(Rs4<Th)&&(Ls1<Th)&&(Ls2<Th)&&(Ls4<Th))&&(C==0)&&(W==0))
  {
     
  rightsharpb90();
    
  }

//Black Line Crossover
 
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
    
//Black Line Right  60 45 30
  if(((Rms>Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2>Th)&&(Ls1<Th)&&(Ls2<Th))||((Rms<Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2>Th)&&(Ls1<Th)&&(Ls2<Th))||((Rms>Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2>Th)&&(Ls1<Th)&&(Ls2<Th))||((Rms>Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2>Th)&&(Ls1>Th)&&(Ls2<Th))||((Rms>Th)&&(Lms<Th)&&(Rs1<Th)&&(Rs2>Th)&&(Ls1>Th)&&(Ls2<Th))||((Rms<Th)&&(Lms>Th)&&(Rs1<Th)&&(Rs2>Th)&&(Ls1>Th)&&(Ls2<Th)))
  {
    
    rightsharpb45();
 }
 //Black Line Right 90 
if(((Rms>Th)&&(Lms>Th)&&(Rs1>Th)&&(Rs2>Th)&&(Ls1<Th)&&(Ls2<Th))||((Rms>Th)&&(Lms<Th)&&(Rs1>Th)&&(Rs2>Th)&&(Ls1<Th)&&(Ls2<Th))||((Rms>Th)&&(Lms>Th)&&(Rs1>Th)&&(Rs2>Th)&&(Ls1>Th)&&(Ls2<Th)))
{ 
  rightsharpb90();
    }
    

//Black Line Left  60 45 30 
  if(((Lms>Th)&&(Rms>Th)&&(Ls1<Th)&&(Ls2>Th)&&(Rs1<Th)&&(Rs2<Th))||((Lms<Th)&&(Rms>Th)&&(Ls1<Th)&&(Ls2>Th)&&(Rs1<Th)&&(Rs2<Th))||((Lms>Th)&&(Rms<Th)&&(Ls1<Th)&&(Ls2>Th)&&(Rs1<Th)&&(Rs2<Th))||((Lms>Th)&&(Rms>Th)&&(Ls1<Th)&&(Ls2>Th)&&(Rs1>Th)&&(Rs2<Th))||((Lms>Th)&&(Rms<Th)&&(Ls1<Th)&&(Ls2>Th)&&(Rs1>Th)&&(Rs2<Th))||((Lms<Th)&&(Rms>Th)&&(Ls1<Th)&&(Ls2>Th)&&(Rs1>Th)&&(Rs2<Th)))
  {
    
    leftsharpb45();
  }
  //Black Line Left 90
 if(((Lms>Th)&&(Rms>Th)&&(Ls1>Th)&&(Ls2>Th)&&(Rs1<Th)&&(Rs2<Th))||((Lms>Th)&&(Rms<Th)&&(Ls1>Th)&&(Ls2>Th)&&(Rs1<Th)&&(Rs2<Th))||((Lms>Th)&&(Rms>Th)&&(Ls1>Th)&&(Ls2>Th)&&(Rs1>Th)&&(Rs2<Th)))
{
  leftsharpb90();
}
}


//White Line







if(C==0)
{

//Extra
if(((Lms<Th)&&(Rms<Th)&&(Ls1>Th)&&(Ls2<Th)&&(Rs1>Th)&&(Rs2<Th))||((Lms<Th)&&(Rms<Th)&&(Ls1>Th)&&(Ls2>Th)&&(Rs1>Th)&&(Rs2<Th))||((Lms<Th)&&(Rms<Th)&&(Ls1>Th)&&(Ls2>Th)&&(Rs1>Th)&&(Rs2>Th))||((Lms<Th)&&(Rms<Th)&&(Ls1<Th)&&(Ls2>Th)&&(Rs1<Th)&&(Rs2>Th))||((Lms<Th)&&(Rms<Th)&&(Ls1>Th)&&(Ls2>Th)&&(Rs1<Th)&&(Rs2>Th)))
{
  YA();
}
   
 } 
}
}   

}

                            

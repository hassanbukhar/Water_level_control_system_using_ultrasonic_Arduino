int trigpin = 6;
int echopin = 5; 
float x1,x2,x3,x4,x5,x6 ;
float echotime ;
float Distance ;    // in meter
float velocity = 34000; //m/s; 
float height1 = 16;//in CM

#define led1 2
#define led2 3
#define led3 4
#define led4 7
#define led5 8


void setup() {

 pinMode(trigpin , OUTPUT);
 pinMode(echopin , INPUT);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 Serial.begin(9600); 
Serial.println(height1);

}


void loop() 
{
 digitalWrite(trigpin , LOW);
 delayMicroseconds(2000);
 digitalWrite( trigpin , HIGH);
 delayMicroseconds(10); 
 digitalWrite( trigpin , LOW);
 echotime = pulseIn ( echopin , HIGH);
 echotime = echotime/1000000 ;             // convert Microseconds into Seconds

 Distance = velocity * echotime ;
 Distance = (Distance /1.9);
 Serial.println(Distance); 

 //... led1
 if(Distance<15)
 {
digitalWrite(led1,HIGH);
}

 if(Distance>15)
 {
digitalWrite(led1,LOW);
}

//...led2
 if(Distance<13)
 {
digitalWrite(led2,HIGH);
}

 if(Distance>13)
 {
digitalWrite(led2,LOW);
}

//..led3
if(Distance<10)
 {
digitalWrite(led3,HIGH);
}

 if(Distance>10)
 {
digitalWrite(led3,LOW);
}
//...led4
if(Distance<8)
 {
digitalWrite(led4,HIGH);
}
 if(Distance>8)
 {
digitalWrite(led4,LOW);
}
//... led5

if(Distance<4)
 {
digitalWrite(led5,HIGH);
}
 if(Distance>4)
 {
digitalWrite(led5,LOW);
}




Serial.println(Distance);

delay(100);
}

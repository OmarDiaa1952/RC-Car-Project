//IChallenge Made by FaLCoNS_ASU
#include <Servo.h>
Servo myservo;
char Incoming_value = 0;  //Variable for storing Incoming_value
int pin1 = 7; //in 1      // ln1 and ln 2 control right side motors
int pin2 = 8; // in 2     // ln3 and ln 4 control right side motors
int pin3 = 9; // in 3
int pin4 = 10; // in 4
int ENA = 6; // EN1
int ENB = 11;//EN2
int x;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(12);
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  
  
  
 
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
    
    if(Incoming_value == 'w')            
    {
    move_forward();
    }
    if(Incoming_value == 'p')          
    {
    stop_car();
    }
    if(Incoming_value == 'd')            
    {
    turn_right();
    }
    if(Incoming_value == 'a')            
    {
    turn_left();
    }
    if(Incoming_value == 's')            
    {
    move_backward();
    }
    if(Incoming_value == 'b') // mid_speed           
    {
    mid_speed();
    }
    if(Incoming_value == 'z') // low_speed           
    {
    low_speed();
    }
    if(Incoming_value == 'c') // high_speed           
    {
    high_speed();
    }
    if(Incoming_value == 'g')          
    {
    stop_steering();
    }
    
    
}
}
void move_forward(){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
}

void stop_car(){
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  
  
}

void turn_right(){
    myservo.write(135);
}
void turn_left(){
    myservo.write(45);
}
void move_backward(){
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
}
void low_speed(){
  analogWrite(ENA,128);
  analogWrite(ENB,128);
}
void mid_speed(){
  analogWrite(ENA,170);
  analogWrite(ENB,170);
}
void high_speed(){
  analogWrite(ENA,255);
  analogWrite(ENB,255);
}
void stop_steering(){
  myservo.write(90);
}

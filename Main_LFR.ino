#include <Servo.h>  

Servo myServo;      
int fireSensor1 = 2; 
int fireSensor2 = 3; 
int fireSensor3 = 4; 
int pumpRelay = 7;   

void setup() {
  myServo.attach(9);           
  pinMode(fireSensor1, INPUT);  
  pinMode(fireSensor2, INPUT);  
  pinMode(fireSensor3, INPUT);  
  pinMode(pumpRelay, OUTPUT);   
  digitalWrite(pumpRelay, LOW); 
  myServo.write(90);           
  Serial.begin(9600);           
}

void loop() {
 
  int sensorValue1 = digitalRead(fireSensor1);
  int sensorValue2 = digitalRead(fireSensor2);
  int sensorValue3 = digitalRead(fireSensor3);

  
  Serial.print("Sensor 1: ");
  Serial.println(sensorValue1);
  Serial.print("Sensor 2: ");
  Serial.println(sensorValue2);
  Serial.print("Sensor 3: ");
  Serial.println(sensorValue3);

  if (sensorValue1 == HIGH) {
    
    myServo.write(90);           
    digitalWrite(pumpRelay, HIGH); 
  } 
  else if (sensorValue2 == HIGH) {
   
    myServo.write(0);            
    digitalWrite(pumpRelay, HIGH); 
  } 
  else if (sensorValue3 == HIGH) {
    
    myServo.write(180);           
    digitalWrite(pumpRelay, HIGH); 
  } 
  else {
    
    digitalWrite(pumpRelay, LOW);  
  }

  delay(100);  
}
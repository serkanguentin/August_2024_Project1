#define echoPin 12  
#define trigPin 13  

const int enA = 6; // Enable pin 1 (first Motor ) 
const int enB = 5; // Enable pin 2 (second Motor) 
const int in1 = 7; // for first motor
const int in2 = 4; // for first motor
const int in3 = 2; // for second motor 
const int in4 = 3; // for second motor
long time, distance;  
 
void setup() { 
  
    pinMode(echoPin, INPUT); 
    pinMode(trigPin, OUTPUT);  
    Serial.begin(115200); //serial monitor
     
 
    pinMode(enA, OUTPUT);    
    pinMode(in1, OUTPUT);    
    pinMode(in2, OUTPUT);     
   
    pinMode(enB, OUTPUT);    
    pinMode(in3, OUTPUT);    
    pinMode(in4,OUTPUT); 
} 
 
void loop() { 
   analogWrite(enA ,255); 
   analogWrite(enB ,255); 
 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  time = pulseIn(echoPin, HIGH); 
  distance = time / 29.1 / 2; 
  Serial.println("distance"); 
  Serial.println(distance); 
 
 
      if (distance < 35 && distance > 1)  
  { 
    back();   
    delay(2000); 
    right();   
    delay(1200); 
     
  } 
  else {   
    forward();  
  } 
} 
 
 
void forward(){ 
     
  digitalWrite (in4 , LOW ) ; 
  digitalWrite (in3,HIGH ) ;   
  digitalWrite(in1,HIGH);   
  digitalWrite(in2 ,LOW );  
  Serial.println("forward ") ;   
  
} 
 
void stop(){ 
     
  digitalWrite (in4,LOW );  
  digitalWrite (in3 , LOW );  
  digitalWrite(in1 ,LOW ); 
  digitalWrite(in2 ,LOW ); 
  Serial.println ("stop");  
 
} 
 
void back(){ 
  digitalWrite (in3 , LOW ) ; 
  digitalWrite (in4,HIGH ) ;   
  digitalWrite(in2,HIGH);   
  digitalWrite(in1 ,LOW );  
  Serial.println("back "); 
   
} 
 
void right(){ 
  digitalWrite (in4 , LOW ) ; 
  digitalWrite (in3,HIGH ) ;   
  digitalWrite(in2,HIGH);   
  digitalWrite(in1 ,LOW );    
  Serial.println(" right "); 
   
} 
void left(){ 
     
  digitalWrite (in3 , LOW ) ; 
  digitalWrite (in4,HIGH ) ;   
  digitalWrite(in1,HIGH);   
  digitalWrite(in2 ,LOW );    
  Serial.println(" left "); 
   
}
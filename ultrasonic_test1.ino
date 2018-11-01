#define LMP  2
#define LMN  3
#define RMP  4
#define RMN  5
#define ENA  6
#define ENB  9
#define trigPin 10
#define echoPin 11
int inByte = 0;            
boolean status_unlock;
boolean status_bluetooth;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LMP, OUTPUT);
  pinMode(LMN, OUTPUT);
  pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(LMP, LOW);  // switch off MOTOR
  digitalWrite(LMN, LOW);  // switch off MOTOR
  digitalWrite(RMP, LOW);  // switch off MOTOR
  digitalWrite(RMN, LOW);  // switch off MOTOR
    
 status_bluetooth = true;
  status_unlock = false;
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println(" cm");
  if (distance > 20) { 
     if (Serial.available() > 0)
  {   
       
    inByte = Serial.read();                      // get incoming byte:  
//     Serial.print(inByte); 
 if(inByte == 'A')
    {    
    
      analogWrite(ENA, 255);
    analogWrite(ENB, 255);
      digitalWrite(LMP, HIGH);         
      digitalWrite(LMN, LOW);
      digitalWrite(RMP, HIGH);
      digitalWrite(RMN, LOW);
            
      inByte = 0;     
    }    
   
    if(inByte == 'B')
    {   analogWrite(ENA, 255);
    analogWrite(ENB, 255); 
      digitalWrite(LMP, LOW);         
      digitalWrite(LMN, HIGH);
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, HIGH);
    
                      
      inByte = 0;     
    }
        
    if(inByte == 'D')
    {    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
       digitalWrite(LMP, HIGH);         
      digitalWrite(LMN, LOW);
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, LOW);
          
      inByte = 0;     
    }
    
   if(inByte == 'C')
    {   analogWrite(ENA, 255);
    analogWrite(ENB, 255); 
      digitalWrite(LMP, LOW);         
      digitalWrite(LMN, LOW);
      digitalWrite(RMP, HIGH);
      digitalWrite(RMN, LOW);
    
      //Serial.print('D', BYTE);                  
      inByte = 0;     
    }
       
    if(inByte == 'E')
    {   analogWrite(ENA, 255);
    analogWrite(ENB, 255); 
      digitalWrite(LMP, LOW);         
      digitalWrite(LMN, LOW);
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, LOW);
    
     
      //Serial.print('E', BYTE);                   
      inByte = 0;     
    }
    
  if(inByte == 'G')
    {   analogWrite(ENA, 255);
    analogWrite(ENB, 255); 
     digitalWrite(LMP, HIGH);         
      digitalWrite(LMN, LOW);
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, HIGH);
        
      inByte = 0;     
    }
    
    if(inByte == 'F'){  
      analogWrite(ENA, 255);
    analogWrite(ENB, 255);  
       digitalWrite(LMP, LOW);         
      digitalWrite(LMN, HIGH);
      digitalWrite(RMP, HIGH);
      digitalWrite(RMN, LOW);
     
      
     // Serial.print('G', BYTE);  
      inByte = 0;     
    }
    
  }
  }
  else {
   
    digitalWrite(LMP, LOW);         
      digitalWrite(LMN, LOW);
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, LOW);
  }
  delay(500);
}

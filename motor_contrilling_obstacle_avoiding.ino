int enable=2;
int input1=18;
int input2=19;
int trigpin=23;
int echopin=22;
 long duration;
 long distance;
 
void setup() {
pinMode(enable,OUTPUT);
pinMode(input1,OUTPUT);
pinMode(input2,OUTPUT);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
Serial.begin(9600);
  
}
void loop() {

  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
    digitalWrite(trigpin,LOW);

  duration=pulseIn(echopin,HIGH);
  distance=duration *0.0342 /2;
  Serial.println(distance);

  
  if(distance>10){
      
digitalWrite(input1,HIGH);
digitalWrite(input2,LOW);
analogWrite(enable,250);

    }
    else{
digitalWrite(input1,LOW);
digitalWrite(input2,LOW);
analogWrite(enable,0);

      }
}

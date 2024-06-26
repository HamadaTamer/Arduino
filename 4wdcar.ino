// hardware used:
/*
  arduino uno 
  car chassis
  1 H-bridge
  4 dc motors 
  4 wheels
  ultrasonic sensor

*/
//Hbridge connections 
int ena1=5; //controls speed by having a number between 1 and 255

int in1=6;   // controls direction by having one on and one off
int in2=7;

int ena2=10; // same as above but for the other set 
int in3=11;
int in4=12;

int trigpin=3; //ultrasonic pins 
int echopin=2;
int distance;

void setup()
{
	pinMode(ena1, OUTPUT);
	pinMode(in1, OUTPUT);
 	pinMode(in2, OUTPUT);
  	
  pinMode(ena2, OUTPUT);
	pinMode(in3, OUTPUT);
 	pinMode(in4, OUTPUT);

  pinMode(trigpin,OUTPUT);
  pinMode(echopin, INPUT);

  Serial.begin(9600);  // used to watch the distance calculated by the ultrasonic
}
void ultrasonic(){ 
  float duration=0;
  	//sending out an ultrasonic wave
	digitalWrite(trigpin, LOW);
  	delayMicroseconds(2);
  	digitalWrite(trigpin, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(trigpin, LOW);
  	
  	//recieving it
  	duration= pulseIn(echopin, HIGH);
  	distance=(0.0343*duration)/2; 
      //s=d/t
      //d=s*t
}

void forward(int num){    //move forward and num controls speed and to be a number : 0-255
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena1,255);
  
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(ena2,num);
  	
}
void backward(int num){   //move backward and num controls speed and to be a number : 0-255
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(ena1,num);
  
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(ena2,255);
}
void stop(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  
}
void rotateclockwise(){ //spins in place 
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  analogWrite(ena1,255);
  
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(ena2,255); //2 seconds at full speed is 360° /2π
}
void rotateright(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena1,255);
  
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
  analogWrite(ena2,127);
}
void turn45degclockwise(){  // turns 45 degrees since time is 1/4 second
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  analogWrite(ena1,255);
  
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(ena2,255);
  delay(250);
  stop();
}
void turn45deganticlockwise(){ 
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena1,255);
  
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(ena2,255);
  delay(250);
  stop();
}



void loop(){
  ultrasonic(); //// constantly calculates and updates the distance variable

  if (distance>50){  
    backward(255);  // was backward as the ultrasonic sensor was installed on the back
  }
  else {
    stop();
    turn45degclockwise();
    delay(1000);
  }
  Serial.println(distance);
  
}
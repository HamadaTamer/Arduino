
//mode 1: 3 leds flashing differently according to the distance.
//mode 2: rgb LED changing colour differently according to the distance 
const int trigpin = 13;
const int echopin= 12;

const int led1= 11;
const int led2= 10;
const int led3=9;

const int loneled= 6;

const int pb= 8;

/*const int red= 5;
const int blue = 4;
const int green= 3;*/

double duration;
double distance;

boolean prevstate= LOW;
int counter;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  pinMode(pb, INPUT);
  
  /*pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);*/
  pinMode(loneled, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  
  Serial.begin(9600);
  
}

void loop()
{
  int val = digitalRead(pb);   // read the input pin
  if (val==HIGH){
  	
    delay(80);
  	val=digitalRead(pb);
    if (val==HIGH)
      counter++;
  }
  switch(counter%2){
    case 1: digitalWrite(loneled, HIGH);
    delay(1000);
    digitalWrite(loneled, LOW);
    		break;
    case 0:
    		ultrasonic();
  			double period= map(distance,0,300,1,20);
  			blink(period);
  }
  Serial.println(counter);
}


void ultrasonic(){
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
void blink(double period){
	period*=30;
  digitalWrite(led3, HIGH);
  delay(period);
  digitalWrite(led3, LOW);
  
  digitalWrite(led2, HIGH);
  delay(period);
  digitalWrite(led2, LOW);
  
  digitalWrite(led1, HIGH);
  delay(period);
  digitalWrite(led1, LOW);
}
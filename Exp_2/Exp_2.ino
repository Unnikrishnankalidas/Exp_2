
 
int ledPin1 = 2;
int ledPin2 = 3;
int ledPin3 = 5;

int sensor1Pin = A2;
int sensor1Val;

boolean ledState1 = false;
boolean ledState2 = false;
boolean ledState3 = false;

//Blink State
long lastTimeYouBlinked;
long lastTimeYouBlinked2;
long lastTimeYouBlinked3;

int blinkRate1 = 1000;
int blinkRate2 =1000;
int blinkRate3 =1000;  


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor1Val = analogRead(sensor1Pin);

   Serial.print("light1: ");
  Serial.println(sensor1Val);

blinkRate1 = map(sensor1Val,0,1023,500,100); //mapping the sensor values to speed of the light
blinkRate2 = map(sensor1Val,0,600,100,500);
blinkRate3 = map(sensor1Val,0,300,100,500);


//Red Light

if(millis()-lastTimeYouBlinked>=blinkRate1) //this very simple statement is the timer,
{                               
  if(ledState1==true)  {                   
      if(sensor1Val >600 && sensor1Val <=1023) {                     
     digitalWrite(ledPin1,ledState1);          
     ledState1=false;                         
     
    }
    }
  else                                   
  {
    digitalWrite(ledPin1, ledState1);           
    ledState1=true;                     
  }
  lastTimeYouBlinked = millis();
}


//Yellow Light
if(millis()-lastTimeYouBlinked2>=blinkRate2) {
      if(ledState2 == true){
        if(sensor1Val >300 && sensor1Val <=600) {
            digitalWrite(ledPin2,ledState2);
            ledState2 = false;
        }
      } 
    else {
      digitalWrite(ledPin2,ledState2);
      ledState2 = true;
    }
    lastTimeYouBlinked2 = millis();
}
  
      //Control the Blue Light
      if(millis()-lastTimeYouBlinked3>=blinkRate3) {
      if(ledState3 == true){
        if(sensor1Val >0 && sensor1Val <=300) {
            digitalWrite(ledPin3,ledState3);
            ledState3 = false;
        }
      } 
    else {
      digitalWrite(ledPin3,ledState3);
      ledState3 = true;
    }
    
lastTimeYouBlinked3 = millis();
  }

}   

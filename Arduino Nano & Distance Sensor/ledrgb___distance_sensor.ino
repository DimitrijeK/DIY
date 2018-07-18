
//Libraries
#include "Arduino.h"
#include <NewPing.h>

//Pin definitions
#define HCSR04_PIN_ECHO 2
#define HCSR04_PIN_TRIG 4

//#define COMMON_ANODE ---> Uncomment this if you have common anode led

//Initializing sensor pins with NewPing library
NewPing hcsr04(HCSR04_PIN_TRIG,HCSR04_PIN_ECHO);

int bluePin = 3;
int greenPin = 5;
int redPin = 6;

void setup() {
  
  Serial.begin(9600);
  while (!Serial) ; //wait for serial port to connect
  Serial.println("start");

  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  
  int hcsr04Dist = hcsr04.ping_cm();
  
  Serial.print(F("Distance: ")); 
  Serial.print(hcsr04Dist); 
  Serial.println(F("[cm]"));
    
  if(hcsr04Dist <= 10)
  {
    //red
    setColor(255,0,0);
  }

  else if(hcsr04Dist > 10 && hcsr04Dist <= 20)
  {
    //orange
    setColor(255,140,0);
  }

  else if(hcsr04Dist > 20)
  {
    //green
    setColor(0,255,0);
  }
  
}

void setColor(int red, int green, int blue) {
  
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

}



#include <ParsingLibrary.h>

#include <Adafruit_PWMServoDriver.h>

#include <Wire.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

ParsingLibrary parse;

int paramList[200];
byte data[2];

#define SERVOMIN  200 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  500 // this is the 'maximum' pulse length count (out of 4096)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  yield();
}

void loop() {
  // put your main code here, to run repeatedly:

  parse.ParseCode();

  parse.getParameters(&paramList[0]);
////
  for(int i = 0; i < sizeof(paramList); i++){
    Serial.print(paramList[i]);
    Serial.print(" ");
  }

    delay(500);

    pwm.setPWM(paramList[0], 0, paramList[1]);

    delay(500);

 }

  

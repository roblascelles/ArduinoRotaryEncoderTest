#include <Arduino.h>
#include <RotaryControl.h>

int encoderSW = 6;
int encoderDT = 7;
int encoderCLK = 8;

void encoderTurned(int pos);

RotaryControl rotary(encoderCLK, encoderDT, encoderSW, &encoderTurned);

void setup()
{
  Serial.begin(9600);

  while (!Serial)
  {
    ;
  }

  Serial.println("Start setup");

  Serial.println("End setup");
}


void loop()
{
  delay(1);
}

void encoderTurned(int pos) {
    Serial.println(pos);
}
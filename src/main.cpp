#include <Arduino.h>
#include <RotaryControl.h>

int encoderSW = 6;
int encoderDT = 7;
int encoderCLK = 8;

void encoderTurned(int pos);
void encoderPressed(ClickType clickType);

int pos = 0;

RotaryControl rotary(encoderCLK, encoderDT, encoderSW, &encoderTurned, &encoderPressed);


void setup()
{
  Serial.begin(9600);

  while (!Serial)
  {
    ;
  }

  Serial.println("Start setup");

  RotaryControl::init();

  Serial.println("End setup");
}

void loop()
{
  delay(1);
}

void encoderTurned(int diff) {
  pos += diff;
  Serial.print("Turned ");
  Serial.println(pos);
}

void encoderPressed(ClickType pressType) {
  Serial.print("Pressed ");
  Serial.println(pressType);
}
#ifndef RotaryControl_H
#define RotaryControl_H

#include <Arduino.h>

typedef void (*turnedCallback)(int pos);

class RotaryControl
{
private:
  int _clkPin;
  int _dtPin;
  int _swPin;

  turnedCallback _turnedCallback; 

  int _lastState = 0;
  int _pos = 0;

  int _clk = 0;
  int _cclk = 0;

  static void update();
  int read();

public:
  RotaryControl(int clk, int dt, int sw, turnedCallback turnedCallback);
};

#endif
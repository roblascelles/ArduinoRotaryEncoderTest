#include "RotaryControl.h"

static RotaryControl* controls[5];
static int controlCnt = 0;

RotaryControl::RotaryControl(int clk, int dt, int sw, turnedCallback turnedCallback)
{
    _clkPin = clk;
    _dtPin = dt;
    _swPin = sw;

    _turnedCallback = turnedCallback;

    pinMode(clk, INPUT);
    attachInterrupt(digitalPinToInterrupt(clk), RotaryControl::update, CHANGE);

    pinMode(dt, INPUT);
    attachInterrupt(digitalPinToInterrupt(dt), RotaryControl::update, CHANGE);

    controls[controlCnt++] = this;
}

void RotaryControl::update()
{
    for (int i = 0; i < controlCnt; i++)
    {
      controls[i]->read();
    }
}

int RotaryControl::read()
{
    int state = digitalRead(_clkPin) * 2 + digitalRead(_dtPin);

    if ((state == 1 && _lastState == 3) ||
        (state == 0 && _lastState == 1) ||
        (state == 2 && _lastState == 0) ||
        (state == 3 && _lastState == 2))
    {
        _clk++;
    }
    else if ((state == 2 && _lastState == 3) ||
             (state == 0 && _lastState == 2) ||
             (state == 1 && _lastState == 0) ||
             (state == 3 && _lastState == 1))
    {
        _cclk++;
    }

    _lastState = state;

    if (state == 3)
    {
        if (_clk > _cclk)
        {
            _pos++;
            _turnedCallback(_pos);
        }
        else if (_clk < _cclk)
        {
            _pos--;
            _turnedCallback(_pos);
        }

        _clk = _cclk = 0;
    }

    return _pos;
}

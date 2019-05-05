// CalibratedSpeed.cpp
/*
Arduino Library for calibrating DC motors
    Copyright (C) 2019 Gheorghe Nedelcu <nedghe@gmail.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
    USA
*/
#include "CalibratedSpeed.h"

#include <Arduino.h>

CalibratedSpeed::CalibratedSpeed(int outMin, int outMax)
{
    _inMin = 0;
    _inMax = 255;
    _outMin = outMin;
    _outMax = outMax;
}

CalibratedSpeed::CalibratedSpeed(int inMin, int inMax, int outMin, int outMax)
{
    _inMin = inMin;
    _inMax = inMax;
    _outMin = outMin;
    _outMax = outMax;
}

CalibratedSpeed::~CalibratedSpeed(){}

int CalibratedSpeed::getSpeed(int rowSpeed)
{
  if (rowSpeed > 0) return map(rowSpeed, _inMin, _inMax, _outMin, _outMax);
  else if (rowSpeed < 0) return map(rowSpeed, -1*_inMin, -1*_inMax, -1*_outMin, -1*_outMax);
  else return 0;
}

void CalibratedSpeed::calibrate(int inMin, int inMax, int outMin, int outMax)
{
    _inMin = inMin;
    _inMax = inMax;
    _outMin = outMin;
    _outMax = outMax;
}
// CalibratedSpeed.h
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
#ifndef CalibratedSpeed_h
#define CalibratedSpeed_h

#include <stdint.h>

class CalibratedSpeed
{
    public:
        CalibratedSpeed(int outMin, int outMax);
        ~CalibratedSpeed();
        int getSpeed(int rowSpeed);
        void calibrate(int inMin, int inMax, int outMin, int outMax);
    private:
        int _inMin;
        int _inMax;
        int _outMin;
        int _outMax;
};

#endif
# CalibratedSpeed
Arduino Library for calibrating DC motors - greatly reduces the left/right motor speed unbalance and removes start/stop threshold.

## About
When dealing with DC Motors controls, as in the ubiquitous robot car with dual dc motor (and not only), you will soon discover how unbalanced identical motors are. This can be easily observed by running motors at the same direction and speed. If the car trajectory is straight, you can consider yourself very lucky and probably don't need anything of this.
This library is fairly simple, and can also serve as library example, if you ever intended to build one of your own. It basically rescale the speed values sent to a PWM output pin (0 to 255) to a new interval of values (e.g. 25 to 250), corresponding to a desired minimum and maximum.

## Determining the min and max values
Determining the minimum and maximum values for your motors are not subject of this library or the example herein, but you can use the following tips:
* for each motor determine the minimum speed required to start spinning
* make sure the value is large enough to start it every time and in both direction
* run the car (forward and reverse) at minimum speed and adjust the values if necessary aiming for a straight trajectory
* note down this minimum values for each motor
* run the car (forward and reverse) at maximum speed supported by your driver (usually 255 or the maximum you choose).
* lower the max left value if your car goes right and right value if the car goes left, aiming again for a straight line
* note down this maximum values for each motor

## Use CalibratedSpeed Library
### Importing the library
Follow **[Installing an Arduino Library Guide](https://www.arduino.cc/en/guide/libraries)**

### Include the library in your sketch
```c++
#include <CalibratedSpeed.h>
```

### Instantiate CalibratedSpeed objects
```c++
#define LeftMinSpeed 24
#define RightMinSpeed 24
#define LeftMaxSpeed 246
#define RightMaxSpeed 255

// creates two objects for calibrating left and right motor speed
CalibratedSpeed csl = CalibratedSpeed(LeftMinSpeed, LeftMaxSpeed);
CalibratedSpeed csr = CalibratedSpeed(RightMinSpeed, RightMaxSpeed);
```

### Use getSpeed() method
If the code for setting the motor speed are looking like this,
```c++
digitalWrite(LEFT_PWM_PIN, speed);
digitalWrite(RIGHT_PWM_PIN, speed)

```
use getSpeed() method to use the calibrated speed.
```c++
digitalWrite(LEFT_PWM_PIN, csl.getSpeed(speed));
digitalWrite(RIGHT_PWM_PIN, csr.getSpeed(speed));

```

## Note

The getSpeed method accepts and returs negative values to acomodate all kind of dc motor drivers and it uses the positive calibration values mirrored in the negative domain.

## Advanced usage
If the input domain differ from the standard 0..255, the overridden constructer can be used:
```c++
#define InMin 1023
#define InMax 1
#define OutMin 24
#define Out max 246

// creates calibrating object
CalibratedSpeed cs = CalibratedSpeed(IN_MIN, IN_MAX, OUT_MIN, OUT_MAX);
```
Regardless of the constructor chosen initially for the CalibratedSpeed object, you can always use calibrate() method to change the object settings during runtime.
```c++
cs.calibrate(10, 1000, 25, 250);

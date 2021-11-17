---
title: FlexyStepper


---

# FlexyStepper






`#include <FlexyStepper.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[FlexyStepper](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-flexystepper)**() <br>constructor for the stepper class  |
| void | **[connectToPins](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-connecttopins)**(byte stepPinNumber, byte directionPinNumber) <br>connect the stepper object to the IO pins  |
| void | **[setStepsPerMillimeter](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setstepspermillimeter)**(float motorStepPerMillimeter) <br>set the number of steps the motor has per millimeters  |
| float | **[getCurrentPositionInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-getcurrentpositioninmillimeters)**() <br>get the current position of the motor in millimeters, this functions is updated while the motor moves  |
| void | **[setCurrentPositionInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setcurrentpositioninmillimeters)**(float currentPositionInMillimeters) <br>set the current position of the motor in millimeters, this does not move the motor  |
| void | **[setSpeedInMillimetersPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setspeedinmillimeterspersecond)**(float speedInMillimetersPerSecond) <br>set the maximum speed, units in millimeters/second, this is the maximum speed reached while accelerating  |
| void | **[setAccelerationInMillimetersPerSecondPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setaccelerationinmillimeterspersecondpersecond)**(float accelerationInMillimetersPerSecondPerSecond) <br>set the rate of acceleration, units in millimeters/second/second  |
| bool | **[moveToHomeInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-movetohomeinmillimeters)**(long directionTowardHome, float speedInMillimetersPerSecond, long maxDistanceToMoveInMillimeters, int homeLimitSwitchPin) <br>home the motor by moving until the homing sensor is activated, then set the position to zero, with units in millimeters  |
| void | **[moveRelativeInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-moverelativeinmillimeters)**(float distanceToMoveInMillimeters) <br>move relative to the current position, units are in millimeters, this function does not return until the move is complete  |
| void | **[setTargetPositionRelativeInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositionrelativeinmillimeters)**(float distanceToMoveInMillimeters) <br>setup a move relative to the current position, units are in millimeters, no motion occurs until processMove() is called  |
| void | **[moveToPositionInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-movetopositioninmillimeters)**(float absolutePositionToMoveToInMillimeters) <br>move to the given absolute position, units are in millimeters, this function does not return until the move is complete  |
| void | **[setTargetPositionInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositioninmillimeters)**(float absolutePositionToMoveToInMillimeters) <br>setup a move, units are in millimeters, no motion occurs until processMove() is called  |
| float | **[getCurrentVelocityInMillimetersPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-getcurrentvelocityinmillimeterspersecond)**() <br>Get the current velocity of the motor in millimeters/second.  |
| void | **[setStepsPerRevolution](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setstepsperrevolution)**(float motorStepPerRevolution) <br>set the number of steps the motor has per revolution  |
| void | **[setCurrentPositionInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setcurrentpositioninrevolutions)**(float currentPositionInRevolutions) <br>set the current position of the motor in revolutions, this does not move the motor  |
| float | **[getCurrentPositionInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-getcurrentpositioninrevolutions)**() <br>get the current position of the motor in revolutions, this functions is updated while the motor moves  |
| void | **[setSpeedInRevolutionsPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setspeedinrevolutionspersecond)**(float speedInRevolutionsPerSecond) <br>set the maximum speed, units in revolutions/second, this is the maximum speed reached while accelerating  |
| void | **[setAccelerationInRevolutionsPerSecondPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setaccelerationinrevolutionspersecondpersecond)**(float accelerationInRevolutionsPerSecondPerSecond) <br>set the rate of acceleration, units in revolutions/second/second  |
| bool | **[moveToHomeInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-movetohomeinrevolutions)**(long directionTowardHome, float speedInRevolutionsPerSecond, long maxDistanceToMoveInRevolutions, int homeLimitSwitchPin) <br>home the motor by moving until the homing sensor is activated, then set the position to zero, with units in revolutions  |
| void | **[moveRelativeInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-moverelativeinrevolutions)**(float distanceToMoveInRevolutions) <br>move relative to the current position, units are in revolutions, this function does not return until the move is complete  |
| void | **[setTargetPositionRelativeInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositionrelativeinrevolutions)**(float distanceToMoveInRevolutions) <br>setup a move relative to the current position, units are in revolutions, no motion occurs until processMove() is called  |
| void | **[moveToPositionInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-movetopositioninrevolutions)**(float absolutePositionToMoveToInRevolutions) <br>move to the given absolute position, units are in revolutions, this function does not return until the move is complete  |
| void | **[setTargetPositionInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositioninrevolutions)**(float absolutePositionToMoveToInRevolutions) <br>setup a move, units are in revolutions, no motion occurs until processMove() is called  |
| float | **[getCurrentVelocityInRevolutionsPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-getcurrentvelocityinrevolutionspersecond)**() <br>Get the current velocity of the motor in revolutions/second.  |
| void | **[setCurrentPositionInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setcurrentpositioninsteps)**(long currentPositionInSteps) <br>set the current position of the motor in steps, this does not move the motor  |
| long | **[getCurrentPositionInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-getcurrentpositioninsteps)**() <br>get the current position of the motor in steps, this functions is updated while the motor moves  |
| void | **[setSpeedInStepsPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setspeedinstepspersecond)**(float speedInStepsPerSecond) <br>set the maximum speed, units in steps/second, this is the maximum speed reached while accelerating  |
| void | **[setAccelerationInStepsPerSecondPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setaccelerationinstepspersecondpersecond)**(float accelerationInStepsPerSecondPerSecond) <br>set the rate of acceleration, units in steps/second/second  |
| bool | **[moveToHomeInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-movetohomeinsteps)**(long directionTowardHome, float speedInStepsPerSecond, long maxDistanceToMoveInSteps, int homeSwitchPin) <br>home the motor by moving until the homing sensor is activated, then set the position to zero with units in steps  |
| void | **[moveRelativeInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-moverelativeinsteps)**(long distanceToMoveInSteps) <br>move relative to the current position, units are in steps, this function does not return until the move is complete  |
| void | **[setTargetPositionRelativeInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositionrelativeinsteps)**(long distanceToMoveInSteps) <br>setup a move relative to the current position, units are in steps, no motion occurs until processMove() is called  |
| void | **[moveToPositionInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-movetopositioninsteps)**(long absolutePositionToMoveToInSteps) <br>move to the given absolute position, units are in steps, this function does not return until the move is complete  |
| void | **[setTargetPositionInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositioninsteps)**(long absolutePositionToMoveToInSteps) <br>setup a move, units are in steps, no motion occurs until processMove() is called  |
| void | **[setTargetPositionToStop](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositiontostop)**() <br>setup a "Stop" to begin the process of decelerating from the current velocity to zero, decelerating requires calls to processMove() until the move is complete  |
| bool | **[motionComplete](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-motioncomplete)**() <br>check if the motor has competed its move to the target position  |
| float | **[getCurrentVelocityInStepsPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-getcurrentvelocityinstepspersecond)**() <br>Get the current velocity of the motor in steps/second.  |
| bool | **[processMovement](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-processmovement)**(void ) <br>if it is time, move one step  |





















## Public Functions Documentation

### function FlexyStepper

```cpp
FlexyStepper()
```

constructor for the stepper class 




























### function connectToPins

```cpp
void connectToPins(
    byte stepPinNumber,
    byte directionPinNumber
)
```

connect the stepper object to the IO pins 

**Parameters**: 

  * **stepPinNumber** IO pin number for the Step 
  * **directionPinNumber** IO pin number for the direction bit 
  * **enablePinNumber** IO pin number for the enable bit (LOW is enabled). set to 0 if enable is not supported 




























### function setStepsPerMillimeter

```cpp
void setStepsPerMillimeter(
    float motorStepPerMillimeter
)
```

set the number of steps the motor has per millimeters 




























### function getCurrentPositionInMillimeters

```cpp
float getCurrentPositionInMillimeters()
```

get the current position of the motor in millimeters, this functions is updated while the motor moves 







**Return**: a signed motor position in millimeters returned 





















### function setCurrentPositionInMillimeters

```cpp
void setCurrentPositionInMillimeters(
    float currentPositionInMillimeters
)
```

set the current position of the motor in millimeters, this does not move the motor 




























### function setSpeedInMillimetersPerSecond

```cpp
void setSpeedInMillimetersPerSecond(
    float speedInMillimetersPerSecond
)
```

set the maximum speed, units in millimeters/second, this is the maximum speed reached while accelerating 

**Parameters**: 

  * **speedInMillimetersPerSecond** speed to accelerate up to, units in millimeters/second 




























### function setAccelerationInMillimetersPerSecondPerSecond

```cpp
void setAccelerationInMillimetersPerSecondPerSecond(
    float accelerationInMillimetersPerSecondPerSecond
)
```

set the rate of acceleration, units in millimeters/second/second 

**Parameters**: 

  * **accelerationInMillimetersPerSecondPerSecond** accelerationInMillimetersPerSecondPerSecond = rate of acceleration, units in millimeters/second/second 




























### function moveToHomeInMillimeters

```cpp
bool moveToHomeInMillimeters(
    long directionTowardHome,
    float speedInMillimetersPerSecond,
    long maxDistanceToMoveInMillimeters,
    int homeLimitSwitchPin
)
```

home the motor by moving until the homing sensor is activated, then set the position to zero, with units in millimeters 

**Parameters**: 

  * **directionTowardHome** 1 to move in a positive direction, -1 to move in a negative directions 
  * **speedInMillimetersPerSecond** speed to accelerate up to while moving toward home, units in millimeters/second 
  * **maxDistanceToMoveInMillimeters** unsigned maximum distance to move toward home before giving up 
  * **homeLimitSwitchPin** pin number of the home switch, switch should be configured to go low when at home 







**Return**: true returned if successful, else false 





















### function moveRelativeInMillimeters

```cpp
void moveRelativeInMillimeters(
    float distanceToMoveInMillimeters
)
```

move relative to the current position, units are in millimeters, this function does not return until the move is complete 

**Parameters**: 

  * **distanceToMoveInMillimeters** signed distance to move relative to the current position in millimeters 




























### function setTargetPositionRelativeInMillimeters

```cpp
void setTargetPositionRelativeInMillimeters(
    float distanceToMoveInMillimeters
)
```

setup a move relative to the current position, units are in millimeters, no motion occurs until processMove() is called 

**Parameters**: 

  * **distanceToMoveInMillimeters** signed distance to move relative to the current position in millimeters 




























### function moveToPositionInMillimeters

```cpp
void moveToPositionInMillimeters(
    float absolutePositionToMoveToInMillimeters
)
```

move to the given absolute position, units are in millimeters, this function does not return until the move is complete 

**Parameters**: 

  * **absolutePositionToMoveToInMillimeters** signed absolute position to move to in units of millimeters 




























### function setTargetPositionInMillimeters

```cpp
void setTargetPositionInMillimeters(
    float absolutePositionToMoveToInMillimeters
)
```

setup a move, units are in millimeters, no motion occurs until processMove() is called 

**Parameters**: 

  * **absolutePositionToMoveToInMillimeters** signed absolute position to move to in units of millimeters 




























### function getCurrentVelocityInMillimetersPerSecond

```cpp
float getCurrentVelocityInMillimetersPerSecond()
```

Get the current velocity of the motor in millimeters/second. 







**Return**: float velocity speed in steps per second returned, signed 



















This functions is updated while it accelerates up and down in speed. This is not the desired speed, but the speed the motor should be moving at the time the function is called. This is a signed value and is negative when the motor is moving backwards. Note: This speed will be incorrect if the desired velocity is set faster than this library can generate steps, or if the load on the motor is too great for the amount of torque that it can generate.


### function setStepsPerRevolution

```cpp
void setStepsPerRevolution(
    float motorStepPerRevolution
)
```

set the number of steps the motor has per revolution 

**Parameters**: 

  * **motorStepPerRevolution** 




























### function setCurrentPositionInRevolutions

```cpp
void setCurrentPositionInRevolutions(
    float currentPositionInRevolutions
)
```

set the current position of the motor in revolutions, this does not move the motor 




























### function getCurrentPositionInRevolutions

```cpp
float getCurrentPositionInRevolutions()
```

get the current position of the motor in revolutions, this functions is updated while the motor moves 

**Parameters**: 

  * **currentPositionInRevolutions** a signed motor position in revolutions returned 




























### function setSpeedInRevolutionsPerSecond

```cpp
void setSpeedInRevolutionsPerSecond(
    float speedInRevolutionsPerSecond
)
```

set the maximum speed, units in revolutions/second, this is the maximum speed reached while accelerating 

**Parameters**: 

  * **speedInRevolutionsPerSecond** speed to accelerate up to, units in revolutions/second 




























### function setAccelerationInRevolutionsPerSecondPerSecond

```cpp
void setAccelerationInRevolutionsPerSecondPerSecond(
    float accelerationInRevolutionsPerSecondPerSecond
)
```

set the rate of acceleration, units in revolutions/second/second 

**Parameters**: 

  * **accelerationInRevolutionsPerSecondPerSecond** rate of acceleration, units in revolutions/second/second 




























### function moveToHomeInRevolutions

```cpp
bool moveToHomeInRevolutions(
    long directionTowardHome,
    float speedInRevolutionsPerSecond,
    long maxDistanceToMoveInRevolutions,
    int homeLimitSwitchPin
)
```

home the motor by moving until the homing sensor is activated, then set the position to zero, with units in revolutions 

**Parameters**: 

  * **directionTowardHome** 1 to move in a positive direction, -1 to move in a negative directions 
  * **speedInRevolutionsPerSecond** speed to accelerate up to while moving toward home, units in revolutions/second 
  * **maxDistanceToMoveInRevolutions** unsigned maximum distance to move toward home before giving up 
  * **homeLimitSwitchPin** pin number of the home switch, switch should be configured to go low when at home 







**Return**: true returned if successful, else false 





















### function moveRelativeInRevolutions

```cpp
void moveRelativeInRevolutions(
    float distanceToMoveInRevolutions
)
```

move relative to the current position, units are in revolutions, this function does not return until the move is complete 

**Parameters**: 

  * **distanceToMoveInRevolutions** signed distance to move relative to the current position in revolutions 




























### function setTargetPositionRelativeInRevolutions

```cpp
void setTargetPositionRelativeInRevolutions(
    float distanceToMoveInRevolutions
)
```

setup a move relative to the current position, units are in revolutions, no motion occurs until processMove() is called 

**Parameters**: 

  * **distanceToMoveInRevolutions** signed distance to move relative to the currentposition in revolutions 




























### function moveToPositionInRevolutions

```cpp
void moveToPositionInRevolutions(
    float absolutePositionToMoveToInRevolutions
)
```

move to the given absolute position, units are in revolutions, this function does not return until the move is complete 

**Parameters**: 

  * **absolutePositionToMoveToInRevolutions** signed absolute position to move to in units of revolutions 




























### function setTargetPositionInRevolutions

```cpp
void setTargetPositionInRevolutions(
    float absolutePositionToMoveToInRevolutions
)
```

setup a move, units are in revolutions, no motion occurs until processMove() is called 

**Parameters**: 

  * **absolutePositionToMoveToInRevolutions** signed absolute position to move to in units of revolutions 




























### function getCurrentVelocityInRevolutionsPerSecond

```cpp
float getCurrentVelocityInRevolutionsPerSecond()
```

Get the current velocity of the motor in revolutions/second. 







**Return**: velocity speed in steps per second returned, signed 



















This functions is updated while it accelerates up and down in speed. This is not the desired speed, but the speed the motor should be moving at the time the function is called. This is a signed value and is negative when the motor is moving backwards. Note: This speed will be incorrect if the desired velocity is set faster than this library can generate steps, or if the load on the motor is too great for the amount of torque that it can generate.


### function setCurrentPositionInSteps

```cpp
void setCurrentPositionInSteps(
    long currentPositionInSteps
)
```

set the current position of the motor in steps, this does not move the motor 

**Parameters**: 

  * **currentPositionInSteps** the new position of the motor in steps 





















**Remark**: Note: This function should only be called when the motor is stopped







### function getCurrentPositionInSteps

```cpp
long getCurrentPositionInSteps()
```

get the current position of the motor in steps, this functions is updated while the motor moves 







**Return**: a signed motor position in steps returned 





















### function setSpeedInStepsPerSecond

```cpp
void setSpeedInStepsPerSecond(
    float speedInStepsPerSecond
)
```

set the maximum speed, units in steps/second, this is the maximum speed reached while accelerating 

**Parameters**: 

  * **speedInStepsPerSecond** speed to accelerate up to, units in steps/second 




























### function setAccelerationInStepsPerSecondPerSecond

```cpp
void setAccelerationInStepsPerSecondPerSecond(
    float accelerationInStepsPerSecondPerSecond
)
```

set the rate of acceleration, units in steps/second/second 

**Parameters**: 

  * **accelerationInStepsPerSecondPerSecond** rate of acceleration, units in steps/second/second 




























### function moveToHomeInSteps

```cpp
bool moveToHomeInSteps(
    long directionTowardHome,
    float speedInStepsPerSecond,
    long maxDistanceToMoveInSteps,
    int homeSwitchPin
)
```

home the motor by moving until the homing sensor is activated, then set the position to zero with units in steps 

**Parameters**: 

  * **directionTowardHome** 1 to move in a positive direction, -1 to move in a negative directions 
  * **speedInStepsPerSecond** speed to accelerate up to while moving toward home, units in steps/second 
  * **maxDistanceToMoveInSteps** unsigned maximum distance to move toward home before giving up 
  * **homeSwitchPin** pin number of the home switch, switch should be configured to go low when at home 







**Return**: true returned if successful, else false 





















### function moveRelativeInSteps

```cpp
void moveRelativeInSteps(
    long distanceToMoveInSteps
)
```

move relative to the current position, units are in steps, this function does not return until the move is complete 

**Parameters**: 

  * **distanceToMoveInSteps** signed distance to move relative to the current position in steps 




























### function setTargetPositionRelativeInSteps

```cpp
void setTargetPositionRelativeInSteps(
    long distanceToMoveInSteps
)
```

setup a move relative to the current position, units are in steps, no motion occurs until processMove() is called 

**Parameters**: 

  * **distanceToMoveInSteps** signed distance to move relative to the current positionin steps 




























### function moveToPositionInSteps

```cpp
void moveToPositionInSteps(
    long absolutePositionToMoveToInSteps
)
```

move to the given absolute position, units are in steps, this function does not return until the move is complete 

**Parameters**: 

  * **absolutePositionToMoveToInSteps** signed absolute position to move to in unitsof steps 




























### function setTargetPositionInSteps

```cpp
void setTargetPositionInSteps(
    long absolutePositionToMoveToInSteps
)
```

setup a move, units are in steps, no motion occurs until processMove() is called 

**Parameters**: 

  * **absolutePositionToMoveToInSteps** signed absolute position to move to in units of steps 




























### function setTargetPositionToStop

```cpp
void setTargetPositionToStop()
```

setup a "Stop" to begin the process of decelerating from the current velocity to zero, decelerating requires calls to processMove() until the move is complete 





















**Remark**: Note: This function can be used to stop a motion initiated in units of steps or revolutions 







### function motionComplete

```cpp
bool motionComplete()
```

check if the motor has competed its move to the target position 







**Return**: true returned if the stepper is at the target position 





















### function getCurrentVelocityInStepsPerSecond

```cpp
float getCurrentVelocityInStepsPerSecond()
```

Get the current velocity of the motor in steps/second. 







**Return**: velocity speed in steps per second returned, signed 



















This functions is updated while it accelerates up and down in speed. This is not the desired speed, but the speed the motor should be moving at the time the function is called. This is a signed value and is negative when the motor is moving backwards. Note: This speed will be incorrect if the desired velocity is set faster than this library can generate steps, or if the load on the motor is too great for the amount of torque that it can generate.


### function processMovement

```cpp
bool processMovement(
    void 
)
```

if it is time, move one step 







**Return**: true returned if movement complete, false returned not a final target position yet 





























-------------------------------


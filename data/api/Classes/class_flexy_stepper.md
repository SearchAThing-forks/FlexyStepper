---
title: FlexyStepper


---

# FlexyStepper






`#include <FlexyStepper.h>`















## Public Functions

|                | Name           |
| -------------- | -------------- |
|  | **[FlexyStepper](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-flexystepper)**()  |
| void | **[connectToPins](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-connecttopins)**(byte stepPinNumber, byte directionPinNumber) <br>connect the stepper object to the IO pins  |
| void | **[setStepsPerMillimeter](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setstepspermillimeter)**(float motorStepPerMillimeter)  |
| float | **[getCurrentPositionInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-getcurrentpositioninmillimeters)**()  |
| void | **[setCurrentPositionInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setcurrentpositioninmillimeters)**(float currentPositionInMillimeters)  |
| void | **[setCurrentPositionInMillimeter](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setcurrentpositioninmillimeter)**(float currentPositionInMillimeter)  |
| void | **[setSpeedInMillimetersPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setspeedinmillimeterspersecond)**(float speedInMillimetersPerSecond)  |
| void | **[setAccelerationInMillimetersPerSecondPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setaccelerationinmillimeterspersecondpersecond)**(float accelerationInMillimetersPerSecondPerSecond)  |
| bool | **[moveToHomeInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-movetohomeinmillimeters)**(long directionTowardHome, float speedInMillimetersPerSecond, long maxDistanceToMoveInMillimeters, int homeLimitSwitchPin)  |
| void | **[moveRelativeInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-moverelativeinmillimeters)**(float distanceToMoveInMillimeters)  |
| void | **[setTargetPositionRelativeInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositionrelativeinmillimeters)**(float distanceToMoveInMillimeters)  |
| void | **[moveToPositionInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-movetopositioninmillimeters)**(float absolutePositionToMoveToInMillimeters)  |
| void | **[setTargetPositionInMillimeters](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositioninmillimeters)**(float absolutePositionToMoveToInMillimeters)  |
| float | **[getCurrentVelocityInMillimetersPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-getcurrentvelocityinmillimeterspersecond)**()  |
| void | **[setStepsPerRevolution](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setstepsperrevolution)**(float motorStepPerRevolution)  |
| void | **[setCurrentPositionInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setcurrentpositioninrevolutions)**(float currentPositionInRevolutions)  |
| float | **[getCurrentPositionInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-getcurrentpositioninrevolutions)**()  |
| void | **[setSpeedInRevolutionsPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setspeedinrevolutionspersecond)**(float speedInRevolutionsPerSecond)  |
| void | **[setAccelerationInRevolutionsPerSecondPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setaccelerationinrevolutionspersecondpersecond)**(float accelerationInRevolutionsPerSecondPerSecond)  |
| bool | **[moveToHomeInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-movetohomeinrevolutions)**(long directionTowardHome, float speedInRevolutionsPerSecond, long maxDistanceToMoveInRevolutions, int homeLimitSwitchPin)  |
| void | **[moveRelativeInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-moverelativeinrevolutions)**(float distanceToMoveInRevolutions)  |
| void | **[setTargetPositionRelativeInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositionrelativeinrevolutions)**(float distanceToMoveInRevolutions)  |
| void | **[moveToPositionInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-movetopositioninrevolutions)**(float absolutePositionToMoveToInRevolutions)  |
| void | **[setTargetPositionInRevolutions](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositioninrevolutions)**(float absolutePositionToMoveToInRevolutions)  |
| float | **[getCurrentVelocityInRevolutionsPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-getcurrentvelocityinrevolutionspersecond)**()  |
| void | **[setCurrentPositionInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setcurrentpositioninsteps)**(long currentPositionInSteps)  |
| long | **[getCurrentPositionInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-getcurrentpositioninsteps)**()  |
| void | **[setSpeedInStepsPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setspeedinstepspersecond)**(float speedInStepsPerSecond)  |
| void | **[setAccelerationInStepsPerSecondPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-setaccelerationinstepspersecondpersecond)**(float accelerationInStepsPerSecondPerSecond)  |
| bool | **[moveToHomeInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-movetohomeinsteps)**(long directionTowardHome, float speedInStepsPerSecond, long maxDistanceToMoveInSteps, int homeSwitchPin)  |
| void | **[moveRelativeInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-moverelativeinsteps)**(long distanceToMoveInSteps)  |
| void | **[setTargetPositionRelativeInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositionrelativeinsteps)**(long distanceToMoveInSteps)  |
| void | **[moveToPositionInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-movetopositioninsteps)**(long absolutePositionToMoveToInSteps)  |
| void | **[setTargetPositionInSteps](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositioninsteps)**(long absolutePositionToMoveToInSteps)  |
| void | **[setTargetPositionToStop](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-settargetpositiontostop)**()  |
| bool | **[motionComplete](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-motioncomplete)**()  |
| float | **[getCurrentVelocityInStepsPerSecond](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-getcurrentvelocityinstepspersecond)**()  |
| bool | **[processMovement](https://github.com/SearchAThing-forks/FlexyStepper/blob/master/data/api/Classes/class_flexy_stepper.md#function-processmovement)**(void )  |





















## Public Functions Documentation

### function FlexyStepper

```cpp
FlexyStepper()
```





























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





























### function getCurrentPositionInMillimeters

```cpp
float getCurrentPositionInMillimeters()
```





























### function setCurrentPositionInMillimeters

```cpp
void setCurrentPositionInMillimeters(
    float currentPositionInMillimeters
)
```





























### function setCurrentPositionInMillimeter

```cpp
void setCurrentPositionInMillimeter(
    float currentPositionInMillimeter
)
```





























### function setSpeedInMillimetersPerSecond

```cpp
void setSpeedInMillimetersPerSecond(
    float speedInMillimetersPerSecond
)
```





























### function setAccelerationInMillimetersPerSecondPerSecond

```cpp
void setAccelerationInMillimetersPerSecondPerSecond(
    float accelerationInMillimetersPerSecondPerSecond
)
```





























### function moveToHomeInMillimeters

```cpp
bool moveToHomeInMillimeters(
    long directionTowardHome,
    float speedInMillimetersPerSecond,
    long maxDistanceToMoveInMillimeters,
    int homeLimitSwitchPin
)
```





























### function moveRelativeInMillimeters

```cpp
void moveRelativeInMillimeters(
    float distanceToMoveInMillimeters
)
```





























### function setTargetPositionRelativeInMillimeters

```cpp
void setTargetPositionRelativeInMillimeters(
    float distanceToMoveInMillimeters
)
```





























### function moveToPositionInMillimeters

```cpp
void moveToPositionInMillimeters(
    float absolutePositionToMoveToInMillimeters
)
```





























### function setTargetPositionInMillimeters

```cpp
void setTargetPositionInMillimeters(
    float absolutePositionToMoveToInMillimeters
)
```





























### function getCurrentVelocityInMillimetersPerSecond

```cpp
float getCurrentVelocityInMillimetersPerSecond()
```





























### function setStepsPerRevolution

```cpp
void setStepsPerRevolution(
    float motorStepPerRevolution
)
```





























### function setCurrentPositionInRevolutions

```cpp
void setCurrentPositionInRevolutions(
    float currentPositionInRevolutions
)
```





























### function getCurrentPositionInRevolutions

```cpp
float getCurrentPositionInRevolutions()
```





























### function setSpeedInRevolutionsPerSecond

```cpp
void setSpeedInRevolutionsPerSecond(
    float speedInRevolutionsPerSecond
)
```





























### function setAccelerationInRevolutionsPerSecondPerSecond

```cpp
void setAccelerationInRevolutionsPerSecondPerSecond(
    float accelerationInRevolutionsPerSecondPerSecond
)
```





























### function moveToHomeInRevolutions

```cpp
bool moveToHomeInRevolutions(
    long directionTowardHome,
    float speedInRevolutionsPerSecond,
    long maxDistanceToMoveInRevolutions,
    int homeLimitSwitchPin
)
```





























### function moveRelativeInRevolutions

```cpp
void moveRelativeInRevolutions(
    float distanceToMoveInRevolutions
)
```





























### function setTargetPositionRelativeInRevolutions

```cpp
void setTargetPositionRelativeInRevolutions(
    float distanceToMoveInRevolutions
)
```





























### function moveToPositionInRevolutions

```cpp
void moveToPositionInRevolutions(
    float absolutePositionToMoveToInRevolutions
)
```





























### function setTargetPositionInRevolutions

```cpp
void setTargetPositionInRevolutions(
    float absolutePositionToMoveToInRevolutions
)
```





























### function getCurrentVelocityInRevolutionsPerSecond

```cpp
float getCurrentVelocityInRevolutionsPerSecond()
```





























### function setCurrentPositionInSteps

```cpp
void setCurrentPositionInSteps(
    long currentPositionInSteps
)
```





























### function getCurrentPositionInSteps

```cpp
long getCurrentPositionInSteps()
```





























### function setSpeedInStepsPerSecond

```cpp
void setSpeedInStepsPerSecond(
    float speedInStepsPerSecond
)
```





























### function setAccelerationInStepsPerSecondPerSecond

```cpp
void setAccelerationInStepsPerSecondPerSecond(
    float accelerationInStepsPerSecondPerSecond
)
```





























### function moveToHomeInSteps

```cpp
bool moveToHomeInSteps(
    long directionTowardHome,
    float speedInStepsPerSecond,
    long maxDistanceToMoveInSteps,
    int homeSwitchPin
)
```





























### function moveRelativeInSteps

```cpp
void moveRelativeInSteps(
    long distanceToMoveInSteps
)
```





























### function setTargetPositionRelativeInSteps

```cpp
void setTargetPositionRelativeInSteps(
    long distanceToMoveInSteps
)
```





























### function moveToPositionInSteps

```cpp
void moveToPositionInSteps(
    long absolutePositionToMoveToInSteps
)
```





























### function setTargetPositionInSteps

```cpp
void setTargetPositionInSteps(
    long absolutePositionToMoveToInSteps
)
```





























### function setTargetPositionToStop

```cpp
void setTargetPositionToStop()
```





























### function motionComplete

```cpp
bool motionComplete()
```





























### function getCurrentVelocityInStepsPerSecond

```cpp
float getCurrentVelocityInStepsPerSecond()
```





























### function processMovement

```cpp
bool processMovement(
    void 
)
```





































-------------------------------


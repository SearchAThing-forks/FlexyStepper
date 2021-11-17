
//      ******************************************************************
//      *                                                                *
//      *                    FlexyStepper Motor Driver                   *
//      *                                                                *
//      *            Stan Reifel                     12/8/2014           *
//      *               Copyright (c) S. Reifel & Co, 2014               *
//      *                                                                *
//      ******************************************************************

// MIT License
//
// Copyright (c) 2014 Stanley Reifel & Co.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is furnished
// to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

//
// This library is used to control one or more stepper motors.  It requires a
// stepper driver board that has a Step and Direction interface.  The motors are
// accelerated and decelerated as they travel to the final position.  This driver
// supports changing the target position, speed or rate of acceleration while a
// motion is in progress.
//
// Because the library allows making changes while moving, it can not generate
// as fast of a step rate as a driver that requires each motion to complete.
// To step faster, see the companion the Arduino stepper library:  SpeedyStepper
//
// This library can generate a maximum of about 7,000 steps per second using an
// Arduino Uno.  Assuming a system driving only one motor at a time, in full step
// mode, with a 200 steps per rotation motor, the maximum speed is about 35 RPS
// or 2100 RPM (most stepper motor can not go this fast).  Driving one motor in
// half step mode, a maximum speed of 17 RPS or 1050 RPM can be reached.  In
// quarter step mode about 9 RPS or 525 RPM.  Running multiple motors at the same
// time will reduce the maximum speed.  For example running two motors will reduce
// the step rate by half or more.
//
// This stepper motor driver is based on Aryeh Elderman's paper "Real Time Stepper
// Motor Linear Ramping Just By Addition and Multiplication".  See:
//                          www.hwml.com/LeibRamp.pdf
//
// It has advantages and disadvantages over David Austin's method.  The advantage
// is that it is faster, meaning you can generate more steps/second.  The
// disadvantage is that the speed ramping while accelerating and decelerating is
// less linear.  This is likely to only be a problem when coordinating multiple
// axis that all need to start and finish motions precisely at the same time.
//
//
// Usage:
//    Near the top of the program, add:
//        include "FlexyStepper.h"
//
//    For each stepper, declare a global object outside of all functions as
//    follows:
//        FlexyStepper stepper1;
//        FlexyStepper stepper2;
//
//    In Setup(), assign pin numbers:
//        stepper1.connectToPins(10, 11);
//        stepper2.connectToPins(12, 14);
//
//    Notes:
//        * Most stepper motors have 200 steps per revolution.
//        * With driver board set for 2x microstepping, then 400 steps per
//          revolution
//        * 8x microstepping results in 1600 steps per revolution
//        * NEMA 17 Steppers with lead screws typically have 25 steps per
//          millimeter when the driver is set for 1x microstepping
//
//
//    Move one motor in units of steps:
//        //
//        // set the speed in steps/second and acceleration in steps/second/second
//        //
//        stepper1.setSpeedInStepsPerSecond(100);
//        stepper1.setAccelerationInStepsPerSecondPerSecond(100);
//
//        //
//        // move 200 steps in the backward direction
//        //
//        stepper1.moveRelativeInSteps(-200);
//
//        //
//        // move to an absolute position of 200 steps
//        //
//        stepper1.moveToPositionInSteps(200);
//
//
//    Move one motor in units of revolutions:
//        //
//        // set the number of steps per revolutions, 200 with no microstepping,
//        // 800 with 4x microstepping
//        //
//        stepper1.setStepsPerRevolution(200);
//
//        //
//        // set the speed in rotations/second and acceleration in
//        // rotations/second/second
//        //
//        stepper1.setSpeedInRevolutionsPerSecond(1);
//        stepper1.setAccelerationInRevolutionsPerSecondPerSecond(1);
//
//        //
//        // move backward 1.5 revolutions
//        //
//        stepper1.moveRelativeInRevolutions(-1.5);
//
//        //
//        // move to an absolute position of 3.75 revolutions
//        //
//        stepper1.moveToPositionInRevolutions(3.75);
//
//
//    Move one motor in units of millimeters:
//        //
//        // set the number of steps per millimeter
//        //
//        stepper1.setStepsPerMillimeter(25);
//
//        //
//        // set the speed in millimeters/second and acceleration in
//        // millimeters/second/second
//        //
//        stepper1.setSpeedInMillimetersPerSecond(20);
//        stepper1.setAccelerationInMillimetersPerSecondPerSecond(20);
//
//        //
//        // move backward 15.5 millimeters
//        //
//        stepper1.moveRelativeInMillimeters(-15.5);
//
//        //
//        // move to an absolute position of 125 millimeters
//        //
//        stepper1.moveToPositionInMillimeters(125);
//
//
//    Move two motors in units of revolutions:
//        //
//        // set the number of steps per revolutions, 200 with no microstepping,
//        // 800 with 4x microstepping
//        //
//        stepper1.setStepsPerRevolution(200);
//        stepper2.setStepsPerRevolution(200);
//
//        //
//        // set the speed in rotations/second and acceleration in
//        // rotations/second/second
//        //
//        stepper1.setSpeedInRevolutionsPerSecond(1);
//        stepper1.setAccelerationInRevolutionsPerSecondPerSecond(1);
//        stepper2.setSpeedInRevolutionsPerSecond(1);
//        stepper2.setAccelerationInRevolutionsPerSecondPerSecond(1);
//
//        //
//        // setup motor 1 to move backward 1.5 revolutions, this step does not
//        // actually move the motor
//        //
//        stepper1.setupRelativeMoveInRevolutions(-1.5);
//
//        //
//        // setup motor 2 to move forward 3.0 revolutions, this step does not
//        // actually move the motor
//        //
//        stepper2.setupRelativeMoveInRevolutions(3.0);
//
//        //
//        // execute the moves
//        //
//        while((!stepper1.motionComplete()) || (!stepper2.motionComplete()))
//        {
//          stepper1.processMovement();
//          stepper2.processMovement();
//        }
//

#include "FlexyStepper.h"

//
// direction signal level for "step and direction"
//
#define POSITIVE_DIRECTION LOW
#define NEGATIVE_DIRECTION HIGH

// ---------------------------------------------------------------------------------
//                                  Setup functions
// ---------------------------------------------------------------------------------

FlexyStepper::FlexyStepper()
{
  //
  // initialize constants
  //
  stepsPerRevolution = 200L;
  stepsPerMillimeter = 25.0;
  directionOfMotion = 0;
  currentPosition_InSteps = 0L;
  targetPosition_InSteps = 0L;
  setSpeedInStepsPerSecond(200);
  setAccelerationInStepsPerSecondPerSecond(200.0);
  currentStepPeriod_InUS = 0.0;
  nextStepPeriod_InUS = 0.0;
}

void FlexyStepper::connectToPins(byte stepPinNumber, byte directionPinNumber)
{
  //
  // remember the pin numbers
  //
  stepPin = stepPinNumber;
  directionPin = directionPinNumber;

  //
  // configure the IO bits
  //
  pinMode(stepPin, OUTPUT);
  digitalWrite(stepPin, LOW);

  pinMode(directionPin, OUTPUT);
  digitalWrite(directionPin, LOW);
}

// ---------------------------------------------------------------------------------
//                     Public functions with units in millimeters
// ---------------------------------------------------------------------------------

void FlexyStepper::setStepsPerMillimeter(float motorStepsPerMillimeter)
{
  stepsPerMillimeter = motorStepsPerMillimeter;
}

float FlexyStepper::getCurrentPositionInMillimeters()
{
  return ((float)getCurrentPositionInSteps() / stepsPerMillimeter);
}

void FlexyStepper::setCurrentPositionInMillimeters(
    float currentPositionInMillimeters)
{
  setCurrentPositionInSteps((long)round(currentPositionInMillimeters *
                                        stepsPerMillimeter));
}

void FlexyStepper::setSpeedInMillimetersPerSecond(float speedInMillimetersPerSecond)
{
  setSpeedInStepsPerSecond(speedInMillimetersPerSecond * stepsPerMillimeter);
}

void FlexyStepper::setAccelerationInMillimetersPerSecondPerSecond(
    float accelerationInMillimetersPerSecondPerSecond)
{
  setAccelerationInStepsPerSecondPerSecond(
      accelerationInMillimetersPerSecondPerSecond * stepsPerMillimeter);
}

bool FlexyStepper::moveToHomeInMillimeters(long directionTowardHome,
                                           float speedInMillimetersPerSecond, long maxDistanceToMoveInMillimeters,
                                           int homeLimitSwitchPin)
{
  return (moveToHomeInSteps(directionTowardHome,
                            speedInMillimetersPerSecond * stepsPerMillimeter,
                            maxDistanceToMoveInMillimeters * stepsPerMillimeter,
                            homeLimitSwitchPin));
}

void FlexyStepper::moveRelativeInMillimeters(float distanceToMoveInMillimeters)
{
  setTargetPositionRelativeInMillimeters(distanceToMoveInMillimeters);

  while (!processMovement())
    ;
}

void FlexyStepper::setTargetPositionRelativeInMillimeters(
    float distanceToMoveInMillimeters)
{
  setTargetPositionRelativeInSteps((long)round(distanceToMoveInMillimeters *
                                               stepsPerMillimeter));
}

void FlexyStepper::moveToPositionInMillimeters(
    float absolutePositionToMoveToInMillimeters)
{
  setTargetPositionInMillimeters(absolutePositionToMoveToInMillimeters);

  while (!processMovement())
    ;
}

void FlexyStepper::setTargetPositionInMillimeters(
    float absolutePositionToMoveToInMillimeters)
{
  setTargetPositionInSteps((long)round(absolutePositionToMoveToInMillimeters *
                                       stepsPerMillimeter));
}

float FlexyStepper::getCurrentVelocityInMillimetersPerSecond()
{
  return (getCurrentVelocityInStepsPerSecond() / stepsPerMillimeter);
}

// ---------------------------------------------------------------------------------
//                     Public functions with units in revolutions
// ---------------------------------------------------------------------------------

void FlexyStepper::setStepsPerRevolution(float motorStepPerRevolution)
{
  stepsPerRevolution = motorStepPerRevolution;
}

float FlexyStepper::getCurrentPositionInRevolutions()
{
  return ((float)getCurrentPositionInSteps() / stepsPerRevolution);
}

void FlexyStepper::setCurrentPositionInRevolutions(
    float currentPositionInRevolutions)
{
  setCurrentPositionInSteps((long)round(currentPositionInRevolutions *
                                        stepsPerRevolution));
}

void FlexyStepper::setSpeedInRevolutionsPerSecond(float speedInRevolutionsPerSecond)
{
  setSpeedInStepsPerSecond(speedInRevolutionsPerSecond * stepsPerRevolution);
}

void FlexyStepper::setAccelerationInRevolutionsPerSecondPerSecond(
    float accelerationInRevolutionsPerSecondPerSecond)
{
  setAccelerationInStepsPerSecondPerSecond(
      accelerationInRevolutionsPerSecondPerSecond * stepsPerRevolution);
}

bool FlexyStepper::moveToHomeInRevolutions(long directionTowardHome,
                                           float speedInRevolutionsPerSecond, long maxDistanceToMoveInRevolutions,
                                           int homeLimitSwitchPin)
{
  return (moveToHomeInSteps(directionTowardHome,
                            speedInRevolutionsPerSecond * stepsPerRevolution,
                            maxDistanceToMoveInRevolutions * stepsPerRevolution,
                            homeLimitSwitchPin));
}

void FlexyStepper::moveRelativeInRevolutions(float distanceToMoveInRevolutions)
{
  setTargetPositionRelativeInRevolutions(distanceToMoveInRevolutions);

  while (!processMovement())
    ;
}

void FlexyStepper::setTargetPositionRelativeInRevolutions(
    float distanceToMoveInRevolutions)
{
  setTargetPositionRelativeInSteps((long)round(distanceToMoveInRevolutions *
                                               stepsPerRevolution));
}

void FlexyStepper::moveToPositionInRevolutions(
    float absolutePositionToMoveToInRevolutions)
{
  setTargetPositionInRevolutions(absolutePositionToMoveToInRevolutions);

  while (!processMovement())
    ;
}

void FlexyStepper::setTargetPositionInRevolutions(
    float absolutePositionToMoveToInRevolutions)
{
  setTargetPositionInSteps((long)round(absolutePositionToMoveToInRevolutions *
                                       stepsPerRevolution));
}

float FlexyStepper::getCurrentVelocityInRevolutionsPerSecond()
{
  return (getCurrentVelocityInStepsPerSecond() / stepsPerRevolution);
}

// ---------------------------------------------------------------------------------
//                        Public functions with units in steps
// ---------------------------------------------------------------------------------

void FlexyStepper::setCurrentPositionInSteps(long currentPositionInSteps)
{
  currentPosition_InSteps = currentPositionInSteps;
}

long FlexyStepper::getCurrentPositionInSteps()
{
  return (currentPosition_InSteps);
}

void FlexyStepper::setSpeedInStepsPerSecond(float speedInStepsPerSecond)
{
  desiredSpeed_InStepsPerSecond = speedInStepsPerSecond;
  desiredPeriod_InUSPerStep = 1000000.0 / desiredSpeed_InStepsPerSecond;
}

void FlexyStepper::setAccelerationInStepsPerSecondPerSecond(
    float accelerationInStepsPerSecondPerSecond)
{
  acceleration_InStepsPerSecondPerSecond = accelerationInStepsPerSecondPerSecond;
  acceleration_InStepsPerUSPerUS = acceleration_InStepsPerSecondPerSecond / 1E12;

  periodOfSlowestStep_InUS =
      1000000.0 / sqrt(2.0 * acceleration_InStepsPerSecondPerSecond);
  minimumPeriodForAStoppedMotion = periodOfSlowestStep_InUS / 2.8;
}

bool FlexyStepper::moveToHomeInSteps(long directionTowardHome,
                                     float speedInStepsPerSecond, long maxDistanceToMoveInSteps,
                                     int homeLimitSwitchPin)
{
  float originalDesiredSpeed_InStepsPerSecond;
  bool limitSwitchFlag;

  //
  // setup the home switch input pin
  //
  pinMode(homeLimitSwitchPin, INPUT_PULLUP);

  //
  // remember the current speed setting
  //
  originalDesiredSpeed_InStepsPerSecond = desiredSpeed_InStepsPerSecond;

  //
  // if the home switch is not already set, move toward it
  //
  if (digitalRead(homeLimitSwitchPin) == HIGH)
  {
    //
    // move toward the home switch
    //
    setSpeedInStepsPerSecond(speedInStepsPerSecond);
    setTargetPositionRelativeInSteps(maxDistanceToMoveInSteps * directionTowardHome);
    limitSwitchFlag = false;
    while (!processMovement())
    {
      if (digitalRead(homeLimitSwitchPin) == LOW)
      {
        limitSwitchFlag = true;
        directionOfMotion = 0;
        break;
      }
    }

    //
    // check if switch never detected
    //
    if (limitSwitchFlag == false)
      return (false);
  }
  delay(25);

  //
  // the switch has been detected, now move away from the switch
  //
  setTargetPositionRelativeInSteps(maxDistanceToMoveInSteps *
                                   directionTowardHome * -1);
  limitSwitchFlag = false;
  while (!processMovement())
  {
    if (digitalRead(homeLimitSwitchPin) == HIGH)
    {
      limitSwitchFlag = true;
      directionOfMotion = 0;
      break;
    }
  }
  delay(25);

  //
  // check if switch never detected
  //
  if (limitSwitchFlag == false)
    return (false);

  //
  // have now moved off the switch, move toward it again but slower
  //
  setSpeedInStepsPerSecond(speedInStepsPerSecond / 8);
  setTargetPositionRelativeInSteps(maxDistanceToMoveInSteps * directionTowardHome);
  limitSwitchFlag = false;
  while (!processMovement())
  {
    if (digitalRead(homeLimitSwitchPin) == LOW)
    {
      limitSwitchFlag = true;
      directionOfMotion = 0;
      break;
    }
  }
  delay(25);

  //
  // check if switch never detected
  //
  if (limitSwitchFlag == false)
    return (false);

  //
  // successfully homed, set the current position to 0
  //
  setCurrentPositionInSteps(0L);

  //
  // restore original velocity
  //
  setSpeedInStepsPerSecond(originalDesiredSpeed_InStepsPerSecond);
  return (true);
}

void FlexyStepper::moveRelativeInSteps(long distanceToMoveInSteps)
{
  setTargetPositionRelativeInSteps(distanceToMoveInSteps);

  while (!processMovement())
    ;
}

void FlexyStepper::setTargetPositionRelativeInSteps(long distanceToMoveInSteps)
{
  setTargetPositionInSteps(currentPosition_InSteps + distanceToMoveInSteps);
}

void FlexyStepper::moveToPositionInSteps(long absolutePositionToMoveToInSteps)
{
  setTargetPositionInSteps(absolutePositionToMoveToInSteps);

  while (!processMovement())
    ;
}

void FlexyStepper::setTargetPositionInSteps(long absolutePositionToMoveToInSteps)
{
  targetPosition_InSteps = absolutePositionToMoveToInSteps;
}

void FlexyStepper::setTargetPositionToStop()
{
  if (currentStepPeriod_InUS == 0.0f)
    return;

  long decelerationDistance_InSteps;

  //
  // move the target position so that the motor will begin deceleration now
  //
  decelerationDistance_InSteps = (long)round(
      5E11 / (acceleration_InStepsPerSecondPerSecond * currentStepPeriod_InUS *
              currentStepPeriod_InUS));

  if (directionOfMotion > 0)
    setTargetPositionInSteps(currentPosition_InSteps + decelerationDistance_InSteps);
  else
    setTargetPositionInSteps(currentPosition_InSteps - decelerationDistance_InSteps);
}

bool FlexyStepper::processMovement(void)
{
  unsigned long currentTime_InUS;
  unsigned long periodSinceLastStep_InUS;
  long distanceToTarget_Signed;

  //
  // check if currently stopped
  //
  if (directionOfMotion == 0)
  {
    distanceToTarget_Signed = targetPosition_InSteps - currentPosition_InSteps;

    //
    // check if target position in a positive direction
    //
    if (distanceToTarget_Signed > 0)
    {
      directionOfMotion = 1;
      digitalWrite(directionPin, POSITIVE_DIRECTION);
      nextStepPeriod_InUS = periodOfSlowestStep_InUS;
      lastStepTime_InUS = micros();
      return (false);
    }

    //
    // check if target position in a negative direction
    //
    else if (distanceToTarget_Signed < 0)
    {
      directionOfMotion = -1;
      digitalWrite(directionPin, NEGATIVE_DIRECTION);
      nextStepPeriod_InUS = periodOfSlowestStep_InUS;
      lastStepTime_InUS = micros();
      return (false);
    }

    else
      return (true);
  }

  //
  // determine how much time has elapsed since the last step (Note 1: this method
  // works even if the time has wrapped. Note 2: all variables must be unsigned)
  //
  currentTime_InUS = micros();
  periodSinceLastStep_InUS = currentTime_InUS - lastStepTime_InUS;

  //
  // if it is not time for the next step, return
  //
  if (periodSinceLastStep_InUS < (unsigned long)nextStepPeriod_InUS)
    return (false);

  //
  // execute the step on the rising edge
  //
  digitalWrite(stepPin, HIGH);

  //
  // this delay almost nothing because there's so much code between rising &
  // falling edges
  //
  delayMicroseconds(2);

  //
  // update the current position and speed
  //
  currentPosition_InSteps += directionOfMotion;
  currentStepPeriod_InUS = nextStepPeriod_InUS;

  //
  // remember the time that this step occured
  //
  lastStepTime_InUS = currentTime_InUS;

  //
  // figure out how long before the next step
  //
  DeterminePeriodOfNextStep();

  //
  // return the step line low
  //
  digitalWrite(stepPin, LOW);

  //
  // check if the move has reached its final target position, return true if all
  // done
  //
  if (currentPosition_InSteps == targetPosition_InSteps)
  {
    //
    // at final position, make sure the motor is not going too fast
    //
    if (nextStepPeriod_InUS >= minimumPeriodForAStoppedMotion)
    {
      currentStepPeriod_InUS = 0.0;
      nextStepPeriod_InUS = 0.0;
      directionOfMotion = 0;
      return (true);
    }
  }

  return (false);
}

float FlexyStepper::getCurrentVelocityInStepsPerSecond()
{
  if (currentStepPeriod_InUS == 0.0)
    return (0);
  else
  {
    if (directionOfMotion > 0)
      return (1000000.0 / currentStepPeriod_InUS);
    else
      return (-1000000.0 / currentStepPeriod_InUS);
  }
}

bool FlexyStepper::motionComplete()
{
  if ((directionOfMotion == 0) &&
      (currentPosition_InSteps == targetPosition_InSteps))
    return (true);
  else
    return (false);
}

void FlexyStepper::DeterminePeriodOfNextStep()
{
  long distanceToTarget_Signed;
  long distanceToTarget_Unsigned;
  float currentSpeed_InStepsPerSecond;
  long decelerationDistance_InSteps;
  float currentStepPeriodSquared;
  bool speedUpFlag = false;
  bool slowDownFlag = false;
  bool targetInPositiveDirectionFlag = false;
  bool targetInNegativeDirectionFlag = false;

  //
  // determine the distance to the target position
  //
  distanceToTarget_Signed = targetPosition_InSteps - currentPosition_InSteps;
  if (distanceToTarget_Signed >= 0L)
  {
    distanceToTarget_Unsigned = distanceToTarget_Signed;
    targetInPositiveDirectionFlag = true;
  }
  else
  {
    distanceToTarget_Unsigned = -distanceToTarget_Signed;
    targetInNegativeDirectionFlag = true;
  }

  //
  // determine the number of steps needed to go from the current speed down to a
  // velocity of 0, Steps = Velocity^2 / (2 * Acceleration)
  //
  currentStepPeriodSquared = currentStepPeriod_InUS * currentStepPeriod_InUS;
  decelerationDistance_InSteps = (long)round(
      5E11 / (acceleration_InStepsPerSecondPerSecond * currentStepPeriodSquared));

  //
  // check if: Moving in a positive direction & Moving toward the target
  //    (directionOfMotion == 1) && (distanceToTarget_Signed > 0)
  //
  if ((directionOfMotion == 1) && (targetInPositiveDirectionFlag))
  {
    //
    // check if need to start slowing down as we reach the target, or if we
    // need to slow down because we are going too fast
    //
    if ((distanceToTarget_Unsigned < decelerationDistance_InSteps) ||
        (nextStepPeriod_InUS < desiredPeriod_InUSPerStep))
      slowDownFlag = true;
    else
      speedUpFlag = true;
  }

  //
  // check if: Moving in a positive direction & Moving away from the target
  //    (directionOfMotion == 1) && (distanceToTarget_Signed < 0)
  //
  else if ((directionOfMotion == 1) && (targetInNegativeDirectionFlag))
  {
    //
    // need to slow down, then reverse direction
    //
    if (currentStepPeriod_InUS < periodOfSlowestStep_InUS)
    {
      slowDownFlag = true;
    }
    else
    {
      directionOfMotion = -1;
      digitalWrite(directionPin, NEGATIVE_DIRECTION);
    }
  }

  //
  // check if: Moving in a negative direction & Moving toward the target
  //    (directionOfMotion == -1) && (distanceToTarget_Signed < 0)
  //
  else if ((directionOfMotion == -1) && (targetInNegativeDirectionFlag))
  {
    //
    // check if need to start slowing down as we reach the target, or if we
    // need to slow down because we are going too fast
    //
    if ((distanceToTarget_Unsigned < decelerationDistance_InSteps) ||
        (nextStepPeriod_InUS < desiredPeriod_InUSPerStep))
      slowDownFlag = true;
    else
      speedUpFlag = true;
  }

  //
  // check if: Moving in a negative direction & Moving away from the target
  //    (directionOfMotion == -1) && (distanceToTarget_Signed > 0)
  //
  else if ((directionOfMotion == -1) && (targetInPositiveDirectionFlag))
  {
    //
    // need to slow down, then reverse direction
    //
    if (currentStepPeriod_InUS < periodOfSlowestStep_InUS)
    {
      slowDownFlag = true;
    }
    else
    {
      directionOfMotion = 1;
      digitalWrite(directionPin, POSITIVE_DIRECTION);
    }
  }

  //
  // check if accelerating
  //
  if (speedUpFlag)
  {
    //
    // StepPeriod = StepPeriod(1 - a * StepPeriod^2)
    //
    nextStepPeriod_InUS = currentStepPeriod_InUS - acceleration_InStepsPerUSPerUS *
                                                       currentStepPeriodSquared * currentStepPeriod_InUS;

    if (nextStepPeriod_InUS < desiredPeriod_InUSPerStep)
      nextStepPeriod_InUS = desiredPeriod_InUSPerStep;
  }

  //
  // check if decelerating
  //
  if (slowDownFlag)
  {
    //
    // StepPeriod = StepPeriod(1 + a * StepPeriod^2)
    //
    nextStepPeriod_InUS = currentStepPeriod_InUS + acceleration_InStepsPerUSPerUS *
                                                       currentStepPeriodSquared * currentStepPeriod_InUS;

    if (nextStepPeriod_InUS > periodOfSlowestStep_InUS)
      nextStepPeriod_InUS = periodOfSlowestStep_InUS;
  }
}

// -------------------------------------- End --------------------------------------

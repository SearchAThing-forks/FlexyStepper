
//      ******************************************************************
//      *                                                                *
//      *                 Header file for FlexyStepper.c                 *
//      *                                                                *
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

#ifndef FlexyStepper_h
#define FlexyStepper_h

#include <Arduino.h>
#include <stdlib.h>

//
// the FlexyStepper class
//
class FlexyStepper
{
public:
  //
  // public functions
  //

  /**
   * @brief constructor for the stepper class   
   */
  FlexyStepper();

  /**
   * @brief connect the stepper object to the IO pins
   * 
   * @param stepPinNumber IO pin number for the Step
   * @param directionPinNumber IO pin number for the direction bit
   * @param enablePinNumber IO pin number for the enable bit (LOW is enabled).
   * set to 0 if enable is not supported
   */
  void connectToPins(byte stepPinNumber, byte directionPinNumber);

  /**
   * @brief set the number of steps the motor has per millimeters
   */
  void setStepsPerMillimeter(float motorStepPerMillimeter);

  /**
   * @brief get the current position of the motor in millimeters, this functions is updated while the motor moves
   * 
   * @return a signed motor position in millimeters returned
   */
  float getCurrentPositionInMillimeters();

  /**
   * @brief set the current position of the motor in millimeters, this does not move the motor
   */
  void setCurrentPositionInMillimeters(float currentPositionInMillimeters);  

  /**
   * @brief set the maximum speed, units in millimeters/second, this is the maximum speed reached while accelerating
   * 
   * @param speedInMillimetersPerSecond speed to accelerate up to, units in millimeters/second
   */
  void setSpeedInMillimetersPerSecond(float speedInMillimetersPerSecond);

  /**
   * @brief set the rate of acceleration, units in millimeters/second/second
   * 
   * @param accelerationInMillimetersPerSecondPerSecond accelerationInMillimetersPerSecondPerSecond = rate of acceleration, units in millimeters/second/second
   */
  void setAccelerationInMillimetersPerSecondPerSecond(float accelerationInMillimetersPerSecondPerSecond);

  /**
   * @brief home the motor by moving until the homing sensor is activated, then set the position to zero, with units in millimeters
   * 
   * @param directionTowardHome 1 to move in a positive direction, -1 to move in a negative directions
   * @param speedInMillimetersPerSecond speed to accelerate up to while moving toward home, units in millimeters/second
   * @param maxDistanceToMoveInMillimeters unsigned maximum distance to move toward home before giving up
   * @param homeLimitSwitchPin pin number of the home switch, switch should be configured to go low when at home
   * @return true returned if successful, else false
   */
  bool moveToHomeInMillimeters(long directionTowardHome, float speedInMillimetersPerSecond, long maxDistanceToMoveInMillimeters, int homeLimitSwitchPin);

  /**
   * @brief move relative to the current position, units are in millimeters, this function does not return until the move is complete
   * 
   * @param distanceToMoveInMillimeters signed distance to move relative to the current position in millimeters
   */
  void moveRelativeInMillimeters(float distanceToMoveInMillimeters);

  /**
   * @brief setup a move relative to the current position, units are in millimeters, no motion occurs until processMove() is called
   * 
   * @param distanceToMoveInMillimeters signed distance to move relative to the current position in millimeters
   */
  void setTargetPositionRelativeInMillimeters(float distanceToMoveInMillimeters);

  /**
   * @brief move to the given absolute position, units are in millimeters, this function does not return until the move is complete
   * 
   * @param absolutePositionToMoveToInMillimeters signed absolute position to move to in units of millimeters
   */
  void moveToPositionInMillimeters(float absolutePositionToMoveToInMillimeters);

  /**
   * @brief setup a move, units are in millimeters, no motion occurs until processMove() is called
   * 
   * @param absolutePositionToMoveToInMillimeters signed absolute position to move to in units of millimeters
   */
  void setTargetPositionInMillimeters(float absolutePositionToMoveToInMillimeters);

  /**
   * @brief Get the current velocity of the motor in millimeters/second.
   * 
   * This functions is updated while it accelerates up and down in speed.  This is not the desired
   * speed, but the speed the motor should be moving at the time the function is
   * called.  This is a signed value and is negative when the motor is moving
   * backwards.  Note: This speed will be incorrect if the desired velocity is set
   * faster than this library can generate steps, or if the load on the motor is too
   * great for the amount of torque that it can generate.
   * 
   * @return float velocity speed in steps per second returned, signed
   */
  float getCurrentVelocityInMillimetersPerSecond();

  /**
   * @brief set the number of steps the motor has per revolution
   * 
   * @param motorStepPerRevolution 
   */
  void setStepsPerRevolution(float motorStepPerRevolution);

  /**
   * @brief set the current position of the motor in revolutions, this does not move the motor
   */
  void setCurrentPositionInRevolutions(float currentPositionInRevolutions);

  /**
   * @brief get the current position of the motor in revolutions, this functions is updated while the motor moves
   * 
   * @param currentPositionInRevolutions a signed motor position in revolutions returned
   */
  float getCurrentPositionInRevolutions();

  /**
   * @brief set the maximum speed, units in revolutions/second, this is the maximum speed reached while accelerating
   * 
   * @param speedInRevolutionsPerSecond speed to accelerate up to, units in revolutions/second
   */
  void setSpeedInRevolutionsPerSecond(float speedInRevolutionsPerSecond);

  /**
   * @brief set the rate of acceleration, units in revolutions/second/second
   * 
   * @param accelerationInRevolutionsPerSecondPerSecond rate of acceleration, units in revolutions/second/second
   */
  void setAccelerationInRevolutionsPerSecondPerSecond(float accelerationInRevolutionsPerSecondPerSecond);

  /**
   * @brief home the motor by moving until the homing sensor is activated, then set the position to zero, with units in revolutions
   * 
   * @param directionTowardHome 1 to move in a positive direction, -1 to move in a negative directions
   * @param speedInRevolutionsPerSecond speed to accelerate up to while moving toward home, units in revolutions/second
   * @param maxDistanceToMoveInRevolutions unsigned maximum distance to move toward home before giving up
   * @param homeLimitSwitchPin pin number of the home switch, switch should be configured to go low when at home
   * @return true returned if successful, else false
   */
  bool moveToHomeInRevolutions(long directionTowardHome, float speedInRevolutionsPerSecond, long maxDistanceToMoveInRevolutions, int homeLimitSwitchPin);

  /**
   * @brief move relative to the current position, units are in revolutions, this function does not return until the move is complete
   * 
   * @param distanceToMoveInRevolutions signed distance to move relative to the current position in revolutions
   */
  void moveRelativeInRevolutions(float distanceToMoveInRevolutions);

  /**
   * @brief setup a move relative to the current position, units are in revolutions, no motion occurs until processMove() is called
   * 
   * @param distanceToMoveInRevolutions signed distance to move relative to the currentposition in revolutions
   */
  void setTargetPositionRelativeInRevolutions(float distanceToMoveInRevolutions);

  /**
   * @brief move to the given absolute position, units are in revolutions, this function does not return until the move is complete
   * 
   * @param absolutePositionToMoveToInRevolutions signed absolute position to move to in units of revolutions
   */
  void moveToPositionInRevolutions(float absolutePositionToMoveToInRevolutions);

  /**
   * @brief setup a move, units are in revolutions, no motion occurs until processMove() is called
   * 
   * @param absolutePositionToMoveToInRevolutions signed absolute position to move to in units of revolutions
   */
  void setTargetPositionInRevolutions(float absolutePositionToMoveToInRevolutions);

  /**
   * @brief Get the current velocity of the motor in revolutions/second.
   * 
   * This functions is updated while it accelerates up and down in speed.  This is not the desired
   * speed, but the speed the motor should be moving at the time the function is
   * called.  This is a signed value and is negative when the motor is moving
   * backwards.  Note: This speed will be incorrect if the desired velocity is set
   * faster than this library can generate steps, or if the load on the motor is too
   * great for the amount of torque that it can generate.
   * 
   * @return velocity speed in steps per second returned, signed 
   */
  float getCurrentVelocityInRevolutionsPerSecond();

  /**
   * @brief set the current position of the motor in steps, this does not move the motor
   * 
   * @remark Note: This function should only be called when the motor is stopped
   * 
   * @param currentPositionInSteps the new position of the motor in steps
   */
  void setCurrentPositionInSteps(long currentPositionInSteps);

  /**
   * @brief get the current position of the motor in steps, this functions is updated while the motor moves
   * 
   * @return a signed motor position in steps returned 
   */
  long getCurrentPositionInSteps();

  /**
   * @brief set the maximum speed, units in steps/second, this is the maximum speed reached while accelerating
   * 
   * @param speedInStepsPerSecond speed to accelerate up to, units in steps/second
   */
  void setSpeedInStepsPerSecond(float speedInStepsPerSecond);

  /**
   * @brief set the rate of acceleration, units in steps/second/second
   * 
   * @param accelerationInStepsPerSecondPerSecond rate of acceleration, units in steps/second/second
   */
  void setAccelerationInStepsPerSecondPerSecond(float accelerationInStepsPerSecondPerSecond);

  /**
   * @brief home the motor by moving until the homing sensor is activated, then set the position to zero with units in steps
   * 
   * @param directionTowardHome 1 to move in a positive direction, -1 to move in a negative directions
   * @param speedInStepsPerSecond speed to accelerate up to while moving toward home, units in steps/second
   * @param maxDistanceToMoveInSteps unsigned maximum distance to move toward home before giving up
   * @param homeSwitchPin pin number of the home switch, switch should be configured to go low when at home
   * @return true returned if successful, else false
   */
  bool moveToHomeInSteps(long directionTowardHome, float speedInStepsPerSecond, long maxDistanceToMoveInSteps, int homeSwitchPin);

  /**
   * @brief move relative to the current position, units are in steps, this function does not return until the move is complete
   * 
   * @param distanceToMoveInSteps signed distance to move relative to the current position in steps
   */
  void moveRelativeInSteps(long distanceToMoveInSteps);

  /**
   * @brief setup a move relative to the current position, units are in steps, no motion occurs until processMove() is called
   * 
   * @param distanceToMoveInSteps signed distance to move relative to the current positionin steps
   */
  void setTargetPositionRelativeInSteps(long distanceToMoveInSteps);

  /**
   * @brief move to the given absolute position, units are in steps, this function does not return until the move is complete
   * 
   * @param absolutePositionToMoveToInSteps signed absolute position to move to in unitsof steps
   */
  void moveToPositionInSteps(long absolutePositionToMoveToInSteps);

  /**
   * @brief setup a move, units are in steps, no motion occurs until processMove() is called
   * 
   * @param absolutePositionToMoveToInSteps signed absolute position to move to in units of steps
   */
  void setTargetPositionInSteps(long absolutePositionToMoveToInSteps);

  /**
   * @brief setup a "Stop" to begin the process of decelerating from the current velocity to zero, decelerating requires calls to processMove() until the move is complete
   * 
   * @remark Note: This function can be used to stop a motion initiated in units of steps or revolutions  
   */
  void setTargetPositionToStop();

  /**
   * @brief check if the motor has competed its move to the target position
   * 
   * @return true returned if the stepper is at the target position
   */
  bool motionComplete();

  /**
   * @brief Get the current velocity of the motor in steps/second.
   * 
   * This functions is updated while it accelerates up and down in speed.  This is not the desired
   * speed, but the speed the motor should be moving at the time the function is
   * called.  This is a signed value and is negative when the motor is moving
   * backwards.  Note: This speed will be incorrect if the desired velocity is set
   * faster than this library can generate steps, or if the load on the motor is too
   * great for the amount of torque that it can generate.
   * 
   * @return velocity speed in steps per second returned, signed 
   */
  float getCurrentVelocityInStepsPerSecond();

  /**
   * @brief if it is time, move one step
   * 
   * @return true returned if movement complete, false returned not a final target position yet
   */
  bool processMovement(void);

private:
  //
  // private functions
  //

  /**
   * @brief determine the period for the next step, either speed up a little, slow down a little or go the same speed  
   */
  void DeterminePeriodOfNextStep();

  //
  // private member variables
  //
  byte stepPin;
  byte directionPin;
  float stepsPerMillimeter;
  float stepsPerRevolution;
  int directionOfMotion;
  long currentPosition_InSteps;
  long targetPosition_InSteps;
  float desiredSpeed_InStepsPerSecond;
  float desiredPeriod_InUSPerStep;
  float acceleration_InStepsPerSecondPerSecond;
  float acceleration_InStepsPerUSPerUS;
  float periodOfSlowestStep_InUS;
  float minimumPeriodForAStoppedMotion;
  float nextStepPeriod_InUS;
  unsigned long lastStepTime_InUS;
  float currentStepPeriod_InUS;
  bool stopIssued;
};

// ------------------------------------ End ---------------------------------
#endif

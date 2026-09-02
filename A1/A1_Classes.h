#ifndef A1_CLASSES_H
#define A1_CLASSES_H

// Given classes
class CRender;
class CLoopReader;

// Stores the speed of one wheel.
class CWheel {
public:
  CWheel();

  void SetSpeed(float aSpeed);
  float GetSpeed() const;

private:
  float mSpeed;
};

// JUDE - SENSOERERERE - Angle, measure wall
class CRangeSensor {
public:
  CRangeSensor();

private:
  // sensor's data here.
};

// This will use the two sensor readings to choose a turn.
class CWallFollowerController {
public:
  CWallFollowerController();

  // Add the wall-following decision later.
};

// This will store the positions visited by the robot.
class CTrail {
public:
  CTrail();

  // Add positions to the trail.
  // Draw the saved trail.
};

// Stores the robot and updates its movement.
class CRobot {
public:
  enum class ETurnState { STOPPED, STRAIGHT, TURN_LEFT, TURN_RIGHT };

  CRobot();

  void SetTurnState(ETurnState aNewState);
  void UpdateMovement();
  void Report() const;

  // Add Draw when CRender is connected.
  // Add collision checking when the walls are connected.

private:
  void SetWheelSpeeds();

  float mX;
  float mY;
  float mHeading;
  ETurnState mTurnState;

  CWheel mLeftWheel;
  CWheel mRightWheel;

  CRangeSensor mRightSensor;
  CRangeSensor mForwardRightSensor;

  CWallFollowerController mController;
  CTrail mTrail;

  const float mTimeStep;
  const float mWheelSeparation;
};

// complete A1 simulation.
class CSimulation {
public:
  CSimulation();
  ~CSimulation();

  void Run();

private:
  void Update();
  void Draw();
  void PrintSummary() const;

  // The simulation will create and delete these supplied objects.
  CRender *mpRender;
  CLoopReader *mpWalls;

  CRobot mRobot;
  int mUpdateCount;
  int mCollisionCount;
  bool mFinished;
};

#endif

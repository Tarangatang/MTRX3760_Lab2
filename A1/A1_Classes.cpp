
#include "A1_Classes.h"

#include <cmath>
#include <iostream>

//---CWheel---

CWheel::CWheel() : mSpeed(0.0f) {}

void CWheel::SetSpeed(float aSpeed) { mSpeed = aSpeed; }

float CWheel::GetSpeed() const { return mSpeed; }

//---Empty classes for Jude to look at---

CRangeSensor::CRangeSensor() {}

CWallFollowerController::CWallFollowerController() {}

CTrail::CTrail() {}

//---CRobot---

CRobot::CRobot()
    : mX(150.0f), mY(140.0f), mHeading(1.5707963f),
      mTurnState(ETurnState::STOPPED), mLeftWheel(), mRightWheel(),
      mRightSensor(), mForwardRightSensor(), mController(), mTrail(),
      mTimeStep(0.05f), mWheelSeparation(30.0f) {}

void CRobot::SetTurnState(ETurnState aNewState) {
  mTurnState = aNewState;
  SetWheelSpeeds();
}

void CRobot::SetWheelSpeeds() {
  const float ForwardSpeed = 40.0f;
  const float TurningSpeed = 15.0f;

  if (mTurnState == ETurnState::STRAIGHT) {
    mLeftWheel.SetSpeed(ForwardSpeed);
    mRightWheel.SetSpeed(ForwardSpeed);
  } else if (mTurnState == ETurnState::TURN_LEFT) {
    mLeftWheel.SetSpeed(TurningSpeed);
    mRightWheel.SetSpeed(ForwardSpeed);
  } else if (mTurnState == ETurnState::TURN_RIGHT) {
    mLeftWheel.SetSpeed(ForwardSpeed);
    mRightWheel.SetSpeed(TurningSpeed);
  } else {
    mLeftWheel.SetSpeed(0.0f);
    mRightWheel.SetSpeed(0.0f);
  }
}

void CRobot::UpdateMovement() {
  const float LeftSpeed = mLeftWheel.GetSpeed();
  const float RightSpeed = mRightWheel.GetSpeed();
  const float ForwardSpeed = (LeftSpeed + RightSpeed) / 2.0f;
  const float TurnRate = (LeftSpeed - RightSpeed) / mWheelSeparation;

  mHeading += TurnRate * mTimeStep;
  mX += ForwardSpeed * std::cos(mHeading) * mTimeStep;
  mY += ForwardSpeed * std::sin(mHeading) * mTimeStep;
}

void CRobot::Report() const {
  std::cout << "Robot position: " << mX << ", " << mY << std::endl;
}

//---CSimulation---

CSimulation::CSimulation()
    : mpRender(NULL), mpWalls(NULL), mRobot(), mUpdateCount(0),
      mCollisionCount(0), mFinished(false) {
  // Create CRender and load SimpleWalls.map.
}

CSimulation::~CSimulation() {
  // Delete the supplied objects after their files are connected.
}

void CSimulation::Run() {
  if (mpRender == NULL || mpWalls == NULL) {
    std::cout << "Renderer and wall map are not connected yet." << std::endl;
  }

  while (!mFinished) {
    Update();
    Draw();

    // This temporary stop prevents an endless unfinished loop.
    if (mUpdateCount >= 20) {
      mFinished = true;
    }
  }

  PrintSummary();
}

void CSimulation::Update() {
  // Planned final order:
  // 1. Read both sensors.
  // 2. Ask the controller to choose a turn state.
  // 3. Update the robot movement.
  // 4. Check for a collision.
  // 5. Add the position to the trail.

  // Temporary state used only to test movement.
  mRobot.SetTurnState(CRobot::ETurnState::STRAIGHT);
  mRobot.UpdateMovement();
  ++mUpdateCount;
}

void CSimulation::Draw() {
  // Draw the walls, trail, robot and heading through CRender.
}

void CSimulation::PrintSummary() const {
  std::cout << "Updates: " << mUpdateCount << std::endl;
  std::cout << "Collisions: " << mCollisionCount << std::endl;
  mRobot.Report();
}

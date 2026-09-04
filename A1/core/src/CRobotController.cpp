/**
 * @file
 * @brief
 * @author
 */

 # include "CRobotController.hpp"

 CRobotController::CRobotController()
    :mLWheel(), mRWheel()
 {
    std::cout <<
        "Constructor: Robot Controller"
        << std:: endl;
 }

 CRobotController::~CRobotController()
 {
    std::cout <<
        "Destructor: Robot Controller"
        << std:: endl;
 }

 float CRobotController::GetRobotSize() const
 {
   return mRobotBack;
 } 

 void CRobotController::Report() const
 {
    mLWheel.Report();
    mRWheel.Report();
 }


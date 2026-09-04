/**
 * @file
 * @brief
 * @author
 */

 # include "CWallFollowerRobot.hpp"


 CWallFollowerRobot::CWallFollowerRobot()
 {
    std::cout << 
        "Constructor: Wall Follower"
        << std::endl;
 }

 CWallFollowerRobot::~CWallFollowerRobot()
 {
    std::cout << 
        "Destructor: Wall FOllower"
        << std::endl;
 }

 void CWallFollowerRobot::UpdateState()
 {
    mNSensor.Update();
    mNESensor.Update();

    // --- Control Logic Here ---
 }

 void CWallFollowerRobot::Report() const
 {
    mNESensor.Report();
    mNESensor.Report();

    
 }


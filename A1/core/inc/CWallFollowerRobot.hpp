/**
 * @file
 * @brief
 * @author
 */

 # ifndef CWALL_FOLLOWER_H
 # define CWALL_FOLLOWER_H
 
 # include "CRangeSensor.hpp"
 # include "CRobotController.hpp"
 # include "CWheel.hpp"

 /**
  * @brief
  */
 class CWallFollowerRobot : public CRobotController
 {
    public:
        CWallFollowerRobot();
        virtual ~CWallFollowerRobot();

        void UpdateState();
        void Report() const;

    private:
        CRangeSensor mNSensor;
        CRangeSensor mNESensor;
        
 };

 # endif
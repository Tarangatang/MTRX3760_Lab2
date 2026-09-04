/**
 * @file
 * @brief
 * @author
 */

 # ifndef CROBOT_CONTORLLER_H
 # define CROBOT_CONTORLLER_H
 
 # include "CWheel.hpp"
 # include "iostream"

 /**
  * @brief
  */
 class CRobotController
 {
    public:
        CRobotController();
        virtual ~CRobotController();

        virtual void UpdateState() = 0;
        void Report() const;
        float GetRobotSize() const;

    protected:
        CWheel mLWheel;
        CWheel mRWheel;

    private:
        float mRobotBack = 15.0;
        
 };

 # endif
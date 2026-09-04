/**
 * @file
 * @brief
 * @author
 */

 # ifndef CRANGESENSOR_H
 # define CRANGESENSOR_H

 # include "iostream"
 
 /**
  * @brief 
  */
 class CRangeSensor
 {
    public:
        CRangeSensor();
        ~CRangeSensor();

        float GetRange() const;
        void Update();
        void Report() const;
    private:
        float mRange_;
 };

 # endif
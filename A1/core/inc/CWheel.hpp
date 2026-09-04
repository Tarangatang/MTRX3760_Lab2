/**
 * @file
 * @brief
 * @author
 */

 # ifndef CWHEEL_H
 # define CWHEEL_H

 # include <iostream>

 /**
  * @brief 
  */
 class CWheel
 {
    public:
        CWheel();
        ~CWheel();

        void SetSpeed(float aSpeed);
        float GetSpeed() const;
        void Report() const;

    private:
        float mSpeed;
 };

 #endif

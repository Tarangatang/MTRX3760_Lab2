/**
 * @file
 * @brief
 * @author
 */

 # include "CWheel.hpp"

 CWheel::CWheel()
    :mSpeed(0.0)
 {
    std::cout << 
        "Constructor: Wheel"
        << std::endl;
 }

 CWheel::~CWheel()
 {
    std::cout << 
        "Destructor: Wheel"
        << std::endl;
 }

 void CWheel::SetSpeed(float aSpeed)
 {
    if (aSpeed < -100.0 || aSpeed > 100.0)
    {   
        mSpeed = 0.0;
        std::cout <<
            "Invalid Speed Input"
            << std::endl;
        return;
    }

    mSpeed = aSpeed;
 }

 float CWheel::GetSpeed() const
 {
    return mSpeed;
 }

 void CWheel::Report() const
 {
    std::cout <<
        "Speed at " << mSpeed 
        << std::endl;
 }
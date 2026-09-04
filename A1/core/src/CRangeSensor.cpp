/**
 * @file
 * @brief
 * @author
 */

 # include "CRangeSensor.hpp"

 CRangeSensor::CRangeSensor()
    :mRange_(0.0)
 {
    std::cout <<
        "Constructor: Range Sensor." 
      << std::endl;
 }

 CRangeSensor::~CRangeSensor()
 {
    std::cout <<
        "Destructor: Range Sensor." 
      << std::endl;
 }

 float CRangeSensor::GetRange() const
 {
    return mRange_;
 }

 void CRangeSensor::Update()
 {

 }

 void CRangeSensor::Report() const
 {
   std::cout <<
      "Distance at " << mRange_
      << std::endl;
 }
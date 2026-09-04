/**
 * @file
 * @brief
 * @author
 */

 # include "CSimulator.hpp"
 # include <iostream>

 int main ()
 {
   std::string SimMap = "SimpleWalls.map";

   CSimulator* wallSim = new CSimulator(SimMap);

   delete wallSim;

   return 0;
 }
/**
 * @file
 * @brief
 * @author
 */

 # ifndef SIMULATOR_H
 # define SIMULATOR_H

 # include "CLoopReader.hpp"
 # include "CRender.hpp"
 # include "CRobotController.hpp"
 # include "CWallFollowerRobot.hpp"

 # include <iostream>
 # include <vector>

 class CSimulator
 {
    public:
        CSimulator(std::string aMapName);
        ~CSimulator();
    
        void Run();

    private:
        void Update();
        void DrawLoop();
        void PrintSummary() const;

        CRender* mpRender;
        CLoopReader* mpReader;
        CRobotController* mpRobot;

        int mUpdateCount;
        int mCollisionCount;
        bool mFinished;
 };

 # endif
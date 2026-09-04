/**
 * @file
 * @brief
 * @author
 */

 # include "CSimulator.hpp"
#include <cmath>

 CSimulator::CSimulator(std::string aMapFile)
    :mpRender(new CRender), 
    mpReader(new CLoopReader),
    mpRobot(new CWallFollowerRobot),
    mUpdateCount(0), mCollisionCount(0), mFinished(false)
 {
    std::cout <<
        "Constructor: Simulator."
        << std::endl;

	// Read and make map and robot
    bool ReadSuccess = mpReader->ReadFile( aMapFile );
    std::cout << "Read " << (ReadSuccess ? "successful":"unsuccessful") << std::endl;

    while( !mpRender->WindowShouldClose() )
    {
        mpRender->BeginDrawing();
        DrawLoop();

		Vec2D position = mpReader->GetStartPose().mPosition;
		float heading = mpReader->GetStartPose().mHeading;
		float robot_radius = mpRobot->GetRobotSize();
		Vec2D face = 
		{
			position.x + std::cos(heading) * robot_radius,
			position.y + std::sin(heading) * robot_radius
		};

		mpRender->DrawCircle(position, robot_radius, BLUE);
		mpRender->DrawLine(position, face, 2.0, RED);
        mpRender->EndDrawing();
    }	

	// Make robot
 }

 CSimulator::~CSimulator()
 {
    std::cout <<
        "Destructor: Simulator."
        << std::endl;
 }

 void CSimulator::Run()
 {
	while( !mpRender->WindowShouldClose() )
    {
        mpRender->BeginDrawing();
        DrawLoop();

		Vec2D position = mpReader->GetStartPose().mPosition;
		float heading = mpReader->GetStartPose().mHeading;
		float robot_radius = mpRobot->GetRobotSize();
		Vec2D face = 
		{
			position.x + std::cos(heading) * robot_radius,
			position.y + std::sin(heading) * robot_radius
		};

		mpRender->DrawCircle(position, robot_radius, BLUE);
		mpRender->DrawLine(position, face, 2.0, RED);
        mpRender->EndDrawing();
    }	
	
    while (!mFinished)
    {
        /* code */
        Update();
        ++mUpdateCount;
    }

    PrintSummary();
 }

 void CSimulator::Update()
 {
    mpRobot->UpdateState();

    // --- Check if back in Starting pose ---

    // --- Check if Collision ---
 }

 void CSimulator::DrawLoop()
 {
   const float EdgeThickness = 2.0f;

   const std::vector<Vec2D>& Vertices = mpReader->GetVertices();
   if( !Vertices.empty() )
   {
      // Start from the last vertex so the first edge drawn closes the loop.
      Vec2D Previous = Vertices.back();
      for( const Vec2D& Vertex : Vertices )
      {
         mpRender->DrawLine( Previous, Vertex, EdgeThickness, RAYWHITE );
         Previous = Vertex;
      }
   }
 }

 void CSimulator::PrintSummary() const
 {
    std::cout << "Updates: " << mUpdateCount << std::endl;
    std::cout << "Collisions: " << mCollisionCount << std::endl;
    mpRobot->Report();
 }



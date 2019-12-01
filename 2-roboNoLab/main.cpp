#include "TestMaze.h"
#include "Texture.h"
#include "RobotB9.h"
#include "GL.h"
#include "RobotRobby.h"
#include "PerfectMaze.h"

using namespace std;

int main()
{
    GL::init();
    // Load the test maze
    PerfectMaze* lab = new PerfectMaze();
    lab->loadMaze("maze1.txt");

    Point posIni = lab->getIniPos();
    cout << "Starting pos: " << posIni.getX() << " , " << posIni.getY() << endl;
    RobotRobby* robo = new RobotRobby(posIni, lab, 200); // 200 passos no maximo

    GL::setMazeRobot(lab, robo);

	GL::loop();
}

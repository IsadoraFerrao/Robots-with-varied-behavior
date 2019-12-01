#include "TestMaze.h"
#include "RobotB9.h"
#include "GL.h"
#include "RobotRobby.h"

using namespace std;

int main()
{
    GL::init();
    // Load the test maze
    Maze* lab = new TestMaze();
    lab->loadMaze("maze1.txt");

    Point posIni = lab->getIniPos();
    cout << "Starting pos: " << posIni.getX() << " , " << posIni.getY() << endl;
    RobotRobby* robo = new RobotRobby(posIni, lab, 200); // 200 passos no maximo

    GL::setMazeRobot(lab, robo);

	GL::loop();
}

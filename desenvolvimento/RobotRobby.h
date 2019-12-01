#ifndef ROBOTROBBY_H
#define ROBOTROBBY_H

#include "Maze.h"
#include "Robot.h"
#include "Texture.h"

using namespace std;

class RobotRobby: public Robot{
  public:
    RobotRobby(const Point& iniPos, Maze*l, int maxSteps);
    void draw();
    void generateSteps();
    vector<Point> getSteps();
  private:
    TEX* roboTex;
};

#endif

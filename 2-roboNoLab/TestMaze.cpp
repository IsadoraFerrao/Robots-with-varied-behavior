#include "TestMaze.h"
#include <iostream>

TestMaze :: TestMaze() {
}

// Should load the maze from a text file
// Here is just creates boundaries with an exit at the bottom
void TestMaze :: loadMaze(string arquivo) {
    dimx = 20; dimy = 20;
    for(int i=0; i<dimy; i++)
        for(int j=0; j<dimx; j++)
            lab[i][j] = ' ';
    for(int i=0; i<dimx; i++)
    {
        lab[0][i] = '*';
        lab[dimy-1][i] = '*';
        lab[i][0] = '*';
        lab[i][dimx-1] = '*';
    }
    lab[dimy-2][dimx-1] = ' '; // exit
    lab[2][1] = '*';
    lab[2][2] = '*';
    lab[3][2] = '*';
    robot = 1;
    posIni = Point(1,1);


}

// Returns true if the x,y pos is empty
bool TestMaze :: isEmpty(const Point& pos) const {
    if(pos.getX()<0 || pos.getX()>=dimx
                    || pos.getY()<0 || pos.getY()>=dimy) return true;
    return (lab[pos.getY()][pos.getX()]==' ');
}

// Return the maze dimensions
int TestMaze :: getWidth() { return dimx; }
int TestMaze :: getHeight() { return dimy; }
int TestMaze::getRobot() { return robot; }
Point TestMaze::getIniPos() { return posIni; }

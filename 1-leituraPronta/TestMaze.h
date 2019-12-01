#ifndef TESTMAZE_H
#define TESTMAZE_H

#include <fstream>
#include "Maze.h"
#include "Point.h"

class TestMaze : public Maze {
	public:
		TestMaze();	// Constructor
        bool isEmpty(const Point& ponto) const;
	    int  getWidth();
	    int  getHeight();
	    void loadMaze(std::string arquivo);
        int  getRobot();
        Point getIniPos();
	private:
		int dimx, dimy;		// Maze size
        char lab[100][100];	// The maze
        int robot;
        Point posIni;
};

#endif

#include "RobotB9.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

RobotB9::RobotB9(const Point& iniPos, Maze*l, int maxSteps)
    : Robot(iniPos, l, maxSteps) //Chama o construtor da classe pai
{
    srand(time(NULL));
    roboTex = LoadTexture("b9.jpg", false); // Carrega a textura do robô
}

void RobotB9::generateSteps() // Gera os passos aleatórios
{
    int cont = 1; // Número de passos
    bool saiu = false; // Bool para saber se saiu do labirinto
    int x = iniPos.getX(); // Pega a posição inicial x
    int y = iniPos.getY(); // Pega a posição inicial y
    steps.push_back(Point(x,y)); // Adiciona a posição inicial no vector de posições percorridas
    while(!saiu && cont < maxSteps) // Enquanto não saiu do labirinto e não ultrapassou o número máximo de passos
    {
        int dx, dy;
        do {
            int dir = rand()%4; // Escolhe uma posição aleatória
            dx = 0;
            dy = 0;
            switch(dir) {
                case 0:	dx = 1;
                    break;
                case 1:	dx = -1;
                    break;
                case 2:	dy = 1;
                    break;
                case 3: dy = -1;
                    break;
            }
        }
        while(!maze->isEmpty(Point(x+dx, y+dy)));
        x += dx;
        y += dy;
        steps.push_back(Point(x, y));
        cont++;
        if(x >= maze->getWidth() || x < 0
                || y >= maze->getHeight() || y < 0)
            saiu = true;
    }
}

void RobotB9::draw()
{
    float rx,ry;
    float deltax = GL::getDeltaX();
    float deltay = GL::getDeltaY();
    rx = pos.getX() * deltax;
    ry = pos.getY() * deltay;
    GL::enableTexture(roboTex->texid);
    GL::setColor(255,255,255);
    GL::drawRect(rx, ry, rx+deltax, ry+deltay);
    GL::disableTexture();
}

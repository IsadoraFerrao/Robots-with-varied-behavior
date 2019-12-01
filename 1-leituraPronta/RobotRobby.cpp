#include "RobotRobby.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;


RobotRobby::RobotRobby(const Point& iniPos, Maze*l, int maxSteps): Robot(iniPos, l, maxSteps){
  roboTex = LoadTexture("atlas.jpg", false);
}

void RobotRobby::draw(){
  float rx, ry;
  float deltax = GL::getDeltaX();
  float deltay = GL::getDeltaY();
  rx = pos.getX() * deltax;
  ry = pos.getY() * deltay;
  GL::enableTexture(roboTex->texid);
  GL::setColor(0,255,100);
  GL::drawRect(rx, ry, rx+deltax, ry+deltay);
  GL::disableTexture();
}

void RobotRobby::generateSteps(){
  int cont = 1; // Número de passos
  bool saiu = false;// Bool para saber se saiu do labirinto
  int x = iniPos.getX(); // Pega a coordenada x da posição inicial
  int y = iniPos.getY(); // Pega a coordenada y da posição inicial
  steps.push_back(Point(x,y)); // Adiciona posição atual no vetor de passos
  int dx = 1; // Deslocamento em x e deslocamento em y
  int dy = 0;
  while(!saiu && cont < maxSteps)
  // Enquanto não saiu do labirinto e nem ultrapassou o número máximo de passos
  {
    while(maze->isEmpty(Point(x+dx, y+dy)) && cont < maxSteps){
      // Enquanto o ponto a frente do robo é espaço vazio executa
      x += dx; // Incrementa a posição x pelo movimento no eixo x
      y += dy; // Incrementa a posição y pelo movimento no eixo y
      steps.push_back(Point(x,y)); // Adiciona a nova posição no vector de passos
      cont++; // Incrementa o número de passos dados

      // Se a posição atual está nas bordas do labirinto (Onde fica a saída) ou
      // está fora do labirinto, o robô saiu. Muda a bool saiu para true.
      if(x >= maze->getWidth() || x < 0 || y >= maze->getHeight() || y < 0)
        saiu = true;
    }
    // Aqui o robô encontrou uma posição bloqueada a sua frente.
    // Agora ele precisa virar para a direita, para isso checamos em qual direção
    // ele andou pela última vez. Se ele andou pela última vez para a direita, a sua direita
    // agora é pra baixo, etc.
    // dx = 1 ; anda pra direita
    // dx = -1 ; anda pra esquerda
    // dy = 1; anda pra baixo
    // dy = -1; anda pra cima

    // IMPORTANTE: Nunca dar um valor diferente de 0 para ambos dx e dy,
    // pois o robô não pode se mover na diagonal.

    if(dx == 1) { // Se andou para a direita na última
      // Agora vai pra baixo (direita da pos atual)
      dx = 0;
      dy = 1;
    } else if(dx == -1){ // Se andou para a esquerda na ultima
      // Agora vai pra cima (direita da pos atual)
      dx = 0;
      dy = -1;
    } else if(dy == 1){ // Se andou para baixo na última
      // Agora vai para a esquerda (direita da pos atual)
      dx = -1;
      dy = 0;
    } else if(dy == -1){ // Se andou para cima na última
      // Agora anda para a direita (direita da posição atual)
      dx = 1;
      dy = 0;
    }
  }
}


vector<Point> RobotRobby::getSteps(){
  return steps;
}

#ifndef PERFECTMAZE_H
#define PERFECTMAZE_H

/* A classe PerfectMaze foi criada tendo como base a classe TestMaze do thielo. So mudei algumas coisinhas */

#include "Maze.h"
#include "Point.h"
/*

incluir o Maze.h e o Point.h

*/
#include <iostream>
#include <fstream>
/* o public depois dos ":" serve para dizer o nivel da relação. deixei publico pq o thielo tbm deixou
na classe TestMaze, porem acho melhor deixar privado*/
class PerfectMaze : public Maze // os ":" serve para dizer que a classe PerfectMaze é filha da classe Maze
{
  private:
    int dimX, dimY;// X = coluna, Y = linha ---->> tomar cuidado *
    /* *---->> o arquivo le primeiro a variavel y (linhas) e depois a variavel x (colunas) */
    char **lab; /* o thielo deixou fixo o tamanho na classe TestMaze. Achei que dinamico seria melhor.  */
    int robot; //tipo do robo
    Point posIni; //posicao inicial do robo no labirinto
  public:
    PerfectMaze (); //construtor padrão
    ~PerfectMaze (); //destrutor padrão <------- importante (explicado no arquivo PerfectMaze.cpp)
    /* AQUI */
    bool isEmpty(const Point& ponto) const;
    int  getWidth();
    int  getHeight();
    void loadMaze(std::string arquivo);
    int  getRobot();
    Point getIniPos();
    /* ATE AQUI feito pelo thielo. so mudei as variaveis dimX e dimY para deixar em um padrão
    (antes o x e o y estavam em minusculo) */
    void printMaze (); //feita por mim para mostrar no terminal o estado do labirinto lido do arquivo
};

#endif

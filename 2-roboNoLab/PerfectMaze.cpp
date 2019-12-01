#include "Maze.h"
#include "PerfectMaze.h"

#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

PerfectMaze::PerfectMaze () {} //construtor padrão sem nada implementado

PerfectMaze::~PerfectMaze () //destrutor padrão <---- IMPORTANTE
{
  /* COMO A MATRIZ DO LABIRINTO NÃO É MAIS ESTATICA E SIM DINAMICA, TIVE QUE ALOCAR MEMORIA USANDO new
  POR ESTE MOTIVO, PARA DESTRUIRMOS A MATRIZ TEMOS QUE UTILIZAR O DESTRUTOR PADRÃO CHAMADO QUANDO O
  OBJETO NÃO É MAIS NECESSARIO*/
  for(int i = 0; i < this->dimY; i++)//o destrutor padrão começa limpando a memoria de cada linha da matriz
  {
    delete[] lab[i];
  }
  delete[] lab;// e por ultimo, limpa o ponteiro
}

void PerfectMaze::loadMaze (string arquivo)//funcao para carregar o labirinto de um arquivo
{
  string ignore; //criei essa string para ignorar coisas inuteis do arquivo
  string line; //esta string ira pegar cada linha do labirinto
  int x; //um inteiro para guardar a coluna em que o robo começa
  int y; //guarda a linha em que o robo começa
  ifstream iFile; //objeto para ler o arquivo
  iFile.open (arquivo.c_str()); //nas versoes mais recentes o "c_str()" n é obrigatorio, porem o thielo quer na versao 98

  iFile >> ignore; //ignora a palavra dim
  iFile >> this->dimY; //guarda o numero de linhas
  iFile >> this->dimX; //guarda o numero de colunas
  iFile >> ignore; //ignora a palavra pos
  iFile >> x; //guarda a coluna do robo
  iFile >> y; //guarda a linha do robo
  this->posIni = Point (x, y); // guarda as coordenadas do robo por meio do construtor da classe Point
  /*A classe Point foi implementada pelo thielo*/
  iFile >> ignore; //ignora a palavra robo
  iFile >> this->robot; //guarda o tipo do robo deste labirinto

  lab = new char* [this->dimY]; // aloca memoria para a quantidade de linhas da matriz
  for (int row = 0; row < this->dimY; row++)
  {
    lab[row] = new char [this->dimX];//aloca memoria para cada coluna e o seu tamanho na matriz
  }
// /*
  getline (iFile, ignore);//ignora o espaço vazio e o \n depois do tipo do robo
  for (int i = 0; i < dimY; i++)
  {
    getline (iFile, line);// guarda a proxima linha depois das informações ja obtidas
    for (int j = 0; j < dimX; j++)
    {
      lab [i][j] = line[j]; // para cada caracter da string linha, guarda na matriz 
    }
  }
}
/*FEITO PELO THIELO DAQUI*/
bool PerfectMaze::isEmpty (const Point& pos) const
{
    if(pos.getX()<0 || pos.getX()>=dimX || pos.getY()<0 || pos.getY()>=dimY) return true;
    return (lab[pos.getY()][pos.getX()]==' ');
}
  // Return the maze dimensions
int PerfectMaze :: getWidth() { return dimX; }
int PerfectMaze :: getHeight() { return dimY; }
int PerfectMaze::getRobot() { return robot; }
Point PerfectMaze::getIniPos() { return posIni; }
/* ATE AQUI */
void PerfectMaze::printMaze ()
{
  /*FUNCAO PARA MOSTRAR CADA CELULA DA MATRIZ NO TERMINAL*/
  for (int i = 0; i < this->dimY; i++)//dimY (numero de linhas)
  {
    for (int j = 0; j < this->dimX; j++)//dimX (numero de colunas)
    {
      cout << lab[i][j] << " ";
    }
    cout << endl;
  }
}

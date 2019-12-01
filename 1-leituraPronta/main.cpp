#include "TestMaze.h"
#include "RobotB9.h"
#include "GL.h"
#include "RobotRobby.h"
#include <cstdlib>

/*
comentei as linhas para fazer os testes so com a classe PerfectMaze, para testar se a leitura estava certa
*/
#include "PerfectMaze.h"
/*

inclui o .h para poder usar na main. deixei com ".h" em vez de ".hpp" para evitar conflitos com as classes
ja implementadas do thielo

*/

using namespace std;

int main(int argc, char *argv[])
{

    GL::init();
    // Load the test maze
    PerfectMaze* lab = new PerfectMaze();
    lab->loadMaze(argv[1]);

    Point posIni = lab->getIniPos();
    cout << "Starting pos: " << posIni.getX() << " , " << posIni.getY() << endl;
    Robot* robo;

    if (lab->getRobot() == 1){
        robo = new RobotB9(posIni, lab, atoi(argv[2]));
    } else if (lab->getRobot() == 2){
        robo = new RobotRobby(posIni, lab, atoi(argv[2]));
    }
    // else if (lab->getRobot() == 3){
    //    Robot* robo = new RobotArTur(posIni, lab, atoi(argv[2]));
    // }
    else {
      cout << "Usando robô padrão (aleatório)" << endl;
      robo = new RobotB9(posIni, lab, atoi(argv[2]));
    }

    // Robot* robo = new RobotB9(posIni, lab, atoi(argv[2])); // 200 passos no maximo

    GL::setMazeRobot(lab, robo);
	  GL::loop();

  /*
  PerfectMaze *lab = new PerfectMaze (); //instancia do objeto com um construtor padrão sem nada de especial
  lab->loadMaze ("maze1.txt"); //como é somente um teste, deixei estatico o nome do arquivo
  lab->printMaze(); //fiz uma função para mostrar na saida padrão o resultado da leitura do arquivo
  return 0;
  */
}

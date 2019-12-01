//labirinto.cpp
/*
Antônio de Freitas Valle Neto 1602020029
Guilherme Neri Bustamante Sá  161150744

o labirinto foi feito usando a logica da arvore minima geradora para percorrer a matriz d vertices atraves da matriz de arestas, 
porem em vez de uma arvore, foi utilizado um vector como pilha
a principal condição para cavar a matriz é que a posição a ser cavada tenha no minimo 3 paredes como adjacentes
valores menores que 0 representam espaços em branco na matriz
valores iguais a 0 representam espaços que n podem ser vazios
valores maiores que 0 representam paredes
*/

#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>

using std::setw;
using namespace std;



int main(void)
{
	srand((unsigned)time(0)); // gera numeros aleatorios
	vector <vector <int> > matriz_vertices;//matriz de vertices com tamanho ::vert
	vector <vector <int> > matriz_arestas;//matriz de arestas com tamanho ::ares
	vector <int> b;//um vector para popular as matrizes
	vector <int> pilha;//vector pilha para guardar os caminho ja visitado
	vector <int> lista_prioridade;//lista de prioridades
	int inicio = 0, fim = 0;//valor de inicio e de fim do labirinto (onde comeca e onde termina)
    //---------------------------------------------
	int modulo_aux = 0;
	int modulo_valor_atual = 0;
	//como uma matriz n tem numeros negativos, utilizei o modulo dos valores e coloquei nessas duas variaveis
	//-------------------------------------------
	unsigned char barra = 179, tr = 45, fundo = 177, fundo2 = 178, fundo3 = 176, base = 196, espaco = 32;
	int k = 0;
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int termina = 0;
	int flag = 1;
	int o = 0;
	int vert = 0;
	int ares = 0;
	int saida = 0;
	int valor_atual = 0;
	int sai = 0;
	int fica = 0;
	int u = 1;
	int tamanho = 0;
	int menor = 11;
	int aux = 0;


	cout << "de o tamanho da matriz: ";//pede o tamanho da matriz quadrada
	cin >> vert;//entra com o tamanho da matriz de vertices
	ares = vert * vert;//como a matriz de arestas é de vertice para vertice, a variavel ares tem o valor quadrado da variavel vert


	for (int k = 0; k < vert; k++)//cria a matriz de vertices
	{
		matriz_vertices.push_back(b);//puxa o vector b para criar a matriz
	}


	for (int k = 0; k < ares; k++)//cria a matriz de arestas
	{
		matriz_arestas.push_back(b);//puxa a vector b para criar a matriz
	}

	for (int k = 0; k < vert; k++)//da valores para a matriz de vertices para manipular mais tarde
	{
		for (int t = 0; t < vert; t++)
		{
			matriz_vertices[k].push_back(i + 1);//os valores comecam com 1 e vão ate o numero vert
			i++;
		}
	}


	for (int k = 0; k < ares; k++)//da valores 0 para a matriz de arestas
	{
		for (int t = 0; t < ares; t++)
		{
			matriz_arestas[k].push_back(0);//todos os valores da matriz de arestas começam com zero para q a matriz tenha forma a partir desta posição do algoritmo
		}
	}


	cout << endl;


	for (i = 0; i < ares; i++)//limpa a lista de prioridades
	{
		lista_prioridade.push_back(0);// a lista de prioridades ganha forma com o tamanho da variavel ares
	}


	while (flag == 1)//faz as adjacencias entre os nodos da matriz de vertices na matriz de arestas. as adjacencias são feitas para baixo e para a direita
	{
		for (i = 0; i < vert; i++)
		{
			if ((i < vert - 1) && (o < ares - vert))// para numeros entre a primeira linha e a penultima sem considerar a ultima coluna d cada linha
			{
				k = rand() % 9 + 1;
				x = o + i;
				y = x + 1;
				matriz_arestas[x][y] = k;
				matriz_arestas[y][x] = k;
				k = rand() % 9 + 1;
				y = x + vert;
				matriz_arestas[x][y] = k;
				matriz_arestas[y][x] = k;
			}
			else if ((i == vert - 1) && (o < ares - vert))// ultima coluna da primeira linha ate a penultima coluna
			{
				k = rand() % 9 + 1;
				x = o + i;
				y = x + vert;
				matriz_arestas[x][y] = k;
				matriz_arestas[y][x] = k;
			}
			else if ((i < vert - 1) && (o >= ares - vert) && (o < ares - 1))// ultima linha
			{
				k = rand() % 9 + 1;
				x = o + i;
				y = x + 1;
				matriz_arestas[x][y] = k;
				matriz_arestas[y][x] = k;
			}
			else if (o + i == ares - 1)// sai do while
			{
				flag = 0;
			}
		}
		o = o + i;// a variavel o eh aquela que guarda o valor da matriz ja visitada
	}

	for (i = 2; i < vert-2; i = i + 2)//algumas partes da matriz nao podem ser cavadas e por isso recebem o valor 0
	{
		for (j = 2; j < vert-2; j = j + 2)
			matriz_vertices[i][j] = 0;
	}
	

	for (int k = 0; k < vert; k++)//mostra a matriz de vertices
	{
		for (int t = 0; t < vert; t++)
		{
			cout << matriz_vertices[k][t] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	

	while (saida == 0)//pede o valor de inicio do labirinto e testa para aceita-los ou n
	{
		cout << "de o valor de inicio: ";
		cin >> inicio;
		if ((inicio != matriz_vertices[0][0]) && (inicio != matriz_vertices[0][vert - 1]) && (inicio != matriz_vertices[vert - 1][0]) && (inicio != matriz_vertices[vert - 1][vert - 1]))
		{
			for (int i = 0; i < vert; i++)
			{
				if ((inicio == matriz_vertices[0][i]) || (inicio == matriz_vertices[i][0]) || (inicio == matriz_vertices[vert - 1][i]) || (inicio == matriz_vertices[i][vert - 1]))
				{
					saida = 1;
				}
			}
		}
	}
	saida = 0;


	while (saida == 0)//pede o valor de fim do labirinto e testa para aceita-los eu n
	{
		cout << "de o valor de fim: ";
		cin >> fim;
		if ((fim != matriz_vertices[0][0]) && (fim != matriz_vertices[0][vert - 1]) && (fim != matriz_vertices[vert - 1][0]) && (fim != matriz_vertices[vert - 1][vert - 1]))
		{
			for (int i = 0; i < vert; i++)
			{
				if ((fim == matriz_vertices[0][i]) || (fim == matriz_vertices[i][0]) || (fim == matriz_vertices[vert - 1][i]) || (fim == matriz_vertices[i][vert - 1]))
				{
					saida = 1;
				}
			}
		}
	}

	pilha.push_back(inicio);// puxa o inicio para a "pilha"
	/*a pilha serve para saber o caminho feito ate agora e para voltar por ele para queum novo caminho seja feito quando o ultimo chega ao fim*/

	for (int i = 0; i < vert; i++)//comeca a escavar o labirinto pela posição de inicio... quando uma posição é cavada ela recebe um valor negativo
	{
		for (int j = 0; j < vert; j++)
		{
			if (matriz_vertices[i][j] == inicio)
			{
				matriz_vertices[i][j] = -1* matriz_vertices[i][j];
				valor_atual = matriz_vertices[i][j];// o valor da variavel valor_atual recebe o valor de inicio para então começar a cavar o labirinto
			}
		}
	}


	for (int i = 0; i < ares; i++)//destroi as arestas que ligam os outros vertices ao vertice de inicio
	{
		matriz_arestas[i][inicio - 1] = 0;
	}

	while (u > 0 || tamanho == 1)// se o numero de arestas for 0 o while para
	{
		for (int k = 0; k < vert; k++)//mostra a matriz em forma de labirinto
		{
			for (int t = 0; t < vert; t++)
			{
				if (matriz_vertices[k][t] < 0)
					cout << ' ' << ' ';
				else 	cout << fundo << fundo;

			}
			cout << endl;
		}
		cout << endl;
		
	
		sai = 0;
		fica = 0;
		while (sai < 3)
		{
			sai = 0;
			fica = 0;
			while (1)//testa ate encontrar uma posição para cavar
			{
				for (i = 0; i < ares; i++)//limpa a lista de prioridades
				{
					lista_prioridade[i] = 0;
				}
				if (valor_atual < 0)// o modulo_valor atual vai receber o modulo do valor atual, pois as matrizes n tem posição negativa
					modulo_valor_atual = valor_atual * -1;
				else modulo_valor_atual = valor_atual;

				lista_prioridade = matriz_arestas[(modulo_valor_atual) - 1];//a lista d prioridades vai guardar os caminho do valor atual para os outros vertices

				aux = 0;//limpa o aux
				menor = 11;// comeca com o maior valor possivel
				for (i = 0; i < ares; i++)// acha o menor valor maior que 0 na lista de prioridades e guarda o vertice na variavel aux
				{
					if ((menor >= lista_prioridade[i]) && (lista_prioridade[i] > 0))
					{
						menor = lista_prioridade[i];
						aux = i + 1;
					}
				}
				if (menor > 10)// se o caminho estiver no fim... volta um e faz d novo
				{
					tamanho = 0;
					pilha.pop_back();
					tamanho = pilha.size();
					valor_atual = pilha[tamanho - 1];
					if (tamanho == 1)// se o tamanho da pilha é igual a 1, então o labirinto voltou para o inicio e as condições para a saida de todos os whiles são cumpridas
					{
						termina = valor_atual;
						sai = 4;
						u = 0;
						break;
					}
				}
				else break;
			}
			if (aux == fim)//se o caminho estiver na posição final do labirinto... volta um e faz d novo
			{
				sai = 4;
				tamanho = 0;
				pilha.pop_back();
				tamanho = pilha.size();
				valor_atual = pilha[tamanho - 1];
			}

			


			for (int k = 0; k < vert; k++)//testa as condições para cavar
			{
				for (int p = 0; p < vert; p++)
				{
					if (termina == inicio)// se o programa voltou para o inicio, tão o algoritmo sai de todos os whiles
					{
						k = vert;
						p = ares;
						u = 0;
						sai = 4;
						break;
					}
					else if (aux == 0)//se a proxima posição tem valor zero, então a condição para parar o while que escolhe a proxima posição n é cumprida e por isso um novo aux é achado
						sai = 0;
					else if (matriz_vertices[k][p] == aux)//acha a proxima posição na matriz
					{
						if ((k != 0) && (k != vert - 1))//testa para os valores das bordas
						{
							if ((p != 0) && (p != vert - 1))//testa para os valores das bordas
							{
								/*o programa so ira cavar a proxima posição se esta tiver no minimo 3 parades como posições adjacentes*/
								if (matriz_vertices[k + 1][p] >= 0)
									sai++;
								if (matriz_vertices[k - 1][p] >= 0)
									sai++;
								if (matriz_vertices[k][p + 1] >= 0)
									sai++;
								if (matriz_vertices[k][p - 1] >= 0)
									sai++;
							}
						}
					}
				}
			}
			if (aux < 0)//modulo do aux
				modulo_aux = aux * -1;
			else modulo_aux = aux;
			if (termina != inicio)//testa para saber se o labirinto não voltou para a posição de inicio
			{
				if (valor_atual < 0)// modulo do valor atual
					modulo_valor_atual = valor_atual * -1;
				else modulo_valor_atual = valor_atual;

				matriz_arestas[modulo_valor_atual - 1][modulo_aux - 1] = 0;//corta a adjacencia entre o valor atual e o proximo valor 
			}
		}
		if (aux < 0)//modulo do aux
			modulo_aux = aux * -1;
		else modulo_aux = aux;
		if (termina != inicio)
		{
			if (valor_atual < 0)
				modulo_valor_atual = valor_atual * -1;
			else modulo_valor_atual = valor_atual;

			matriz_arestas[modulo_aux - 1][modulo_valor_atual - 1] = 0;//elimina a aresta de aux em valor atual
			matriz_arestas[modulo_valor_atual - 1][modulo_aux - 1] = 0;//elimina a aresta de valor atual em aux
			pilha.push_back(aux*-1);//puxa aux para a pilha
		}
		for (int i = 0; i < vert; i++)//cava o aux na matriz de vertices
		{
			for (int j = 0; j < vert; j++)
			{
				if (matriz_vertices[i][j] == aux)
					if (matriz_vertices[i][j] > 0)
					{
						matriz_vertices[i][j] = -1 * matriz_vertices[i][j];
					}
			}
		}
		if (valor_atual < 0)//modulo do valor atual
			modulo_valor_atual = valor_atual * -1;
		else modulo_valor_atual = valor_atual;

		for (int i = 0; i < ares; i++)//elimina as arestas d i em valor atual
		{
			matriz_arestas[i][modulo_valor_atual - 1] = 0;
		}
		valor_atual = aux;// novo valor atual
		if (u == 0)
		{
			break;
		}
		u = 0;

		for (int i = 0; i < ares; i++)// testa quantas arestas ainda existem
		{
			for (int j = 0; j < ares; j++)
			{
				if (matriz_arestas[i][j] > 0)
					u++;

			}
		}

	}
	for (int k = 0; k < vert; k++)//mostra a matriz em forma de labirinto
	{
		for (int t = 0; t < vert; t++)
		{
			if (matriz_vertices[k][t] < 0)
				cout << ' ' << ' ';
			else 	cout << fundo << fundo;

		}
		cout << endl;
	}
	
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <cstdlib> //rand() srand()
#include <cmath>
#include <ctime>   //time() para seed de numeros aleatorios

void imprimir_matriz(int matriz[16][16])
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			printf("%d | ", matriz[i][j]);
		}
		printf("\n"); //imprimir a matriz em formato 16x16
	}
	printf("\n"); //pula linha
}

void imprimir_vetor(int vetor[10], int param)
{
	for (int j = 0; j < param; j++)
	{
		printf("%d | ", vetor[j]);
	}
	printf("\n"); //pula linha
}

void matriz_indice(int param, int v_param[10], int m_inicio[16][16], int m_indice[16][16])
{
	int indice_k = 0;
	for (int i = 0; i < 16; i++)
	{
		int dist_min = 101; //variavel local para armazenar o valor de distancia minima (começa em 101 devido à distancia maxima de 100)
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < param; k++)
			{
				if (dist_min >= std::abs(m_inicio[i][j] - v_param[k]))
				{
					dist_min = std::abs(m_inicio[i][j] - v_param[k]);
					indice_k = k; //guarda o indice do parametro cuja distancia é a menor em relação à posição da matriz
				}
			}
			m_indice[i][j] = indice_k;
		}
	}
}

void simplificar_matriz(int param, int v_param[10], int m_indice[16][16], int m_fim[16][16])
{
	int indice_k;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			indice_k = m_indice[i][j];
			m_fim[i][j] = v_param[indice_k];
		}
	}
}

void novoCentro(int m_indice[16][16], int m_inicio[16][16], int param, int v_newParam[10])
	{
	int v_contador[10];
	int parametro = 0;
	//inicializando os vetores:
	for (int k = 0; k < param; k++)
	{
		v_newParam[k] = 0;
		v_contador[k] = 0;
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			parametro = m_indice[i][j];
			v_newParam[parametro] += m_inicio[i][j];
			v_contador[parametro]++;
		}
	}

	for (int k = 0; k < param; k++)
	{
		if (v_contador[k] != 0)
		{
			v_newParam[k] = v_newParam[k] / v_contador[k];
		}
	}
}

void distancia_m(int param, int v_param[10], int v_newParam[10], int* melhora)
{
	for (int k = 0; k < param; k++)
	{
		if (abs(v_param[k] - v_newParam[k]) > 1)
		{
			*melhora = 1;
		}
	}
}

int main(void) {

	int m_inicio[16][16];
	int m_indice[16][16];
	int m_fim[16][16];
	int parametro = 0;
	int m_parametros[10];
	int v_newParam[10];
	int m = 0, *melhora = &m;

	std::srand(std::time(0)); //usa a hora como seed para gerar numeros aleatorios

	//preencher matriz com números aleatorios:
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			m_inicio[i][j] = std::rand()%101; //gera números de 0 a 100
//			m_indice[i][j] = m_inicio[i][j];
		}
	}

	imprimir_matriz(m_inicio);

	//receber_parametros:
	std::cout << "\nEntre com um numero inteiro e positivo de parametros (maximo 10): ";
	std::cin >> parametro;
	while (parametro > 10 || parametro < 1) //evitar erros de entrada do usuario (nao aceita valor negativo ou maior que 10)
	{
		std::cout << "\nEntre com um numero inteiro e positivo de parametros (maximo 10): ";
		std::cin >> parametro;
	}

	//preencher matriz de parametros:
	for(int i = 0; i < parametro; i++)	
	{
		m_parametros[i] = m_inicio[rand()%16][rand()%16];
	}

	//verificacao da matriz de parametros :
	printf("\nParametros selecionados:\n");
	for(int i = 0; i < parametro; i++)
	{
		printf("%i  ", m_parametros[i]);
	}
	printf("\n\n%d", parametro);

	matriz_indice(parametro, m_parametros, m_inicio, m_indice);
	printf("\n\n%d", parametro);

	printf("Matriz de indices:\n");
	imprimir_matriz(m_indice);

	simplificar_matriz(parametro, m_parametros, m_indice, m_fim);
	printf("\n\n%d", parametro);

	printf("\nMatriz final:\n");
	imprimir_matriz(m_fim);

	do
	{
		//etapa de otimizacao:
		novoCentro(m_indice, m_inicio, parametro, v_newParam);
		distancia_m(parametro, m_parametros, v_newParam, melhora);
		printf("%d", melhora)
		simplificar_matriz(parametro, v_newParam, m_indice, m_fim);
		printf("Novo centro:\n");
		imprimir_vetor(v_newParam, parametro);
		printf("Nova matriz:\n");
		imprimir_matriz(m_fim);
	} while (*melhora == 1);

	printf("\nMatriz otimizada:\n");
	imprimir_matriz(m_fim);

	return 0;
}




//rascunhos
/*
	//substituir_valores:
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			int dist_min = 101; //variavel local para armazenar o valor de distancia minima (começa em 101 devido à distancia maxima de 100)
			for (int k = 0; k < parametro; k++)
			{
				if (dist_min >= std::abs(m_inicio[i][j] - m_parametros[k]))
				{
					dist_min = std::abs(m_inicio[i][j] - m_parametros[k]);
					indice_k = k; //guarda o indice do parametro cuja distancia é a menor em relação à posição da matriz
				}
			}
			m_indice[i][j] = m_parametros[indice_k];
		}
	}
*/

/* 
Denise Cristina de Moura
ADS-IFSP/JCR
Cálculo - Programa de Otimização

https://www.youtube.com/watch?v=pFBm4KLg5jc&ab_channel=DeniseCristinadeMoura

*/

#include <iostream>
#include <cmath>
#include <cstdio>

#define TAMANHO 32

using namespace std;

// variáveis
float pontoA, pontoB, custoTerra, custoRio;

// protótipos
float EntradaDeDados();
float Calculo(float pontoA, float pontoB, float custoTerra, float custoRio);


int main ()
{
	cout << "\t_______________________________________________________________" << endl;
	cout << "\t|                                                             |" << endl;
	cout << "\t|         #   CALCULO PARA OTIMIZACAO   #                     |" << endl;
	cout << "\t|                                                             |" << endl;
	cout << "\t|                                                             |" << endl;
	cout << "\t|         Tecle 'enter' para calcular                         |" << endl;
	cout << "\t|                                                             |" << endl;
	cout << "\t_______________________________________________________________" << endl;
	
	getchar();
	system("cls");
	EntradaDeDados();
	
	return 0;
}


// Funções
float EntradaDeDados ()
{	
	
	char teste[TAMANHO];
	int i;
	
	cout << "\t_______________________________________________________________" << endl;
	cout << "\t|                                                             |" << endl;
	cout << "\t|               #   CALCULO PARA OTIMIZACAO   #               |" << endl;
	cout << "\t|                                                             |" << endl;
	cout << "\t|                                                             |" << endl;
	cout << "\t|   Calcule o percurso mais economico para estender um cabo   |" << endl;
	cout << "\t|   na distacia do ponto 'A' para o ponto 'B':                |" << endl; 
	cout << "\t|                                                             |" << endl;

// DISTÂNCIA PONTO A:	
	do{
		cout << "\t|   Distancia por terra [ponto 'A']:   ";
		cin >> teste;	
	}while (teste == '\0');
	
	for(i=0; i<TAMANHO && teste[i] != '\0'; i++)
	{
		if(isalpha(teste[i]))
		{
			cout << "\t|   Valor invalido. Tecle 'enter' e digite novamente:         |" << endl << endl;
			getchar();
			EntradaDeDados();
		}
		else
			pontoA = atof(teste);
	}

// CUSTO TERRA
	do{
		cout << "\t|   Custo cabo por terra:              R$ ";
		cin >> teste;	
	}while (teste == '\0');
	
	for(i=0; i<TAMANHO && teste[i] != '\0'; i++)
	{
		if(isalpha(teste[i]))
		{
			cout << "\t|   Valor invalido. Tecle 'enter' e digite novamente:         |" << endl << endl;
			getchar();
			EntradaDeDados();
		}
		else
			custoTerra = atof(teste);
	}
		
	cout << "\t|                                                             |" << endl;
	
// DISTÂNCIA PONTO B:	
	do{
		cout << "\t|   Distancia pelo rio [ponto 'B']:    ";
		cin >> teste;	
	}while (teste == '\0');
	
	for(i=0; i<TAMANHO && teste[i] != '\0'; i++)
	{
		if(isalpha(teste[i]))
		{
			cout << "\t|   Valor invalido. Tecle 'enter' e digite novamente:         |" << endl << endl;
			getchar();
			EntradaDeDados();
		}
		else
			pontoB = atof(teste);
	}

// CUSTO RIO
	do{
		cout << "\t|   Custo cabo pelo rio:               R$ ";
		cin >> teste;	
	}while (teste == '\0');
	
	for(i=0; i<TAMANHO && teste[i] != '\0'; i++)
	{
		if(isalpha(teste[i]))
		{
			cout << "\t|   Valor invalido. Tecle 'enter' e digite novamente:         |" << endl << endl;
			getchar();
			EntradaDeDados();
		}
		else
			custoRio = atof(teste);
	}
	
	cout << "\t|                                                             |" << endl;
	cout << "\t|               Tecle 'enter' para calcular                   |" << endl;
	cout << "\t|                                                             |" << endl;
	cout << "\t_______________________________________________________________" << endl;
	
	getchar();
	Calculo(pontoA, pontoB, custoTerra, custoRio);

	return 0;
	
}

float Calculo(float pontoA, float pontoB, float custoTerra, float custoRio)
{
	int opcao;
	float custo, orcamento=0, orcamentoCatetos;
	float i, x, y, menorX, menorY;
		
	orcamentoCatetos = pontoA*custoTerra + pontoB*custoRio;
	
	orcamento = orcamentoCatetos;
	
		for (i=0; i<pontoA; i++)
		{
			x = i;
			
			y = sqrt(x*x + pontoB*pontoB);
		
			custo = (pontoA - x)*custoTerra + (y * custoRio);	
			
			if (orcamento > custo)
			{
				orcamento = custo;
				menorX = x;
				menorY = y;		
			}
		}
				
	system("cls");
	
	cout << "\t_______________________________________________________________" << endl;
	cout << "\t|                                                             |" << endl;
	cout << "\t|               #   CALCULO PARA OTIMIZACAO   #               |" << endl;
	cout << "\t|                                                             |" << endl;
	cout << "\t|                                                             |" << endl;
	cout << "\t|   Informacoes:                                              |" << endl;
	cout << "\t|   distancia por terra:\t" << pontoA << " * " << custoTerra << endl;
	cout << "\t|   distancia pelo rio:\t\t" << pontoB << " * " << custoRio << endl;
	cout << "\t|                                                             |" << endl;
	std::printf("\t|   Menor orcamento: \tR$ %.2f", orcamento);
		cout << endl;
	
	cout << "\t|                                                             |" << endl;
	cout << "\t|   Distancia do cabeamento                                   |" << endl;
	cout << "\t|   por terra: \t" << (pontoA-menorX) << "\t * " << custoTerra << " = ";
	std::printf("R$ %.2f", (pontoA-menorX)*custoTerra);
	cout << endl;
	cout << "\t|   pelo rio: \t" << menorY << "\t * " << custoRio << " = ";
	std::printf("R$ %.2f", (menorY)*custoRio);
	cout << endl;
	
	cout << "\t|                                                             |" << endl;
	cout << "\t|                                                             |" << endl;
	cout << "\t|   Digite (1) para novo calculo ou (2) para sair             |" << endl;
		cin >> opcao;
		if (opcao == 1)
		{
			system("cls");
			EntradaDeDados();
		}	
		else if (opcao == 2)
		{
			system("cls");
			cout << "\t\tSaindo...";
			exit;
		}	
		else 
			cout << "\t\tValor invalido!" << endl << endl;

}

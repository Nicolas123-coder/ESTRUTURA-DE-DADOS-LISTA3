#include "StaticQueue.h"
#include <stdio.h>
#include <iostream>
#include <ctime> 
#include <string>

#pragma warning(disable : 4996)

using namespace std;

// NICOLAS DE BARROS TIA : 32070837
// ARQUIVO MAIN.CPP


int main()
{
	setlocale(LC_ALL, "pt_BR");

	//inicialização de variaveis
	int opcao = 0;
	int estante, prateleira, gaveta;
	string unidade_de_agua;                 //será adicionado na lista A ou B, dependendo da marca 
	string elemento_removido;
	string VENDA_marca_da_agua;
	char ADD_marca_da_agua;
	char dataaux[110];					   //vetor de char auxilidar p/ colocar na queue 


	//Criação das filas, do tipo StaticQueue
	StaticQueue queue_A = Create();
	StaticQueue queue_B = Create();

	//MENU 
	while (opcao != 3)
	{
		cout << "\n-------------------------------------------\n";
		cout << "Digite a opcao desejada : \n";
		cout << "   1-)	Realizar venda \n";
		cout << "   2-)	Cadastrar um produto no estoque \n";
		cout << "   3-)	Sair \n";
		cout << "-------------------------------------------\n";
		cout << "\n";

		cin >> opcao;
		if (opcao != 1 && opcao != 2 && opcao != 3)
		{
			cout << "Digite a opcao correta de acordo com o MENU ! \n";
			cin >> opcao;
		}

		switch (opcao)
		{
			// faz a venda e remove do estoque 
		case 1:

			cout << "\nDigite a marca de preferencia (A / B / QUALQUER) : ";
			cin >> VENDA_marca_da_agua;
			cout << "\n";

			//Mostra as informações e remove do estoque
			//VENDA DA MARCA --> A <--	
			if (VENDA_marca_da_agua == "a" || VENDA_marca_da_agua == "A")
			{
				if (IsEmpty(queue_A) == true)
				{
					cout << "\nO estoque de A está vazio !";
					continue;
				}
				elemento_removido = Dequeue(queue_A);
				cout << "*** INFORMAÇÕES DA AGUA VENDIDA : ***\n" << elemento_removido;
				continue;
			}

			//Mostra as informações e remove do estoque
			//VENDA DA MARCA --> B <--
			else if (VENDA_marca_da_agua == "b" || VENDA_marca_da_agua == "B")
			{
				if (IsEmpty(queue_B) == true)
				{
					cout << "\nO estoque de B está vazio !";
					continue;
				}
				elemento_removido = Dequeue(queue_B);
				cout << "*** INFORMAÇÕES DA AGUA VENDIDA (mais antiga) : ***\n" << elemento_removido;
				continue;
			}

			//Mostra as informações e remove do estoque 
			//VENDA DE QUALQUER UMA --> MARCA <--
			else if (VENDA_marca_da_agua == "Qualquer" || VENDA_marca_da_agua == "qualquer" || VENDA_marca_da_agua == "QUALQUER")
			{
				if ((queue_A.count + queue_B.count) > 0)
				{
					if (IsEmpty(queue_B))
					{
						elemento_removido = Dequeue(queue_A);
						cout << "***  INFORMAÇÕES DA AGUA VENDIDA --> A <-- :  ***\n" << elemento_removido;
						continue;
					}

					if (IsEmpty(queue_A))
					{
						elemento_removido = Dequeue(queue_B);
						cout << "***  INFORMAÇÕES DA AGUA VENDIDA --> B <-- :  ***\n" << elemento_removido;
						continue;
					}

					else
					{
						string primeiro_A, primeiro_B;
						primeiro_A = Front(queue_A);
						primeiro_B = Front(queue_B);
						string tempo_total_A = " ";
						string tempo_total_B = " ";

						//Soma os dias, meses, ano, minutos, segundos e horas
						tempo_total_A = primeiro_A.substr(6, 4) + primeiro_A.substr(3, 2) + primeiro_A.substr(0, 2) + primeiro_A.substr(11, 8);
						tempo_total_B = primeiro_B.substr(6, 4) + primeiro_B.substr(3, 2) + primeiro_B.substr(0, 2) + primeiro_B.substr(11, 8);

						//Comparação de qual é  omais antigo 
						if (tempo_total_A > tempo_total_B)
						{
							elemento_removido = Dequeue(queue_B);
							cout << "***  INFORMAÇÕES DA AGUA VENDIDA (MAIS ANTIGA) --> B <-- :  ***\n" << elemento_removido;
						}

						if (tempo_total_B > tempo_total_A)
						{
							elemento_removido = Dequeue(queue_A);
							cout << "***  INFORMAÇÕES DA AGUA VENDIDA (MAIS ANTIGA)--> A <-- :  ***\n" << elemento_removido;
						}
						continue;
					}
				}
				else
				{
					cout << "\nESTOQUE ESGOTADO !!!\n";
					continue;
				}
			}

		case 2 :

			cout << "\nDigite a marca da agua que deseja adicionar no estoque : ";
			cin >> ADD_marca_da_agua;

			// ADD MARCA --> A <--
			if (ADD_marca_da_agua == 'A' || ADD_marca_da_agua == 'a')
			{
				time_t t = time(nullptr);
				tm timeinfo;
				localtime_s(&timeinfo, &t);

				cout << "\nDigite a estante onde será armazenado : ";
				cin >> estante;
				cout << "\nDigite a prateleira onde será armazenado : ";
				cin >> prateleira;
				cout << "\nDigite a gaveta onde será armazenado : ";
				cin >> gaveta;
				cout << "\n *** INFORMAÇÕES DO PRODUTO CADASTRADO : *** \n";
				sprintf(dataaux, "%02d/%02d/%04d %02d:%02d:%02d estante:%02d prateleira:%02d  gaveta:%02d", timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900, timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, estante, prateleira, gaveta);
				unidade_de_agua = (string)(dataaux);

				cout << dataaux << "\n";

				Enqueue(queue_A, unidade_de_agua);
				cout << "\nCOUNT : " <<Count(queue_A);
			}

			// ADD MARCA --> B <--
			else if (ADD_marca_da_agua == 'B' || ADD_marca_da_agua == 'b')
			{
				time_t t = time(nullptr);
				tm timeinfo;
				localtime_s(&timeinfo, &t);

				cout << "\nDigite a estante onde será armazenado : ";
				cin >> estante;
				cout << "\nDigite a prateleira onde será armazenado : ";
				cin >> prateleira;
				cout << "\nDigite a gavete onde será armazenado : ";
				cin >> gaveta;

				cout << "INFORMAÇÕES DO PRODUTO CADASTRADO : \n";
				sprintf(dataaux, "%02d/%02d/%04d %02d:%02d:%2d estante:%02d prateleira:%02d  gaveta:%02d", timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900, timeinfo.tm_hour,timeinfo.tm_min, timeinfo.tm_sec, estante, prateleira, gaveta);
				unidade_de_agua = (string)(dataaux);
				cout << dataaux << "\n";

				Enqueue(queue_B, unidade_de_agua);
				cout << "\nCOUNT : " << Count(queue_B);
			}

			//ERRO
			else
			{
				cout << "Digite apenas aguas da marca A ou B !!\n";
			}
			continue;
		}
	}
}



#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__
#include <ctime>
#include <string>

//NICOLAS DE BARROS 
// TIA : 32070837

using namespace std;

// Estrutura de dados do tipo Fila.
const int STATIC_QUEUE_CAPACITY = 8;

struct StaticQueue
{
	int front;
	int rear;
	int count;

	string fila[STATIC_QUEUE_CAPACITY];
};

// Sintaxe de função:
// <tipo do retorno> <nome da função>(<parâmetros, caso exista>);

//Create()
//Cria e retorna uma fila vazia.
//
//Pré - condição: N / A.
//Pós - condição : Uma nova fila vazia é criada.
StaticQueue Create();

//Enqueue(queue, elem)
//Insere o elemento elem no fim da fila queue, se a fila não estiver cheia.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : O final da fila contém o elemento elem OU erro se a fila estiver cheia.
bool Enqueue(StaticQueue& queue_A, string elem);

//Dequeue(queue)
//Remove e retorna o primeiro elemento da fila queue, se a fila não estiver vazia.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : Remove e retorna o primeiro elemento da fila OU erro se a fila estiver vazia.
string Dequeue(StaticQueue& queue);

//Front(queue)
//Retorna uma referência do elemento que está no começo da fila(mas não o remove), se a fila não estiver vazia.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : Retorna o primeiro elemento da fila sem removê - lo OU erro se a fila estiver vazia.
string Front(const StaticQueue& queue);

//Size(queue)
//Retorna a capacidade da fila.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : N / A.
int Size(const StaticQueue& queue);

//Count(queue)
//Retorna a quantidade de elementos na fila.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : N / A.
int Count(const StaticQueue& queue);

//IsEmpty(queue)
//Retorna true se a fila estiver vazia ou falso, caso contrário.
//
//Pré - condição: A fila queue é válida.
//Pós - condição : N / A.
bool IsEmpty(const StaticQueue& queue);

//Clear(queue)
//Esvazia a fila(remove todos os elementos da fila).
//
//Pré - condição: A fila queue é válida.
//Pós - condição : A fila queue está vazia.
bool Clear(StaticQueue& queue);

#endif // __STATIC_QUEUE_H__

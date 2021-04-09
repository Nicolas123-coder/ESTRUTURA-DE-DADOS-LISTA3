#include "StaticQueue.h"
#include <string>
// NICOLAS DE BARROS 
// TIA : 32070837

using namespace std;

//Create()
//Cria e retorna uma fila vazia.
//
//Pré - condição: N / A.
//Pós - condição : Uma nova fila vazia é criada.
StaticQueue Create()
{
	StaticQueue queue =
	{
		0, // int front;
		0, // int rear;
		0, // int count;
		{ " " } // char values[STATIC_QUEUE_CAPACITY] ----> AGUA[STATIC_QUEUE_CAPACITY];
	};

	return queue;
}


bool Enqueue(StaticQueue& queue, string elem)
{
	// Verifica se a fila está cheia.
	if (queue.count == Size(queue))
	{
		return false;
	}

	// Insere elem no final da fila (vetor da queue).
	queue.fila[queue.rear] = elem;

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a variável rear, que é usada para indicar o índice correto para um novo elemento da fila,
	// volta pro início do vetor.
	queue.rear = (queue.rear + 1) % Size(queue); // Mantém queue.rear no intervalo 0 <= queue.rear < Size(queue).

	// A linha acima equivale à:
	// ++queue.rear;
	// if (queue.rear == Size(queue))
	// {
	// 	queue.rear = 0;
	// }

	++queue.count;

	return true;
}

string Dequeue(StaticQueue& queue)
{
	if (IsEmpty(queue))
	{
		return "";
	}

	// Como remover e retornar o primeiro elemento da fila?
	string value = queue.fila[queue.front];
	queue.fila[queue.front] = '\0';

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a variável front, que é usada para indicar o índice correto do primeiro elemento da fila,
	// volta pro início do vetor.
	queue.front = (queue.front + 1) % Size(queue); // Mantém queue.front no intervalo 0 <= queue.front < Size(queue).

	// A linha acima equivale à:
	// ++queue.front;
	// if (queue.front == Size(queue))
	// {
	// 	queue.front = 0;
	// }

	--queue.count;

	return value;
}


string Front(const StaticQueue& queue)
{
	if (IsEmpty(queue))
	{
		return "\0";
	}
	else
	{
		return queue.fila[queue.front];
	}
}


int Size(const StaticQueue& queue)
{
	return sizeof(queue.fila) / sizeof(queue.fila[0]); // return STATIC_QUEUE_CAPACITY;
}


int Count(const StaticQueue& queue)
{
	return queue.count;
}


bool IsEmpty(const StaticQueue& queue)
{
	return queue.count == 0;
}


bool Clear(StaticQueue& queue)
{
	while (!IsEmpty(queue))
	{
		Dequeue(queue);
	}

	return IsEmpty(queue);
}

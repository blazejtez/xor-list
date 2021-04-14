#include "Kolejka.h"
#include "Lista.h"
Queue* initialize_queue()
{
	Queue* q = new Queue;
	q->lista = initialize_list();
	q->front = nullptr;
	q->back = nullptr;
	return q;
}
Queue* initialize_queue(Queue* q)
{
	q->front = nullptr;
	q->back = nullptr;
	return q;
}

//PUSH N - wepchnij element N na koniec kolejki.
void push(Queue* q, int n)
{
	//wepchnij element na koniec kolejki to taki jakby add beg, co?


}
//POP - wyciągnij pierwszy element z kolejki.
void pop(Queue* q)
{

}
//PRINT_QUEUE - drukuj kolejkę od pierwszego elementu do ostatnio wepchniętego.
void print_queue(Queue* q)
{

}
//COUNT - liczba elementów kolejki ≤ SIZE.
void count(Queue* q)
{

}
//GARBAGE_SOFT - wpisz wartość 0 do wszystkich elementów listy które nie należą do kolejki.
void garbage_soft(Queue* q)
{

}
//GARBAGE_HARD - usuń wszystkie elementy listy które nie należą do kolejki.
void garbage_hard(Queue* q)
{

}
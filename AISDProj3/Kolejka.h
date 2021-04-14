#ifndef QUEUE_H
#define QUEUE_H
#include "Lista.h"
#include "Wezel.h"
struct Queue
{
	XorList * lista;
	int size;
	Node* front;
	Node* back;
};

//metody byczku
Queue* initialize_queue();
Queue* initialize_queue(Queue* queue);
//


//PUSH N - wepchnij element N na koniec kolejki.
void push(Queue* q, int n);
//POP - wyciągnij pierwszy element z kolejki.
void pop(Queue* q);
//PRINT_QUEUE - drukuj kolejkę od pierwszego elementu do ostatnio wepchniętego.
void print_queue(Queue* q);
//COUNT - liczba elementów kolejki ≤ SIZE.
void count(Queue* q);
//GARBAGE_SOFT - wpisz wartość 0 do wszystkich elementów listy które nie należą do kolejki.
void garbage_soft(Queue* q);
//GARBAGE_HARD - usuń wszystkie elementy listy które nie należą do kolejki.
void garbage_hard(Queue* q);
#endif
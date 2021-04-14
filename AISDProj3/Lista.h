#ifndef LISTA_H
#define LISTA_H
#include "Wezel.h"

struct XorList
{
	Node* beg;
	Node* prev;
	Node* act;
	Node* end;
};

XorList* initialize_list();

void actual(XorList* lista);
void next(XorList* lista);
void prev(XorList* lista);
void add_beg(XorList* lista, int n);
void add_end(XorList* lista, int n);
void add_act(XorList* lista, int n);
void del_beg(XorList* lista);
void del_end(XorList* lista);
void del(XorList** lista, Node* to_delete, Node** prev_node);
void del_val(XorList* lista, int n);
void del_act(XorList* lista);
void print_forward(XorList* lista);
void print_backward(XorList* lista);
void delete_all(XorList* lista);
#endif
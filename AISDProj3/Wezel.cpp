#include "Wezel.h"
using namespace std;

Node* eval_next_adress(Node* wezel, Node* prev)
{
	return calc_xor(prev, wezel->xor_adress);
}
Node* eval_prev_adress(Node* wezel, Node* next)
{
	return (Node*)((int)wezel->xor_adress ^ (int)next);
}
Node* calc_xor(Node* prev, Node* next)
{
	return (Node*)((int)prev ^ (int)next);
}
Node* initialize_node(int n, Node* prev, Node* next)
{
	Node* nowy = new Node;
	nowy->value = n;
	nowy->xor_adress = calc_xor(prev, next);
	return nowy;
}

#ifndef WEZEL_H
#define WEZEL_H
struct Node
{
	int value = 0;
	Node* xor_adress = 0;
};

Node* initialize_node(int n, Node* prev, Node* next);
Node* eval_next_adress(Node* wezel, Node* prev);
Node* eval_prev_adress(Node* wezel, Node* next);
Node* calc_xor(Node* prev, Node* next);
#endif
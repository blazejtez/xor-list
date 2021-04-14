#include <iostream>
#include "Lista.h"
#include "Wezel.h"
//testowanie wystapienia warunkow granicznych
bool is_empty(XorList* lista)
{
	return lista->beg == nullptr && lista->end == nullptr && lista->act == nullptr;
}
bool has_one_element(XorList* lista)
{
	return lista->beg == lista->end;
}
bool has_two_elements(XorList* lista)
{
	return lista->beg->xor_adress == nullptr;
}

//utils
//dodaje wezel pomiedzy sasiadami w liscie, pod warunkiem ze nie sa to szczegolne przypadki
//tj lista ma wiecej niz jeden element. Radzi sobie z dwuelementowymi listami
Node* add_reg(XorList** lista, Node** right_neighbour, Node** left_neighbour, int n)
{
	if (has_two_elements(*lista))
	{
		Node* nowy = initialize_node(n, *right_neighbour, *left_neighbour);
		//uaktualnienie xorow:
		(*left_neighbour)->xor_adress = calc_xor(nowy, *right_neighbour);
		(*right_neighbour)->xor_adress = calc_xor(nowy, *left_neighbour);
		//uaktualnienie listy musi sie odbyc w dedykowanych funkcjach.
		return nowy;
	}
	else
	{
		Node* nowy = initialize_node(n, *right_neighbour, *left_neighbour);
		Node* next_after_right_neighbour = eval_next_adress(*right_neighbour, *left_neighbour);
		Node* prev_than_left_neighbour = eval_prev_adress(*left_neighbour, *right_neighbour);
		//uaktualnienie xorow
		(*left_neighbour)->xor_adress = calc_xor(nowy, prev_than_left_neighbour);
		(*right_neighbour)->xor_adress = calc_xor(nowy, next_after_right_neighbour);
		//uaktualnienie listy musi sie odbyc w dedykowanych funkcjach.
		return nowy;
	}
}
void del(XorList** lista, Node* to_delete, Node** prev_node)
{
	if (has_two_elements(*lista))
	{
		if (to_delete == (*lista)->beg)
		{
			(*lista)->end->xor_adress = nullptr;
			(*lista)->act = (*lista)->end;
		}
		else
		{
			(*lista)->beg->xor_adress = nullptr;
			(*lista)->act = (*lista)->beg;
			(*lista)->end = (*lista)->beg;
		}
		delete to_delete;
		(*lista)->prev = nullptr;
		return;
	}
	else
	{
		Node* next = eval_next_adress(to_delete, *prev_node);
		Node* before_prev = eval_prev_adress(*prev_node, to_delete);
		//sasiedzi do zmiany
		Node* after_next = eval_next_adress(next, to_delete);
		next->xor_adress = calc_xor(*prev_node, after_next);
		(*prev_node)->xor_adress = calc_xor(before_prev, next);
		delete to_delete;
		//uwaga, brak aktualizacji listy
	}
}
//inicjalizowanie listy lub zerowanie listy
XorList* initialize_list()
{
	XorList* temp = new XorList;
	temp->act = nullptr;
	temp->prev = nullptr;
	temp->beg = nullptr;
	temp->end = nullptr;
	return temp;
}
XorList* initialize_list(XorList** lista)
{
	(*lista)->act = nullptr;
	(*lista)->prev = nullptr;
	(*lista)->beg = nullptr;
	(*lista)->end = nullptr;
	return (*lista);
}
//funkcje z zadania
void actual(XorList * lista)
{
	 if (is_empty(lista))
	 {
		 printf("NULL\n");
		 return;
	 }
	 else
		 printf("%d\n", lista->act->value);
}
void next(XorList * lista)
{
	//warunki graniczne
	if (is_empty(lista))
	{
		printf("NULL\n");
		return;
	}
	if (has_one_element(lista))
	{
		actual(lista);
		return;
	}
	if (has_two_elements(lista))
	{
		Node* temp = lista->act;
		printf("%d\n", lista->prev->value);
		lista->act = lista->prev;
		lista->prev = temp;
	}
	//normalna wersja
	else
	{
		Node* next = eval_next_adress(lista->act, lista->prev);
		lista->prev = lista->act;
		lista->act = next;
		printf("%d\n", lista->act->value);
	}
	
}
void prev(XorList * lista)
{
	//warunki graniczne
	if (is_empty(lista))
	{
		printf("NULL\n");
		return;
	}
	if (has_one_element(lista))
	{
		actual(lista);
		return;
	}
	if (has_two_elements(lista))
	{
		Node* temp = lista->act;
		printf("%d\n", lista->prev->value);
		lista->act = lista->prev;
		lista->prev = temp;
	}
	else
	{
		printf("%d\n", lista->prev->value);
		Node* next = lista->act;
		lista->act = lista->prev;
		lista->prev = eval_prev_adress(lista->act, next);
	}


}
void add_beg(XorList* lista, int n)
{
	Node* stary_beg = lista->beg;
	if (is_empty(lista))
	{
		lista->beg = initialize_node(n, nullptr, nullptr);
		lista->act = lista->beg;
		lista->end = lista->beg;
	}
	else if (has_one_element(lista))
	{
		lista->beg = initialize_node(n, nullptr, nullptr);
		lista->prev = lista->beg;
	}
	else
	{
		Node* nowy = add_reg(&lista, &lista->beg, &lista->end, n);
		lista->beg = nowy;
		//jezeli act byl pierwszym elementem, to musimy tutaj 
		//zmienic prev, tak zeby nowy beg byl prevem dla act
		if (stary_beg == lista->act)
			lista->prev = lista->beg;
	}
}
void add_end(XorList* lista, int n)
{
		if (is_empty(lista))
		{
			lista->beg = initialize_node(n, nullptr, nullptr);
			lista->act = lista->beg;
			lista->end = lista->beg;
		}
		else if (has_one_element(lista))
		{
			lista->end = initialize_node(n, nullptr, nullptr);
			lista->prev = lista->beg;
		}
		else
		{
			Node* nowy = add_reg(&lista, &lista->beg, &lista->end, n);
			lista->end = nowy;
			//jezeli act byl pierwszym elementem, to musimy tutaj 
			//zmienic prev, tak zeby nowy beg byl prevem dla act
			if (lista->beg == lista->act)
				lista->prev = lista->end;
		}
}
void add_act(XorList * lista, int n)
{
	if (is_empty(lista))
	{
		lista->beg = initialize_node(n, nullptr, nullptr);
		lista->end = lista->beg;
		lista->act = lista->beg;
	}
	else if (has_one_element(lista))
	{
		lista->prev = initialize_node(n, nullptr, nullptr);
		lista->beg = lista->prev;
	}
	else
	{
		Node* nowy_prev = add_reg(&lista, &lista->act, &lista->prev, n);
		lista->prev = nowy_prev;
		if (lista->act == lista->beg)
			lista->beg = nowy_prev;
	}
}
void del_beg(XorList* lista)
{
	if (is_empty(lista))
	{
		return;
	}
	else if (has_one_element(lista))
	{
		delete lista->beg;
		lista = initialize_list(&lista);
	}
	else
	{
		Node* second = eval_next_adress(lista->beg, lista->end);
		del(&lista, lista->beg, &lista->end);
		//uaktualnienie listy
		if (lista->act == lista->beg)
		{
			lista->act = second;
		}
		else if (lista->prev == lista->beg)
		{
			lista->prev = second;
		}
		lista->beg = second;
		
	}
}
void del_end(XorList* lista)
{
	if (is_empty(lista))
	{
		return;
	}
	else if (has_one_element(lista))
	{
		delete lista->end;
		lista = initialize_list(&lista);
	}
	else if (has_two_elements(lista))
	{
		delete lista->end;
		lista->act = lista->prev;
		lista->beg = lista->prev;
		lista->end = lista->prev;
		lista->prev = nullptr;
	}
	else
	{
		Node* second_to_last = eval_prev_adress(lista->end, lista->beg);
		Node* third_to_last = eval_prev_adress(second_to_last, lista->end);
		del(&lista, lista->end, &lista->beg);
		//uaktualnienie listy
		if (lista->act == lista->end)
		{
			lista->act = second_to_last;
			lista->prev = third_to_last;
		}
		else if (lista->prev == lista->end)
		{
			lista->prev = second_to_last;
		}
		lista->end = second_to_last;

	}
}
void del_val(XorList* lista, int n)
{
	if (is_empty(lista))
	{
		return;
	}
	else if (has_one_element(lista))
	{
		if (lista->beg->value == n)
		{
			delete lista->beg;
			lista = initialize_list(&lista);
		}
			
	}
	else
	{
		Node* cursor = lista->beg;
		Node* prev_cursor = lista->end;
		Node* next_cursor = eval_next_adress(cursor, prev_cursor);
		Node* after_next_cursor = eval_next_adress(next_cursor, cursor);
		do
		{
			if (cursor->value == n)
			{
				del(&lista, cursor, &prev_cursor);
				if (cursor == lista->end)
					lista->end = prev_cursor;
				else if (cursor == lista->beg)
				{
					lista->beg = next_cursor;
				}
				else if (cursor == lista->act)
					lista->act = next_cursor;
				else if (cursor == lista->prev)
					lista->prev = prev_cursor;
				cursor = next_cursor;
			}
			else
			{
				prev_cursor = cursor;
				cursor = next_cursor;
			}
			next_cursor = after_next_cursor;
			after_next_cursor = eval_next_adress(next_cursor, cursor);
		} while (cursor != lista->end);

		if (cursor->value == n)
		{
			del(&lista, cursor, &prev_cursor);
			if (cursor == lista->end)
				lista->end = prev_cursor;
			else if (cursor == lista->beg)
			{
				lista->beg = next_cursor;
			}
			else if (cursor == lista->act)
				lista->act = next_cursor;
			else if (cursor == lista->prev)
				lista->prev = prev_cursor;
		}

	}
	
}
void del_act(XorList * lista)
{
	if (is_empty(lista))
	{
		return;
	}
	else if (has_one_element(lista))
	{
		delete lista->act;
		lista = initialize_list(&lista);
	}
	else if (has_two_elements(lista))
	{
		delete lista->act;
		lista->act = lista->prev;
		lista->beg = lista->prev;
		lista->end = lista->prev;
		lista->prev = nullptr;
	}
	else
	{
		Node* next = eval_next_adress(lista->act, lista->prev);
		Node* prev_prev = eval_prev_adress(lista->prev, lista->act);
		del(&lista, lista->act, &lista->prev);
		//uaktualnienie listy
		if (lista->beg == lista->act)
		{
			lista->beg = next;
		}
		else if (lista->end == lista->act)
		{
			lista->end = lista->prev;
		}
		lista->act = lista->prev;
		lista->prev = prev_prev;

	}
}
void print_forward(XorList * lista)
{
	if (is_empty(lista))
	{
		printf("NULL\n");
		return;
	}
	else if (has_one_element(lista))
	{
		printf("%d\n", lista->beg->value);
		//cout << lista->beg->value << endl;
		return;
	}
	else if (has_two_elements(lista))
	{
		printf("%d %d\n", lista->beg->value, lista->end->value);
		//cout << lista->beg->value << " ";
		//cout << lista->end->value << endl;
		return;
	}
	else
	{
		Node* cursor = lista->beg;
		Node* next_cursor = eval_next_adress(cursor, lista->end);
		do
		{
			Node* after_next_cursor = eval_next_adress(next_cursor, cursor);
			printf("%d ", cursor->value);
			//cout << cursor->value << " ";
			cursor = next_cursor;
			next_cursor = after_next_cursor;
		} while (cursor != lista->beg);
		printf("\n");
	}
	
}
void print_backward(XorList * lista)
{
	if (is_empty(lista))
	{
		printf("NULL\n");
		return;
	}
	else if (has_one_element(lista))
	{
		printf("%d\n", lista->beg->value);
		//cout << lista->beg->value << endl;
		return;
	}
	else if (has_two_elements(lista))
	{
		printf("%d %d\n", lista->end->value, lista->beg->value);
		//cout << lista->end->value << " ";
		//cout << lista->beg->value << endl;
		return;
	}
	else
	{
		Node* cursor = lista->end;
		Node* prev_cursor = eval_prev_adress(cursor, lista->beg);
		do
		{
			Node* before_prev_cursor = eval_prev_adress(prev_cursor, cursor);
			printf("%d ", cursor->value);
			//cout << cursor->value << " ";
			cursor = prev_cursor;
			prev_cursor = before_prev_cursor;
		} while (cursor != lista->end);
		printf("\n");
		//cout << endl;
	}
}
void delete_all(XorList* lista)
{
	if (is_empty(lista))
	{
		return;
	}
	else if (has_one_element(lista))
	{
		if (lista->beg->value)
		{
			delete lista->beg;
			lista = initialize_list(&lista);
		}

	}
	else
	{
		Node* cursor = lista->beg;
		Node* prev_cursor = lista->end;
		Node* next_cursor = eval_next_adress(cursor, prev_cursor);
		Node* after_next_cursor = eval_next_adress(next_cursor, cursor);
		do
		{
			del(&lista, cursor, &prev_cursor);
			if (cursor == lista->end)
				lista->end = prev_cursor;
			else if (cursor == lista->beg)
			{
				lista->beg = next_cursor;
			}
			else if (cursor == lista->act)
				lista->act = next_cursor;
			else if (cursor == lista->prev)
				lista->prev = prev_cursor;
			cursor = next_cursor;
			next_cursor = after_next_cursor;
			after_next_cursor = eval_next_adress(next_cursor, cursor);
		} while (cursor != lista->end);
		del(&lista, cursor, &prev_cursor);
		if (cursor == lista->end)
			lista->end = prev_cursor;
		else if (cursor == lista->beg)
		{
			lista->beg = next_cursor;
		}
		else if (cursor == lista->act)
			lista->act = next_cursor;
		else if (cursor == lista->prev)
			lista->prev = prev_cursor;
	}

}
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "Wezel.h"
#include "Lista.h"

#define ACTUAL "ACTUAL"
#define NEXT "NEXT"
#define PREV "PREV"
#define ADD_BEG "ADD_BEG"
#define ADD_END "ADD_END"
#define ADD_ACT "ADD_ACT"
#define DEL_BEG "DEL_BEG"
#define DEL_END "DEL_END"
#define ADD_END "ADD_END"
#define DEL_VAL "DEL_VAL"
#define DEL_ACT "DEL_ACT"
#define PRINT_FORWARD "PRINT_FORWARD"
#define PRINT_BACKWARD "PRINT_BACKWARD"

using namespace std;
int main(void)
{
    XorList* plista = initialize_list();
    char inp[100] = {0};
    while (scanf("%s", inp)==1)
	{
        if (!strcmp(inp, ACTUAL))
        {
            actual(plista);
        }
        else if (!strcmp(inp, NEXT))
        {
            next(plista);
        }
        else if (!strcmp(inp, PREV))
        {
            prev(plista);
        }
        else if (!strcmp(inp, ADD_BEG))
        {
            int n;
            scanf("%d", &n);
            add_beg(plista, n);
        }
        else if (!strcmp(inp, ADD_END))
        {
            int n;
            scanf("%d", &n); 
            add_end(plista, n);
        }
        else if (!strcmp(inp, ADD_ACT))
        {
            int n;
            scanf("%d", &n);
            add_act(plista, n);
        }
        else if (!strcmp(inp, DEL_BEG))
        {
            del_beg(plista);
        }
        else if (!strcmp(inp, DEL_END))
        {
            del_end(plista);
        }
        else if (!strcmp(inp, DEL_VAL))
        {
            int n;
            scanf("%d", &n);
            del_val(plista, n);
        }
        else if (!strcmp(inp, DEL_ACT))
        {
            del_act(plista);
        }
        else if (!strcmp(inp, PRINT_FORWARD))
        {
            print_forward(plista);
        }
        else if (!strcmp(inp, PRINT_BACKWARD))
        {
            print_backward(plista);
        }
        else
        {
            printf("BLAD\n");
        }
	}
    delete_all(plista);
    delete plista;
	return 0;
}
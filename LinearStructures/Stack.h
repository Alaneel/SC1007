// CX1007 Data Structures

#ifndef LT10_Stack_h
#define LT10_Stack_h

#include "LinkedList.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct _stack{
    LinkedList ll;
} Stack;

////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

#endif

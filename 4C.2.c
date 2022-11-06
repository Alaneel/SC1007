#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct stack {
    int num[MAX];
    int top;
} Stack;

int isFullStack(Stack *s);
int isEmptyStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);

int main()
{
    int i = 0;
    Stack s;
    s.top = -1;

    printf("Enter a number: \n");
    scanf("%d", &i);
    while (i != -1)
    {
        push(&s, i);
        printf("Enter a number: \n");
        scanf("%d", &i);
    }
    printf("Popping stack: \n");
    while (!isEmptyStack(&s))
    {
        printf("%d ", pop(&s));
    }
    printf("\n");
    return 0;
}

int isFullStack(Stack *s)
{
    if (s->top == MAX - 1) return 1;
    else return 0;
}

int isEmptyStack(Stack *s)
{
    if (s->top == -1) return 1;
    else return 0;
}

void push(Stack *s, int value)
{
    if (!isFullStack(s)) // q->top < MAX - 1
        s->num[++(s->top)] = value; // top is -1 for empty stack
    return;
}

int pop(Stack *s)
{
    if (!isEmptyStack(s)) // q->top > 0
        return (s->num[(s->top)--]);

    else return 0;
}

int peek(Stack *s)
{
    if (!isEmptyStack(s))
        return s->num[s->top];
    else return -1;
}
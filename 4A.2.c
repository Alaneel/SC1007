#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node *next;
} ListNode;

typedef struct linkedlist {
    int size;
    ListNode *head;
} LinkedList;

typedef struct stack {
    LinkedList ll;
} Stack;

ListNode *findNode(LinkedList *ll, int value);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

int main()
{
    int i, j, crane, row, col, targetid;
    Stack containeryard[10][10];

    for (i=0; i<10; i++)
        for (j=0; j<10; j++)
            containeryard[i][j].ll.head = NULL;
            containeryard[i][j].ll.size = 0;
    
    row = col = 1;
    targetid = 555;

    // Initialize the target stack at (1, 1)
    // Each container has an ID number - this will go in the stack
    for (i=0; i<10; i++)
        push(&(containeryard[row][col]), i*100 + i*10 + i);

    // Find a container within a stack
    // Row, col of stack and ID of container are given
    while (!isEmptyStack(&(containeryard[row][col]))){
        crane = pop(&(containeryard[row][col]));

        // container found
        if (crane == targetid)
            break;
        
        // still not found, so store this crane temporarily in (0, 0)
        push(&(containeryard[0][0]), crane);
    }

        // Need to rebuild the original stack
    while (!isEmptyStack(&(containeryard[0][0])))
        push(&(containeryard[row][col]), pop(&(containeryard[0][0])));
        
    if (crane == targetid)
        printf("Container found!\n");
        
    return 0;
}

ListNode *findNode(LinkedList *ll, int index)
{
    ListNode *tmp = ll->head;

    if (tmp == NULL || index < 0) return NULL;

    while (index > 0)
    {
        tmp = tmp->next;
        if (tmp == NULL) return NULL;
        index--;
    }
    return tmp;
}

int insertNode(LinkedList *ll, int index, int value)
{
    ListNode *pre = NULL, *cur = NULL;

    if (ll->head == NULL || index == 0)
    {
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode));
        ll->head->item = value;
        ll->head->next = cur;
        (ll->size)++;
        return 0;
    }

    if (findNode(ll, index-1) != NULL)
    {
        pre = findNode(ll, index-1);
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = value;
        pre->next->next = cur;
        (ll->size)++;
        return 0;
    }
    return -1;
}

int removeNode(LinkedList *ll, int index)
{
    ListNode *pre = NULL, *cur = NULL;

    if (ll->head->next == NULL || index == 0)
    {
        cur = ll->head->next;
        free(ll->head);
        ll->head = cur;
        (ll->size)--;
        return 0;
    }

    if (findNode(ll, index-1) != NULL)
    {
        pre = findNode(ll, index-1);
        cur = pre->next->next;
        free(pre->next);
        pre->next = cur;
        (ll->size)--;
        return 0;
    }
    return -1;
}

void push(Stack *s, int value)
{
    insertNode(&(s->ll), 0, value);
}

int pop(Stack *s)
{
    int item = 0;
    item = (s->ll).head->item;
    removeNode(&(s->ll), 0);
    return item;
}

int peek(Stack *s)
{
    return (s->ll).head->item;
}

int isEmptyStack(Stack *s)
{
    if ((s->ll).size == 0) return 1;
    return 0;
}
// Reverse String using stack functions

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

ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);


int main()
{
    int i = 0;
    Stack s;
    s.ll.head = NULL;
    s.ll.size = 0;

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

ListNode *findNode (LinkedList *ll, int index)
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

int insertNode (LinkedList *ll, int index, int value)
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
    int item;
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
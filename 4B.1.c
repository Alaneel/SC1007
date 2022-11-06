#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node *next;
} ListNode;

typedef struct linkedlist {
    int size;
    ListNode *head;
    ListNode *tail;
} LinkedList;

typedef struct queue {
    LinkedList ll;
} Queue;

ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int peek(Queue *q);
int isEmptyQueue(Queue *q);

int main()
{
    Queue q;
    q.ll.head = NULL;
    q.ll.tail = NULL;
    q.ll.size = 0;
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);

    while (!isEmptyQueue(&q))
        printf("%d ", dequeue(&q));
    printf("\n");
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

void enqueue(Queue *q, int value)
{
    if (q->ll.head == NULL)
    {
        insertNode(&(q->ll), 0, value);
        q->ll.tail = q->ll.head;
    }
    else
    {
        q->ll.tail->next = malloc(sizeof(ListNode));
        q->ll.tail = q->ll.tail->next;
        q->ll.tail->item = value;
        q->ll.tail->next = NULL;
        q->ll.size++;
    }
}

/* Inefficient way

void enqueue(Queue *q, int value)
{
    insertNode(&(q->ll), (q->ll).size, value);
}
*/

int dequeue(Queue *q)
{
    int item = 0;
    item = ((q->ll).head)->item;
    removeNode(&(q->ll), 0);
    return item;
}

int peek(Queue *q)
{
    return ((q->ll).head)->item;
}

int isEmptyQueue(Queue *q)
{
    if ((q->ll).size == 0) return 1;
    return 0;
}
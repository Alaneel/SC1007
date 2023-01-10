#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int item;
    struct node *next;
} ListNode;

typedef struct linkedlist {
    ListNode *head;
    int size;
} LinkedList;

int sizeList(ListNode *head);
void printList(ListNode *head);
ListNode *findNode(ListNode *head, int index);
int insertNode(ListNode **head, int index, int value);
int removeNode(ListNode **head, int index);

int main()
{
    ListNode *head = NULL;
    int size;

    srand(time(NULL));
    size = sizeList(head);
    while (size < 10)
    {
        insertNode(&head, 0, rand() % 100);
        printf("List: ");
        printList(head); 
        printf("\n");
        size++;
    }
    printf("%d nodes\n", size);

    while (size > 0)
    {
        removeNode(&head, size-1);
        printf("List: ");
        printList(head);
        printf("\n");
        size--;
    }
    printf("%d nodes\n", size);

    return 0;
}

int sizeList(ListNode *head)
{
    int count = 0;

    if (head == NULL) return 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void printList(ListNode *head)
{
    if (head == NULL) return;

    while (head != NULL)
    {
        printf("%d ", head->item);
        head = head->next;
    }
}

ListNode *findNode(ListNode *head, int index)
{
    if (head == NULL || index < 0) return NULL;

    while (index > 0)
    {
        head = head->next;
        if (head == NULL) return NULL;
        index--;
    }
    return head;
}

int insertNode(ListNode **head, int index, int value)
{
    ListNode *pre, *cur;

    if (head == NULL || index == 0)
    {
        cur = *head;
        *head = malloc(sizeof(ListNode));
        (*head)->item = value;
        (*head)->next = cur;
        return 0;
    }

    if (findNode(*head, index-1) != NULL)
    {
        pre = findNode(*head, index-1);
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = value;
        pre->next->next = cur;
        return 0;
    }
    return -1;
}

int removeNode(ListNode **head, int index)
{
    ListNode *pre, *cur;

    if ((*head)->next == NULL || index == 0)
    {
        cur = (*head)->next;
        free(*head);
        *head = cur;
        return 0;
    }

    if (findNode(*head, index-1) != NULL)
    {
        pre = findNode(*head, index-1);
        cur = pre->next->next;
        free(pre->next);
        pre->next = cur;
        return 0;
    }
    return -1;
}
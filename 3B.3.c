// ChatGPT generated linkedlist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int item;
    struct node *next;
} ListNode;

typedef struct linkedlist {
    ListNode *sentinel;  // sentinel node serves as the head of the list
    int size;
} LinkedList;

void printList(LinkedList *list);
int insertNode(LinkedList *list, int index, int value);
int removeNode(LinkedList *list, int index);

int main()
{
    LinkedList list;
    list.sentinel = malloc(sizeof(ListNode));
    list.sentinel->next = NULL;
    list.size = 0;

    srand(time(NULL));
    while (list.size < 10)
    {
        insertNode(&list, 0, rand() % 100);
        printf("List: ");
        printList(&list); 
        printf("\n");
    }
    printf("%d nodes\n", list.size);

    while (list.size > 0)
    {
        removeNode(&list, list.size-1);
        printf("List: ");
        printList(&list);
        printf("\n");
    }
    printf("%d nodes\n", list.size);

    return 0;
}

void printList(LinkedList *list)
{
    ListNode *cur = list->sentinel->next;

    while (cur != NULL)
    {
        printf("%d ", cur->item);
        cur = cur->next;
    }
}

int insertNode(LinkedList *list, int index, int value)
{
    ListNode *pre, *cur;

    // Find the node before the one we want to insert
    pre = list->sentinel;
    for (int i = 0; i < index; i++)
    {
        pre = pre->next;
    }

    // Insert the new node after the one we found
    cur = pre->next;
    pre->next = malloc(sizeof(ListNode));
    pre->next->item = value;
    pre->next->next = cur;
    list->size++;

    return 0;
}

int removeNode(LinkedList *list, int index)
{
    ListNode *pre, *cur;

    // Find the node before the one we want to delete
    pre = list->sentinel;
    for (int i = 0; i < index; i++)
    {
        pre = pre->next;
    }

    // Delete the node after the one we found
    cur = pre->next;
    pre->next = cur->next;
    free(cur);
    list->size--;

    return 0;
}

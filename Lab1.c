// removeNode()

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node *next;
} ListNode;

int sizeList(ListNode *head);
void printList(ListNode *head);
ListNode *findNode(ListNode *head, int index);
int insertNode(ListNode **head, int index, int value);
int removeNode(ListNode **head, int index);
void freeList (ListNode *head);

int main()
{
    ListNode *head = NULL, *temp = NULL;
    int i = 0, index, value, size;

    printf("Enter your number (input -1 to stop): \n");
    scanf("%d", &i);
    while (i != -1)
    {
        if (head == NULL)
        {
            head = malloc(sizeof(ListNode));
            temp = head;
        }
        else
        {
            temp->next = malloc(sizeof(ListNode));
            temp = temp->next;
        }
        temp->item = i;
        printf("Enter your number (input -1 to stop): \n");
        scanf("%d", &i);
    }
    if (temp != NULL) temp->next = NULL;

    printf("sizeList(): %d\n", sizeList(head));
    printf("printList(): ");
    printList(head);

    printf("Enter the index of node to be found: \n");
    scanf("%d", &index);
    if (findNode(head, index) != NULL) printf("findNode(): %d\n", findNode(head, index)->item);

    printf("Enter the index of the node to insert your number: \n");
    scanf("%d", &index);
    printf("Enter your inserted number: \n");
    scanf("%d", &value);
    if (insertNode(&head, index, value) == -1) printf("Wrong input!\n");

    printf("Enter the index of the node to be removed: \n");
    scanf("%d", &index);
    if (removeNode(&head, index) == -1) printf("Wront input!\n");

    printf("sizeList(): %d\n", sizeList(head));
    printf("printList(): ");
    printList(head);

    freeList(head);
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
    printf("\n");
}

ListNode *findNode(ListNode *head, int index)
{
    if (head == NULL || index < 0) return NULL;

    while (index > 0)
    {
        head = head->next;
        if (head == NULL)
            return NULL;
        index--;
    }
    return head;
}

int insertNode(ListNode **head, int index, int value)
{
    ListNode *pre, *cur;

    if (*head == NULL || index == 0)
    {
        cur = *head;
        *head = malloc(sizeof(ListNode));
        (*head)->item = value;
        (*head)->next = cur;
        return 0;
    }    

    if (findNode(*head, index - 1) != NULL)
    {
        pre = (findNode(*head, index-1));
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

void freeList(ListNode *head)
{
    ListNode *currentnode;
    while (head != NULL)
    {
        currentnode = head;
        head = head->next;
        free(currentnode);
    }
}
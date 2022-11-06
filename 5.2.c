#include <stdio.h>
#include <stdlib.h>

typedef struct btnode {
    int item;
    struct btnode *left;
    struct btnode *right;
} BTNode;

typedef struct queuenode {
    BTNode *item;
    struct queuenode *next;
} QueueNode;

typedef struct linkedlist {
    int size;
    QueueNode *head;
    QueueNode *tail;
} LinkedList;

typedef struct queue {
    LinkedList ll;
} Queue;

void PrintNode(BTNode *cur);
void PreTreeTraversal(BTNode *cur);
void InTreeTraversal(BTNode *cur);
void PostTreeTraversal(BTNode *cur);
int countNode(BTNode *cur);
void findGrandChildren(BTNode *cur, int count);
int calcHeight(BTNode *cur);
void calcDepth(BTNode *cur, int depth);
BTNode *newNode(int value);
void LevelOrderTreeTraversal(BTNode *root);

void enqueue(Queue *q, BTNode *node);
int dequeue(Queue *q);
int isEmptyQueue(Queue *q);

int main()
{
    int num;
    BTNode *root = NULL;

    root = malloc(sizeof(BTNode));
    root->item = 70;
    root->left = malloc(sizeof(BTNode));
    root->left->item = 31;
    root->right = malloc(sizeof(BTNode));
    root->right->item = 93;
    root->left->left = malloc(sizeof(BTNode));
    root->left->left->item = 14;
    root->right->left = malloc(sizeof(BTNode));
    root->right->left->item = 73;
    root->right->right = malloc(sizeof(BTNode));
    root->right->right->item = 94;
    root->left->left->left = malloc(sizeof(BTNode));
    root->left->left->left->item = 23;
    printf("PreTreeTraversal(): ");
    PreTreeTraversal(root);
    printf("\n");
    printf("InTreeTraversal(): ");
    InTreeTraversal(root);
    printf("\n");
    printf("PostTreeTraversal(): ");
    PostTreeTraversal(root);
    printf("\n");
    printf("countNode(): %d\n", countNode(root));
    printf("findGrandChildren(): ");
    findGrandChildren(root, 0);
    printf("\n");
    printf("LevelOrderTreeTraversal(): ");
    LevelOrderTreeTraversal(root);
    printf("\n");
    return 0;
}

void PrintNode(BTNode *cur)
{
    printf("%d ", cur->item);
}

void PreTreeTraversal(BTNode *cur) // dfs traversal
{
    if (cur == NULL) return;
    PrintNode(cur);
    PreTreeTraversal(cur->left);
    PreTreeTraversal(cur->right);
}

void InTreeTraversal(BTNode *cur)
{
    if (cur == NULL) return;
    InTreeTraversal(cur->left);
    PrintNode(cur);
    InTreeTraversal(cur->right);
}

void PostTreeTraversal(BTNode *cur)
{
    if (cur == NULL) return;
    PostTreeTraversal(cur->left);
    PostTreeTraversal(cur->right);
    PrintNode(cur);
}

int countNode(BTNode *cur)
{
    int NumLeft = 0, NumRight = 0;

    if (cur == NULL) return 0;

    NumLeft = countNode(cur->left);
    NumRight = countNode(cur->right);
    return NumLeft + 1 + NumRight;
}

void findGrandChildren(BTNode *cur, int count)
{
    int k = 2;

    if (cur == NULL) return;

    if (count == k)
    {
        printf("%d ", cur->item);
        return;
    }

    if (count < k)
    {
        findGrandChildren(cur->left, count + 1);
        findGrandChildren(cur->right, count + 1);
    }
}

int calcHeight(BTNode *cur)
{
    int HeightLeft = 0, HeightRight = 0, HeightMax = 0;

    if (cur == NULL) return -1;

    HeightLeft = calcHeight(cur->left);
    HeightRight = calcHeight(cur->right);
    
    if (HeightLeft >= HeightRight) HeightMax = HeightLeft;
    else HeightMax = HeightRight;

    return HeightMax + 1;
}

void calcDepth(BTNode *cur, int depth)
{
    if (cur == NULL) return;

    printf("Node: %d, Depth: %d\n", cur->item, depth);

    calcDepth(cur->left, depth + 1);
    calcDepth(cur->right, depth + 1);
}

BTNode *newNode(int value)
{
    BTNode *node= (BTNode *) malloc(sizeof(BTNode));
    node->item = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void LevelOrderTreeTraversal(BTNode *root)
{
    if (root == NULL) return;
    Queue q;
    q.ll.head = NULL;
    q.ll.tail = NULL;
    enqueue(&q, root);

    while (!isEmptyQueue(&q))
    {
        BTNode *node = q.ll.head->item;
        printf("%d ", node->item);
        dequeue(&q);
        if (node->left != NULL)
            enqueue(&q, node->left);
        if (node->right != NULL)
            enqueue(&q, node->right);
    }
}

void enqueue(Queue *q, BTNode *node)
{
    QueueNode *cur = NULL;

    if (q->ll.head == NULL)
    {
        cur = q->ll.head;
        q->ll.head = malloc(sizeof(QueueNode));
        q->ll.head->item = node;
        q->ll.head->next = cur;
        q->ll.tail = q->ll.head;
        q->ll.size++;
    }
    else
    {
        q->ll.tail->next = malloc(sizeof(QueueNode));
        q->ll.tail = q->ll.tail->next;
        q->ll.tail->item = node;
        q->ll.tail->next = NULL;
    }
}

int dequeue(Queue *q)
{
    QueueNode *cur = NULL;

    if (!isEmptyQueue(q))
    {
        BTNode item;
        item = *((q->ll).head)->item;
        cur = q->ll.head->next;
        free(q->ll.head);
        q->ll.head = cur;
        q->ll.size--;  
        return 1;
    }
    else return 0;
}

int isEmptyQueue(Queue *q)
{
    if (q->ll.head == NULL) return 1;
    return 0;
}
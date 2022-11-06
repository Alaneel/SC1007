#include <stdio.h>
#include <stdlib.h>

typedef struct btnode {
    int item;
    struct btnode *left;
    struct btnode *right;
} BTNode;

void PrintNode(BTNode *cur);
void PreTreeTraversal(BTNode *cur);
void InTreeTraversal(BTNode *cur);
void PostTreeTraversal(BTNode *cur);
int countNode(BTNode *cur);
void findGrandChildren(BTNode *cur, int count);
int calcHeight(BTNode *cur);
void calcDepth(BTNode *cur, int depth);
BTNode *newNode(int value);
void currentLevel(BTNode *root, int height);
void LevelOrderTreeTraversal(BTNode *root);

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

void currentLevel(BTNode *root, int height)
{
    if (root == NULL) return;

    if (height == 1)
        printf("%d ", root->item);
    else if (height > 1)
        currentLevel(root->left, height - 1);
        currentLevel(root->right, height - 1);
}

void LevelOrderTreeTraversal(BTNode *root)
{
    int h = calcHeight(root) + 1;
    int i;
    for (i=0; i<h; i++)
    {
        currentLevel(root, i + 1);
    }
}
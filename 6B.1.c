// AVL tree

#include <stdio.h>
#include <stdlib.h>

// Create Node
typedef struct node {
    int item;
    struct node *left;
    struct node *right;
    int height;
} Node;

int max(int a, int b);
int height(Node *N);
Node *newNode(int item);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
int getBalance(Node *N);
Node *insertNode(Node *N, int item);
Node *minValueNode(Node *N);
Node *deleteNode(Node *N, int item);
void printPreOrder(Node *N);

int main()
{
    Node *root = NULL;

    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 8);

    printPreOrder(root);

    root = deleteNode(root, 3);

    printf("\nAfter deletion: ");
    printPreOrder(root);

    return 0;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *N)
{
    if (N == NULL) return 0;
    return N->height;
}

Node *newNode(int item)
{
    Node *node = malloc(sizeof(Node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get the balance factor
int getBalance(Node *N)
{
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

Node *insertNode(Node *N, int item)
{
    // Find the correct position to insertNode the node and insertNode it
    if (N == NULL) return(newNode(item));

    if (N->item > item)
        N->left = insertNode(N->left, item);
    else if (N->item < item)
        N->right = insertNode(N->right, item);
    
    // Update the balance factor of each node and balance the tree
    N->height = 1 + max(height(N->left), height(N->right));

    int balance = getBalance(N);
    if (balance > 1 && item < N->left->item)
        return rightRotate(N);

    if (balance < -1 && item > N->right->item)
        return leftRotate(N);

    if (balance > 1 && item > N->left->item)
    {
        N->left = leftRotate(N->left);
        return rightRotate(N);
    }
    
    if (balance < -1 && item < N->right->item)
    {
        N->right = rightRotate(N->right);
        return leftRotate(N);
    }
    
    return N;
}

Node *minValueNode(Node *N)
{
    Node *cur = N;

    while (cur->left != NULL)
        cur = cur->left;
    
    return cur;
}

Node *deleteNode(Node *N, int item)
{
    // Find the node and delete it
    if (N == NULL) return N;

    if (N->item > item)
        N->left = deleteNode(N->left, item);

    else if (N->item < item)
        N->right = deleteNode(N->right, item);
    
    else
    {
        if ((N->left == NULL) || (N->right == NULL))
        {
            Node *tmp = N->left ? N->left : N->right;

            if (tmp == NULL)
            {
                tmp = N;
                N = NULL;
            }
            else *N = *tmp;
            free(tmp);
        }
        else
        {
            Node *tmp = minValueNode(N->right);

            N->item = tmp->item;

            N->right = deleteNode(N->right, tmp->item);
        }
    }

    if (N == NULL) return N;

    // Update the balance factor of each node and balance the tree  
    N->height = 1 + max(height(N->left), height(N->right));

    int balance = getBalance(N);
    if (balance > 1 && getBalance(N->left) >= 0)
        return rightRotate(N);
    
    if (balance > 1 && getBalance(N->left) < 0)
        N->left = leftRotate(N->left);
        return rightRotate(N);

    if (balance < -1 && getBalance(N->right) <= 0)
        return leftRotate(N);
    
    if (balance < -1 && getBalance(N->right) > 0)
        N->right = rightRotate(N->right);
        return leftRotate(N);
    
    return N;
}

void printPreOrder(Node *N)
{
    if (N != NULL)
    {
        printf("%d ", N->item);
        printPreOrder(N->left);
        printPreOrder(N->right);
    }
}
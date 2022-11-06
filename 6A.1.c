#include <stdio.h>
#include <stdlib.h>

typedef struct btnode {
    char item;
    struct btnode *left;
    struct btnode *right;
} BTNode;

BTNode *newNode(char c);
void inorder(BTNode *root);
void BSTT(BTNode *cur, char c);
BTNode *BSTI(BTNode *cur, char c);

int main()
{
    BTNode *root = NULL;
    root = BSTI(root, 'H');
    root = BSTI(root, 'E');
    root = BSTI(root, 'L');
    root = BSTI(root, 'B');
    root = BSTI(root, 'F');
    root = BSTI(root, 'J');
    root = BSTI(root, 'M');

    printf("Inorder traversal: \n");
    inorder(root);
    printf("\n");
    printf("Can you find J?\n");
    BSTT(root, 'J');
    printf("After Inserting: \n");
    BSTI(root, 'G');
    printf("Inorder traversal: \n");
    inorder(root);
    printf("\n");
    printf("Can you find J?\n");
    BSTT(root, 'G');
    return 0;
}

BTNode *newNode(char c)
{
    BTNode *tmp = malloc(sizeof(BTNode));
    tmp->item = c;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void inorder(BTNode *root)
{
    if (root != NULL)
    {
        // Traverse left
        inorder(root->left);

        // Traverse root
        printf("%c -> ", root->item);

        // Traverse right
        inorder(root->right);
    }
}

void BSTT(BTNode *cur, char c)
{
    if (cur == NULL) 
    {
        printf("Can't find!\n");
        return;
    }
    if (c == cur->item)
    {
        printf("Found!\n");
        return;
    }
    if (c < cur->item)
        BSTT(cur->left, c);
    else
        BSTT(cur->right, c);
}

BTNode *BSTI(BTNode *cur, char c)
{
    if (cur == NULL) 
    {
        cur = malloc(sizeof(BTNode));
        cur->item = c;
        cur->left = NULL;
        cur->right = NULL;
    }

    else if (cur->item == c)
        printf("%c is already in the BST!\n", c);

    else
    {
        if (c < cur->item)
            cur->left = BSTI(cur->left, c);
        else
            cur->right = BSTI(cur->right, c);
    }

    return cur;
}
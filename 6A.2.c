#include <stdio.h>
#include <stdlib.h>

typedef struct btnode {
    char item;
    struct btnode *left;
    struct btnode *right;
} BTNode;

BTNode *newNode(char c);
void inorder(BTNode *root);
BTNode *insertNode(BTNode *root, char c);
void BSTT(BTNode *cur, char c);
BTNode *removeNode(BTNode *root, char c);
BTNode *Successor(BTNode *root);

int main()
{
    BTNode *root = NULL;
    root = insertNode(root, 'H');
    root = insertNode(root, 'E');
    root = insertNode(root, 'L');
    root = insertNode(root, 'B');
    root = insertNode(root, 'F');
    root = insertNode(root, 'J');
    root = insertNode(root, 'A');
    root = insertNode(root, 'C');
    root = insertNode(root, 'G');
    root = insertNode(root, 'I');
    root = insertNode(root, 'K');
    root = insertNode(root, 'D');

    printf("Inorder traversal: \n");
    inorder(root);
    printf("\n");
    printf("Can you find J?\n");
    BSTT(root, 'J');
    printf("After deleting: \n");
    removeNode(root, 'J');
    printf("Inorder traversal: \n");
    inorder(root);
    printf("\n");
    printf("Can you find J?\n");
    BSTT(root, 'J');
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

BTNode *insertNode(BTNode *root, char c)
{
    // Return a new node if the tree is empty
    if (root == NULL) return newNode(c);

    else if (root->item == c)
        printf("%c is already in the BST!\n", c);

    else
    {
        // Traverse to the right place and insert the node
        if (root->item > c)
            root->left = insertNode(root->left, c);
        else
            root->right = insertNode(root->right, c);
    }
    
    return root;
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

BTNode *removeNode(BTNode *root, char c)
{
    BTNode *tmp = NULL, *suc = NULL;

    // Return if the tree is empty
    if (root == NULL) return root;

    // Find the node to be deleted
    if (root->item < c)
        root->right = removeNode(root->right, c);
    else if (root->item > c)
        root->left = removeNode(root->left, c);
    else
    {
        // If the node is with only one child or no child 
        if (root->left == NULL)
        {
            tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            tmp = root->left;
            free(root);
            return tmp;
        }
    // If the node has two children
    suc = Successor(root->right);
    // Place the successor in position of the node to be deleted
    root->item = suc->item;
    // Delete the successor
    root->right = removeNode(root->right, suc->item);
    }
    return root;
}
    
BTNode *Successor(BTNode *root)
{
    while (root && root->left != NULL) root = root->left;
    return root;
}
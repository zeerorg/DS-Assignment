#include<stdio.h>
#include<malloc.h>

typedef struct Node
{
    int key;
    struct Node *left, *right;
} Node;

Node* newNode(int key)
{
    Node *n = (Node*) malloc(sizeof(Node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insertTree(Node* root, int key)
{
    if(root == NULL)    return newNode(key);

    if(key < root->key) root->left = insertTree(root->left, key);

    else if(key > root->key) root->right = insertTree(root->right, key);
}

Node* deleteNode(Node *node, int key)
{
    if(node == NULL)    return node;

    else if (key < node->key)
        node->left = deleteNode(node->left, key);

    else if(key > node->key)
        node->right = deleteNode(node->right, key);

    else
    {
        if(node->left == NULL)
        {
            Node *temp = node->right;
            free(node);
            return temp;
        }

        if(node->right == NULL)
        {
            Node *temp = node->left;
            free(node);
            return temp;
        }

        Node *temp = node->right;
        while(temp->left != NULL)
            temp = temp->left;

        node->key = temp->key;
        node->right = deleteNode(node->right, temp->key);
        return node;
    }
}

void preorder(Node *node)
{
    if(node == NULL)    return;

    printf("%d ", node->key);
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node *node)
{
    if(node == NULL)    return;
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
}

int main()
{
    Node *root = NULL;
    root = insertTree(root, 50);
    root = insertTree(root, 30);
    root = insertTree(root, 20);
    root = insertTree(root, 40);
    root = insertTree(root, 70);
    root = insertTree(root, 60);
    root = insertTree(root, 80);

    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    return 0;
}

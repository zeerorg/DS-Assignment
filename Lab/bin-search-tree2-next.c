#include<stdio.h>
#include<malloc.h>
#include<math.h>

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

void preorder(Node *node)
{
    if(node == NULL)    return;
    printf("%d ", node->key);
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node *node)
{
    if(node == NULL)    return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->key);
}

void inorder(Node *node)
{
    if(node == NULL)    return;
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
}

int height(Node* node)
{
    if(node == NULL)    return (0);

    int left = height(node->left);
    int right = height(node->right);
    if(left > right)    return(1 + left);
    else                return(1 + right);
}

int count_node(Node *node)
{
    if(node == NULL)    return 0;
    return 1 + count_node(node->left) + count_node(node->right);
}

int compare_tree(Node *node1, Node *node2)
{
    if( node1 == node2) return 1;
    if( node1 == NULL)  return 0;
    if( node2 == NULL)  return 0;

    if( node1->key == node2->key )
    {
        if( compare_tree(node1->right, node2->right) == 1 && compare_tree(node1->left, node2->left) == 1 )
            return 1;
    }
    else
        return 0;
}

Node* makeCopy(Node *node)
{
    if( node == NULL )  return NULL;

    Node* newN = newNode(node->key);
    newN->left = makeCopy(node->left);
    newN->right = makeCopy(node->right);

    return newN;
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

    printf("\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nHeight: %d", height(root));

    Node *copyTree = makeCopy(root);
    printf("\nInorder Copy: ");
    inorder(copyTree);

    printf("\nPreorder Copy: ");
    preorder(copyTree);

    printf("\nTrue=1 , False=0 : %d ", compare_tree(root, copyTree));
    printf("\nNumber of Nodes: %d", count_node(root));

    return 0;
}

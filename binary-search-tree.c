#include<stdio.h>
#include<stdlib.h>

struct tnode
{
    int data;
    struct tnode *left, *right;
};

void insert(struct tnode **root, int x)
{
    struct tnode* p = (struct tnode*) malloc(sizeof(struct tnode));
    struct tnode* q = *root;
    p->data = x;
    p->left = p->right = NULL;
    if (*root == NULL)
        *root = p;

    else
    {
        while(1)
        {
            if(x < q->data)
                if(q->left != NULL)
                    q = q->left;
                else
                    break;

            if(x > q->data)
                if(q->right != NULL)
                    q = q->right;
                else
                    break;
        }
        if(x < q->data)
            q->left = p;
        else
            q->right = p;
    }
}

void inorder(struct tnode *root)
{
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct tnode *root = NULL;
    insert(&root, 1);
    insert(&root, 12);
    insert(&root, 6);
    inorder(root);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
};

void display(struct node**);
void push(struct node**, struct node**, int);
int pop(struct node**, struct node**);

int main()
{
    struct node *start = NULL, *end = NULL;
    int choice, x;
    do
    {
        printf("\nMENU: \n1.Push \n2.Display \n3.Pop \n4.Exit \nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Give Number to Add: ");
                    scanf("%d", &x);
                    push(&start, &end, x);
                    break;

            case 2: display(&start); break;

            case 3: printf("Poping: %d\n", pop(&start, &end));
                    break;

            case 4: break;
            default: printf("Wrong Choice.\n");
        }

    }while(choice != 4);
    return 0;
}

void push(struct node **start, struct node **end, int x)
{
    struct node *p = (struct node*) malloc(sizeof(struct node));
    p->val = x;
    p->next = NULL;
    if(*start == NULL)  *start = *end = p;
    else
    {
        (*end)->next = p;
        *end = p;
    }
}

void display(struct node **start)
{
    struct node *p = *start;
    if(p == NULL)
    {
        printf("List Empty.\n");
        return;
    }
    printf("List: ");
    while(p->next != NULL)
    {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("%d\n", p->val);
}

int pop(struct node **start, struct node **end)
{
    struct node *p = *start, *q = *end;
    int result;
    if(p == NULL)   return -1;

    if(p == q)
    {
        result = p->val;
        *start = *end = NULL;
    }

    else
    {
        while(p->next != q) p = p->next;
        result = q->val;
        *end = p;
        (*end)->next = NULL;
    }

    free(q);
    return result;
}

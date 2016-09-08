#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
};

void addAtBeg(struct node**, struct node**, int);
void display(struct node**);
void addAtEnd(struct node**, struct node**, int);
void deleteNode(struct node**, struct node**, int x);


int main()
{
    struct node *start = NULL, *end = NULL;
    int choice, x;
    char cont = 'Y';
    do
    {
        printf("\nMENU: \n1.Add At Beginning \n2.Add at End \n3.Display \n4.Delete \n5.Exit \nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Give Number to Add: ");
                    scanf("%d", &x);
                    addAtBeg(&start, &end, x);
                    break;

            case 2: printf("Give Number to Add: ");
                    scanf("%d", &x);
                    addAtEnd(&start, &end, x);
                    break;

            case 3: display(&start); break;

            case 4: printf("Give Number to Delete: ");
                    scanf("%d", &x);
                    deleteNode(&start, &end, x);
                    break;

            case 5: break;
            default: printf("Wrong Choice.\n");
        }

    }while(choice != 5);
    return 0;
}

void addAtBeg(struct node **start, struct node **end, int x)
{
    struct node* p = (struct node*) malloc(sizeof(struct node));
    p->val = x;
    p->next = *start;
    if(*start == NULL)  *start = *end = p;
    else                *start = p;


}

void addAtEnd(struct node **start, struct node **end, int x)
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

void deleteNode(struct node **start, struct node **end, int x)
{
    struct node *p = *start, *prev;
    while((p != NULL) && (p->val != x))
    {
        prev = p;
        p = p->next;
    }

    if(p == NULL)
    {
        printf("Not Found\n");
        return 0;
    }

    printf("Freeing: %d\n", p->val);
    if(p == *start) *start = (*start)->next;

    else if(p == *end)
    {
        *end = prev;
        (*end)->next = NULL;
    }

    else    prev->next = p->next;

    free(p);
    return;
}





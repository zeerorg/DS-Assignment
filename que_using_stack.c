#include<stdio.h>

#define N 50

struct stack
{
    int arr[N];
    int last;
};

void push(struct stack*, int);
int pop(struct stack*);
void addQ(struct stack*, int);
int delQ(struct stack*, struct stack*);
void displayQ(struct stack*, struct stack*);

int main()
{
    struct stack s1, s2;
    s1.last = s2.last = -1;

    addQ(&s1, 4);
    addQ(&s1, 2);
    addQ(&s1, 6);
    addQ(&s1, 8);
    displayQ(&s1, &s2);
    printf("Deleting: %d\n",delQ(&s1, &s2));
    printf("Deleting: %d\n",delQ(&s1, &s2));
    displayQ(&s1, &s2);
    addQ(&s1, 10);
    addQ(&s1, 1);
    displayQ(&s1, &s2);
    printf("Deleting: %d\n",delQ(&s1, &s2));
    displayQ(&s1, &s2);
    return 0;
}

void push(struct stack *s, int x)
{
    if(s->last == N-1) printf("Stack Full");
    else    s->arr[++s->last] = x;
}

int pop(struct stack *s)
{
    if(s->last == -1)   return(-1);
    s->last--;
    return(s->arr[s->last+1]);
}

void addQ(struct stack *s1, int x)
{
    push(s1, x);
}

int delQ(struct stack *s1, struct stack *s2)
{
    if(s2->last == -1)
    {
        while(s1->last != -1)   push(s2, pop(s1));
    }
    return(pop(s2));
}

void displayQ(struct stack *s1, struct stack *s2)
{
    int temp = s2->last;
    printf("Queue: ");
    while(temp >= 0)    printf("%d ",s2->arr[temp--]);
    temp = 0;
    while(temp <= s1->last) printf("%d ",s1->arr[temp++]);
    printf("\n");
}






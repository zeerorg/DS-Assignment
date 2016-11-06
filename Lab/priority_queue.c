#include<stdio.h>

typedef struct item
{
    int value;
    int priority;
} item;

int parent(int i){ return (i-1)/2; }

void swapItem(item H[100], int i, int j)
{
    item temp = H[i];
    H[i] = H[j];
    H[j] = temp;
}

void insert(item H[100], int *n, int value, int priority)
{
    if(*n == 0)
    {
        H[0].value = value;
        H[0].priority = priority;
        (*n)++;
        display(H, *n);
        return;
    }

    H[*n].value = value;
    H[*n].priority = priority;
    (*n)++;
    display(H, *n);
    int i = *n-1;
    while(parent(i) >= 0 && H[i].priority > H[parent(i)].priority)
    {
        swapItem(H, i, parent(i));
        i = parent(i);
    }
    display(H, *n);
}

int getHighestPriority(item H[100])
{
    return H[0].value;
}

void deleteHighestPriority(item H[100], int *n)
{
    swapItem(H, 0, (*n)-1);
    (*n)--;
    display(H, *n);
    int i = 0, left = 2*i + 1, right = 2*i + 2;
    while(right < *n || left < *n)
    {
        if(right < *n && H[left].priority < H[right].priority)
            i = right;
        else if(left < *n && H[left].priority > H[right].priority)
            i = left;

        else
            break;

        swapItem(H, i, parent(i));

        left = 2*i + 1;
        right = 2*i + 2;
    }
}

void display(item H[100], int n)
{
    int i = 0;
    for(i=0; i<n; i++)
        printf("%d ", H[i].value);

    printf("\n");
}

int main()
{
    item H[100];
    int n = 0;
    insert(H, &n, 3, 3);
    insert(H, &n, 11, 11);
    insert(H, &n, 6, 6);
    insert(H, &n, 4, 4);
    insert(H, &n, 10, 10);
    insert(H, &n, 9, 9);
    insert(H, &n, 2, 2);

    display(H, n);

    deleteHighestPriority(H, &n);
    deleteHighestPriority(H, &n);
    display(H, n);
}








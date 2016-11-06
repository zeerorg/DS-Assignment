#include<stdio.h>

struct queue
{
    int arr[100];
    int beg, end;
};

void insert(struct queue*, int);
int del(struct queue*);
void display(struct queue);

int main()
{
      struct queue q;
      int ch, x;
      q.beg = q.end = -1;
      do
      {
        printf("\nMENU: \n1.insert \n2.delete \n3.Display \n4.Exit \nEnter Choice: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
          printf("Enter number to insert: ");
          scanf("%d", &x);
          insert(&q, x);
        }
        else if (ch == 2)
        {
          printf("%d\n",del(&q));
        }
        else if(ch == 3)
        {
          display(q);
        }
      } while(ch!=4);
      return 0;
}

void insert(struct queue *q, int x)
{
    if(q->end == 99)    printf("Queue Full.!\n");

    else if(q->end == -1)
    {
        q->beg = q->end = 0;
        q->arr[q->end] = x;
    }

    else                q->arr[++q->end] = x;
}

int del(struct queue *q)
{
    if(q->beg == -1)    return -1;

    int result = q->arr[q->beg];

    if(q->beg == q->end)    q->beg = q->end = -1;

    else                    q->beg++;
    return result;
}

void display(struct queue q)
{
  int i;
  for(i=q.beg; i<=q.end; i++)
  {
    printf("%d ", q.arr[i]);
  }
}

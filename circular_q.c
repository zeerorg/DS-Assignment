#include<stdio.h>
#define N 40
struct queue
{
    int arr[N];
    int front, rear;
};

void insertQ(struct queue*, int);
int deleteQ(struct queue*);
void displayQ(struct queue*);


int main()
{
    struct queue q;
    q.front = q.rear = -1;
    int choice, x;
    do
    {
        printf("\nMENU: \n1.Insert in Queue \n2.Delete from Queue \n3.Display \n4.Exit \nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Give Number to Add: ");
                    scanf("%d", &x);
                    insertQ(&q, x);
                    break;

            case 2: deleteQ(&q);    break;

            case 3: displayQ(&q); break;

            case 4: break;
            default: printf("Wrong Choice.\n");
        }

    }while(choice != 4);
    return 0;
}

void insertQ(struct queue *q, int x)
{
    if(q->front == -1)
    {
        q->front = q->rear = 0;
        q->arr[0] = x;
    }
    else if((q->rear+1)%N == q->front)  return;
    else
    {
        q->rear = (q->rear+1)%N;
        q->arr[q->rear] = x;
    }
}

void displayQ(struct queue *q)
{
    int scan;
    if(q->front == -1)  printf("Queue Empty\n");
    else
    {
        scan = q->front;
        printf("Queue is: ")
        while(scan != q->rear)
        {
            printf("%d ", q->arr[scan]);
            scan = (scan+1) % N;
        }
        printf("%d\n", q->arr[scan]);
    }

}

int deleteQ(struct queue *q)
{
    int x;
    if(q->front == -1)  return(-1);

    x = q->arr[q->front];

    if(q->front == q->rear)     q->front = q->rear = -1;

    else    q->front = (q->front+1)%N;
    return(x);
}





#include<stdio.h>

struct stack
{
    int arr[100];
    int n;
};

void push(struct stack*, int);
int pop(struct stack*);
void display(struct stack);

int main()
{
  struct stack s1;
  int ch, x;
  s1.n = -1;
  do
  {
    printf("\nMENU: \n1.Push \n2.Pop \n3.Display \n4.Exit \nEnter Choice: ");
    scanf("%d", &ch);
    if (ch == 1)
    {
      printf("Enter number to push: ");
      scanf("%d", &x);
      push(&s1, x);
    }
    else if (ch == 2)
    {
      printf("%d\n",pop(&s1));
    }
    else if(ch == 3)
    {
      display(s1);
    }
  } while(ch!=4);
  return 0;
}

void push(struct stack *s1, int x)
{
  if(s1->n == 99)
  {
    printf("Stack full\n");
  }
  else
  {
    s1->arr[++s1->n] = x;
  }
}

int pop(struct stack *s1)
{
  if (s1->n == -1)
  {
    printf("Stack EMpty\n");
    return -1;
  }
  else
  {
    s1->n--;
    return s1->arr[s1->n+1];
  }
}

void display(struct stack s1)
{
  int i=0;
  for(i=0; i<=s1.n; i++)
  {
    printf("%d ", s1.arr[i]);
  }
}

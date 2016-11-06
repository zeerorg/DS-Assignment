#include<stdio.h>

typedef struct stack
{
  int arr[100];
  int rear;
} stack;

void push(stack* s, int x)
{
  if(s->rear == 100-1)
    printf("stack full!");
  else
  {
    s->rear++;
    s->arr[s->rear] = x;
  }
}

int pop(stack* s)
{
  if(s->rear == -1)
    return -1;
  else
  {
    s->rear--;
    return s->arr[s->rear+1];
  }
}

int isOperand(char ch)
{
  if(ch >= 'a' && ch <= 'd')
    return 1;
  else
    return 0;
}

int isOperator(char ch)
{
  if(ch == '+' || ch == '-' || ch == '/' || ch == '*')
    return 1;
  else
    return 0;
}

int valueOf(char ch)
{
  switch(ch)
  {
    case 'a': return 1;
    case 'b': return 2;
    case 'c': return 3;
    case 'd': return 4;
  }
}

int operation(char op, int x, int y)
{
  switch(op)
  {
    case '+': return (x+y);
    case '-': return (x-y);
    case '*': return (x*y);
    case '/': return (x/y);
  }
}

int main()
{
  char expr[100];
  stack s1;
  int i;

  s1.rear = -1;
  printf("Enter expression with $ at end Example: abc*+$ \n");
  scanf("%s", expr);

  for(i=0; expr[i] != '$'; i++)
  {
    if(isOperand(expr[i]))
      push(&s1, valueOf(expr[i]));
    else if(isOperator(expr[i]))
    {
      int x = pop(&s1);
      int y = pop(&s1);
      int result = operation(expr[i], x, y);
      push(&s1, result);
    }
  }
  printf("%d", pop(&s1));
  return 0;
}

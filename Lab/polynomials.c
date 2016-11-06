#include<stdio.h>
#include<malloc.h>

struct var
{
    int coeff, exp;
    struct var *next;
};

void insertVar(struct var**, int, int);
struct var* makePoly();
struct var* addPoly(struct var*, struct var*);
struct var* multiplyPoly(struct var*, struct var*);
void display(struct var*);

int main()
{
    struct var *p = makePoly();
    struct var *q = makePoly();
    display(p);
    display(q);
    display(addPoly(p, q));
    display(multiplyPoly(p, q));

    return 0;
}

void insertVar(struct var **p, int c, int e)
{
    struct var* q = (struct var*) malloc(sizeof(struct var));
    q->coeff = c;
    q->exp = e;
    q->next = NULL;

    if(*p == NULL)
    {
        *p = q;
        return;
    }

    struct var *r = *p, *parent;
    if(r->exp < e)
    {
        q->next = r;
        r = q;
        return;
    }

    parent = r;
    r = r->next;
    while(r != NULL && r->exp > e)
    {
        parent = r;
        r = r->next;
    }

    q->next = parent->next;
    parent->next = q;
}

struct var* makePoly()
{
    struct var *p = NULL;
    int n, c, e, x;
    printf("Enter number of variables in polynomial: ");
    scanf("%d", &n);
    printf("Enter polynomial (Example: 5x3 6x4 2x1 -3x0) in decreasing exponent : ");
    for(x=0; x<n; x++)
    {
        scanf("%dx%d", &c, &e);
        insertVar(&p, c, e);
    }
    return(p);
}

struct var* addPoly(struct var *p, struct var *q)
{
    int maxExp, x;
    struct var *ans = NULL;
    if((p==NULL) && (q==NULL))  return(NULL);
    else if(p == NULL)  return(q);
    else if(q == NULL)  return(p);

    maxExp = (p->exp > q->exp ? p->exp : q->exp);

    for(x = maxExp; x >= 0; x--)
    {
        if(p != NULL && q != NULL && p->exp == x && q->exp == x)
        {
            insertVar(&ans, p->coeff + q->coeff, x);
            p = p->next;
            q = q->next;
        }
        else if(p != NULL && p->exp == x)
        {
            insertVar(&ans, p->coeff, x);
            p = p->next;
        }
        else if(q != NULL && q->exp == x)
        {
            insertVar(&ans, q->coeff, x);
            q = q->next;
        }
    }

    return(ans);
}

struct var* multiplyPoly(struct var *p, struct var *q)
{
    struct var *ans = NULL, *r1 = p, *r2, *mul;
    while(r1 != NULL)
    {
        r2 = q;
        mul = NULL;
        while(r2 != NULL)
        {
            insertVar(&mul, r1->coeff * r2->coeff, r1->exp + r2->exp);
            r2 = r2->next;
        }
        r1 = r1->next;
        ans = addPoly(ans, mul);
    }
}

void display(struct var *p)
{
    printf("Polynomial: ");
    while(p != NULL)
    {
        printf("%dx%d ", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

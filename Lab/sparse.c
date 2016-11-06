#include<stdio.h>
#include<malloc.h>
#define ROW 3
#define COL 3

typedef struct sparse
{
    int row;
    int col;
    int value;
} Sparse;

void swapSpar(Sparse *mat, int i, int j)
{
    Sparse temp = mat[i];
    mat[i] = mat[j];
    mat[j] = temp;
}

Sparse* getSparse(int mat[ROW][COL], int row, int col)
{
    int i, j, k = 0;
    Sparse *s_mat;
    s_mat = (Sparse*) calloc(30, sizeof(Sparse));
    s_mat[0].row = row;
    s_mat[0].col = col;
    s_mat[0].value = k;

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; ++j)
        {
            if(mat[i][j] != 0)
            {
                k++;
                s_mat[k].row = i;
                s_mat[k].col = j;
                s_mat[k].value = mat[i][j];
                //printf("Value: %d\n", mat[i][j]);
            }
        }
    }
    s_mat[0].value = k;
    return s_mat;
}

Sparse* addSparse(Sparse *mat1, Sparse *mat2)
{
    int i=1, j=1, k=0, ctr=1;
    Sparse *sum;
    sum = (Sparse*) calloc(30, sizeof(Sparse));
    sum[0].row = mat1[0].row;
    sum[0].col = mat1[0].col;

    while(i<=mat1[0].value || j<=mat2[0].value)
    {
        //printf("%d\n", sum[k].value);
        ++k;
        if(i<=mat1[0].value && j<=mat2[0].value && mat1[i].row == mat2[j].row)
        {
            if(mat1[i].col == mat2[j].col)
            {
                sum[k].row = mat1[i].row;
                sum[k].col = mat1[i].col;
                sum[k].value = mat1[i].value + mat2[j].value;
                ++i;
                ++j;
                continue;
            }
        }

        if((i<=mat1[0].value && j>mat2[0].value) ||
         mat1[i].row < mat2[j].row ||
         (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col))
        {
            sum[k].row = mat1[i].row;
            sum[k].col = mat1[i].col;
            sum[k].value = mat1[i].value;
            ++i;
            continue;
        }

        if((i>mat1[0].value && j<=mat2[0].value) ||
        mat1[i].row > mat2[j].row ||
        (mat1[i].row == mat2[j].row && mat1[i].col > mat2[j].col))
        {
            sum[k].row = mat2[j].row;
            sum[k].col = mat2[j].col;
            sum[k].value = mat2[j].value;
            ++j;
            continue;
        }

        //printf("%d ", sum[k].value);
    }

    sum[0].value = k;

    return sum;
}

void display(Sparse *mat)
{
    int k=1;
    for(k=0; k<=mat[0].value; k++)
    {
        printf("%d  %d : %d\n", mat[k].row, mat[k].col, mat[k].value);
    }
    printf("\n");
}

Sparse* transpose(Sparse* a)
{
    int i, j, min;
    Sparse *mat;
    mat = (Sparse*) calloc(30, sizeof(Sparse));
    for(i=0; i<=a[0].value; i++)
        mat[i] = a[i];

    for(i=0; i<=mat[0].value; i++)
    {
        j = mat[i].row;
        mat[i].row = mat[i].col;
        mat[i].col = j;
    }

    for(i=1; i<=mat[0].value; i++)
    {
        min = i;
        for(j = i+1; j<=mat[0].value; j++)
        {
            if(mat[j].col <= mat[min].col)
            {
                min = j;
            }
        }
        if(min != i)
            swapSpar(mat, min, i);
    }

    for(i=1; i<=mat[0].value; i++)
    {
        min = i;
        for(j = i+1; j<=mat[0].value; j++)
        {
            if(mat[j].row <= mat[min].row)
                min = j;
        }
        if(min != i)
            swapSpar(mat, min, i);
    }
    return(mat);
}

Sparse *multiply(Sparse *a, Sparse *oldb)
{
    Sparse *b = transpose(oldb);
    int j=0, r=0, ctr=0, sj=1, k;

    Sparse *pro = (Sparse*) calloc(30, sizeof(Sparse));
    while(r < a[0].row)
    {
        for(sj=1; a[sj].row < r && sj <= a[0].value; ++sj);

        if(a[sj].row > r)
        {
            ++r;
            continue;
        }

        //printf("sj: %d\n", a[sj].row);

        for(k=1; k<=b[0].value; k++)

            for(j=sj; j==sj || a[j-1].row==a[j].row; ++j)
            {
                //printf("%d %d :: %d %d\n", a[j].row, a[j].col, b[k].row, b[k].col);
                if(a[j].col == b[k].col)
                {
                    if(ctr==0 || pro[ctr].row != a[j].row || pro[ctr].col != b[k].row)
                    {
                        ctr++;
                        pro[ctr].row = a[j].row;
                        pro[ctr].col = b[k].row;
                        pro[ctr].value = 0;
                        //printf("%d %d :: %d %d\n", a[j].row, a[j].col, b[k].row, b[k].col);
                    }
                    pro[ctr].value += a[j].value * b[k].value;

                    //printf("%d %d :: %d %d\n", a[j].row, a[j].col, b[k].row, b[k].col);
                }
            }

        ++r;
    }

    pro[0].row = a[0].row;
    pro[0].col = b[0].row;
    pro[0].value = ctr;

    free(b);
    return pro;
}

int main()
{
    int a[ROW][COL] = {
       {0, 5, 0} ,
       {9, 0, 0} ,
       {0, 3, 0}
    };

    int b[ROW][COL] = {
       {0, 8, 0} ,
       {0, 2, 0} ,
       {6, 1, 0}
    };

    int i, j, k;
    /*
    for(i = 0; i<3; i++)
        for(j=0; j<4; j++)
            printf("%d ", a[i][j]);
    printf("\n");
    */

    Sparse *sparse1 = getSparse(a, ROW, COL);
    Sparse *sparse2 = getSparse(b, ROW, COL);
    display(sparse1);
    display(sparse2);

    Sparse *sum = addSparse(sparse1, sparse2);
    display(sum);

    Sparse *tran = transpose(sparse2);
    display(tran);

    Sparse* product = multiply(sparse1, sparse2);
    display(product);
    return 0;
}

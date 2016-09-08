#include<stdio.h>

struct sparse
{
    int row;
    int col;
    int value;
};

int main()
{
    struct sparse mat1[20], mat2[20], sum[20], diff[20];
    int i, j, k;

    printf("Enter first sparse matrix\n");
    scanf("%d %d %d", &mat1[0].row, &mat1[0].col, &mat1[0].value);
    for(i=1; i<=mat1[0].value; ++i)
    {
        scanf("%d %d %d", &mat1[i].row, &mat1[i].col, &mat1[i].value);
    }

    printf("\nEnter second sparse matrix\n");
    scanf("%d %d %d", &mat2[0].row, &mat2[0].col, &mat2[0].value);
    for(i=1; i<=mat2[0].value; ++i)
    {
        scanf("%d %d %d", &mat2[i].row, &mat2[i].col, &mat2[i].value);
    }

    k=1;
    for(i=1; i<=mat1[0].value; ++i)
    {
        for(j=1; j<=mat2[0].value; j++)
        {
            if(mat1[i].row == mat2[j].row && mat1[i].col == mat2[j].col)
            {
                sum[k].value = mat1[i].value + mat2[j].value;
                diff[k].value = mat1[i].value - mat2[j].value;
                sum[k].row = diff[k].row = mat1[i].row;
                sum[k].col = diff[k].col = mat1[i].col;
            }
        }
    }

    return 0;
}

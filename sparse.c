#include<stdio.h>

struct sparse
{
    int row;
    int col;
    int value;
}s_mat[200];

int main()
{
    int mat[20][20], row, col, i, j, k = 0;
    scanf("%d %d", &row, &col);
    s_mat[0].row = row;
    s_mat[0].col = col;
    s_mat[0].value = k;
    for(i=0; i<row; i++)
        for(j=0; j<col; ++j)
        {
            scanf("%d", &mat[i][j]);
        }

    /* Matrix to sparse matrix */
    for(i=0; i<row; i++)
        for(j=0; j<col; ++j)
        {
            if(mat[i][j] != 0)
            {
                k++;
                s_mat[k].row = i;
                s_mat[k].col = j;
                s_mat[k].value = mat[i][j];
            }
        }

    s_mat[0].value = k;
    printf("\nSparse matrix is: ");
    for(i=0; i<=s_mat[0].value; i++)
    printf("\n%d, %d, %d", s_mat[i].row, s_mat[i].col, s_mat[i].value);

    printf("\nEnter sparse matrix\n");
    scanf("%d %d %d", &s_mat[0].row, &s_mat[0].col, &s_mat[0].value);
    for(i=1; i<=s_mat[0].value; ++i)
    {
        scanf("%d %d %d", &s_mat[i].row, &s_mat[i].col, &s_mat[i].value);
    }

    for(i=0; i<s_mat[0].row; i++)
        for(j=0; j<s_mat[0].col; j++)
            mat[i][j] = 0;

    for(k=1; k<=s_mat[0].value; k++)
        mat[s_mat[k].row][s_mat[k].col] = s_mat[k].value;

    printf("\nMatrix is:\n")
    for(i=0; i<s_mat[0].row; i++)
    {
        for(j=0; j<s_mat[0].col; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}

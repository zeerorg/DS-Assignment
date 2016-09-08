#include<stdio.h>

struct sparse{

    int row;
    int col;
    int val;

};

int main(){

    struct sparse a[100],b[100];

    int i,j,A[10][10],r,c,count = 0,k=1;

    scanf("%d %d",&r,&c);

    a[0].row = r;
    a[0].col = c;

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&A[i][j]);
            if(A[i][j]!=0){
                count++;
                a[k].row = i;
                a[k].col = j;
                a[k].val = A[i][j];
                k++;
            }
        }
    }

    a[0].val = count;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    int countmatrix[100] = {0} ,m[100];

    for(i=1;i<count+1;i++){
        countmatrix[a[i].col]++;
    }

    m[0] = 1;

    for(i=1;i<c;i++){

        m[i] =m[i-1] + countmatrix[i-1];

    }

    for(i=1;i<count+1;i++){

        b[m[a[i].col]].row = a[i].col;
        b[m[a[i].col]].col = a[i].row;
        b[m[a[i].col]].val = a[i].val;
        m[a[i].col]++;

    }

    k=1;

    for(i=0;i<c;i++){
        for(j=0;j<r;j++){

            if(i==b[k].row && j == b[k].col){

                printf("%6d ", b[k].val);
                k++;

            }

            else{

                printf("%6d ", 0);

            }

        }

        printf("\n");
    }
    return 0;

}

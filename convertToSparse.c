#include<stdio.h>

struct sparse{

    int row;
    int col;
    int val;

};

int main(){

    struct sparse a[100];

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

    for(i=0;i<count+1;i++){
        printf("%d %d %d\n",a[i].row,a[i].col,a[i].val);
    }


    return 0;
}

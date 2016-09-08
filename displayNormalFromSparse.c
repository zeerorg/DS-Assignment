#include<stdio.h>

struct sparse{

    int row;
    int col;
    int val;

};

int main(){

    struct sparse a[8];

    int i,j,r,c,count,k;

    scanf("%d %d %d", &r, &c, &count);

    a[0].row = r;
    a[0].col = c;
    a[0].val = count;

    for(i=1;i<count+1;i++){
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val);
    }

    k=1;
    for(i=0;i<a[0].row;i++){
        for(j=0;j<a[0].col;j++){

            if(i==a[k].row && j == a[k].col){

                printf("%6d ", a[k].val);
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

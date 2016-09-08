#include<stdio.h>
#include<limits.h>
int main(){

    int A[100],n,max = -1,i;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(A[i]>max)
            max = A[i];
    }

    int C[100]={0},M[100];

    for(i=0;i<n;i++){

        C[A[i]]++;

    }

    M[0] = 0;

    for(i=1;i<=max;i++){

     M[i] = M[i-1] + C[i-1];

    }

    int B[n];

    for(i=0;i<n;i++){

        B[M[A[i]]] = A[i];
        M[A[i]]++;

    }

    for(i=0;i<n;i++){

        printf("%d ", B[i]);

    }

    return 0;
}

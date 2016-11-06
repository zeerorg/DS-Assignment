#include<stdio.h>

void swapArr(int A[100], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int partition(int A[100], int start, int end)
{
    int pivot = A[start], i = start+1, j = end, m;
    //printf("%d\n", pivot);
    while(i <= j)
    {
        while(A[i] < pivot)
            i++;
        while(A[j] > pivot && start < j)
            j--;

        if(i < j)   swapArr(A, i, j);
    }
    for(m=start; m<=end; m++)
        printf("%d ", A[m]);

    printf("\n");

    swapArr(A, start, j);
    for(m=start; m<=end; m++)
        printf("%d ", A[m]);

    printf("\n");
    return j;
}

void quickSort(int A[100], int start, int end)
{
    if(start >= end)    return;
    int v = partition(A, start, end);
    quickSort(A, start, v-1);
    quickSort(A, v+1, end);
}

int main()
{
    int A[] = {5, 9, 1, 7, 11, 3, 6};
    int n = 7, i;
    quickSort(A, 0, n-1);
    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    return 0;
}

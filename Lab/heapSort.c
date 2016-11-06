#include<stdio.h>

void swapArr(int A[100], int n, int m)
{
    int temp = A[n];
    A[n] = A[m];
    A[m] = temp;
}

void heapify(int A[100], int n, int i)
{
    int left = 2*i + 1, right = 2*i + 2;
    int large = i;
    printf("%d\n", i);

    if(left < n && A[left] > A[large])
        large = left;

    if(right < n && A[right] > A[large])
        large = right;

    if(large != i)
    {
        swapArr(A, i, large);
        for(i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
        heapify(A, n, large);
    }
}

void makeHeap(int A[100], int n)
{
    int i;
    for( i = n/2; i>=0; i-- )
    {
        heapify(A, n, i);
    }
}

void deleteMax(int A[100], int n)
{
    int x = A[0], i;
    swapArr(A, 0, n-1);
    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
    n = n-1;
    heapify(A, n, 0);
}

void HeapSort(int A[100], int n)
{
    makeHeap(A, n);
    int i = 0;
    for(i=0; i<n; i++)
        printf("%d ", A[i]);

    printf("\n");
    for(i = 0; i < n; i++)
        deleteMax(A, n-i);
}

int main()
{
    //int A[] = {5, 11, 9, 10, 3, 6};
    int A[] = {56,31,63,49,65,93,53,61,92,28,74,22,44,40,87,42,37,36,12,15};
    int n = 20;
    HeapSort(A, n);
    int i = 0;
    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    return 0;
}

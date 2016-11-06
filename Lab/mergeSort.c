#include<stdio.h>

void mergeSort(int A[100], int start, int end)
{
    int mid = (end + start)/2, m;
    //printf("%d %d\n", start, end);
    //printf("%d\n", mid);
    if(start < end)
    {
        mergeSort(A, start, mid);
        mergeSort(A, mid+1, end);
    }
    else
    {
        return;
    }

    //for(m=start; m<end+1; m++)
        //printf("%d ", A[m]);
    int B[100];
    int i = start, j = mid+1, k = 0;
    while(i <= mid || j <= end)
    {
        if(i <= mid && (j > end || A[i] <= A[j]))
        {
            B[k] = A[i];
            i++;
        }
        else if(j <= end && (i > mid || A[j] <= A[i]))
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    for(i=0; i<k; i++)
    {
        A[start+i] = B[i];
    }
}


int main()
{
    int A[] = {5, 9, 1, 7, 11, 3, 6};
    int n = 7, i;
    mergeSort(A, 0, n-1);
    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    return 0;
}

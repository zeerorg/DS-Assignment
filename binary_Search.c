#include<stdio.h>

int binS(int low, int high, int arr[], int num)
{
    int mid = (low + high)/2;
    if(low > high)
        return -1;
    else if(arr[mid] == num)
        return mid;
    else if(arr[mid] > num)
        return binS(low, mid-1, arr, num);
    else if(arr[mid] < num)
        return binS(mid+1, high, arr, num);
}

int main()
{
    int arr[] = {4, 8, 14, 19, 33, 42, 55};
    int n = 8, i;
    int num = 2;
    for(i=0; i<=n; i++)
        printf("%d ", arr[i]);
    printf("\nFinding %d", num);
    printf("\n%d", 1+binS(0, n-1, arr, num));
    num = 33;
    printf("\nFinding %d", num);
    printf("\n%d", 1+binS(0, n-1, arr, num));
    return 0;
}

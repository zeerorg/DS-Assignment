#include<stdio.h>

int main()
{
  int arr[200], count[200], n, sorted[200], max = 0, count_inc[200];
  int i;
  scanf("%d", &n);
  printf("ENter array:\n");
  for(i=0; i<200; ++i)
  {
    count[i] = 0;
    count_inc[i] = 0;
  }

  for(i=0; i<n; ++i)
    {
      scanf("%d", &arr[i]);
      count[arr[i]] += 1;
      if(max < arr[i])
        max = arr[i];
    }

  for(i=0; i<n; i++)
    {
      printf("%d : %d\n", arr[i], count[arr[i]]);
    }

  count_inc[0] = count[0];
  for(i=1; i<=max; ++i)
  {
    count_inc[i] = count_inc[i-1] + count[i];
    printf("%d : %d\n", arr[i], count_inc[arr[i]]);
  }

 /* for(i=0; i<n; ++i)
  {
    sorted[count]
  }
  */
  return 0;
}

#include <stdio.h>

void towerOfHanoi(int n, char beg, char ex, char target)
{
    if(n == 1)
    {
        printf("Move 1 from %c to %c\n", beg, target);
        return;
    }

    towerOfHanoi(n-1, beg, target, ex);
    printf("Move %d from %c to %c\n", n, beg, target);
    towerOfHanoi(n-1, ex, beg, target);
}

int main()
{
    int num;
    printf("Number of pegs. ");
    scanf("%d", &num);
    towerOfHanoi(num, 'A', 'B', 'C');
    return 0;
}

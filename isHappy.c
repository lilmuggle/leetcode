#include <stdio.h>

int digitSquareSum(int n)
{
    int tmp;
    int sum = 0;

    while(n)
    {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }

    return sum;
}

int isHappy(int n)
{
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if(slow == 1)
            return 1;
    return 0;
}

void main()
{
    int number;

    printf("pls input the number: ");
    scanf("%d", &number);
    if(isHappy(number))
        printf("%d is a happy number.\n", number);
    else
        printf("%d is not a happy number.\n", number);
}

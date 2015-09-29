#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>

int hammingWeight(uint32_t n)
{
    int hw = 0;

    while(n != 0)
    {
        if((n % 2) != 0)
            hw++;
        n = n / 2;
    }
    return hw;
}

void main()
{
    int hw;
    uint32_t n;

    scanf("%u", &n);
    hw = hammingWeight(n);
    printf("The hammingWeight is: %d", hw);
}

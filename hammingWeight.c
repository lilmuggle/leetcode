#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>

int hammingWeight(uint32_t n)
{
    int hw = 0;

    while(n)
    {
        if(n & 0x01)
            hw++;
        n >>= 1;
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

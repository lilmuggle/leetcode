#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t number = 0;
    int count = 32;

    while(count > 0)
    {
        number <<= 1;
        if(n & 0x01)
            number++;
        n >>= 1;
        count--;
    }
    return number;
}

void main()
{
    uint32_t n, number;

    scanf("%u", &n);
    number = reverseBits(n);
    printf("After reverse is: %u", number);
}

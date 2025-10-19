#include <stdio.h>
#include <stdint.h>

int64_t suss1(const char *a1, unsigned char *a2)
{
    const char *v3 = a1;
    int64_t result;

    while (1)
    {
        result = sscanf(v3, "%2hhx", a2);
        if ((int)result != 1)
            break;
        v3 += 2;
        ++a2;
        if (v3 == a1 + 32)
            return result;
    }
    return 0;
}

int main()
{
    const char *hex_input = "68607fcb6ffb4feef431032496f5b3b5";
    unsigned char output[16];
    
    suss1(hex_input, output);

    printf("Output bytes (hex):\n");
    for (int i = 0; i < 16; i++)
    {
        printf("%02x ", output[i]);
    }
    printf("\n");

    return 0;
}

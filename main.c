#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

void show_bit_pattern(float number, char *bitPattern)
{
    uint32_t *value_ptr = (uint32_t *)&number;

    uint32_t sign = (*value_ptr >> 31);
    uint32_t exponent = (*value_ptr >> 23) & 0xFF;
    uint32_t fraction = *value_ptr & 0x7FFFFF;

    sprintf(bitPattern, "%d ", sign);
    for (int i = 0; i < 8; i++)
    {
        sprintf(bitPattern + strlen(bitPattern), "%d", (exponent >> (7 - i)) & 0x1);
    }
    sprintf(bitPattern + strlen(bitPattern), " ");
    for (int i = 0; i < 23; i++)
    {
        sprintf(bitPattern + strlen(bitPattern), "%d", (fraction >> (22 - i)) & 0x1);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("A entrade deve possuir o formato: %s val1 op val2\n", argv[0]);
        return 1;
    }

    float value1 = strtof(argv[1], NULL);
    char operation = argv[2][0];
    float value2 = strtof(argv[3], NULL);

    float result;
    switch (operation)
    {
    case '+':
        result = value1 + value2;
        break;
    case '-':
        result = value1 - value2;
        break;
    case '*':
        result = value1 * value2;
        break;
    case '/':
        result = value1 / value2;
        break;
    default:
        printf("Operação inválida: %c\n", operation);
        return 1;
    }

    printf("\nRecebi %f %c %f e o resultado deu %f\n", value1, operation, value2, result);

    char bitPattern[40];
    show_bit_pattern(value1, bitPattern);
    printf("\nval1 : %s = %f\n", bitPattern, value1);

    show_bit_pattern(value2, bitPattern);
    printf("val2 : %s = %f\n", bitPattern, value2);

    show_bit_pattern(result, bitPattern);
    printf("res  : %s = %f\n\n", bitPattern, result);
    return 0;
}
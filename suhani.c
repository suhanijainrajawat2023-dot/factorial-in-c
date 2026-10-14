
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_DIGITS 3000

// Function to calculate factorial using a big integer array
void calculateFactorial(int n)
{
    int result[MAX_DIGITS] = {0};
    int digits = 1;

    result[0] = 1;

    for (int multiplier = 2; multiplier <= n; multiplier++)
    {
        int carry = 0;

        for (int i = 0; i < digits; i++)
        {
            int product = result[i] * multiplier + carry;

            result[i] = product % 10;
            carry = product / 10;
        }

        while (carry > 0)
        {
            if (digits >= MAX_DIGITS)
            {
                printf("Error: Result exceeds storage capacity.\n");
                return;
            }

            result[digits] = carry % 10;
            carry /= 10;
            digits++;
        }
    }

    printf("\nFactorial of %d = ", n);

    for (int i = digits - 1; i >= 0; i--)
    {
        printf("%d", result[i]);
    }

    printf("\n");
}

// Main function
int main(void)
{
    int n;

    printf("====================================\n");
    printf("     ADVANCED FACTORIAL CALCULATOR\n");
    printf("====================================\n");

    printf("Enter a non-negative integer (0-%d): ", MAX_N);

    if (scanf("%d", &n) != 1)
    {
        fprintf(stderr, "Error: Invalid input. Enter an integer.\n");
        return EXIT_FAILURE;
    }

    if (n < 0)
    {
        fprintf(stderr, "Error: Factorial is undefined for negative integers.\n");
        return EXIT_FAILURE;
    }

    if (n > MAX_N)
    {
        fprintf(stderr, "Error: Please enter a number between 0 and %d.\n",
                MAX_N);
        return EXIT_FAILURE;
    }

    calculateFactorial(n);

    printf("\nCalculation completed successfully!\n");

    return EXIT_SUCCESS;
}

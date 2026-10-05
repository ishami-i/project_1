#include "main.h"

void deposit(void)
{
    long double n;

    if (!read_amount("Enter deposit amount: ", &n) || n <= 0)
    {
        printf("Invalid amount.\n");
        return;
    }

    money += n;
    total_deposited += n;
    deposit_count++;

    printf("Deposit successful.\n");
    printf("Current balance: %.2Lf RWF\n", money);
}
#include "main.h"

void withdraw(void)
{
    long double n;

    if (!read_amount("Enter withdrawal amount: ", &n) || n <= 0)
    {
        printf("Invalid amount.\n");
        return;
    }

    if (n > money)
    {
        printf("Transaction rejected: Insufficient balance.\n");
        return;
    }
    
    money -= n;
    total_withdrawn += n;
    withdraw_count++;

    printf("Withdrawal successful.\n");
    printf("Current balance: %.2Lf RWF\n", money);
}
#include "main.h"

void transaction_summary(void)
{
    printf("\n--- Transaction Summary ---\n");
    printf("Deposits made:    %d (total %.2Lf RWF)\n", deposit_count, total_deposited);
    printf("Withdrawals made: %d (total %.2Lf RWF)\n", withdraw_count, total_withdrawn);
    printf("Current balance:  %.2Lf RWF\n", money);
}
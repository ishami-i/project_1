#include "main.h"

long double money = 0;
int deposit_count = 0;
int withdraw_count = 0;
long double total_deposited = 0;
long double total_withdrawn = 0;

void check_balance(void)
{
    printf("Current balance: %.2Lf RWF\n", money);
}

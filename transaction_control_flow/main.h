#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

/* Account state (defined in balance.c) */
extern long double money;
extern int deposit_count;
extern int withdraw_count;
extern long double total_deposited;
extern long double total_withdrawn;

/* Input helpers (defined in main.c) */
void clear_input(void);
int read_amount(const char *prompt, long double *out);

/* Operations */
void deposit(void);
void withdraw(void);
void check_balance(void);
void transaction_summary(void);
void terminate(void);

#endif
# Transaction Control Flow

A menu-driven mobile-money transaction system for an agent, written in C. The agent can process many transactions in one session. Inputs are validated and invalid operations are rejected.

## Files

| File | Purpose |
|------|---------|
| `main.h` | Shared header: account state (`extern`) and function prototypes |
| `main.c` | Menu loop, input helpers (`clear_input`, `read_amount`) and `terminate` |
| `balance.c` | Defines the account state variables and `check_balance` |
| `deposit.c` | `deposit` operation |
| `withdraw.c` | `withdraw` operation |
| `summary.c` | `transaction_summary` operation |

## Features

- Repeats until the agent chooses Exit (`do/while` loop with a `switch`).
- Deposit: rejects non-numeric, zero and negative amounts.
- Withdraw: rejects invalid amounts and amounts above the balance.
- Check balance.
- Transaction summary: number and total of deposits and withdrawals, plus the current balance.
- Invalid menu input (letters, out-of-range numbers) is handled without crashing or looping forever.
- Amounts are shown in RWF with two decimal places.

## Menu

```
===== MOBILE MONEY TRANSACTION SYSTEM =====
1. Deposit
2. Withdraw
3. Check Balance
4. Transaction Summary
5. Exit
Enter choice:
```

## Build and run

```bash
gcc -Wall -Wextra -o momo main.c balance.c deposit.c withdraw.c summary.c
./momo
```

## Sample session

```
Enter choice: 1
Enter deposit amount: 5000
Deposit successful.
Current balance: 5000.00 RWF

Enter choice: 2
Enter withdrawal amount: 8000
Transaction rejected: Insufficient balance.

Enter choice: 2
Enter withdrawal amount: 1500
Withdrawal successful.
Current balance: 3500.00 RWF

Enter choice: 4

--- Transaction Summary ---
Deposits made:    1 (total 5000.00 RWF)
Withdrawals made: 1 (total 1500.00 RWF)
Current balance:  3500.00 RWF

Enter choice: 5
Thank you for using the Mobile Money Transaction System. Goodbye!
```

## Design notes

- The shared state (`money`, counts, totals) is defined once in `balance.c` and declared `extern` in `main.h`, so every file sees the same variables.
- No function calls `main()` recursively. Control always returns to the loop in `main`.
- To show whole RWF only, change `%.2Lf` to `%.0Lf` in the `printf` calls.

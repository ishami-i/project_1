#include "main.h"

/* Discard leftover characters up to the end of the line */
void clear_input(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* Prompt for an amount; returns 1 on success, 0 on bad input */
int read_amount(const char *prompt, long double *out)
{
    printf("%s", prompt);

    if (scanf("%Lf", out) != 1)
    {
        clear_input();
        return 0;
    }

    clear_input();
    return 1;
}

void terminate(void)
{
    printf("Thank you for using the Mobile Money Transaction System. Goodbye!\n");
}

static void print_menu(void)
{
    printf("\n===== MOBILE MONEY TRANSACTION SYSTEM =====\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Transaction Summary\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

int main(void)
{
    int choice = 0;

    do
    {
        print_menu();

        if (scanf("%d", &choice) != 1)
        {
            if (feof(stdin))
                break;
            clear_input();
            choice = 0;
        }
        else
        {
            clear_input();
        }

        switch (choice)
        {
        case 1:
            deposit();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            check_balance();
            break;
        case 4:
            transaction_summary();
            break;
        case 5:
            terminate();
            break;
        default:
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
        }
    } while (choice != 5);

    return 0;
}
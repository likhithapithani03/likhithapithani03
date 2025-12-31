#include <stdio.h>
#include <string.h>

struct Account {
    char name[50];
    int accNo;
    float balance;
};

// Function prototypes
void createAccount(struct Account *acc);
void deposit(struct Account *acc, float amount);
void withdraw(struct Account *acc, float amount);
void checkBalance(struct Account *acc);
void saveToFile(struct Account *acc);

int main() {
    struct Account acc;
    int choice;
    float amount;

    while (1) {
        printf("\n--- Banking System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Save Data to File\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&acc);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&acc, amount);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&acc, amount);
                break;
            case 4:
                checkBalance(&acc);
                break;
            case 5:
                saveToFile(&acc);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Function definitions
void createAccount(struct Account *acc) {
    printf("Enter name: ");
    scanf("%s", acc->name);
    printf("Enter account number: ");
    scanf("%d", &acc->accNo);
    acc->balance = 0;
    printf("Account created successfully!\n");
}

void deposit(struct Account *acc, float amount) {
    acc->balance += amount;
    printf("Deposited %.2f successfully!\n", amount);
}

void withdraw(struct Account *acc, float amount) {
    if (amount > acc->balance) {
        printf("Insufficient balance!\n");
    } else {
        acc->balance -= amount;
        printf("Withdrawn %.2f successfully!\n", amount);
    }
}

void checkBalance(struct Account *acc) {
    printf("Account: %d | Name: %s | Balance: %.2f\n", acc->accNo, acc->name, acc->balance);
}

void saveToFile(struct Account *acc) {
    FILE *fp = fopen("bank.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "Account: %d | Name: %s | Balance: %.2f\n", acc->accNo, acc->name, acc->balance);
    fclose(fp);
    printf("Data saved to file successfully!\n");
}

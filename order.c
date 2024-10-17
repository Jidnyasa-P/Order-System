#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_ITEMS 3

struct Item {
    char name[MAX_NAME_LENGTH];
    float price;
};

struct Customer {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
};

void printBill(struct Customer customer, struct Item items[], int quantities[], int itemCount) {
    float total = 0.0;

    printf("\n---------- Shopping Bill ----------\n");
    printf("Customer Name: %s\n", customer.name);
    printf("Phone: %s\n", customer.phone);
    printf("Address: %s\n", customer.address);
    printf("Item\t\t\tQuantity\tPrice (Rs)\tTotal (Rs)\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < itemCount; i++) {
        float itemTotal = items[i].price * quantities[i];
        total += itemTotal;
        printf("%-20s\t%d\t\t%.2f\t%.2f\n", items[i].name, quantities[i], items[i].price, itemTotal);
    }

    printf("-------------------------------------------\n");
    printf("Total Amount: %.2f Rs\n", total);
    printf("-------------------------------------------\n");
}

int main() {
    struct Customer customer;
    struct Item items[MAX_ITEMS] = {
        {"iPhone", 90000.0},
        {"MacBook", 110000.0},
        {"iPods", 20000.0}
    };
    int quantities[MAX_ITEMS] = {0};
    int itemCount = 0;

    // Get customer details
    printf("Enter customer name: ");
    scanf(" %[^\n]s", customer.name);

    printf("Enter customer phone number: ");
    scanf(" %[^\n]s", customer.phone);

    printf("Enter customer address: ");
    scanf(" %[^\n]s", customer.address);

    // Show menu
    printf("\nAvailable items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - Rs %.2f\n", i + 1, items[i].name, items[i].price);
    }

    // Input items to buy
    for (int i = 0; i < MAX_ITEMS; i++) {
        int menuChoice;
        printf("Choose item %d (1-3, or 0 to finish): ", i + 1);
        scanf("%d", &menuChoice);

        if (menuChoice == 0) {
            break; // Exit if user enters 0
        }

        if (menuChoice < 1 || menuChoice > MAX_ITEMS) {
            printf("Invalid choice. Please select a valid item.\n");
            i--; // Repeat this iteration
            continue;
        }

        printf("Enter quantity for %s: ", items[menuChoice - 1].name);
        scanf("%d", &quantities[menuChoice - 1]);
        itemCount++;
    }

    // Print the bill
    printBill(customer, items, quantities, itemCount);

    return 0;
}

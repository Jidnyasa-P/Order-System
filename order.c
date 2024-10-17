#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 15

struct Item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

struct Customer {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
};

void printBill(struct Item items[], int count, struct Customer customer) {
    float total = 0.0;

    printf("\n---------- Shopping Bill ----------\n");
    printf("Customer Name: %s\n", customer.name);
    printf("Phone: %s\n", customer.phone);
    printf("Address: %s\n", customer.address);
    printf("Item\t\t\tQuantity\tPrice (Rs)\tTotal (Rs)\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        float itemTotal = items[i].quantity * items[i].price;
        total += itemTotal;
        printf("%-20s\t%d\t\t%.2f\t%.2f\n", items[i].name, items[i].quantity, items[i].price, itemTotal);
    }

    printf("-------------------------------------------\n");
    printf("Total Amount: %.2f Rs\n", total);
    printf("-------------------------------------------\n");
}

int getValidatedInput(int min, int max) {
    int choice;
    while (1) {
        if (scanf("%d", &choice) != 1 || choice < min || choice > max) {
            printf("Invalid input. Please enter a number between %d and %d: ", min, max);
            while (getchar() != '\n'); // clear invalid input
        } else {
            return choice;
        }
    }
}

int main() {
    struct Item items[MAX_ITEMS];
    struct Customer customer;
    int count = 0;
    const char* menuItems[] = {"iPhone", "MacBook", "iPods"};
    const float prices[] = {90000, 110000, 20000};

    printf("Enter customer name (or type 0 to exit): ");
    scanf(" %[^\n]s", customer.name);
    if (strcmp(customer.name, "0") == 0) {
        printf("Exiting...\n");
        return 0;
    }

    printf("Enter customer phone number (or type 0 to exit): ");
    scanf(" %[^\n]s", customer.phone);
    if (strcmp(customer.phone, "0") == 0) {
        printf("Exiting...\n");
        return 0;
    }

    printf("Enter customer address (or type 0 to exit): ");
    scanf(" %[^\n]s", customer.address);
    if (strcmp(customer.address, "0") == 0) {
        printf("Exiting...\n");
        return 0;
    }

    printf("\nAvailable items:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - Rs %.2f\n", i + 1, menuItems[i], prices[i]);
    }

    printf("Enter the number of different items to purchase (max %d, or type 0 to exit): ", MAX_ITEMS);
    count = getValidatedInput(0, MAX_ITEMS);

    if (count == 0) {
        printf("Exiting...\n");
        printBill(items, 0, customer); 
        return 0;
    }

    for (int i = 0; i < count; i++) {
        int menuChoice;
        while (1) {
            printf("Choose item %d (1-3, or type 0 to exit): ", i + 1);
            menuChoice = getValidatedInput(0, 3);

            if (menuChoice == 0) {
                printf("Exiting...\n");
                printBill(items, i, customer);
                return 0;
            }

            // Set item details based on choice
            strcpy(items[i].name, menuItems[menuChoice - 1]);
            items[i].price = prices[menuChoice - 1];

            printf("Enter quantity for %s (or type 0 to exit): ", items[i].name);
            items[i].quantity = getValidatedInput(0, MAX_ITEMS);

            if (items[i].quantity == 0) {
                printf("Exiting...\n");
                printBill(items, i, customer);
                return 0;
            }
            break;
        }
    }

    printBill(items, count, customer);
    printf("Thank you for your purchase!\n");

    return 0;
}


#include <stdio.h>

#define MAX_ITEMS 100

struct Item {
    char name[50];
    int quantity;
    float price;
};

void printBill(struct Item items[], int count) {
    float total = 0.0;

    printf("\n---------- Shopping Bill ----------\n");
    printf("Item\t\tQuantity\tPrice\tTotal\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        float itemTotal = items[i].quantity * items[i].price;
        total += itemTotal;
        printf("%s\t\t%d\t\t%.2f\t%.2f\n", items[i].name, items[i].quantity, items[i].price, itemTotal);
    }

    printf("-------------------------------------------\n");
    printf("Total Amount: %.2f\n", total);
    printf("-------------------------------------------\n");
}

int main() {
    struct Item items[MAX_ITEMS];
    int count = 0;

    printf("Enter the number of items: ");
    scanf("%d", &count);

    if (count > MAX_ITEMS) {
        printf("Cannot enter more than %d items.\n", MAX_ITEMS);
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter name of item %d: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter quantity of item %d: ", i + 1);
        scanf("%d", &items[i].quantity);
        printf("Enter price of item %d: ", i + 1);
        scanf("%f", &items[i].price);
    }

    printBill(items, count);

    return 0;
}

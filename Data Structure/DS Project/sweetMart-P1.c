#include <stdio.h>
#include <string.h>


#define MAX_SWEETS 5


// Define structure for Sweet items
struct SweetItem {
    int id;
    char name[50];
    float price;
};


// Define a list of sweets
struct SweetItem sweets[MAX_SWEETS] = {
    {1, "Gulab Jamun", 10.0},
    {2, "Rasgulla", 12.0},
    {3, "Ladoo", 15.0},
    {4, "Barfi", 20.0},
    {5, "Jalebi", 8.0}
};


// Function to display available sweets
void displaySweets() {
    printf("Available Sweets:\n");
    printf("----------------------------\n");
    for (int i = 0; i < MAX_SWEETS; i++) {
        printf("ID: %d | Name: %s | Price: %.2f\n", sweets[i].id, sweets[i].name, sweets[i].price);
    }
    printf("----------------------------\n");
}


// Function to place an order
void placeOrder() {
    int sweetId, quantity;
    float total = 0.0;


    printf("Enter the ID of the sweet you want to order (0 to finish): ");
    while (1) {
        scanf("%d", &sweetId);
        if (sweetId == 0) break;


        // Validate sweet ID
        int found = 0;
        for (int i = 0; i < MAX_SWEETS; i++) {
            if (sweets[i].id == sweetId) {
                found = 1;
                printf("Enter quantity for %s: ", sweets[i].name);
                scanf("%d", &quantity);
                total += sweets[i].price * quantity;
                printf("Added %d %s to the order. Subtotal: %.2f\n", quantity, sweets[i].name, total);
                break;
            }
        }
        if (!found) {
            printf("Invalid sweet ID. Please try again.\n");
        }


        printf("Enter the ID of another sweet to order (0 to finish): ");
    }


    printf("Total Order Amount: %.2f\n", total);
    printf("Thank you for your order!\n");
}


// Main function
int main() {
    int choice;


    while (1) {
        printf("\nSweet Mart Shop Management\n");
        printf("1. Display Sweets\n");
        printf("2. Place Order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                displaySweets();
                break;
            case 2:
                placeOrder();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }


    return 0;
}
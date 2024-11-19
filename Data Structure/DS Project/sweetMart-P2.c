#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product (sweet item)
typedef struct Sweet {
    int id;
    char name[50];
    float price;
    int stock; // Quantity of the product in stock
} Sweet;

// Structure for binary search tree node
typedef struct BSTNode {
    Sweet product;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Root of the binary search tree
BSTNode* root = NULL;

// Function to create a new BST node
BSTNode* createNode(int id, char *name, float price, int stock) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->product.id = id;
    strcpy(newNode->product.name, name);
    newNode->product.price = price;
    newNode->product.stock = stock;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a product into the binary search tree (BST)
BSTNode* insert(BSTNode* root, int id, char *name, float price, int stock) {
    if (root == NULL) {
        return createNode(id, name, price, stock);
    }
    
    if (id < root->product.id) {
        root->left = insert(root->left, id, name, price, stock);
    } else if (id > root->product.id) {
        root->right = insert(root->right, id, name, price, stock);
    }
    
    return root;
}

// Function to search for a product by ID in the BST
BSTNode* search(BSTNode* root, int id) {
    if (root == NULL || root->product.id == id) {
        return root;
    }
    
    if (id < root->product.id) {
        return search(root->left, id);
    }
    
    return search(root->right, id);
}

// Function to update stock of a product in the BST
void updateStock(BSTNode* root, int id, int quantity) {
    BSTNode* node = search(root, id);
    if (node != NULL) {
        if (node->product.stock >= quantity) {
            node->product.stock -= quantity;
            printf("Order placed successfully for %d %s(s). Remaining stock: %d\n",
                   quantity, node->product.name, node->product.stock);
        } else {
            printf("Insufficient stock for %s. Only %d left.\n", node->product.name, node->product.stock);
        }
    } else {
        printf("Product not found in the inventory!\n");
    }
}

// Function to display a product's details
void displayProduct(Sweet product) {
    printf("ID: %d\n", product.id);
    printf("Name: %s\n", product.name);
    printf("Price: %.2f\n", product.price);
    printf("Stock: %d\n", product.stock);
}

// Function to display all products in the BST (In-order traversal)
void displayInventory(BSTNode* root) {
    if (root != NULL) {
        displayInventory(root->left);
        displayProduct(root->product);
        displayInventory(root->right);
    }
}

int main() {
    // Insert products into the BST
    root = insert(root, 1, "Ladoo", 5.0, 100);
    root = insert(root, 2, "Barfi", 8.0, 50);
    root = insert(root, 3, "Chocolate", 10.5, 200);
    root = insert(root, 4, "Gulab Jamun", 12.0, 75);
    root = insert(root, 5, "Jalebi", 7.5, 150);
    
    // Display all products in the inventory
    printf("\nProduct Inventory:\n");
    displayInventory(root);
    
    // Search for a product by ID
    int searchId = 3;
    BSTNode* productNode = search(root, searchId);
    if (productNode != NULL) {
        printf("\nProduct found:\n");
        displayProduct(productNode->product);
    } else {
        printf("Product with ID %d not found.\n", searchId);
    }

    // Place an order and update stock
    printf("\nPlacing an order...\n");
    int orderId = 3;
    int orderQuantity = 50;
    updateStock(root, orderId, orderQuantity);  // Order for 50 "Chocolate"
    
    // Display updated inventory
    printf("\nUpdated Inventory:\n");
    displayInventory(root);

    // Place another order (insufficient stock case)
    printf("\nPlacing another order...\n");
    orderId = 2;
    orderQuantity = 60;  // Trying to order 60 "Barfi" (only 50 available)
    updateStock(root, orderId, orderQuantity);

    // Display updated inventory
    printf("\nUpdated Inventory:\n");
    displayInventory(root);

    return 0;
}
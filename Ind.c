#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct Node {
    Item item;
    struct Node *next;
} Node;

Node* createItem(Node *head, int id, char name[], int quantity, float price) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->item.id = id;
    strcpy(newNode->item.name, name);
    newNode->item.quantity = quantity;
    newNode->item.price = price;
    newNode->next = head;
    return newNode;
}

void displayItems(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
               current->item.id, current->item.name, current->item.quantity, current->item.price);
        current = current->next;
    }
}

Node* updateItem(Node *head, int id, char name[], int quantity, float price) {
    Node *current = head;
    while (current != NULL && current->item.id != id) {
        current = current->next;
    }
    if (current != NULL) {
        strcpy(current->item.name, name);
        current->item.quantity = quantity;
        current->item.price = price;
    }
    return head;
}

Node* deleteItem(Node *head, int id) {
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL && current->item.id != id) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        if (previous == NULL) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
    return head;
}

int main() {
    Node *head = NULL;
    int choice, id, quantity;
    char name[50];
    float price;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                printf("Enter Price: ");
                scanf("%f", &price);
                head = createItem(head, id, name, quantity, price);
                break;
            case 2:
                displayItems(head);
                break;
            case 3:
                printf("Enter ID of the item to update: ");
                scanf("%d", &id);
                printf("Enter New Name: ");
                scanf("%s", name);
                printf("Enter New Quantity: ");
                scanf("%d", &quantity);
                printf("Enter New Price: ");
                scanf("%f", &price);
                head = updateItem(head, id, name, quantity, price);
                break;
            case 4:
                printf("Enter ID of the item to delete: ");
                scanf("%d", &id);
                head = deleteItem(head, id);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;   // For stack
struct Node* front = NULL; // For queue
struct Node* rear = NULL;

// ========== STACK OPERATIONS ==========

// Push into stack (Insert at beginning)
void push() {
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Pushed %d\n", value);
}

// Pop from stack (Delete from beginning)
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped value: %d\n", temp->data);
    top = top->next;
    free(temp);
}

// Display stack
void displayStack() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ========== QUEUE OPERATIONS ==========

// Insert into queue (Insert at end)
void insertQ() {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Inserted %d\n", value);
}

// Delete from queue (Delete from beginning)
void deleteQ() {
    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Deleted value: %d\n", temp->data);

    front = front->next;
    if (front == NULL)
        rear = NULL; // Queue becomes empty

    free(temp);
}

// Display queue
void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ========== MAIN MENU ==========
int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Insert (Queue)\n");
        printf("5. Delete (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4: insertQ(); break;
            case 5: deleteQ(); break;
            case 6: displayQueue(); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

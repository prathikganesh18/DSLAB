#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// a) Create doubly linked list
struct node* create(struct node *start) {
    struct node *newnode, *temp;
    int choice = 1;

    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = newnode->next = NULL;

        if (start == NULL) {
            start = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Continue (1/0)? ");
        scanf("%d", &choice);
    }
    return start;
}

// b) Insert new node at left (before start)
struct node* insert_left(struct node *start, int value) {
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    newnode->prev = NULL;
    newnode->next = start;

    if (start != NULL)
        start->prev = newnode;

    start = newnode;
    return start;
}

// c) Delete node based on value
struct node* delete_node(struct node *start, int value) {
    struct node *temp = start;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return start;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return start;
}

// d) Display the list
void display(struct node *start) {
    struct node *temp = start;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct node *start = NULL;
    int choice, value;

    while (1) {
        printf("\n1.Create DLL");
        printf("\n2.Insert at Left");
        printf("\n3.Delete Node");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            start = create(start);
            break;

        case 2:
            printf("Enter value to insert at left: ");
            scanf("%d", &value);
            start = insert_left(start, value);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            start = delete_node(start, value);
            break;

        case 4:
            display(start);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

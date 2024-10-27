#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;  // Initialize top pointer
int size, count = 0;  // size is the maximum stack size, count tracks the current number of elements

void push(int value) {
    if (count == size) {
        printf("Stack overflow\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;  // Point to the previous top
    top = newNode;  // Move top to the new node

    count++;  // Increment the element count
    printf("Pushed element %d\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped element %d\n", top->data);
    top = top->next;  // Move top to the next node
    free(temp);  // Free the memory of the removed node

    count--;  // Decrement the element count
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    printf("Enter the stack size\n");
    scanf("%d", &size);  // Set the maximum stack size

    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the push element\n");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;
int size, count = 0; // size is the max queue size, count tracks the current number of elements

void add(int value) {
    if (count == size) {
        printf("Queue is full\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    count++;  // Increment the element count
    printf("Enqueued in queue %d\n", value);
}

void delete() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued from queue %d\n", front->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL; // If the queue becomes empty, set rear to NULL too
    }

    free(temp);
    count--;  // Decrement the element count
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements are:\n");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    printf("Enter the queue size\n");
    scanf("%d", &size); // Setting the size of the queue

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the Enqueue element\n");
                scanf("%d", &value);
                add(value);
                break;
            case 2:
                delete();
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

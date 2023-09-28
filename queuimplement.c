#include <stdio.h>
#include <stdlib.h>

//Defining the structure node, where data is the value stored and next is the pointer to next node.

typedef struct Node {
    int data;
    struct Node* next;
} NODEPTR;


//Defining queue with the Node, front, and rear

typedef struct queue {
    NODEPTR *front, *rear;
} QUEUE;

//If queue is empty then adds a node, otherwise adds new node at the end of the queue.
void insert(QUEUE *q, int value) {
    NODEPTR* temp = (NODEPTR*)malloc(sizeof(NODEPTR));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

//Deletes the first node of the queue. Updates the temp to front and front to the next node. Free(temp) deletes the first node.
int delete(QUEUE *q) {
    if (q->front == NULL)
        return 0; // return 0 if the queue is empty
    NODEPTR* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return 1; // return 1 if a deletion occurred
}

//Printing the Queue.
void printQueue(QUEUE *q) {
    NODEPTR* temp = q->front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    QUEUE q;
    q.front = q.rear = NULL;

    char input[50];
    int choice, value;

    do {
        printf("\n1. Insert\n2. Delete\n3. Print\n4. Exit\nEnter your choice: ");
        fgets(input, sizeof(input), stdin); //Stores the input in "input"

        if (sscanf(input, "%d", &choice) != 1) { //To check if input is a valid integer.
            printf("Invalid choice!\n");
            continue;
        }

        switch(choice) {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &value);
                while(getchar() != '\n'); // clear input buffer
                insert(&q, value);
                break;

            case 2:
                if (!delete(&q)) // check if a deletion occurred
                    printf("Queue is empty.\n");
                break;

            case 3:
                printQueue(&q);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}

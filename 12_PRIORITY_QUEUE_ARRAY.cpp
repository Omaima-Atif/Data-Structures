#include <iostream>
#include <cstdlib>
using namespace std;

// Structure for a node in the priority queue
struct Queue {
    int data;       // Data of the node
    int priority;   // Priority of the node (higher values indicate higher priority)
    Queue *next;    // Pointer to the next node in the queue
};

// Function to enqueue an element with a given priority into the priority queue
void enqueue(Queue *&head, int value, int priority) {
    Queue *newNode = new Queue;    // Create a new node
    newNode->data = value;          // Assign the data
    newNode->priority = priority;   // Assign the priority
    newNode->next = NULL;           // Initialize next pointer to NULL

    // If the queue is empty or the new element has higher priority than the head
    if (head == NULL || priority > head->priority) {
        newNode->next = head;   // New node becomes the new head
        head = newNode;
    } else {
        Queue *temp = head;
        // Find the position to insert the new node based on priority
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;    // Insert the new node after temp
        temp->next = newNode;
    }
}

// Function to dequeue the element with the highest priority from the priority queue
void dequeue(Queue *&head) {
    // If the queue is empty
    if (head == NULL) {
        cout << "Queue Underflow" << endl;
        return;
    }
    Queue *temp = head;
    head = temp->next;  // Move head to the next node
    cout << "The dequeued value is: " << temp->data << endl; // Print dequeued value
    delete temp;        // Delete the dequeued node
}

// Function to peek at the element with the highest priority in the priority queue
void peek(Queue *head) {
    // If the queue is empty
    if (head == NULL) {
        cout << "Queue Underflow" << endl;
        return;
    }
    cout << "The top value is: " << head->data << endl; // Print top value
}

// Function to display the elements of the priority queue
void display(Queue *head) {
    // Traverse the queue and print each element along with its priority
    while (head != NULL) {
        cout << head->data << "(" << head->priority << ") ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int score = -1;
    int value, priority;
    Queue *head = NULL; // Initialize head pointer to NULL (empty queue)
    
    // Menu-driven loop for interacting with the priority queue
    while (score != 0) {
        cout << "enter 1 to enqueue, 2 to dequeue, 3 to peek, 4 to display, or 0 to exit" << endl;
        cin >> score;
        switch (score) {
            case 1:
                cout << "enter value to insert: ";
                cin >> value;
                cout << "enter priority: ";
                cin >> priority;
                enqueue(head, value, priority); // Enqueue operation
                break;
            case 2: 
                dequeue(head); // Dequeue operation
                break;
            case 3:
                peek(head); // Peek operation
                break;
            case 4:
                cout << "the values in list are" << endl;
                display(head); // Display operation
                break;
            case 0:
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}

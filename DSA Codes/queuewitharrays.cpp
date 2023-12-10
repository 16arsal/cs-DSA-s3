#include <iostream>

class Queue {

public:
    static const int MAX_SIZE = 100; // Maximum size of the queue
    int arr[MAX_SIZE]; // Array to store elements
    int front, rear; // Pointers to the front and rear of the queue
    
    Queue() {
        front = rear = -1; // Initialize an empty queue
    }

    // Enqueue (push) an element
        bool enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return false;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE; // Circular queue
        }
        arr[rear] = value;
        return true;
    }

    // Dequeue (pop) an element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a sentinel value for an empty queue
        }
        int value = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE; // Circular queue
        }
        return value;
    }

    // Peek at the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value for an empty queue
        }
        return arr[front];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }
};
int main() {
    Queue myQueue; // Create an instance of the Queue class

    // Enqueue some elements
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Dequeue elements and display them
    cout << "Dequeued elements: ";
    cout << myQueue.dequeue() << " ";
    cout << myQueue.dequeue() << " ";
    cout << myQueue.dequeue() << " ";
    cout << endl;

    // Peek at the front element
    int frontElement = myQueue.peek();
    cout << "Front element: " << frontElement << endl;

    // Check if the queue is empty
    bool empty = myQueue.isEmpty();
    if (empty) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
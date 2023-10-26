#include <iostream>
using namespace std;

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
            front = 0; // Set front to 0 when enqueuing the first element
        }
        arr[++rear] = value;
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
        } else 
        {
            front++;
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
        return rear == MAX_SIZE - 1;
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Front element: " << myQueue.peek() << endl;

    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;

    myQueue.enqueue(40);

    cout << "Front element: " << myQueue.peek() << endl;

    return 0;
}

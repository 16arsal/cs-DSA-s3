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
            std::cout << "Queue is full. Cannot enqueue " << value << std::endl;
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
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
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
            std::cout << "Queue is empty. Cannot peek." << std::endl;
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

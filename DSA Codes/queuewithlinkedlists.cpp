#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front; // Pointer to the front element
    Node* rear; // Pointer to the rear element

public:
    Queue() {
        front = rear = nullptr; // Initialize an empty queue
    }

    // Enqueue (push) an element
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue (pop) an element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a sentinel value for an empty queue
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr; // Queue is now empty
        }

        return value;
    }

    // Peek at the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value for an empty queue
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

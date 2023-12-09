#include <iostream>

struct Node 
{
    int data;
    Node* next;
    
};

class Stack {

public:

    Node* top; // Pointer to the top element

    Stack() 
    {
        top = nullptr; // Initialize an empty stack
    }

    void push(int value)

    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() 
    {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
             return -1; // Return a sentinel value for an empty stack
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
            return -1; // Return a sentinel value for an empty stack
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

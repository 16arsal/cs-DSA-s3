#include <iostream>
using namespace std;

class Stack {

public:

    static const int MAX_SIZE = 100; // Maximum size of the stack
    int arr[MAX_SIZE]; // Array to store elements
    int top; // Index of the top element

    Stack() 
    {
        top = -1; // Initialize the top index to -1 (empty stack)
    }

    // Check if the stack is empty
    bool isEmpty() 
    {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() 
    {
        return top == MAX_SIZE - 1;
    }

    // Push an element onto the stack
    bool push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push " << value << endl;
            return false;
        }
        arr[++top] = value;
        return true;
    }

    // Pop and return the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; // Return a sentinel value for an empty stack
        }
        return arr[top--];
    }

    // Peek at the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value for an empty stack
        }
        return arr[top];
    }
};

int main() {
    Stack myStack;

    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    cout << "Top element: " << myStack.peek() << endl;

    while (!myStack.isEmpty()) {
        cout << "Popped: " << myStack.pop() << endl;
    }

    return 0;
}

//MUHAMMAD ARSAL 
//2022350

#include <iostream>
#include <queue>

using namespace std; // Use the standard namespace for convenience.

int main() {
    // Step 1: Initialize a queue to represent the checkout line.
    queue<string> checkoutQueue;

    // Step 2: Simulate the arrival of customers by adding them to the queue.
    checkoutQueue.push("Customer 1");
    checkoutQueue.push("Customer 2");
    checkoutQueue.push("Customer 3");

    // Step 3: Simulate the serving of customers by removing them from the queue.
    while (!checkoutQueue.empty()) {
        // Print the customer being served.
        cout << "Serving: " << checkoutQueue.front() << endl;
        // Remove the served customer from the queue.
        checkoutQueue.pop();
    }
    // Step 4: Print a message when the checkout queue is empty.
    if (checkoutQueue.empty()) {
        cout << "Checkout queue is empty. No more customers." << endl;
    }

    return 0;}

/*

CODE LOGIC EXPLAINATION 
This C++ program uses a queue to model a supermarket checkout process. 
It initializes a queue to represent the checkout line, adds customers, 
serves them in a first-in-first-out order, and prints the order of service. 
The program also handles edge cases, such as an empty queue, and communicates 
relevant messages throughout the process.

*/

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) : data(value), next(NULL) {}
/*YOU CAN ALSO REWRITE ABOVE CONSTRUCTOR instead of member-initilizer list
	 Node(int value) {
	 	data=value;
		  next=NULL;
	 } */
};

int main() {

    int num[] = {1, 2, 3, 4, 5}; // Sample array
  //  int k = 5; // Sample value of k
    Node* head = new Node(num[0]);
    Node* curr = head;

    for (int itr = 1; itr < 5; ++itr) {
        curr->next = new Node(num[itr]);
        curr = curr->next;
    }

    // Print the linked list for verification
    curr = head;
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }

    // Clean up memory
    curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
 
}


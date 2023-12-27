#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    // Function to delete the first node in a linked list
    void deleteFirstNode() {
        if (head == NULL) {
            cout << "The list is already empty." << endl;
            return;
        }

        Node* temp = head;  // Store the current head in a temporary pointer
        head = head->next; // Move the head to the next node
        delete temp;       // Delete the old head

        cout << "First node deleted successfully." << endl;
    }

    // Function to print the elements of the linked list
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Function to add a new node to the front of the list
    void push_front(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
};

int main() {
    LinkedList list;

    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    cout << "Original Linked List: ";
    list.printList();

    list.deleteFirstNode();

    cout << "Linked List after deletion: ";
    list.printList();

    return 0;
}


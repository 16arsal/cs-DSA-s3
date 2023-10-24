#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr; // Initialize an empty list
    }

    // Insertion at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insertion at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Search for a value in the linked list
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Delete the first occurrence of a value
    void deleteNode(int value) {
        if (head == nullptr) {
            return; // Nothing to delete, the list is empty
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }
};

int main() {
    LinkedList myList;

    myList.insertAtBeginning(5);
    myList.insertAtBeginning(10);
    myList.insertAtEnd(15);

    myList.display();

    if (myList.search(10)) {
        cout << "Found 10 in the list." << endl;
    } else {
        cout << "10 not found in the list." << endl;
    }

    myList.deleteNode(10);
    myList.display();

    return 0;
}


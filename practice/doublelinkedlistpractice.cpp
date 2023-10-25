#include <iostream>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insertion at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Display the linked list forward
    void displayForward() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Display the linked list backward
    void displayBackward() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->prev;
        }
        std::cout << "nullptr" << std::endl;
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
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                if (current->next != nullptr) {
                    current->next->prev = current;
                }
                delete temp;
                return;
            }
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList myList;

    myList.insertAtEnd(5);
    myList.insertAtEnd(10);
    myList.insertAtEnd(15);

    myList.displayForward();
    myList.displayBackward();

    if (myList.search(10)) {
        std::cout << "Found 10 in the list." << std::endl;
    } else {
        std::cout << "10 not found in the list." << std::endl;
    }

    myList.deleteNode(10);
    myList.displayForward();

    return 0;
}

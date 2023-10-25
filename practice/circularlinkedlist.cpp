#include <iostream>

struct Node 
{
    int data;
    Node* next;
};

class CircularLinkedList
{
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insertion at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (head == nullptr) {
            newNode->next = newNode; // Point to itself to create the circular link
            head = newNode;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newNode->next = head; // Point the new node to the head to complete the circle
            last->next = newNode; // Update the last node to point to the new node
            head = newNode; // Update the head to the new node
        }
    }

    // Display the circular linked list
    void display() {
        if (head == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        std::cout << " (loop back to the beginning)" << std::endl;
    }
};

int main() 
{
    CircularLinkedList myList;

    myList.insertAtBeginning(5);
    myList.insertAtBeginning(10);
    myList.insertAtBeginning(15);

    myList.display();

    return 0;
}

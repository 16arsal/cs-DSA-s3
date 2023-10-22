#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

class LinkedList 
{ 
public:

    Node* head;

    LinkedList() 
    {
        head = nullptr; // Initialize an empty list
    }

    void insertAtBeginning(int value) 
    {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    }

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
    void display() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}


};





int main()

{
    cout<<"ez";
}
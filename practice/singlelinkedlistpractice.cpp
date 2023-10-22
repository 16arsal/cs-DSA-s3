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

};





int main()

{
    cout<<"ez";
}
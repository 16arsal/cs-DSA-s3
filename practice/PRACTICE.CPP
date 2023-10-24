#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
};

class LinkedList
{
public:
    Node * head;

    LinkedList()
    {
        head = nullptr; // making an empty linked list
    }

    void InsertAtBeginning(int value)
    {
        Node * newnode = new Node;
        newnode->data = value;
        newnode->next = head;
        head = newnode;
    }

    void InsertAtEnd(int value)
    {
        Node * newnode = new Node;   
        newnode->data= value;
        newnode->next= nullptr;
        
        if (head==nullptr)
        {
            
        }

        Node * current = head;
        
        while (current->next!=nullptr)
        {
            current=current->next;
        }
        
        current->next= newnode;

    }
};

int main()
{
    cout<<"ez";
}
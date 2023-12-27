#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}
    
     void insertAtBeginning(int value) {  
	    Node *newNode = new Node(value);  
	    newNode->next = head;  
	    head = newNode;  
    
}
    
    void insertBetween(int valueToInsert, int valueAfter) {
        Node* newNode = new Node(valueToInsert);
        if (head==NULL) {
            head = newNode;
            return;
        }

        Node* prev = NULL;
        Node* current = head;

        while (current!=NULL && current->data != valueAfter) {
            prev = current;
            current = current->next;
        }

        if (prev!=NULL) {
            newNode->next = prev->next->next;
            prev->next->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;


list.insertAtBeginning(40);  
list.insertAtBeginning(30);  
	list.insertAtBeginning(20);  
	list.insertAtBeginning(10);  

    // Assuming values are inserted already
    list.insertBetween(60, 20); // Inserting 60 after 20
    list.display();

    return 0;
}


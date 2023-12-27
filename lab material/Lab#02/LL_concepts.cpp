#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    // Data can be of different data types
    int intValue;
    double floatValue;
    string stringValue;
    Node* next;

    Node(int data) : intValue(data), next(NULL) {}
    Node(double data1) : floatValue(data1), next(NULL) {}
    Node(string data2) : stringValue(data2), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    void append(double data1) {
        Node* newNode = new Node(data1);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    void append(string data2) {
        Node* newNode = new Node(data2);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            if (current->intValue) {
                cout << current->intValue << " ";
            } else if (current->floatValue) {
                cout << current->floatValue << " ";
            } else if (!current->stringValue.empty()) {
                cout << current->stringValue << " ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList llist;

    llist.append(10);
    llist.append(3.14);
    llist.append("Hello");

    llist.display();

    return 0;
}


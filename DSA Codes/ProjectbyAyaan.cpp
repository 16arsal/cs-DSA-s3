#include<iostream>
using namespace std;

class Node{

    public:
        int data;
        Node * next;

        Node(int data){
            this -> data = data;
            this-> next = NULL;
        }

        ~Node (){
            int value = this -> data;

            if(this -> next != NULL){
                delete next;
                this -> next = NULL;
            }
            cout << value << endl;
        }
};

void insert_at_head(Node *&head, Node *&tail, int data){

    if (head == NULL){
        Node * newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else{

        Node * temp = new Node(data);
        temp -> next = head;
        head = temp;
    }
}

void insert_at_tail(Node *&head, Node *&tail, int data){

    if (head == NULL){
        Node * newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else{

        Node * temp = new Node(data);
        tail -> next = temp;
        tail = temp;
    }
}

void deleteNode(int position, Node *&head){
    if(position == 1){
        Node * temp = head;
        head = head -> next;
        delete temp;
    }

    else{

        Node * curr = head;
        Node * prev = NULL;
        int count = 1;

        while (count <= position ){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

void display(Node * head){
    Node * temp = head;

    while (temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
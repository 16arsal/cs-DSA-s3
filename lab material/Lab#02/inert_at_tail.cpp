	#include <iostream>  
	  
	using namespace std;  
  
	// Node class  
	class Node {  
	public:  
	  int data;  
	  Node *next;  
  
	  Node(int value) {  
	   data = value;  
	   next = NULL;  
	  }  
	};  
	// Linked list class  
	class LinkedList {  
	private:  
	  Node *head;  
  
	public:  
  LinkedList() {  
	    head = NULL;  
	  }  
	  //insert two elements
	  void insertAtBeginning(int value) {  
	    Node *newNode = new Node(value);  
	    newNode->next = head;  
	    head = newNode;  
	  }  
	  
	//now insert elements at the end of that elements
	 void insertAtEnd(int value) {  
	    Node *newNode = new Node(value);  
    if (head == NULL) {  
	      head = newNode;  
	      return;  
	    }  
	    Node *temp = head;  
	    while (temp->next != NULL) {  
	      temp = temp->next;  
    }  
	    temp->next = newNode;  
	  }  
  

	  
	void printList() {  
	  Node *temp = head;  
	  while (temp != NULL) {  
	    cout << temp->data << " ";  
    temp = temp->next;  
	  }  
	  cout << endl;  
	}  
	};  
	int main() {  
	// Create a linked list  
	LinkedList list;  
	  
	 	// Insert some nodes at the beginning of the list  
	list.insertAtBeginning(3);  
	list.insertAtBeginning(2);  


   	// Insert some nodes at the end of the list  
	list.insertAtEnd(4);  
	list.insertAtEnd(5);  
    list.insertAtEnd(6);  

	// Print the list  
	cout << "Original list: ";  
	list.printList();  
	  
}

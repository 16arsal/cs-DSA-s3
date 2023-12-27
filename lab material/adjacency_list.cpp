#include <iostream>
using namespace std;
const int V = 4; // Number of vertices in the graph

struct Node {
    int dest;   //vertex of a edge
    Node* next;          // points to the next node in the linked list.
}; 

void printGraph(Node* adj[]) {
   cout << "Adjacency List Representation:" <<endl;
    for (int i = 0; i < V; ++i) {
        Node* temp = adj[i];  //: Initializes a temporary pointer temp to the head of the linked list for vertex i.
        cout << "Vertex " << i << " --> ";
        while (temp != NULL) {
            cout << temp->dest << " ";//Prints the destination vertex stored in the current node pointed by temp.
            temp = temp->next;
        }
    cout << endl;
    }
}

Node* createNode(int dest) {
    Node* newNode = new Node;
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adj[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = adj[dest];
    adj[dest] = newNode;
}

int main() {
    Node* adj[V];
    for (int i = 0; i < V; ++i) {
        adj[i] = NULL;
    }

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    printGraph(adj);

    return 0;
}


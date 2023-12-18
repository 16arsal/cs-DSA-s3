//MUHAMMAD ARSAL
//2022350

#include <iostream>
#include <list>

using namespace std;

struct Node {
  int vertex;
  Node* next;
};

struct Graph {
  int numVertices;
  Node** adjLists;
};

Graph* createGraph(int numVertices) {
  Graph* graph = new Graph();
  graph->numVertices = numVertices;
  graph->adjLists = new Node*[numVertices];
  

  for (int i = 0; i < numVertices; i++) {
    graph->adjLists[i] = nullptr;
  }
  
  return graph;
}


void addEdge(Graph* graph, int src, int dest) {

  Node* newNode = new Node();
  newNode->vertex = dest;
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = new Node();
  newNode->vertex = src;
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void printGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    cout << i << ": ";
    Node* temp = graph->adjLists[i];
    while (temp) {
      cout << temp->vertex << " -> ";
      temp = temp->next;
    }
    cout << endl;
  }
}


int main() {

  Graph* graph = createGraph(5);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);

  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);

  addEdge(graph, 2, 3);

  addEdge(graph, 3, 4);


  printGraph(graph);

  return 0;
}

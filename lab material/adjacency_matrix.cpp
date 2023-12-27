#include <iostream>

const int V = 4; // Number of vertices in the graph

void printGraph(int graph[][V]) {
    std::cout << "Adjacency Matrix Representation:" << std::endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
 int graph[V][V] = {0};

 // Adding edges between vertices
    graph[0][1] = graph[1][0] = 1;
    graph[0][3] = graph[3][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    printGraph(graph);

    return 0;
}
/*
    0  1  2  3
  +------------
0 | 0  1  0  1
1 | 1  0  1  0
2 | 0  1  0  1
3 | 1  0  1  0

*/


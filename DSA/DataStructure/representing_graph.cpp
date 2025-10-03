#include <iostream>
#include <vector>

int main() {
  int V = 4;              // adjacency matrix
  int matrix[4][4] = {0}; // initialize with 0

  // checking if 2 nodes are adjacent is O(1)

  // Add edges (0-1), (0-2), (1-2), (2-3)
  matrix[0][1] = 1;
  matrix[1][0] = 1; // undirected
  matrix[0][2] = 1;
  matrix[2][0] = 1;
  matrix[1][2] = 1;
  matrix[2][1] = 1;
  matrix[2][3] = 1;
  matrix[3][2] = 1;

  // Print adjacency matrix
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++)
      std::cout << matrix[i][j] << " ";
    std::cout << "\n";
  }

  int V2 = 4;              // can also be implemented with list
  std::vector<int> adj[4]; // adjacency list
                           // create an array of 4 vectors on the stack

  // std::vector<std::vector<int>> create vectors of vectors on the heap
  // so can change the amount of vertices at runtime

  // checking if 2 nodes are adjacent is O(degree)

  // Add edges
  adj[0].push_back(1);
  adj[1].push_back(0); // undirected
  adj[0].push_back(2);
  adj[2].push_back(0);
  adj[1].push_back(2);
  adj[2].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(2);

  // Print adjacency list
  for (int i = 0; i < V; i++) {
    std::cout << i << ": ";
    for (int neighbor : adj[i])
      std::cout << neighbor << " ";
    std::cout << "\n";
  }

  std::vector<std::pair<int, int>>
      adj2[4];               // weighted graph
                             // use pair<int, int> to store (neighbor, weight)
  adj2[0].push_back({1, 5}); // edge 0->1 with weight 5

  return 0;
}

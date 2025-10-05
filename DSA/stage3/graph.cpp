#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

void dfs(int node, std::vector<std::vector<int>> &adj,
         std::vector<bool> &visited) {
  visited[node] = true;
  std::cout << node << " "; // process the node

  for (int neighbor :
       adj[node]) { // iterate on the neighbor of adj[node] not the entire graph
    if (!visited[neighbor]) {
      dfs(neighbor, adj, visited);
    }
  }
}

void iterativeDFS(int start, std::vector<std::vector<int>> &adj) {
  int V = adj.size();
  std::vector<bool> visited(V, false); // create a visited vector (list)
  std::stack<int> st;

  st.push(start);

  while (!st.empty()) {
    int node = st.top();
    st.pop();

    if (!visited[node]) {
      visited[node] = true;
      std::cout << node << " "; // process the node

      // push neighbors to stack
      // optional: reverse order to mimic recursive DFS order
      //             for (auto it = adj[node].rbegin(); it != adj[node].rend();
      //             ++it) {
      //          if (!visited[*it])
      //              st.push(*it);

      for (auto it : adj[node]) {
        if (!visited[it])
          st.push(it); // push all the ndoe neighbors into the stack
      }
    }
  }
}

void BFS(int start, std::vector<std::vector<int>> &adj) {
  int V = adj.size();
  std::vector<bool> visited(V, false);
  std::queue<int> q;

  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    std::cout << node << " "; // process the node

    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

void bfsShortestPath(const std::vector<std::vector<int>> &adj, int src) {
  int n = adj.size();
  std::vector<int> dist(
      n, INT_MAX); // distance array .use INT_MAX to represent unvisited
  std::queue<int> q;

  dist[src] = 0;
  q.push(src);

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int neighbor : adj[node]) {
      if (dist[neighbor] == INT_MAX) { // not visited yet
        dist[neighbor] = dist[node] + 1;
        q.push(neighbor);
      }
    }
  }

  // Print shortest distance from src to every node
  std::cout << "Shortest distances from node " << src << ":\n";
  for (int i = 0; i < n; i++) {
    if (dist[i] == INT_MAX)
      std::cout << i << " : Unreachable\n";
    else
      std::cout << i << " : " << dist[i] << "\n";
  }
}
void bfsShortestPathReconstruct(const std::vector<std::vector<int>>& adj, int src, int dest) {
    int n = adj.size();
    std::vector<int> dist(n, INT_MAX);
    std::vector<int> parent(n, -1); // to reconstruct path
    std::queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == INT_MAX) { // not visited yet
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node;   // remember how we got here
                q.push(neighbor);
            }
        }
    }

    // If destination unreachable
    if (dist[dest] == INT_MAX) {
        std::cout << "No path exists from " << src << " to " << dest << "\n";
        return;
    }

    // Reconstruct path
    std::vector<int> path;
    for (int at = dest; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());

    // Output
    std::cout << "Shortest distance: " << dist[dest] << "\n";
    std::cout << "Path: ";
    for (int node : path) {
        std::cout << node << " ";
    }
    std::cout << "\n";
}

int main() {
  int V = 4; // number of vertices
  std::vector<std::vector<int>> adj;
  adj.resize(V);

  // build the graph
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(3);

  std::vector<bool> visited(V, false);

  // start DFS from node 0
  dfs(0, adj, visited);
  std::cout << '\n';

  int V2 = 4;
  std::vector<std::vector<int>> adj2(V2);

  // build graph
  adj2[0].push_back(1);
  adj2[0].push_back(2);
  adj2[1].push_back(3);

  iterativeDFS(0, adj2);
  std::cout << '\n';

  int V3 = 4;
  std::vector<std::vector<int>> adj3(V3);

  // build graph
  adj3[0].push_back(1);
  adj3[0].push_back(2);
  adj3[1].push_back(3);

  BFS(0, adj3);

  int V4 = 6;
    std::vector<std::vector<int>> adj4(V4);

    // Example graph
    adj4[0] = {1, 2};
    adj4[1] = {0, 3, 4};
    adj4[2] = {0, 4};
    adj4[3] = {1, 5};
    adj4[4] = {1, 2, 5};
    adj4[5] = {3, 4};

    bfsShortestPathReconstruct(adj4, 0, 5);
  return 0;
}

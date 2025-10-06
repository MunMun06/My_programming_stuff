#include <algorithm>
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
void bfsShortestPathReconstruct(const std::vector<std::vector<int>> &adj,
                                int src, int dest) {
  int n = adj.size();
  std::vector<int> dist(n, INT_MAX); // distance from src to every nodes
  std::vector<int> parent(n,
                          -1); // to reconstruct path
                               // parent[node] will be the previous node in BFS
  std::queue<int> q;

  dist[src] = 0;
  q.push(src);

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int neighbor : adj[node]) {
      if (dist[neighbor] == INT_MAX) { // not visited yet
        dist[neighbor] = dist[node] + 1;
        parent[neighbor] = node; // remember how we got here
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
  // 5 -> 3 -> 1 -> 0 to 0 -> 1 -> 3 -> 5

  // Output
  std::cout << "Shortest distance: " << dist[dest] << "\n";
  std::cout << "Path: ";
  for (int node : path) {
    std::cout << node << " ";
  }
  std::cout << "\n";
}

bool dfsCycle(int node, int parent, const std::vector<std::vector<int>> &adj,
              std::vector<bool> &visited) {
  visited[node] = true;

  for (int neighbor : adj[node]) {
    if (!visited[neighbor]) {
      if (dfsCycle(neighbor, node, adj, visited))
        return true;
    }
    // if neighbor is visited and not parent → cycle detected
    else if (neighbor != parent) {
      return true; // acted as a base case for the recursive call to return true
    }
  }

  return false;
}

bool hasCycle(const std::vector<std::vector<int>> &adj) {
  int n = adj.size();
  std::vector<bool> visited(n, false);

  for (int i = 0; i < n; ++i) { // for disconnected graph
    if (!visited[i]) {
      if (dfsCycle(i, -1, adj, visited)) // -1 mean the node has no parent
        return true;
    }
  }

  return false;
}

bool dfsCycleDirected(int node, std::vector<std::vector<int>> &adj,
                      std::vector<bool> &visited, std::vector<bool> &recStack) {
  visited[node] = true; // prevent revisit from another component
  recStack[node] =
      true; // mark node as being part of the current DFS call stack
            // "I havent finished exploring the neighbors of this node"

  for (int neighbor : adj[node]) {
    if (!visited[neighbor]) {
      if (dfsCycleDirected(neighbor, adj, visited, recStack))
        return true; // bubble true
    } else if (recStack[neighbor]) {
      // Found a node currently in the recursion stack → back edge
      return true; // base case true
    }
  }

  recStack[node] =
      false; // Backtrack because we finished exploring the neighbors of this
             // node. base case false but still can be visited = true so we dont
             // explore it again from another DFS
  return false; // bubble false
}

bool hasCycleDirected(std::vector<std::vector<int>> &adj, int n) {
  std::vector<bool> visited(n, false);
  std::vector<bool> recStack(n, false);

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      if (dfsCycleDirected(i, adj, visited, recStack))
        return true;
    }
  }
  return false;
}

void dfsTopo(int node, std::vector<std::vector<int>> &adj,
             std::vector<bool> &visited, std::stack<int> &st) {
  visited[node] = true;

  for (int neighbor : adj[node]) {
    if (!visited[neighbor])
      dfsTopo(neighbor, adj, visited, st);
  }

  // When finished exploring all neighbors, push node to stack
  st.push(node);
}

std::vector<int> topologicalSort(int n, std::vector<std::vector<int>> &adj) {
  std::vector<bool> visited(n, false);
  std::stack<int> st; // topo sort stack not DFS stack

  for (int i = 0; i < n; ++i) {
    if (!visited[i])
      dfsTopo(i, adj, visited, st);
  }

  std::vector<int> topo;
  while (!st.empty()) {
    topo.push_back(st.top());
    st.pop();
  }

  return topo;
}

std::vector<int> topoSortKahn(int n, std::vector<std::vector<int>> &adj) {
  std::vector<int> indegree(n, 0);

  // the topo sort need to be on a DAG (directed acyclic graph)

  // Step 1: Compute indegrees
  for (int u = 0; u < n; ++u) {
    for (int v : adj[u]) {
      indegree[v]++;
    }
  }

  // Step 2: Collect all nodes with indegree 0
  std::queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0)
      q.push(i);
  }

  // Step 3: Process nodes
  std::vector<int> topo;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topo.push_back(u);

    // Step 4: Decrease indegree of neighbors
    for (int v : adj[u]) {
      indegree[v]--;
      if (indegree[v] == 0)
        q.push(v);
    }
  }

  // Step 5: Cycle check
  if ((int)topo.size() != n) {
    std::cout << "Graph has a cycle, no valid topological ordering.\n";
  }

  return topo;
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

  std::cout << '\n';

  int V4 = 6;
  std::vector<std::vector<int>> adj4(V4);

  // Example graph
  adj4[0] = {1, 2};
  adj4[1] = {0, 3, 4};
  adj4[2] = {0, 4};
  adj4[3] = {1, 5};
  adj4[4] = {1, 2, 5};
  adj4[5] = {3, 4};

  bfsShortestPath(adj4, 0);
  bfsShortestPathReconstruct(adj4, 0, 5);

  int n = 5;
  std::vector<std::vector<int>> adj5(n);

  // example: 0 - 1 - 2 - 3 - 0 (cycle)
  adj5[0] = {1, 3};
  adj5[1] = {0, 2};
  adj5[2] = {1, 3};
  adj5[3] = {2, 0};
  adj5[4] = {}; // isolated node

  if (hasCycle(adj5))
    std::cout << "Cycle detected\n";
  else
    std::cout << "No cycle\n";

  int n6 = 4;
  std::vector<std::vector<int>> adj6(n6);

  adj6[0] = {1};
  adj6[1] = {2};
  adj6[2] = {0}; // creates a cycle: 0 → 1 → 2 → 0
  adj6[3] = {2};

  if (hasCycleDirected(adj6, n6))
    std::cout << "Cycle detected (directed)\n";
  else
    std::cout << "No cycle\n";

  int n7 = 6;
  std::vector<std::vector<int>> adj7(n7);

  // example: u → v means u must come before v
  adj7[5].push_back(2);
  adj7[5].push_back(0);
  adj7[4].push_back(0);
  adj7[4].push_back(1);
  adj7[2].push_back(3);
  adj7[3].push_back(1);

  std::vector<int> result = topologicalSort(n7, adj7);

  std::cout << "Topological Sort: ";
  for (int node : result)
    std::cout << node << " ";
  std::cout << "\n";

  int n8 = 6;
  std::vector<std::vector<int>> adj8(n8);

  adj8[5].push_back(2);
  adj8[5].push_back(0);
  adj8[4].push_back(0);
  adj8[4].push_back(1);
  adj8[2].push_back(3);
  adj8[3].push_back(1);

  std::vector<int> result2 = topoSortKahn(n8, adj8);

  std::cout << "Topological Sort (Kahn's Algorithm): ";
  for (int node : result)
    std::cout << node << " ";
  std::cout << "\n";

  return 0;
}

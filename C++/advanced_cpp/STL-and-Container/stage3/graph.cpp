#include <algorithm>
#include <climits>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <utility>
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
  std::cout << "Shortest distances from node " << src << ": (bfs)\n";
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
  std::cout << "Shortest distance (bfs): " << dist[dest] << "\n";
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
      indegree[v]++; // increment the indegree of u's neighbors
    }
  }

  // Step 2: Collect all nodes with indegree 0
  std::queue<int> q; // queue of 0 indegree nodes waiting to be process
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0)
      q.push(i);
  }

  // Step 3: Process nodes
  std::vector<int> topo;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topo.push_back(u); // pop from the queue and push the node with indegree 0
                       // to vector topo

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

bool hasCycleKahn(int n, std::vector<std::vector<int>> &adj) {
  std::vector<int> indegree(n, 0);

  // Step 1: Compute indegrees
  for (int u = 0; u < n; ++u) {
    for (int v : adj[u]) {
      indegree[v]++;
    }
  }

  // Step 2: Push all nodes with indegree 0
  std::queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0)
      q.push(i);
  }

  // Step 3: Process nodes
  int count = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    count++;

    // step 4: decrease indegree of neighbors
    for (int v : adj[u]) {
      indegree[v]--;
      if (indegree[v] == 0)
        q.push(v);
    }
  }

  // this algorithm only works on DAG
  // if it cant create a valid topo order, there must be a cycle
  // edges in cycle will never reach indegree 0
  // so if the number of nodes processed (count) < n
  // a cycle exist

  // Step 5: If not all nodes processed → cycle
  return count != n;
}

void silent_dfs(int node, const std::vector<std::vector<int>> &adj,
                std::vector<bool> &visited) {
  visited[node] = true;
  for (int neighbor : adj[node]) {
    if (!visited[neighbor]) {
      silent_dfs(neighbor, adj, visited);
    }
  }
}

int countComponents(int n, const std::vector<std::vector<int>> &adj) {
  std::vector<bool> visited(n, false);
  int count = 0;

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {             // pick a node in a new component
      silent_dfs(i, adj, visited); // run dfs till it stop
      count++; // if dfs stop then 1 connected component is found
    }
  }

  return count;
}

bool isBipartite(int n, const std::vector<std::vector<int>> &adj) {
  std::vector<int> color(n, -1); // -1 = uncolored, 0 and 1 = two colors

  for (int start = 0; start < n;
       ++start) {             // this loop is for disconnected component
    if (color[start] == -1) { // if start is unvisited
      std::queue<int> q;
      q.push(start);
      color[start] = 0;

      while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) { // process all the neighbor of node
          if (color[neighbor] == -1) {
            color[neighbor] = 1 - color[node]; // opposite color
            q.push(neighbor);
          } else if (color[neighbor] == color[node]) {
            // Conflict — not bipartite
            return false;
          }
        }
      }
    }
  }
  return true;
}

void dijkstra(int n, int start,
              const std::vector<std::vector<std::pair<int, int>>> &adj) {
  const int INF = std::numeric_limits<int>::max(); // INF = infinity
  std::vector<int> dist(n, INF); // distance vector populated with infinity
  dist[start] = 0;

  // time complexity O(E log V). If V is the number of vertices, E is the number
  // of edges

  // works on directed weighted graph

  // min-heap: (distance, node)
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq;

  pq.push({0, start}); // start distance to start is 0

  while (!pq.empty()) {
    int d =
        pq.top().first; // shortest distance from start node from last iteration
    int u = pq.top().second; // current node
    pq.pop();

    // Skip outdated distances
    if (d > dist[u]) // dist[u] is the currently known shortest distance from
                     // start node
      continue;

    // Relax all neighbors
    for (auto &neighbor : adj[u]) { // iterate through the neighbor of u
      int v = neighbor.first;
      int weight = neighbor.second;

      if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }

  // Output result
  std::cout << "Shortest distances from node " << start << ": (Dijkstra)\n";
  for (int i = 0; i < n; ++i) {
    if (dist[i] == INF)
      std::cout << i << ": INF\n";
    else
      std::cout << i << ": " << dist[i] << "\n";
  }
}

void dijkstra_path(int n, std::vector<std::vector<std::pair<int, int>>> &adj,
                   int start, int dest) {
  std::vector<int> dist(n, INT_MAX);
  std::vector<int> parent(n, -1);
  dist[start] = 0;

  // not fully explored the graph anymore unlike dijkstra without path
  // reconstruction

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq;

  pq.push({0, start});

  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (d > dist[u])
      continue;

    for (auto edge : adj[u]) {
      int v = edge.first;
      int w = edge.second;

      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        parent[v] = u; // store previous node
        pq.push({dist[v], v});
      }
    }
  }

  // reconstruct path
  std::vector<int> path;
  for (int v = dest; v != -1; v = parent[v])
    path.push_back(v);

  std::reverse(path.begin(), path.end());

  std::cout << "Shortest distance (Dijkstra) = " << dist[dest] << "\nPath: ";
  for (int v : path)
    std::cout << v << " ";
  std::cout << "\n";
}

struct Edge {
  int u, v, w; // u is current node. v is next node. w is weight
};

void bellmanFord(int n, int start, int dest, std::vector<Edge> &edges) {
  std::vector<int> dist(n, INT_MAX);
  std::vector<int> parent(n, -1);
  dist[start] = 0;

  // time complexity O(V*E) if V is number of vertices, E is number of edges

  // works with weighted negative DAG

  // if there are no negative weight to the furthest node
  // the longest possible path of is at most V - 1
  // (no need to visit the first node so - 1)

  // Step 1: Relax edges (V - 1) times
  for (int i = 0; i < n - 1; ++i) {
    for (auto &e : edges) {
      if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
        dist[e.v] = dist[e.u] + e.w;
        parent[e.v] = e.u;
      }
    }
  }

  // Step 2: Check for negative weight cycles
  for (auto &e : edges) {
    if (dist[e.u] != INT_MAX &&
        dist[e.u] + e.w <
            dist[e.v]) { // if this condition is true after the first loop
                         // then there is a negative weight cycle
                         // that will keep lowering every node's distances
      std::cout << "Graph contains a negative weight cycle\n";
      return;
    }
  }

  // Step 3: Reconstruct path
  std::vector<int> path;
  for (int v = dest; v != -1; v = parent[v])
    path.push_back(v);
  std::reverse(path.begin(), path.end());

  std::cout << "Shortest distance (bellman-Ford)= " << dist[dest] << "\nPath: ";
  for (int v : path)
    std::cout << v << " ";
  std::cout << "\n";
}

void floydWarshall(int n, std::vector<std::vector<int>> &graph) {
  std::vector<std::vector<int>> dist =
      graph; // the shortest distance from vertex i to j is dist[i][j]
             // this is an adjacency matrix

  // like bellman-Ford output-wise but for every pair of start and dest nodes

  // check if going from i to j can be improve by going through k
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
          dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  // Check for negative cycles
  for (int i = 0; i < n; ++i) {
    if (dist[i][i] <
        0) { // detect negativ self loop and all negative cycle
             // i to k to i with total negative weight will make dist[i][j]
             // negative and total negative weight means negative cycle
      std::cout << "Graph contains a negative cycle\n";
      return;
    }
  }
  // Print the shortest distance matrix
  std::cout
      << "Shortest distances between every pair of vertices (dist[i][j]):\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dist[i][j] == INT_MAX)
        std::cout << "INF ";
      else
        std::cout << dist[i][j] << " ";
    }
    std::cout << "\n";
  }
}

struct Edge2 {
  int weight;
  int to;
  Edge2(int w, int t) : weight(w), to(t) {}
};

// Prim’s algorithm using min-heap (priority queue)
int primMST(int n, const std::vector<std::vector<Edge2>> &adj) {
  std::vector<bool> inMST(n, false);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq; // (weight, vertex)

  pq.push({0, 0}); // start with pushing weight 0 of node 0
  int totalWeight = 0;

  // Edge and adjacency list are the same. but Edge is cleaner to read

  while (!pq.empty()) {
    auto [weight, u] =
        pq.top(); // weight = pq.first and u = pq.second
                  // because stuff in pq is of type std::pair<int, int>
    pq.pop();

    if (inMST[u])
      continue; // skip node that already in the MST
    inMST[u] = true;
    totalWeight += weight;

    // Add all edges (u -> v)
    for (auto &edge : adj[u]) {
      if (!inMST[edge.to]) {             // if the neighbor is not in the MST
        pq.push({edge.weight, edge.to}); // weight from u to edge.to
      }
    }
  }

  return totalWeight;
}

struct Edge3 {
  int u, v, wt;
};

// -------------------- DSU Implementation --------------------
int find(std::vector<int> &parent, int x) {
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent, parent[x]); // path compression. set parent[x]
                                              // to root and return it
  // return find(parent, parent[x]); this is no compression
}

void unite(std::vector<int> &parent, std::vector<int> &rank, int x, int y) {
  x = find(parent, x);
  y = find(parent, y);
  if (x == y)
    return;

  if (rank[x] < rank[y])
    parent[x] = y;
  else if (rank[x] > rank[y])
    parent[y] = x;
  else {
    parent[y] = x;
    rank[x]++;
  }
}

void kruskal(int n, std::vector<Edge3> &edges) {
  // 1️⃣ Sort edges by weight
  std::sort(edges.begin(), edges.end(),
            [](const Edge3 &a, const Edge3 &b) { return a.wt < b.wt; });

  // Initialize DSU
  // make detecting cycle linear time
  // (not sure if that better than what we had or not)
  std::vector<int> parent(n);
  std::vector<int> rank(n, 0);
  for (int i = 0; i < n; ++i)
    parent[i] = i; // set every node to be its own parent

  int mstWeight = 0;
  std::vector<Edge3> mstEdges; // answer

  // 3️⃣ Process edges
  for (auto &edge : edges) {
    int pu = find(parent, edge.u); // parent u and parent v
    int pv =
        find(parent, edge.v); // u and v and adjacent by the definition of Edge3
    if (pu != pv) { // but DSU are different from edges so this can be true
                    // while the node are adjacent
                    // DSU are for generating solution

      // if 2 edge have the same parent
      // adding an edge create a cycle
      unite(parent, rank, pu, pv); // unite them by modifying parent and rank
      mstWeight += edge.wt;
      mstEdges.push_back(edge); // add the edge to the MST
    }
  }

  // 4️⃣ Output MST
  std::cout << "\nMST Weight (kruskal)= " << mstWeight << "\n";
  std::cout << "Edges in MST:\n";
  for (auto &e : mstEdges)
    std::cout << e.u << " - " << e.v << " : " << e.wt << "\n";
}

void dfs1(int node, std::vector<std::vector<int>> &adj,
          std::vector<bool> &visited, std::stack<int> &st) {
  // dfs1 is to find the topo ordering
  // top is the first node in the topo ordering and so on
  visited[node] = true;
  for (int neighbor : adj[node]) {
    if (!visited[neighbor])
      dfs1(neighbor, adj, visited, st);
  }
  st.push(node);
}

void dfs2(int node, std::vector<std::vector<int>> &adjT,
          std::vector<bool> &visited, std::vector<int> &component) {
  visited[node] = true; // visited is global
  component.push_back(node);
  for (int neighbor : adjT[node]) {
    if (!visited[neighbor])
      dfs2(neighbor, adjT, visited, component);
  }
}

void kosaraju(int n, std::vector<std::vector<int>> &adj) {
  std::stack<int> st;
  std::vector<bool> visited(n, false);

  // Step 1: obtain topological ordering
  for (int i = 0; i < n; ++i) // for disconnected component
    if (!visited[i])
      dfs1(i, adj, visited, st);

  // Step 2: Reverse the graph
  std::vector<std::vector<int>> adjT(n); // T for transposed
  for (int i = 0; i < n; ++i)
    for (int neighbor : adj[i])    // i go to neighbor
      adjT[neighbor].push_back(i); // neighbor go to i

  // Step 3: DFS on reversed graph in the topological order
  std::fill(visited.begin(), visited.end(), false); // reset the visited vector
  std::cout << "Strongly Connected Components (kosaraju's):\n";

  while (!st.empty()) {
    int node = st.top();
    st.pop();

    if (!visited[node]) {
      std::vector<int> component;           // replace the old one every loop
      dfs2(node, adjT, visited, component); // find an SCC

      for (int v : component) // print the SCC
        std::cout << v << " ";
      std::cout << "\n";
    }
  }
}

void tarjanDFS(int u, const std::vector<std::vector<int>> &adj,
               std::vector<int> &disc, std::vector<int> &low,
               std::vector<bool> &onStack, std::stack<int> &st, int &time,
               std::vector<std::vector<int>> &sccs) {

  disc[u] = low[u] = time++; // same as
  // disc[u] = time;
  // low[u] = time;
  // time++;
  st.push(u);
  onStack[u] = true;

  // Explore all neighbors
  for (int v : adj[u]) {
    if (disc[v] == -1) { // Not visited
      tarjanDFS(v, adj, disc, low, onStack, st, time, sccs);
      low[u] = std::min(low[u], low[v]);
      // propogate disc[root]
    } else if (onStack[v]) { // Back edge
      low[u] = std::min(low[u], disc[v]);
      // low[u] = disc[root]
    }
  }
  // after this loop the node with the same low[] is in the same SCC

  // Root node of SCC
  // pop from st until we reach u to get all the component
  if (low[u] == disc[u]) {
    std::vector<int> component;
    int node;
    do {
      node = st.top();
      st.pop();
      onStack[node] = false;
      component.push_back(node);
    } while (node != u);
    sccs.push_back(component);
  }
}

void tarjanSCC(const std::vector<std::vector<int>> &adj) {
  int n = adj.size();
  std::vector<int> disc(n, -1), low(n, -1);
  // disc is id. low is low-link value aka same low are in the same SCC
  std::vector<bool> onStack(n, false);
  std::stack<int> st;
  std::vector<std::vector<int>> sccs;
  int time = 0;

  // only dfs once

  for (int i = 0; i < n; ++i) { // each loop found one SCC
    if (disc[i] == -1)
      tarjanDFS(i, adj, disc, low, onStack, st, time, sccs);
  }

  // Print all SCCs
  std::cout << "Strongly Connected Components (tarjan's):\n";
  for (const auto &comp : sccs) {
    for (int node : comp)
      std::cout << node << " ";
    std::cout << "\n";
  }
}

void dfsBridge(int u, int parent, const std::vector<std::vector<int>> &adj,
               std::vector<int> &disc, std::vector<int> &low,
               std::vector<std::pair<int, int>> &bridges, int &time) {
  disc[u] = low[u] = time++;

  // based on tarjan's
  // SCC in directed graph is cycle in undirected graph
  // any edge not part of a cycle is a bridges
  // bridges are edge that when remove create more connected component
  for (int v : adj[u]) {
    if (v == parent) // parent = previous
      continue;      // skip the edge we came from
    // because we skip parent
    // this graph now behave like a directed graph

    if (disc[v] == -1) { // not visited
      dfsBridge(v, u, adj, disc, low, bridges, time);
      low[u] = std::min(low[u], low[v]);
      // propogate disc[root]

      if (low[v] > disc[u]) {
        // because we check u first
        // disc[u] is always less than low[v]
        // if they are in different cycle
        bridges.push_back({u, v});
      }
    } else {
      // back edge
      low[u] = std::min(low[u], disc[v]);
      // low[u] = disc[root]
    }
  }
}

std::vector<std::pair<int, int>>
findBridges(int n, const std::vector<std::vector<int>> &adj) {
  std::vector<int> disc(n, -1), low(n, -1);
  std::vector<std::pair<int, int>> bridges;
  int time = 0;

  // adj is an undirected graph
  for (int i = 0; i < n; ++i) { // for disconnected component
    if (disc[i] == -1) {
      dfsBridge(i, -1, adj, disc, low, bridges, time);
    }
  }

  return bridges;
}

void dfsArticulation(int u, int parent,
                     const std::vector<std::vector<int>> &adj,
                     std::vector<int> &disc, std::vector<int> &low,
                     std::vector<bool> &isArticulation, int &time) {
  // articulation point are node that when remove create connected component
  // based on tarjan's again
  disc[u] = low[u] = time++;
  int children = 0;

  for (int v : adj[u]) {
    if (disc[v] == -1) { // Not visited
      children++;        // subtree from root that are disjointed
      dfsArticulation(v, u, adj, disc, low, isArticulation, time);

      low[u] = std::min(low[u], low[v]);

      // Case 1: Non-root node
      if (parent != -1 && low[v] >= disc[u])
        // for u to be an articulation point
        // it need a parent (low[parent] will be the same as low[u])
        // and v need to be in a different cycle
        isArticulation[u] = true;
    } else if (v != parent) {
      // Back edge
      low[u] = std::min(low[u], disc[v]);
    }
  }

  // Case 2: Root node
  if (parent == -1 && children > 1)
    // if u have no parent then it is root
    // if u have more than 2 disjointed subtree
    // u is an articulation point
    isArticulation[u] = true;
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

  int n9 = 4;
  std::vector<std::vector<int>> adj9(n9);

  adj9[0].push_back(1);
  adj9[1].push_back(2);
  adj9[2].push_back(0);
  adj9[2].push_back(3);

  if (hasCycleKahn(n9, adj9))
    std::cout << "Graph has a cycle (Kahn's Algorithm).\n";
  else
    std::cout << "Graph has no cycle (Kahn's Algorithm).\n";

  int n10 = 7; // number of vertices
  std::vector<std::vector<int>> adj10(n10);

  // Example: 3 components → {0-1-2}, {3-4}, {5-6}
  adj10[0] = {1};
  adj10[1] = {0, 2};
  adj10[2] = {1};
  adj10[3] = {4};
  adj10[4] = {3};
  adj10[5] = {6};
  adj10[6] = {5};

  std::cout << "Number of connected components: " << countComponents(n10, adj10)
            << '\n';
  int n11 = 6;
  std::vector<std::vector<int>> adj11(n11);

  // Example 1: Bipartite
  adj11[0] = {1, 3};
  adj11[1] = {0, 2};
  adj11[2] = {1, 3};
  adj11[3] = {0, 2};

  // Example 2 (to test): Add an odd-length cycle
  // adj[0] = {1, 2};
  // adj[1] = {0, 2};
  // adj[2] = {0, 1};

  std::cout << (isBipartite(n11, adj11) ? "Graph is Bipartite\n"
                                        : "Graph is NOT Bipartite\n");

  int n12 = 5;
  std::vector<std::vector<std::pair<int, int>>> adj12(n12);

  // u -> v (weight)
  adj12[0].push_back({1, 10});
  adj12[0].push_back({4, 5});
  adj12[1].push_back({2, 1});
  adj12[1].push_back({4, 2});
  adj12[2].push_back({3, 4});
  adj12[3].push_back({0, 7});
  adj12[3].push_back({2, 6});
  adj12[4].push_back({1, 3});
  adj12[4].push_back({2, 9});
  adj12[4].push_back({3, 2});

  dijkstra(n12, 0, adj12);
  std::cout << '\n';

  int n13 = 5;
  std::vector<std::vector<std::pair<int, int>>> adj13(n13);

  // Example graph (undirected)
  adj13[0].push_back({1, 10});
  adj13[0].push_back({4, 5});
  adj13[1].push_back({2, 1});
  adj13[4].push_back({1, 3});
  adj13[4].push_back({2, 9});
  adj13[4].push_back({3, 2});
  adj13[3].push_back({2, 4});

  dijkstra_path(n13, adj13, 0, 2);

  int n14 = 5;
  std::vector<Edge> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
                             {1, 4, 2},  {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

  bellmanFord(n14, 0, 3, edges);

  const int INF = INT_MAX;
  std::vector<std::vector<int>> graph = {
      {0, 3, INF, 5}, {2, 0, INF, 4}, {INF, 1, 0, INF}, {INF, INF, 2, 0}};

  floydWarshall(4, graph);

  int n15 = 5;
  std::vector<std::vector<Edge2>> adj15(n15);

  auto addEdge = [&](int u, int v, int w) {
    adj15[u].push_back(Edge2(w, v));
    adj15[v].push_back(Edge2(w, u)); // Undirected graph
  };
  // lambda function
  // syntax     type name = [](parameters) { body };
  // can only be called inside this function
  // useful for creating local helper function

  addEdge(0, 1, 2);
  addEdge(0, 3, 6);
  addEdge(1, 2, 3);
  addEdge(1, 3, 8);
  addEdge(1, 4, 5);
  addEdge(2, 4, 7);
  addEdge(3, 4, 9);

  std::cout << "Total weight of MST (prim's): " << primMST(n15, adj15) << '\n';

  int n16 = 5;
  std::vector<Edge3> edges2 = {{0, 1, 2}, {0, 3, 6}, {1, 2, 3},
                               {1, 3, 8}, {1, 4, 5}, {2, 4, 7}};

  kruskal(n16, edges2);

  int n17 = 5;
  std::vector<std::vector<int>> adj17(n17);

  // Graph:
  // 0 -> 2, 0 -> 3
  // 1 -> 0
  // 2 -> 1
  // 3 -> 4
  adj17[0] = {2, 3};
  adj17[1] = {0};
  adj17[2] = {1};
  adj17[3] = {4};

  kosaraju(n17, adj17);

  std::vector<std::vector<int>> adj18 = {{1}, {2, 3}, {0}, {4}, {}};
  tarjanSCC(adj18);

  int n18 = 5;
  std::vector<std::vector<int>> adj19(n18);

  // Example graph
  adj19[0] = {1};
  adj19[1] = {0, 2};
  adj19[2] = {1, 3, 4};
  adj19[3] = {2}; // got edged by chatG the first time
  adj19[4] = {2}; // it gave me an example with no bridges

  auto bridges = findBridges(n18, adj19);

  std::cout << "Bridges:\n";
  for (auto [u, v] : bridges)
    std::cout << u << " - " << v << "\n";

  int V5 = 5;
  std::vector<std::vector<int>> adj20(V5);
  adj20[0] = {1, 2};
  adj20[1] = {0, 2};
  adj20[2] = {0, 1, 3, 4};
  adj20[3] = {2, 4};
  adj20[4] = {2, 3};

  std::vector<int> disc(V5, -1), low(V5, -1);
  std::vector<bool> isArticulation(V5, false);
  int time = 0;

  for (int i = 0; i < V5; ++i) {
    if (disc[i] == -1) {
      dfsArticulation(i, -1, adj20, disc, low, isArticulation, time);
    }
  }

  std::cout << "Articulation points:\n";
  for (int i = 0; i < V; ++i)
    if (isArticulation[i])
      std::cout << i << " ";
  std::cout << "\n";

  return 0;
}

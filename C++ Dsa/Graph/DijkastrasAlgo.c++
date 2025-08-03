#include<iostream>
#include<list>
#include<unordered_map>
#include<set>
#include<queue>
// #include<climits> // For INT_MAX

using namespace std;


class graph {
public:
    // Adjacency list: node -> list of (neighbor, weight)
    unordered_map<int, list<pair<int, int>>> adj;

    // Function to add an edge (undirected graph)
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Dijkstra using min-heap (priority_queue)
    void shortestPath1(int src, vector<int>& dist) {
        // Min-heap: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;// Distance to source is 0
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;     // current distance
            int node = pq.top().second; // current node
            pq.pop();

            // Visit all neighbors
            for (auto neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int wt = neighbor.second;

                // If shorter path found
                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }

    // Dijkstra using set (alternative to min-heap)
    void shortestPath2(int src, vector<int>& dist) {
     
        set<pair<int, int>> st;   // Set stores (distance, node), automatically sorted by distance(smaller at top)

        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
           
            auto it = *st.begin(); // Get node with smallest distance
            int d = it.first;
            int node = it.second;
            st.erase(it);

            // Visit all neighbors
            for (auto neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int wt = neighbor.second;

                // If shorter path found
                if (d + wt < dist[adjNode]) {
                    // If previously visited, remove the old (dist, node) from set
                    if (dist[adjNode] != INT_MAX) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    // Update distance and insert the new one
                    dist[adjNode] = d + wt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
    }
};

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    graph g;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    // Initialize distances to all nodes as infinity (INT_MAX)
    vector<int> dist(n, INT_MAX);

    // Run Dijkstra from source using set (or use shortestPath1 for min-heap)
    g.shortestPath2(src, dist);

    // Print shortest distances from source to all other nodes
    cout << "Shortest path from node " << src << " to other nodes:\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }

    return 0;
}

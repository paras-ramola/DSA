#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool directed) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    void displayList() {
        for (auto i : adj) {
            cout << i.first << ": ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void bfsTraversal(int src, unordered_map<int, bool>& visited) {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            cout << temp << " ";

            for (auto i : adj[temp]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void dfsTraversal(int src, unordered_map<int, bool>& visited) {
        visited[src] = true;
        cout << src << " ";
        for (auto i : adj[src]) {
            if (!visited[i]) {
                dfsTraversal(i, visited);
            }
        }
    }
};

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        g.addEdge(u, v, 0); // undirected graph
    }

    cout << "\nAdjacency List:\n";
    g.displayList();

    unordered_map<int, bool> visited;
    cout << "\nBFS Traversal for disconnected graph:\n";
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "\nstarting  node " << i << ": ";
            g.bfsTraversal(i, visited);
            // g.dfsTraversal(i, visited);
        }
    }

    return 0;
}

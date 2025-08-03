#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<stack>
#include<vector>
using namespace std;


//for nodes start with 0 (change for 1 accordingly)


class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool directed) {
        adj[u].push_back(v); //topological sort works only for Directed Acyclic Graph(DAG)

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

    //************** Topological sort using DFS ***************
    void dfs(int node, stack<int>& s, unordered_map<int, bool>& visited) {
        visited[node] = true;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, s, visited);
            }
        }
        s.push(node);  // Post-order
    }

    //************** Topological sort using BFS (Kahn's Algorithm) ***************
    void topologicalSort(int n) {
        vector<int> inDegree(n);
        vector<int> ans;  // store the topological order

        // Calculate in-degree of each node
        for (auto i : adj) {
            for (auto j : i.second) {
                inDegree[j]++;
            }
        }

        queue<int> q;

        // Push all nodes with inDegree = 0 (source nodes)
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // Decrease in-degree of neighbor nodes
            for (auto neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        cout << "\nTopological Sort (BFS - Kahn's Algorithm): ";
        for (int i : ans) {
            cout << i << " ";
        }

        // Check for cycle
        if (ans.size() != n) {
            cout << "\nCycle detected! Topological sort not possible.\n";
        }
        else {
            cout << "\nNo cycle detected.\n";
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
        g.addEdge(u, v, 1); // Directed graph
    }

    cout << "\nAdjacency List:\n";
    g.displayList();

    // *********** DFS-based Topological Sort ************
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.dfs(i, s, visited);
        }
    }

    cout << "\nTopological Sort (DFS): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    //***********   BFS-based Topological Sort *************
    g.topologicalSort(n);

    return 0;
}

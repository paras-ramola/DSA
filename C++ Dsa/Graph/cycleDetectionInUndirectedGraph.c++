#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

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


    bool checkCycleBfs(int start, unordered_map<int, bool>& visited) {
        unordered_map<int, int> parent;
        visited[start] = true;
        parent[start] = -1;

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            for (auto neighbors : adj[temp]) {
                if (visited[neighbors] && neighbors != parent[temp]) {
                    return true;
                }
                else if (!visited[neighbors]) {
                    visited[neighbors] = true;
                    q.push(neighbors);
                    parent[neighbors] = temp;
                }
            }
        }
        return false;
    }

    bool checkCycleDfs(int start, int parent, unordered_map<int, bool>& visited) {
        visited[start] = true;

        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                if (checkCycleDfs(neighbor, start, visited))
                    return true;
            }
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

};


int main() {
    int n, m;
    cout << "Enter no of Nodes and Edges:";
    cin >> n >> m;


    graph g;

    for (int i = 0;i < m;i++) {
        int u, v;
        cout << "Enter Edge:(u,v) ";
        cin >> u >> v;
        g.addEdge(u, v, false);
    }

    unordered_map<int, bool> visited;


    // ************** Cycle Detection Using BFS *******************

    // for (int i = 0;i < n;i++) {
    //     if (!visited[i]) {
    //         if (g.checkCycleBfs(i, visited)) {
    //             cout << "Cycle is present" << endl;
    //             return 0;
    //         }
    //     }
    // }
    // cout << "Cycle Not present" << endl;

    // ************** Cycle Detection Using DFS *******************

    for (int i = 0;i < n;i++) {
        if (!visited[i]) {
            if (g.checkCycleDfs(i, -1, visited)) {
                cout << "Cycle is present" << endl;
                return 0;
            }
        }
    }
    cout << "Cycle Not present" << endl;

}
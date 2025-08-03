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



    bool checkCycleDfs(int start, unordered_map<int, bool>& visited, unordered_map<int, bool> DfsVisited) {
        visited[start] = true;
        DfsVisited[start] = true;

        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                if (checkCycleDfs(neighbor, visited, DfsVisited))
                    return true;
            }
            else if (DfsVisited[neighbor]) {
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
    unordered_map<int, bool> DfsVisited;

    for (int i = 0;i < n;i++) {
        if (!visited[i]) {
            if (g.checkCycleDfs(i, visited, DfsVisited)) {
                cout << "Cycle is present" << endl;
                return 0;
            }
        }
    }
    cout << "Cycle Not present" << endl;

}
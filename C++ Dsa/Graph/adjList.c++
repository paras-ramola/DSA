#include<iostream>
#include<unordered_map>
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
        g.addEdge(u, v, 0);//creating an undirected  Graph
    }

    cout << "Adjacency List: " << endl;
    g.displayList();



}
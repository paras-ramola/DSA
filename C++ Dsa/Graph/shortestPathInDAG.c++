#include<iostream>
#include<stack>
#include<unordered_map>
#include<list>
#include <vector>

using namespace std;


class graph {
public:
    unordered_map<int, list<pair<int, int>>>adj;


    void addEdge(int u, int v, int weight) {
        pair<int, int>p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printEdge() {
        for (auto i : adj) {
            cout << i.first << ": ";
            for (auto j : i.second) {
                cout << "[ " << j.first << "," << j.second << "]";
            }
            cout << endl;
        }
    }

    void dfs(int s, unordered_map<int, bool>& visted, stack<int>& st) {
        visted[s] = true;

        for (auto i : adj[s]) {
            if (!visted[i.first]) {
                dfs(i.first, visted, st);
            }
        }
        st.push(s);
    }

    void addDist(int src, vector<int>& dist, stack<int>& st) {

        dist[src] = 0;

        while (!st.empty()) {
            int temp = st.top();
            st.pop();

            if (dist[temp] != INT_MAX) {
                for (auto i : adj[temp]) {
                    if (dist[i.first] > dist[temp] + i.second) {
                        dist[i.first] = dist[temp] + i.second;
                    }
                }
            }


        }
    }


};



int main() {
    int n, m;
    cout << "Enter the number of nodes and edges:";
    cin >> n >> m;


    graph g;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);


    g.printEdge();

    unordered_map<int, bool>visited;

    stack<int> st;


    for (int i = 0;i < n;i++) {
        if (!visited[i]) {
            g.dfs(i, visited, st);
        }
    }

    int src;
    cout << "Enter a sorce node:";
    cin >> src;
    vector<int>dist(n);
    for (int i = 0;i < n;i++) {
        dist[i] = INT_MAX;
    }


    g.addDist(src, dist, st);

    cout << "shortest path from " << src << ": ";

    for (int i = 0;i < dist.size();i++) {
        cout << dist[i] << " ";
    }

    cout << endl;



}
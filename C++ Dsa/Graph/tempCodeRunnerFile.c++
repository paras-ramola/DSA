#include<iostream>
#include<list>
using namespace std;


class graph {
public:
    unordered_map<int, list<pair<int, int>>>adj;

    void addEdge(int u, int v, int w) {
        //for undirected graph
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }

    void shortestPath(int src, vector<int>& dist) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


        dist[src] = 0;

        pq.push({ 0,src });

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto i : adj[node]) {
                int adjNode = i.first;
                int wt = i.second;

                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    pq.push({ d + wt,adjNode });
                }
            }
        }



    }



};

int main() {
    int n, m;
    cout << "Enter no of nodes and edges:";
    cin >> n >> m;

    graph g;

    cout << "Enter Edge(u,v) with weight(w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int src;
    cout << "Enter source Node: ";
    cin >> src;

    vector<int> dist(n, INT_MAX);

    g.shortestPath(src, dist);

    cout << "Shortest path from " << src << " to all nodes:\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }

    return 0;
}

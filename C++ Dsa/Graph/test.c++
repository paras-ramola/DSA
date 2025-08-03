#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;




class Graph {

public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool directed) {
        adj[u].push_back(v);

        if (!directed) {
            adj[v].push_back(u);
        }
    }



    void  bfsTraversal(int srcNode, unordered_map<int, bool>& visited) {

        queue<int> q;
        q.push(srcNode);
        visited[srcNode] = true;

        while (!q.empty()) {
            int temp = q.front();
            cout << temp << " ";
            q.pop();

            for (auto i : adj[temp]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
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

   bool khans(int n){
    vector<int> inD(n);

    for(auto i:adj){
        for(auto j:i.second){
            inD[j]++;

        }
    }

    queue<int> q;
    vector<int> ans;

    for(auto i:inD){
        if(i==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int temp=q.front();
        q.pop();
        ans.push_back(temp);

        for(auto i:adj[temp]){
            inD[i]--;
            if(inD[i]==0){
                q.push(i);
            }

        }
    }

   }


};

int main() {
    int n, m;
    cout << "Enter the Number of nodes & edges:";
    cin >> n >> m;

    Graph  g;

    for (int i = 0;i < m;i++) {
        int u, v;
        cout << "enter the edge(u,v)";
        cin >> u >> v;
        g.addEdge(u, v, true);
    }

    unordered_map<int, bool>visited;
    unordered_map<int, bool> dfsVisited;

//    for (int i = 0;i < n;i++) {
//         if (!visited[i]) {
//             if (g.checkCycl(i, visited, dfsVisited)) {
//                 cout << "Cycle is present" << endl;
//                 return 0;
//             }
//         }
//     }
//     cout << "Cycle Not present" << endl;

}

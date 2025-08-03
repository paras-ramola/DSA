#include<iostream>
#include<vector>
using namespace std;



void displayMatrix(vector<vector<int>> &mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n, m;
cout << "Enter the number of nodes: ";
cin >> n;
cout << "Enter the number of edges: ";
cin >> m;

vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

for (int i = 0; i < m; i++) {
    int u, v;
    cout << "Enter edge (u v): ";
    cin >> u >> v;
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // Undirected
}

cout<<"Adjacency Matrix: "<<endl;
displayMatrix(adjMatrix);


}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int V;
    Node** adjList;
} Graph;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

bool isCycleUtil(int v, bool visited[], int parent, Graph* graph) {
    visited[v] = true;
    Node* adjNode = graph->adjList[v];
    while (adjNode != NULL) {
        if (!visited[adjNode->dest]) {
            if (isCycleUtil(adjNode->dest, visited, v, graph))
                return true;
        } else if (adjNode->dest != parent) {
            return true;
        }
        adjNode = adjNode->next;
    }
    return false;
}

bool isCycle(Graph* graph) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    for (int u = 0; u < graph->V; u++) {
        if (!visited[u]) {
            if (isCycleUtil(u, visited, -1, graph))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    if (isCycle(graph))
        printf("Graph contains cycle\n");
    else
        printf("Graph does not contain cycle\n");

    return 0;
}

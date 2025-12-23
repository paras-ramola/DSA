#include<stdio.h>
#include<stdlib.h>

#define INFINITY 99999

struct Edge{
    int u,v,w;//u->source/starting vertex,v->Dest. vertex,w->weigth(u,v)
};

struct Graph{
    int V,E;//total no of Verices and Edges
    struct Edge *edge;//struct Edge *edge; means that edge is a pointer that will point to the first element of an array of Edge structures.
                    //This array will hold all the edges in the graph.
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
}

void printSolution(int dist[],int n){

printf("\n Vertex\tDistance from Source Vertex\n");

for(int i=0;i<n;++i){
    printf("%d \t\t %d\n",i,dist[i]);
}


}

void bellmanford(struct Graph *g,int source){

int V=g->V;//total no of vertices
int E=g->E;

int d[V];//Stores the distance of vertices from source

for(int i=0;i<V;i++)    d[i]=INFINITY;

d[source]=0;//source as zero


//Iterating edges V-1 times(Worst Case)
for(int i=1;i<=V-1;i++){
    for(int j=0;j<E;j++){

        int u=g->edge[j].u;
        int v=g->edge[j].v;
        int w=g->edge[j].w;

        if(d[u]!=INFINITY && d[v]>d[u]+w){//algo contdion
            d[v]=d[u]+w;
        }
    }

}
//if  value  updates again after(v-1)times ,cycle exists
for(int i=0;i<E;i++){
    int u=g->edge[i].u;
    int v=g->edge[i].v;
    int w=g->edge[i].w;
    if (d[u] != INFINITY && d[v] > d[u] + w) {
      printf("Negative weight cycle detected!\n");
      return;
    }
}
printSolution(d,V);

}


int main(){


 int V,E,S;  //V = no.of Vertices, E = no.of Edges, S is source vertex
 
printf("Enter number of vertices in graph\n");
    scanf("%d",&V);
 
printf("Enter number of edges in graph\n");
    scanf("%d",&E);
 
printf("Enter your source vertex number\n");
scanf("%d",&S);
 
struct Graph *g=createGraph(V,E);//calling the function to allocate space to these many vertices and edges

    int i;
    for(i=0;i<E;i++){//iterating on edges
        printf("\nEnter edge %d properties: Source, destination, weight respectively\n",i+1);
        scanf("%d",&g->edge[i].u);
        scanf("%d",&g->edge[i].v);
        scanf("%d",&g->edge[i].w);
    }
 

  bellmanford(g,0);
  return 0;
}
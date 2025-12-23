#include<stdio.h>
#define INF 99999


void printSolution(int V,int dist[][V]){
 printf("Shortest distances between every pair of vertices:\n");
 for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
        if(dist[i][j]==INF){
            printf("INF\t");
        }
        else{
            printf("%d\t",dist[i][j]);
        }
    }
    printf("\n");
 }


}
void floydWarshall(int V,int dist[][V]){
//'V' ko phle lene argument m vrna 'dist' ke andr wala 'V' undefined ayega
for(int k=0;k<V;k++){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]>dist[i][k]+dist[k][j]){
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
}
printSolution(V,dist);
}

int main(){
    int V;
    printf("Enter the number of Vertices: ");
    scanf("%d",&V);

    int graph[V][V];

    printf("Enter the adjacency matrix of the graph(%d x %d):\n",V,V);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        
        if(graph[i][j]==0 && i!=j){// If there's no direct edge, set distance to INF
            graph[i][j]=INF;//if i,j are not diagonal element then 0 will be converted to infinity
        }
    }
    }

    floydWarshall(V,graph);
    return 0;
}
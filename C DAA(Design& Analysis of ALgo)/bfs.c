#include<stdio.h>
#include<stdlib.h>
#define max 5

void breadth_first_search(int adj[][max],int visited[],int start){
    int queue[max],rear=-1,front=-1;
    for(int i=0;i<max;i++){
      visited[i]=0;
    }
    queue[++rear]=start;
    ++front;
    visited[start]=1;

    while(rear>=front){
        start=queue[front++];
        printf("%c-",start+65);
        for(int i=0;i<max;i++){
            if(adj[start][i] && visited[i]==0){
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }

}
void depth_first_search(int adj[][max],int visited[],int start){
    int stack[max];
    int top=-1;
    for(int i=0;i<max;i++){
        visited[i]=0;
    }
    stack[++top]=start;
    visited[start]=1;
    while(top!=-1){
        start=stack[top--];
        printf("%c-",start+65);
        for(int i=0;i<max;i++){
        if(adj[start][i] && visited[i]==0){
            stack[++top]=i;
            visited[i]=1;
        }
    }
    }
}


int main(){
    int visited[max]={0};
    int adj[max][max],i,j;
    int choice,size;
    do{
        printf("\nEnter:");
        printf("\n1-Enter Adjanceny Matrix:");
        printf("\n2-Bfs Traversal");
        printf("\n3-Dfs Traveresal");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: printf("\nEnter the Adjancy Matric:");
        for(i=0;i<max;i++){
            for( j=0;j<max;j++){
                scanf("%d",&adj[i][j]);
            }
        }
            break;
        
        case 2:printf("\nBFS Traversal:");
        breadth_first_search(adj,visited,0);//0 is starting node
        break;

        case 3:printf("\nDFS Traversal:");
        depth_first_search(adj,visited,0);

        default:printf("\nWrong Choice");
        exit(0);
            break;
        }
    }while(1);
}
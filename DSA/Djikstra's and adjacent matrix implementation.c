#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define true 1 
#define false 0

int Edges;
int numVertices;

struct edgepair{
    char *v1;
    char *v2;
    int weight;
};

struct vertice{
    char *v;
    int id;
};

struct vertice vertices[100];

void creating_adjMatrix(int adjMatrix[numVertices][numVertices],struct edgepair edges[]){
    int u,v;
    int V = numVertices;
    int E = Edges;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    
    for (int i = 0; i < E; i++) {
        for (int j = 0; j < V; j++) {
            if(!strcmp(edges[i].v1,vertices[j].v)){
                u = vertices[j].id;
            }
            if(!strcmp(edges[i].v2,vertices[j].v)){
                v = vertices[j].id;
            }
        }
        adjMatrix[u][v] = edges[i].weight;
        adjMatrix[v][u] = edges[i].weight;
    }
    
}

int minDistance(int dist[], int sptSet[])
{
    
    int min = INT_MAX, min_index;
   
    for (int v = 0; v < numVertices; v++)
        if (sptSet[v] == false &&
                   dist[v] <= min)
            min = dist[v], min_index = v;
   
    return min_index;
}
   
void printPath(int parent[], int j)
{
       
    if (parent[j] == - 1)
        return;
   
    printPath(parent, parent[j]);
    
    char *temp =(char *)malloc(sizeof(char));
    
    
    for (int i = 0; i < numVertices; i++) {
        if(j == vertices[i].id){
            strcpy(temp,vertices[i].v);
        }
    }
    printf("%s ",temp);
}



void dijkstra(int graph[numVertices][numVertices], int src,int destId,int startId)
{
    int dist[numVertices]; 
    int sptSet[numVertices];
    int parent[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < numVertices - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < numVertices; v++)
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            } 
    }
    printf("%d ",dist[destId]);
    
    char *srcobj =(char *)malloc(sizeof(char));
    for (int i = 0; i < numVertices; i++) {
        if(startId == vertices[i].id){
            strcpy(srcobj,vertices[i].v);
        }
    }
    printf("%s ",srcobj);
    printPath(parent,destId);
    printf("\n");
}

int main()
{
    scanf("%d",&Edges);
    struct edgepair edges[Edges];
    int i = 0;
    char *vert1 = (char *)malloc(30*sizeof(char));
    char *vert2 = (char *)malloc(30*sizeof(char));
    int k=0,flag=0,id=0;
    int weight;
    while(i<Edges){
        scanf("%s %s %d",vert1,vert2,&weight);
        for (int j = 0; j < k; j++) {
            if(!strcmp(vertices[j].v,vert1)){
                flag = 1;
            }
        }
        if(flag == 0){
            vertices[k].v = (char *)malloc(30*sizeof(char));
            strcpy(vertices[k].v,vert1);
            vertices[k].id = id;
            id++;
            k++;
        }
        else{
            flag = 0;
        }
        
        for (int j = 0; j < k; j++) {
            if(!strcmp(vertices[j].v,vert2)){
                flag = 1;
            }
        }
        if(flag == 0){
            
            vertices[k].v = (char *)malloc(30*sizeof(char));
            strcpy(vertices[k].v,vert2);
            vertices[k].id = id;
            k++;
            id++;
            
        }
        else{
            flag = 0;
        }
        edges[i].v1 = (char *)malloc(30*sizeof(char)); 
        edges[i].v2 = (char *)malloc(30*sizeof(char));
        strcpy(edges[i].v1,vert1);
        strcpy(edges[i].v2,vert2);
        edges[i].weight = weight;
        i++;
    }
    numVertices = k;
    int adjMatrix[numVertices][numVertices];
    creating_adjMatrix(adjMatrix,edges);
    
    int startId;
    for (int i = 0; i < numVertices; i++) {
        if(!strcmp("RC",vertices[i].v)){
            startId = vertices[i].id;
        }
    }
    
    char *server = (char *)malloc(30*sizeof(char));
    while(true){
        int destId;
        scanf("%s",server);
        
        if(!strcmp("T",server)){
            break;
        }
        
        for (int i = 0; i < numVertices; i++) {
            if(!strcmp(server,vertices[i].v)){
                destId = vertices[i].id;
            }
        }
        
        dijkstra(adjMatrix,startId,destId,startId);
        
    }
    return 0;
}

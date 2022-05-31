#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1 
#define false 0
#define TEMP 2

int M,N;

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

// --------------------------------------- This is a recursive function for dfs -------------------------------------------

void dfs(int matrix[M][N],int i,int j,int M,int N){
    
    if(i<0||j<0||i>M||j>N||matrix[i][j]!=0){
        return;
    }
    
    matrix[i][j] = TEMP;
    
    dfs(matrix,i+1,j,M,N);
    dfs(matrix,i,j+1,M,N);
    dfs(matrix,i+1,j+1,M,N);
    dfs(matrix,i-1,j-1,M,N);
    dfs(matrix,i+1,j-1,M,N);
    dfs(matrix,i-1,j,M,N);
    dfs(matrix,i,j-1,M,N);
    dfs(matrix,i-1,j+1,M,N);
    
}

// -------------------------------------------------- Capturing Function -------------------------------------------------

void getBoundary(int matrix[M][N],int M,int N){
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if(i == 0 || j == 0 || i == M-1 || j == N-1){
                
                dfs(matrix,i,j,M,N);
            }
        }
    }
    int replacing_count =0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if(matrix[i][j]==0){
                replacing_count++;
            }
        }
    }
    printf("Replaced\n");
    if(replacing_count==0){
        printf("NULL\n");
    }else{
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if(matrix[i][j] == 0){
                printf("%d %d\n",i,j);
                matrix[i][j] = 1;
            }
        }
        }
    }
    printf("Not Replaced\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if(matrix[i][j] == 2){
                printf("%d %d\n",i,j);
                matrix[i][j] = 0;
            }
        }
    }
}



// -------------------------------------- Function for finding element(s) at maximum depth by BFS -------------------------------

struct queue{
    int x;
    int y;
};
int arr[3];

int *shortestPathBinaryMatrix(int matrix[M][N], int M, int N){
    
    struct queue q[10000];
    int front = -1, tail = -1;
    int x, y;
    
    int count=0, temp=0, temp2=1;
    
    q[++tail].x = 0;
    q[tail].y = 0;
    while(front!=tail){     
        count++;
        while((temp2--)!=0){
            
            x = q[++front].x;
            y = q[front].y;           
            
            if(x<0||y<0||x>M||y>N){
                arr[0] = x;
                arr[1] = y;
                arr[2] = count;
                return arr;
            } 
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(!(i==0 && j==0) || x+i>0 || x+i <M || y+j>0 || j+y<N || matrix[x+i][y+j]==0){
                        q[++tail].x = x+i;
                        q[tail].y = y+j;
                        matrix[x+i][y+j] = 2;
                        temp++;
                    }
                }
            }
        }
        temp2 = temp;
        temp=0;        
    } 
}

// ----------------------------------------- boundary pair structs ---------------------------------------------

struct indexPair{
    int xb;
    int yb;
};

struct distpair{
    int x,y,dist;
};

// ---------------------------------------- index and distance storing containers -----------------------------

struct indexPair boundary[1000];
struct distpair elemnts[1000];
int countn = 0;
int k = 0;

// ------------------------------------------------ max depth getting function --------------------------------

void depth(int mat[M][N],int i,int j,int k)
{
    for (int l = 0; l < k; l++) {
        int distance = 0;
        if (boundary[l].xb > i || boundary[l].xb < i){
            distance = abs(i-boundary[l].xb);
        }
        else{
            distance = abs(j-boundary[l].yb);
        }
        elemnts[countn].x = i;
        elemnts[countn].y = j;
        elemnts[countn].dist = distance;
        countn++;
    }
}

// ----------------------------------------------------- Main function --------------------------------------------------

int main()
{
    
    scanf("%d %d",&M,&N);
    
    int matrix[M][N];
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }    
    
    getBoundary(matrix,M,N);
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j< N; j++) {
            if(i == 0 || j == 0 || i == M-1 || j == N-1){
                boundary[k].xb = i;
                boundary[k].yb = j;
                k++;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for(int j=0;j<N;j++){
            if(!(i == 0 || j == 0 || i == M-1 || j == N-1)){
                if(matrix[i][j]==0){
                    depth(matrix,i,j,k);
                }
            }
        }
    }
    
    int max_ = -1;
    
    for (int i = 1; i < countn; i++) {
        if(elemnts[i-1].dist <=elemnts[i].dist){
            max_ = max(max_,elemnts[i].dist);
        }
    }
    printf("Maximum Depth\n");
    if(countn == 0){
        printf("%d %d\n",boundary[1].xb,boundary[1].yb);
    }
    else{
        printf("%d %d\n",elemnts[countn-1].x,elemnts[countn-1].y);
    }
    

    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define true 1
#define false 0

// ----------------------------------------------------- Code Begins ---------------------------------------------------------


int m=0,n;
int size,moves;

// ------------------------------------------------------ Helper Funtions ----------------------------------------------------

int min(int a,int b){
    return (a<b)?a:b;
}

// ------------------------------------------------------ struct method -------------------------------------------------------

typedef struct state_of_matrix
{
    int cost;
    int **matrix;
    struct state_of_matrix *next;

} node;

node *head = NULL;

node *newNode(int **inp_mat, int p)
{
    node *temp = (node *)malloc(sizeof(node));
    
    temp->matrix =(int**)malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++)
    {
        temp->matrix[i] = (int *)malloc(size*sizeof(int));
    }
    temp->matrix = inp_mat;
    
    temp->cost = p;
    return temp;
}

int cal(int **temp,int t[size][size])
{
    int i,j,m=0;
    for(i=0;i < size;i++)
        for(j=0;j < size;j++)
        {
            if(temp[i][j]!=t[i][j])
            m++;
        }return m;
}

int check(int **temp,int t[size][size])
{
    int i,j,f=1;
    for(i=0;i < size;i++){
        for(j=0;j < size;j++){
            if(temp[i][j]!=t[i][j]){
                f=0;
            }
        }
    }
    return f;
}

node *insert(int size, int **inp_mat, int p)
{
    if (head == NULL)
    {
        node *temp = newNode(inp_mat, p);
        temp->next = head;
        head = temp;
    }
    else
    {
        node *temp = newNode(inp_mat, p);
        node *ptr = head;
        while(ptr->cost >p && ptr->next!= NULL){
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
        ptr = temp;
        
    }
    return head;
}

node *pop()
{
    node *tem = head;
    head = head->next;
    return tem;
}

node *top()
{
    node *temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    return temp;
}

int isempty(){
    return head==NULL;
}

int find_hole(int size, int** mat)
{
    int **tempmat = mat;
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (tempmat[i][j] == 0)
            {
                return i, j;
            }
        }
    }
}

int countelement(){
    int counter=0;
    node *temp = head;
    while(temp->next!=NULL){
        counter++;
        temp = temp->next;
    }
    return counter;
}


void bfsmodified(int **initmatrix,int dest[size][size]){
    int **temp = initmatrix;
    int p=cal(initmatrix,dest);
    node*q=insert(size,initmatrix,p);
    int k = 0;
    while(!isempty()){
        int x,y;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if(temp[i][j] == 0){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        for (int i = -1; i <=1; i++)
        {
            for(int j = -1;j<=1; j++){
                if(i==0 && j == 1){
                    if(y+j<size && y+j>=0){
                        int tempvar = temp[x][y];
                        temp[x][y] = temp[x][y+j];
                        temp[x][y+j] = tempvar;
                        int tempcost = cal(temp,dest);
                        q = insert(size,temp,tempcost);
                        
                    }
                }
                if(i==1 && j == 0){
                    if(x+i<size && x+i>=0){
                        int tempvar = temp[x][y];
                        temp[x][y] = temp[x+i][y];
                        temp[x+i][y] = tempvar;
                        int tempcost = cal(temp,dest);
                        q = insert(size,temp,tempcost);
                    }
                }
                if(i==-1 && j == 0){
                    if(x+i<size && x+i>=0){
                        int tempvar = temp[x][y];
                        temp[x][y] = temp[x+i][y];
                        temp[x+i][y] = tempvar;
                        int tempcost = cal(temp,dest);
                        q = insert(size,temp,tempcost);
                    }
                }
                if(i==0 && j == -1){
                    if(y+j<size && y+j>=0){
                        int tempvar = temp[x][y];
                        temp[x][y] = temp[x][y+j];
                        temp[x][y+j] = tempvar;
                        int tempcost = cal(temp,dest);
                        q = insert(size,temp,tempcost);
                    }
                }
            }
        }
        
        
        node *topelement = top();
        temp = topelement->matrix;
        int costing = topelement->cost;
        
        
        while(!isempty()){
            node * blah = pop();
            free(blah);
        }
        
        int checku = check(temp,dest);
        if(!checku){
            moves++;
            q = insert(size,temp,costing);
        }
    }
}

// ------------------------------------------------ Direct BFS Method ---------------------------------------------------

int CalculateChange(int temp[n][n],int t[n][n])
{
	int i,j,m=0;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
		{
			if(temp[i][j]!=t[i][j])
			m++;
		}
	return m;
}

int CheckSame(int a[n][n],int t[n][n])
{
	int i,j,f=1;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(a[i][j]!=t[i][j])
				f=0;
	return f;
}
int x=0,y=0,d=1000,dmin=0,l=0;

void moveUp(int temp[n][n],int a[n][n]){
    int p;
    for(int i=0;i < n;i++){
		for(int j=0;j < n;j++){
			temp[i][j]=a[i][j];
		}
	}

	if(x!=0){
		p=temp[x][y];
		temp[x][y]=temp[x-1][y];
		temp[x-1][y]=p;
	}
}

void moveDown(int temp[n][n],int a[n][n]){
    int p;
    for(int i=0;i < n;i++){
		for(int j=0;j < n;j++){
			temp[i][j]=a[i][j];
        }
	}
	if(x!=n-1){
		p=temp[x][y];
		temp[x][y]=temp[x+1][y];
		temp[x+1][y]=p;
	}
}

void moveLeft(int temp[n][n],int a[n][n]){
    int p;
    for(int i=0;i < n;i++){
		for(int j=0;j < n;j++){
			temp[i][j]=a[i][j];
		}
	}
	if(y!=0){
		p=temp[x][y];
		temp[x][y]=temp[x][y-1];
		temp[x][y-1]=p;
	}
}

void moveRight(int temp[n][n],int a[n][n]){
    int p;
    for(int i=0;i < n;i++){
		for(int j=0;j < n;j++){
			temp[i][j]=a[i][j];
		}
	}
	if(y!=n-1){
		p=temp[x][y];
		temp[x][y]=temp[x][y+1];
		temp[x][y+1]=p;
	}
}

void deepCopy(int r[n][n],int temp[n][n]){
    for(int i=0;i < n;i++){
		for(int j=0;j < n;j++){
			r[i][j]=temp[i][j];
		}
	}
}

void bfs(int a[n][n],int t[n][n],int temp[n][n],int r[n][n]){
    int p;
    while(!(CheckSame(a,t)))
	{
		l++;
		d=1000;
		for(int i=0;i < n;i++){
			for(int j=0;j < n;j++)
			{
				if(a[i][j]==0)
				{
					x=i;
					y=j;
					break;
				}
			}
	    }

		//To move upwards
		moveUp(temp,a);
		
		m=CalculateChange(temp,t);
		dmin=l+m;
		if(dmin < d)
		{
			d=dmin;
			deepCopy(r,temp);
		}


		//To move downwards
		moveDown(temp,a);
		
		m=CalculateChange(temp,t);
		dmin=l+m;
		if(dmin < d)
		{
			d=dmin;
			deepCopy(r,temp);
		}

		//To move right side
		moveRight(temp,a);
		
		m=CalculateChange(temp,t);
		dmin=l+m;
		if(dmin < d)
		{
			d=dmin;
			deepCopy(r,temp);
		}

		//To move left
		moveLeft(temp,a);
		
		m=CalculateChange(temp,t);
		dmin=l+m;
		if(dmin < d)
		{
			d=dmin;
			deepCopy(r,temp);
		}

		for(int i=0;i < n;i++){
			for(int j=0;j < n;j++)
			{
			  a[i][j]=r[i][j];
			  temp[i][j]=0;
			}
		}
	}
}

// ------------------------------------------------- solve function -------------------------------------------------------

void solve()
{
	int i,j;
	scanf("%d",&n);
	int a[n][n],t[n][n],temp[n][n],r[n][n];
	
	
	for(i=0;i < n;i++){
		for(j=0;j < n;j++){
			scanf("%d",&a[i][j]);
		}
	}
    int p=1;
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(i==j&&j==n-1)
				t[i][j]=0;
			else
				t[i][j]=p++;
		}
	}
    

    bfs(a,t,temp,r);
	printf("%d",d);
}

// -------------------------------------------------- main function  ---------------------------------------------------------

int main(){
    solve();
    return 0;
}
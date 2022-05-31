#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1

// ----------------------------------------------------------------- structures -----------------------------------------------------------------

typedef struct DLLnode{
    int data;
    struct DLLnode *next;
    struct DLLnode *prev;
}node;

typedef struct priorityQueue{
    int queue_element_count;
    int queueCapacity;
    node *rear,*front;
}Queue;

typedef struct HashTable{
    int HashCapacity;
    node **arr;
}Hash;

// ---------------------------------------------------------------- functions ----------------------------------------------------------------

node *newNode( int data ){
    node* temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->prev = temp->next = NULL;
    return temp;
}
 
Queue* createQueue(int queueCapacity)
{
    Queue* queue = (Queue *)malloc(sizeof(Queue)); 
    queue->queue_element_count = 0;
    queue->rear = queue->front = NULL;
    queue->queueCapacity = queueCapacity;
 
    return queue;
}
 

Hash* createHash(int HashCapacity){
    Hash* hash = (Hash *) malloc(sizeof(Hash));
    hash->HashCapacity = HashCapacity;
    hash->arr = (node **) malloc(hash->HashCapacity * sizeof(node*));
    int i = 0;
    while(i<hash->HashCapacity){
        i++;
        hash->arr[i] = NULL;
    }
    return hash;
}

void LRU(Queue* queue, Hash* hash, int data )
{
    node* queryBookId = hash->arr[data];
 
    if (queryBookId == NULL){
        if (queue->queue_element_count == queue->queueCapacity)
        {
            hash->arr[queue->front->data] = NULL;
            if( queue->front == NULL ){
                return;
            }
            if (queue->rear == queue->front){
                queue->rear = NULL;
            }
            node* temp = queue->front;
            queue->front = queue->front->prev;
         
            if (queue->front){
                queue->front->next = NULL;
            }
            free( temp );
            queue->queue_element_count--;
        }
        node* temp = newNode( data );
        temp->next = queue->rear;
        if (queue->front == NULL)
            queue->front = queue->rear = temp;
        else 
        {
            queue->rear->prev = temp;
            queue->rear = temp;
        }
        hash->arr[data] = temp;
        queue->queue_element_count++;
    }
 
    else if (queryBookId != queue->rear)
    {
        queryBookId->prev->next = queryBookId->next;
        if (queryBookId->next){
           queryBookId->next->prev = queryBookId->prev;
        }
        if (queryBookId == queue->front)
        {
           queue->front = queryBookId->prev;
           queue->front->next = NULL;
        }
        queryBookId->next = queue->rear;
        queryBookId->prev = NULL;
        queryBookId->next->prev = queryBookId;
 
        queue->rear = queryBookId;
    }
}

// ----------------------------------------------------------------- testing function -----------------------------------------------------------------

void solve(){
    int N,m;
    scanf("%d %d",&N,&m);
    Queue* q = createQueue( m );        
    
    Hash* hash = createHash(2*N);
    int L;
    scanf("%d",&L);
    
    for (int i = 0; i < L; i++) {
        int temp;
        scanf("%d",&temp);
        LRU(q,hash,temp);
        node *tempq = q->front;
        while(tempq!=NULL){
            printf("%d ",tempq->data);
            
            tempq = tempq->prev;
        }
        printf("\n");
    }
}

// ---------------------------------------------------------------- main function ----------------------------------------------------------------

int main(){
    solve();
    return 0;
}
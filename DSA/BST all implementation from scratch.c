#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// defining 1 as true as it is easier to understand in the code
#define TRUE 1

 

// ---------------------------------------------------- tree ----------------------------------------------------
typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
}treeNode;

treeNode *root = NULL;


void Insert(treeNode *root,int data){
    
    treeNode *temp = root,*p,*tail;    
    while(temp!=NULL){
        if(data == temp->data){
            return;
        }
        else if(data<temp->data){
            tail = temp;
            temp=temp->left;
        }
        else{
            tail = temp;
            temp=temp->right;
        }
    }
    p = (treeNode *)malloc(sizeof(treeNode));
    p->data = data;
    p->left = p->right = NULL;
    if(p->data<tail->data) 
        tail->left= p;
    else
        tail->right = p;
}


treeNode *makeTree(treeNode *root ,int inOrd[],int postOrd[],int n,int m){
    
    root = (treeNode *)malloc(sizeof(treeNode));
    root->data = postOrd[m-1];
    root->left = root->right = NULL;
    for (int i = m-2; i >= 0 ; i--) {
        Insert(root,postOrd[i]);
    }
    return root;
}

// ----------------------------------------------------stack -----------------------------------------------------

typedef struct stack
{
    treeNode *Node;
    struct stack *ptr;
}node;
 
node *top= NULL;

void push(treeNode *root){
    node *link=(node *)malloc(sizeof(node));
    link->Node = root;
    link->ptr = top; 
    top = link;
}


struct stack *pop(){
    if(top == NULL){
        return NULL;
    }
    node *popdata = top;
    top = top->ptr;
    return popdata;
}


int isEmpty(node *top){
    return top==NULL?1:0;
}
//----------------------------------------------------queue ----------------------------------------------------
typedef struct Queue{
    struct tree *node;
    struct Queue *ptr;
}queue;


void enqueue(treeNode *node,queue **head){
    queue *temp = *head;
    queue *element = (queue *)malloc(sizeof(queue));
    
    element -> ptr = NULL;
    element -> node = node;
    if(*head == NULL){
      *head = element;
    }
    else{
      while(temp->ptr!= NULL){
          temp = temp->ptr;
      }
      temp->ptr= element;
    }
}

queue *dequeue(queue **head){
    queue *temp =  *head;
    *head = temp->ptr;
    return temp;
}

int sizeQueue(queue *head){
    int size = 0;
    while(head!=NULL){
        size++;
        head=head->ptr;
    }
    return size;
}


int *PreOrd(treeNode *root,int *arr){
    
    int i = 0;
    while(TRUE){
        
        while(root != NULL){
            *(arr+i) = root->data;
            i++;
            push(root);
            root = root->left;
        }
        if(root == NULL && top!=NULL){
            struct stack *temp = pop();
            root = temp->Node;
            free(temp);
        }
        
        root = root->right;
        
        if(root == NULL && top == NULL){
            break;
        }
    }
    return arr;
}

// ---------------------------------------------------- PreOrdNonRecursive ----------------------------------------------------

void PreOrdNonRecursive(treeNode *root){
    while(TRUE){
        while(root != NULL){
            printf("%d ",root->data);
            push(root);
            root =root->left;
        }
        if(root == NULL && top!=NULL){
            struct stack *temp = pop();
            root = temp->Node;
            free(temp);
        }
        
        root = root->right;
        
        if(root == NULL && top == NULL){
            break;
        }
    }
}

// ---------------------------------------------------- deletion ----------------------------------------------------

// FINDING IN ORDER SUCCESSOR 
treeNode *min(treeNode *root){
    if(root == NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root= root->left;
    }
    return root;
}

// FINDING IN ORDER PREDECESSOR
treeNode *max(treeNode *root){
    if(root == NULL){
        return NULL;
    }
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
} 



treeNode *delete_node(treeNode *root, int data)
{
    treeNode *temp;
    if(root == NULL){ 
        return root;
    }
    if (data < root->data){
        root->left = delete_node(root->left, data);
    }
    else if (data > root->data){
        root->right = delete_node(root->right, data);
    }
    else if (data == root->data) {
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }
        
        else{
            if(root->left!=NULL){
                treeNode *temp = max(root->left);
                root->data = temp->data;
                root->left = delete_node(root->left, temp->data);
            }
            else if(root->right!=NULL){
                treeNode *temp = min(root->right);
                root->data = temp->data;
                root->right = delete_node(root->right, temp->data);
            }
        }
    }
    return root;
}

// ---------------------------------------------------- countLeaves ----------------------------------------------------
 
int countLeaves(treeNode *root){
    treeNode *temp;
    int count= 0;
    
    queue *Q = (queue *)malloc(sizeof(queue));
    Q->node = root;
    Q->ptr = NULL;
    
    
    while(Q!=NULL){
        queue * temp1 = dequeue(&Q);
        temp = temp1->node;
        free(temp1);
        
        if(!temp->left && !temp->right){
            count++;
        }
        else{
            if(temp->left){
                enqueue(temp->left,&Q);
            }
            if(temp->right){
                enqueue(temp->right,&Q);
            }
        }
    }
    return count;
}

// ---------------------------------------------------- Count Nodes and Levels ----------------------------------------------------
int countlevels(treeNode *root){
    treeNode *temp;
    
    int level = 0;
    
    
    queue *Q = (queue *)malloc(sizeof(queue));
    Q->node = root;
    Q->ptr = NULL;
    while(Q!=NULL){
        int size = sizeQueue(Q);
        
        while(size--){
            queue * temp1 = dequeue(&Q);
            temp = temp1->node;
            free(temp1);
            
            if(temp->left){
                enqueue(temp->left,&Q);
            }
            if(temp->right){
                enqueue(temp->right,&Q);
            } 
        }
        level++;
    }
    
    return level;
}

int countnodes(treeNode *root){
    treeNode *temp;
    
    int level = 0;
    if(!root){
        return 0;
    }
    
    queue *Q = (queue *)malloc(sizeof(queue));
    Q->node = root;
    Q->ptr = NULL;
    while(Q!=NULL){
        int size = sizeQueue(Q);
        printf("%d %d\n",level,size);
        while(size--){
            queue * temp1 = dequeue(&Q);
            temp = temp1->node;
            free(temp1);
            
            if(temp->left){
                enqueue(temp->left,&Q);
            }
            if(temp->right){
                enqueue(temp->right,&Q);
            }
        }
        level++;
    }
    return level;
}



// -------------------------------------------- Main --------------------------------------------

int main(){
    while(TRUE){
        int menu = 1;
        scanf("%d",&menu);
        // -------------------------------------------- MENU 1 --------------------------------------------
        if(menu == 1){
            int n;
            scanf("%d",&n);
            int inOrd[n];
            for (int i = 0; i < n; i++) {
                scanf("%d",&inOrd[i]); 
            }
            int m;
            scanf("%d",&m);
            int postOrd[m];
            for (int i = 0; i < m ;i++) {
                scanf("%d",&postOrd[i]); 
            }
            
            
            root = makeTree(root,inOrd,postOrd,n,m);
            
            int leaves = countLeaves(root);
            printf("%d\n",leaves);
            
            int levels = countlevels(root);
            printf("%d\n",levels);
            int nodes = countnodes(root);
        
        }
        
        //-------------------------------------------- MENU 2 ----------------------------------------------------
        
        if(menu==2){
            int num;
            scanf("%d",&num);
            if(root == NULL){
                printf("empty\n");
            }
            else{
                int *preOrd = (int *)malloc(100 * sizeof(int));
                preOrd = PreOrd(root,preOrd);
                int flag = 0;
                
                for(int i = 0;i<100;i++){
                    if(num == *(preOrd + i)){
                        flag = 1;
                    }
                }
                if(flag == 1){
                    root = delete_node(root,num);
                    PreOrdNonRecursive(root);
                    printf("\n"); 
                }
                else{
                    printf("error\n"); 
                }
            }
        }
        if(menu==-1){
            break;
        }
    }
    return 0;
}
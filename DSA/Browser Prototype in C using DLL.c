#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1

typedef struct DLL{
    char *data;
    struct DLL *next;
    struct DLL *prev;
}node;

node *head = NULL,*curr=NULL;

void InsertDLLnode(char *data){
    node *temp = curr;
    
    if(curr == NULL && head == NULL){
        node *link = (node *)malloc(sizeof(node));
        link->data = (char *)malloc(100 *sizeof(char)); 
        strcpy(link->data,data); 
        link->next= head;  
        link->prev = NULL;
        head = link;
        curr = link;
        
        node *temp1 = curr;
        node *temp2 = temp1->prev;
        node *temp3 = temp1->next;
        if(temp2 == NULL){
            printf("none ");
        }
        else{
            printf("%s ",temp2->data);
        }
        printf("%s ",temp1->data);
        if(temp3 == NULL){
            printf("none\n");
        }
        else{
            printf("%s\n",temp3->data);
        }
    }
    else{
        node *link = (node *)malloc(sizeof(node));
        link->data = (char *)malloc(100 *sizeof(char));
        strcpy(link->data,data);
        
        link->next = temp->next;
        link->prev = temp;
        temp->next = link;
        curr = link;
        curr->next = NULL;
        
        node *temp1 = curr;
        node *temp2 = temp1->prev;
        node *temp3 = temp1->next;
        if(temp2 == NULL){
            printf("none ");
        }
        else{
            printf("%s ",temp2->data);
        }
        printf("%s ",temp1->data);
        if(temp3 == NULL){
            printf("none\n");
        }
        else{
            printf("%s\n",temp3->data);
        }
    }
}

void B(int num){
    node *temp = curr;
    
    int i=0;
    for (; i < num && temp->prev!=NULL; i++) {
        temp= temp->prev;
        curr = temp;
    }
    if (i<num){
        printf("%d back not possible\n",num-i);
        // node *temp1 = head;
        
        node *temp1 = curr;
        node *temp2 = temp1->prev;
        node *temp3 = temp1->next;
        if(temp2 == NULL){
            printf("none ");
        }
        else{
            printf("%s ",temp2->data);
        }
        printf("%s ",temp1->data);
        if(temp3 == NULL){
            printf("none\n");
        }
        else{
            printf("%s\n",temp3->data);
        }
    }
    else{
        node *temp1 = curr;
        node *temp2 = temp1->prev;
        node *temp3 = temp1->next;
        if(temp2 == NULL){
            printf("none ");
        }
        else{
            printf("%s ",temp2->data);
        }
        printf("%s ",temp1->data);
        if(temp3 == NULL){
            printf("none\n");
        }
        else{
            printf("%s\n",temp3->data);
        }
    }
}

void F(int num){
    node *temp = curr;
    int i=0;
    for (; i < num && temp->next!=NULL; i++) {
        temp = temp->next;
        curr = temp;
    }
    if (i<num){
        printf("%d forward not possible\n",num-i);
        node *temp1 = curr;
        node *temp2 = temp1->prev;
        node *temp3 = temp1->next;
        if(temp2 == NULL){
            printf("none ");
        }
        else{
            printf("%s ",temp2->data);
        }
        printf("%s ",temp1->data);
        if(temp3 == NULL){
            printf("none\n");
        }
        else{
            printf("%s\n",temp3->data);
        }
    }
    else{
        node *temp1 = curr;
        node *temp2 = temp1->prev;
        node *temp3 = temp1->next;
        if(temp2 == NULL){
            printf("none "); 
        }
        else{
            printf("%s ",temp2->data);
        }
        printf("%s ",temp1->data);
        if(temp3 == NULL){
            printf("none\n");
        }
        else{
            printf("%s\n",temp3->data);
        }
    }
}

void Q(int n){
    node *temp = curr;
    if (n>0){
        
        int i =0;
        while(i < n && temp->next != NULL){
            temp = temp->next;
            i++;
            
        }
        if(i<n){
            printf("none\n");
        }
        else{
            printf("%s\n",temp->data);
        }
    }
    if (n<0){
        
        int i =0;
        while(i < abs(n) && temp->prev!=NULL){
            temp = temp->prev;
            i++;
        }
        if(i<abs(n)){
            printf("none\n");
        }
        else{
            printf("%s\n",temp->data);
        }
        
    }
}

void D(int n){
    node *temp = curr;
    if (n>0){
        
        int i = 0;
        while(i<n && temp->next != NULL){
            temp = temp->next;
            i++;
        }
        if(i<n){
            printf("none\n");
        }
        else{
            node *temp1 = temp->prev;
            node *temp2 = temp ->next;
            
            if(temp2 != NULL){
                temp1->next = temp2;
                temp2->prev = temp1;
                free(temp);
            }
            else{
                temp1->next = temp2;
                free(temp);
            }
        }
        
    }
    if (n<0){
        int i = 0;
        while(i<abs(n) && temp->prev != NULL){
            temp = temp->prev;
            i++;
        }
        if(i<abs(n)){
            printf("none\n");
        }
        else{
            node *temp1 = temp->prev;
            node *temp2 = temp ->next;
            
            if(temp1 != NULL){
                temp1->next = temp2;
                temp2->prev = temp1;
                free(temp);
            }
            else{
                temp2->prev = temp1;
                free(temp);
            }
        }
    }
}

int main()
{
    while(TRUE){
      char menu;
      scanf("%c",&menu);
      if(menu == 'V'){
        char *sitedata = (char *)malloc(100*sizeof(char));
        scanf("%s",sitedata);
        InsertDLLnode(sitedata);
      }
      if(menu == 'B'){
          int n;
          scanf("%d",&n);
          B(n);
      }
      if(menu == 'F'){
          int n;
          scanf("%d",&n);
          F(n);
      }
      if(menu == 'Q'){
          int n;
          scanf("%d",&n);
          Q(n);
      }
      if(menu == 'D'){
          int n;
          scanf("%d",&n);
          D(n);
      }
      if(menu == 'E'){
        break;
      }
    }
    return 0;
}

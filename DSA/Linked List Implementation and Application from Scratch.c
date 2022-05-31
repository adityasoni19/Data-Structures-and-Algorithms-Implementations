#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    return n==0||n==1?1:n*factorial(n-1);
}
int power(int a,int b){
    int mul=a,i=1; 
    if (b==0){
        return 1;
    }
    else if(a==0){
        return 0;
    }
    else{
        while (i<b){
            /* code */
            mul*=a;
            i++;
        }
    return mul;
    }
    
    
}


typedef struct ll_1{
    int powr1;
    int coeff1;
    struct ll_1*ptr1;
}NODE1;

typedef struct ll_2{
    int powr2;
    int coeff2;
    struct ll_2*ptr2;
}NODE2;

typedef struct ll_3{
    int powr3;
    int coeff3;
    struct ll_3*ptr3;
}NODE3;



int main(){
        int P1,P2;
        scanf("%d",&P1);
        NODE1*head1 = NULL;
        for (int i = 0; i < P1+1; i++) {
            
            
            if(head1 == NULL){
                NODE1*link1 = (NODE1 *)malloc(sizeof(NODE1));
                int coeff;
                scanf("%d",&coeff);
                link1->coeff1 = coeff;
                link1 -> powr1 = P1-i;
                link1 -> ptr1 = head1;
                head1 = link1; 
            }
            else{
                NODE1 *temp1 = head1;
                //check that temp != NULL
                while(temp1 -> ptr1 != NULL){
                    temp1 = temp1 -> ptr1;

                }

                NODE1 *link1 = (NODE1 *) malloc(sizeof(NODE1));
                int coeff;
                scanf("%d",&coeff);
                link1 -> coeff1 = coeff;
                link1 ->powr1 = P1-i;
                link1 -> ptr1 = NULL;
                temp1 -> ptr1 = link1;
            }
        }
        
        
        // printf("\n");
        scanf("%d",&P2);
        NODE2*head2 = NULL;
        for (int i = 0; i < P2+1; i++) {
            
            
            if(head2 == NULL){
                NODE2*link2 = (NODE2 *)malloc(sizeof(NODE2));
                int coeff;
                scanf("%d",&coeff);
                link2->coeff2 = coeff;
                link2 -> powr2 = P2-i;
                link2 -> ptr2 = head2;
                head2 = link2; 
            }
            else{
                NODE2 *temp2 = head2;
                //check that temp != NULL
                while(temp2 -> ptr2 != NULL){
                    temp2 = temp2 -> ptr2;

                }

                NODE2 *link2 = (NODE2 *) malloc(sizeof(NODE2));
                int coeff;
                scanf("%d",&coeff);
                link2 -> coeff2 = coeff;
                link2 -> powr2 = P2-i;
                link2 -> ptr2 = NULL;
                temp2 -> ptr2 = link2;
            }
        }
        int x;
        scanf("%d",&x);

        NODE1*temp = head1;
        printf("P1(x) =");
        while(temp!=NULL){
            
            
            if(temp == head1 ){
                if(temp->powr1>0){
                    printf(" %dx^%d",temp->coeff1,temp->powr1);
                    temp=temp->ptr1;
                }
                else{
                    printf(" %d",temp->coeff1);
                    temp=temp->ptr1;
                }
            }
            else if(temp->coeff1 <0){
                if(temp->powr1>0){
                    printf(" - %dx^%d",-1*temp->coeff1,temp->powr1);
                    temp=temp->ptr1;
                }
                else{
                    printf(" - %d",-1*temp->coeff1);
                    temp=temp->ptr1;
                }
            }
            
            else if(temp->coeff1 >0){
                if(temp->powr1>0){
                    printf(" + %dx^%d",temp->coeff1,temp->powr1);
                    temp=temp->ptr1;
                }
                else{
                    printf(" + %d",temp->coeff1);
                    temp=temp->ptr1;
                }
            }
            else{
                temp = temp->ptr1;
                continue;
            }
        }
        printf("\n");
        NODE2*temp_ = head2;
        printf("P2(x) =");
        while(temp_!=NULL){
            if(temp_ == head2){
                if(temp_->powr2>0){
                    printf(" %dx^%d",temp_->coeff2,temp_->powr2);
                    temp_=temp_->ptr2;
                }
                else{
                    printf(" %d",temp_->coeff2);
                    temp_=temp_->ptr2;
                }
            }
            else if(temp_->coeff2<0){
                if(temp_->powr2>0){
                    printf(" - %dx^%d",-1*temp_->coeff2,temp_->powr2);
                    temp_=temp_->ptr2;
                }
                else{
                    printf(" - %d",-1*temp_->coeff2);
                    temp_=temp_->ptr2;
                }
            }
            
            else if(temp_->coeff2 >0){
                if(temp_->powr2>0){
                    printf(" + %dx^%d",temp_->coeff2,temp_->powr2);
                    temp_=temp_->ptr2;
                }
                else{
                    printf(" + %d",temp_->coeff2);
                    temp_=temp_->ptr2;
                }
            }
            else{
                temp_ = temp_->ptr2;
                continue;
            }
        }
        printf("\n");
        // -------------------------------------------------------------Making P3(x)------------------------------------------------------------------------------------
        NODE3*head3 = NULL;
        NODE1*side1 = head1;
        NODE2*side2 = head2;
        for (int i = 0; i < P1+ 1 + P2 + 1; i++) {
            if(head3 == NULL && i<P1+1){
                NODE3*link3 = (NODE3 *)malloc(sizeof(NODE3));
                link3->powr3 = P1+P2+1-i;
                link3->coeff3 = side1->coeff1;
                link3->ptr3 =head3;
                head3 = link3;
                side1=side1->ptr1;
                
            }

            else if(i<P1+1){
                NODE3 *temp3 = head3;
                //check that temp != NULL
                while(temp3 -> ptr3 != NULL){
                    temp3 = temp3 -> ptr3;

                }

                NODE3 *link3 = (NODE3 *) malloc(sizeof(NODE3));
                link3 -> coeff3 = side1->coeff1;
                link3 -> powr3 = P1+P2+1-i;
                link3 -> ptr3 = NULL;
                temp3 -> ptr3 = link3;
                side1=side1->ptr1;
            }
            else{
                NODE3 *temp4 = head3;
                while(temp4 ->ptr3!= NULL){
                    temp4 = temp4 -> ptr3;

                }

                NODE3 *link3 = (NODE3 *) malloc(sizeof(NODE3));
                link3 -> coeff3 = side2->coeff2;
                link3 -> powr3 = P1+P2+1-i;
                link3 -> ptr3 = NULL;
                temp4 -> ptr3 = link3;
                side2=side2->ptr2;
            }
        }
        //printing p3(X) --------------------------------------
        NODE3*temp__ = head3;
        printf("P3(x) =");
        while(temp__!=NULL){
            
            
            if(temp__ == head3){
                if(temp__->powr3>0){
                    printf(" %dx^%d",temp__->coeff3,temp__->powr3);
                    temp__=temp__->ptr3;
                }
                else{
                    printf(" %d",temp__->coeff3);
                    temp__=temp__->ptr3;
                }
            }
            else if(temp__->coeff3<0){
                if(temp__->powr3>0){
                    printf(" - %dx^%d",-1*temp__->coeff3,temp__->powr3);
                    temp__=temp__->ptr3;
                }
                else{
                    printf(" - %d",-1*temp__->coeff3);
                    temp__=temp__->ptr3;
                }
            }
            
            else if(temp__->coeff3 >0){
                if(temp__->powr3>0){
                    printf(" + %dx^%d",temp__->coeff3,temp__->powr3);
                    temp__=temp__->ptr3;
                }
                else{
                    printf(" + %d",temp__->coeff3);
                    temp__=temp__->ptr3;
                }
            }
            else{
                temp__ = temp__->ptr3;
                continue;
            }
        }
        // ------------------------------------------------------------------------------------------------------------
        // evaluating polynomials 
        // ------------------------------------------------------------------------------------------------------------
        printf("\n");
        int p1sum=0,p2sum=0,p3sum=0;
        NODE1*sumptr = head1;
        while(sumptr != NULL){
            p1sum += sumptr->coeff1*(power(x,sumptr->powr1));
            sumptr = sumptr->ptr1;
        }
        printf("P1(%d) = %d",x,p1sum);
        printf("\n");
        NODE2*sumptr1 = head2;
        while(sumptr1 != NULL){
            p2sum += sumptr1->coeff2*(power(x,sumptr1->powr2) );
            sumptr1 = sumptr1->ptr2;
        }
        printf("P2(%d) = %d",x,p2sum);
        printf("\n");
        NODE3*sumptr2 = head3;
        while(sumptr2 != NULL){
            p3sum += sumptr2->coeff3*(power(x,sumptr2->powr3));
            sumptr2= sumptr2->ptr3;
        }
        printf("P3(%d) = %d",x,p3sum);
        printf("\n");
    return 0;
}
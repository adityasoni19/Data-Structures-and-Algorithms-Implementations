#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ---------------------------------------------POWER FUNCTION ----------------------------------------- 

double power(double a,int b){
    double mul=a,i=1; 
    if (b==0){
        return 1;
    } 
    else if(a==0){
        return 0;
    }
    else{
        while (i<b){
            mul*=a;
            i++;
        }
    return mul;
    }    
}

// ----------------------------------------- POSTFIX EVALUATION STACK -----------------------------------------------

typedef struct stack
{
    double data;
    struct stack *ptr;
}node;
 
node *top= NULL;

void push(double data){
    node *link=(node *)malloc(sizeof(node));
    link->data = data;
    link->ptr = top; 
    top = link;
}


double pop(){
    if(top == NULL){
        printf("error");
        return '\0';
    }
    double popdata;
    node *temp = top;
    top = top->ptr;
    popdata = temp->data;
    free(temp);
    return popdata;
}


int isEmpty(node *top){
    return top==NULL?1:0;
}


int topshow(node *top){
    if(top == NULL){
        return '\0';
    }
    
    else{
        return top->data;
    }
}

int size(node *top){
    int count = 0;
    node *temp = top;
    while(temp!=NULL){
        count++;
        temp=temp->ptr;
    }
    return count;
}

// ------------------------------------------ IS DIGIT FUNCTION --------------------------------------------------

int isDgt(char n){
    if((int)n>=48 && (int)n<=57){
        return 1;
    }
    else{
        return 0;
    }
}

// ------------------------------------ POSTFIX TO INFIX CONVERSION STACK ----------------------------------------------

typedef struct stack_
{
    char *data1;
    struct stack_ *ptr1;
} node1;
node1 *top1 = NULL;
void push_(char *data)
{
    node1 *link = (node1 *)malloc(sizeof(node1)); 
    link->ptr1 = top1;
    link->data1 = (char *)malloc(100 * sizeof(char));
    strcpy(link->data1, data);
    top1 = link; 
}
char *pop_()
{
    if (top1 == NULL)
    {
        printf("error");
        return '\0';
    }
    char *popdata = (char *)malloc(100 * sizeof(char));
    node1 *temp1 = top1;
    top1 = top1->ptr1;
    popdata = temp1->data1;
    free(temp1);
    return popdata;
}
int isEmpty_(node1 *top1)
{
    return top1 == NULL ? 1 : 0;
}
char *topshow_(node1 *top1)
{
    if (top1 == NULL)
    {
        return '\0';
    }
    else
    {
        return top1->data1;
    }
}

// -------------------------------------------- IS OPERATOR FUNCTION ---------------------------------------

int isOperator(char n){
    if(n == '*' || n == '/' || n == '+' || n == '-' || n == '^'){
        return 1;
    }
    else{
        return 0;
    }
}

// ------------------------------------------ POSTFIX VALIDATION FUNCTION --------------------------------------

int PostfixChecker(char *str){
    int countnum = 0;
    int countop = 0;
    int flag = 1;
    for (int i = 0; i < strlen(str)&&countnum >=0; i++)
    {
        if(*(str + i) == ','){
            continue;
        }
        if(isDgt(*(str + i))){
            countnum++;
        }
        if(isOperator(*(str+i))){
            countnum--;
        }  
    }
    int q = countnum;
    if(q == 1 || q==0){
        flag = 1;
    }
    if(q<0){
        flag = 0;
    }
    if(!(isDgt(*(str)))){
            flag = 0;
    }
    if(!(isOperator(*(str+ strlen(str)-1)))){
            flag = 0;
    }
    
    
    return flag;

    
}

// ------------------------------------------------ MAIN FUNCTION ---------------------------------------------------

int main()
{

    char input[100];
    scanf("%[^\n]s",input);
    //------------------------------------------ CHECKING INPUT IS VALID -------------------------------------------
    int a = PostfixChecker(input);
    if(!a){
        printf("error");
        exit(0);
    }
    //------------------------------------------ Evaluation of postfix ---------------------------------------------
    double temp_ = 0;
    double sum = 0;
    int l=0;
    while(input[l]!='\0'){
        if(strlen(input) == 1){
            sum = (int)input[l]-48;
            push(sum);
            l++;
            continue;
        }
        if(isDgt(input[l])){
            temp_ = temp_*10 + (input[l]-48);
            l++;
            continue;
        }
        if(input[l] == ','){
            if(input[l-1]=='^'||input[l-1]=='*'||input[l-1]=='/'||input[l-1]=='+'||input[l-1]=='-'){
                l++;
                continue;
            }
            else{
                push(temp_);
                temp_ = 0;
                l++;
                continue;
            }
        }
        
        if(input[l] == '^'){
            if(isEmpty(top)){
                printf("error");
                break;
            }
            double temp2 = pop();
            sum = power(temp2,2);
            push(sum);
            l++;
            continue;
        }
        if(input[l] == '*'){
            if(isEmpty(top)){
                printf("error");
                break;
            }
            double x_temp = pop();
            if(isEmpty(top)){
                printf("error");
                break;
            }
            double y_temp = pop();
            sum = x_temp*y_temp;
            push(sum);
            l++;
            continue;
        }
        if(input[l] == '/'){
            if(isEmpty(top)){
                printf("error");
                break;
            }
            double x_temp = pop();
            if(isEmpty(top)){
                printf("error");
                break;
            }
            double y_temp = pop();
            sum = (double) y_temp/x_temp;
            push(sum);
            l++;
            continue;
        }
        if(input[l] == '+'){
            if(isEmpty(top)){
                printf("error");
                break;
            }
            double x_temp = pop();
            if(isEmpty(top)){
                printf("error");
                break;
            }
            double y_temp = pop();
            sum = x_temp+y_temp;
            push(sum);
            l++;
            continue;
        }

        if(input[l] == '-'){
            if(isEmpty(top)){
                printf("error");
                break;
            }
            double x_temp = pop();
            if(isEmpty(top)){
                printf("error");
                break;
            }
            double y_temp = pop();
            sum = y_temp-x_temp;
            push(sum);
            l++;
            continue;
        }
    }
    
    // --------------------------------------- POSTFIX TO INFIX CODE ------------------------------------------------- 
    
    int i = 0, n = 0;
    char res[100] = "";
    char temp[100] = "";
    while (input[i] != '\0')
    {
        
        if (isDgt(input[i]))
        {
            if (strlen(input) ==1){
                push_(input);
                i++;
                continue;
            }
            else{
                temp[n] = input[i];
                n++;
                i++;
                continue;
            }
        }
        if (input[i] == ',')
        {
            if (input[i - 1] == '^' || input[i - 1] == '*' || input[i - 1] == '/' || input[i - 1] == '+' || input[i - 1] == '-')
            {
                i++;
                continue;
            }
            else
            {
                push_(temp);
                n = 0;
                int b = strlen(temp);
                while(b>=0){
                    temp[b] ='\0';
                    b--;
                }
                i++;
                continue;
            }
        }
        if (input[i] == '^')
        {
            char *sq = (char *)malloc(100 * sizeof(char));
            sq = pop_();
            res[0] = '(';
            for (int i = 0; i < strlen(sq); i++)
            {
                res[i + 1] = *(sq + i);
            }
            res[strlen(res)] = '^';
            
            res[strlen(res)] = ')';
            push_(res);
            int g = strlen(res);
                while(g>=0){
                    res[g] ='\0';
                    g--;
                }
            i++;
            continue;
        }
        if (input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-')
        {
            char *op2 = (char *)malloc(100 * sizeof(char));
            op2 = pop_();
            char *op1 = (char *)malloc(100 * sizeof(char));
            op1 = pop_();
            int lenop1 = strlen(op1), lenop2 = strlen(op2);
            res[0] = '(';
            int j = 1;
            while (j < lenop1 + 1)
            {
                res[j] = *(op1 + (j - 1));
                j++;
            }
            res[j] = input[i];
            j = 1;
            while (j < lenop2 + 1)
            { 
                res[j + lenop1 + 1] = *(op2 + j - 1);
                j++;
            }
            res[j+lenop1+1] = ')';
            push_(res);
            int u = strlen(res);
                while(u>=0){
                    res[u] ='\0';
                    u--;
                } 
            i++;
            continue;
        }
    }
    
    // -------------------------------------------- EVALUATING OUTPUT -----------------------------------
    
    char *final = (char *)malloc(100*sizeof(char));
    final = pop_();
    printf("%s",final);
    printf("\n");
    
    
    double fraction = sum - ((long)sum);
    
    if(fraction == 0){
        printf("%d",(int)sum);
    }
    else{ 
        printf("%.2f",sum);
    }
    printf("\n");
    return 0;
}
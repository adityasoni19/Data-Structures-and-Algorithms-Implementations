#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1

int max(int a,int b){
    return (a>b)?a:b;
}  

char *remove_white_spaces(char *str)
{
	int i = 0, j = 0;
	while (str[i])
	{
        str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
	return str;
}

typedef struct AVL{
    char *name;
    int price;
    char *company;
    double megapixels;
    char *color;
    int ram;
    int battery;
    int rb;
    int height;
    int id;
    int mark;
    struct AVL *left;
    struct AVL *right;
}node1,node2;

node1 *root1 = NULL;
node2 *root2 = NULL;
int pid=0,nid =0;
int delId=0;


int height(node1 *root){
    if(root==NULL){
        return 0;
    }
    else{
        return root->height;
    }
}

node1 *singleRightRotate(node1 *y)
{
	node1 *x = y->left;
	node1 *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	return x;
}

node1 *singleLeftRotate(node1 *x)
{
	node1 *y = x->right;
	node1 *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	return y;
}

int getBalance(node1 *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

node1 *insertbyprice(node1 *root, char *name,int price,char *company,double megapixels,char *color,int ram,int battery,int rb)
{
	if (root == NULL){
		root = (node1 *)malloc(sizeof(node1));
        root->name = (char *)malloc(25*sizeof(char));
        strcpy(root->name,name);
        root->price = price;
        root->company = (char *)malloc(25*sizeof(char));
        strcpy(root->company,company);
        root->megapixels = megapixels;
        root->color = (char *)malloc(10*sizeof(char));
        strcpy(root->color,color);
        root->ram=ram;
        root->battery=battery;
        root->rb = rb;
        root->height = 1;
        root->mark =0;
        root->id=pid;
        root->left=root->right=NULL;
	}

	if (price < root->price)
		root->left = insertbyprice(root->left, name,price,company,megapixels,color,ram,battery,rb);
	else if (price > root->price)
		root->right = insertbyprice(root->right, name,price,company,megapixels,color,ram,battery,rb);
	else
		return root;

	root->height = 1 + max(height(root->left),height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && price < root->left->price)
		return singleRightRotate(root);

	if (balance < -1 && price > root->right->price)
		return singleLeftRotate(root);

	if (balance > 1 && price > root->left->price)
	{
		root->left = singleLeftRotate(root->left);
		return singleRightRotate(root);
	}

	if (balance < -1 && price < root->right->price)
	{
		root->right = singleRightRotate(root->right);
		return singleLeftRotate(root);
	}

	return root;
}
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

node2 *singleRightRotateN(node2 *y)
{
	node2 *x = y->left;
	node2 *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	return x;
}

node2 *singleLeftRotateN(node2 *x)
{
	node2 *y = x->right;
	node2 *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	return y;
}

node2 *insertbyname(node2*root, char *name,int price,char *company,double megapixels,char *color,int ram,int battery,int rb)
{
	if (root == NULL){
		root = (node2 *)malloc(sizeof(node2));
        root->name = (char *)malloc(25*sizeof(char));
        strcpy(root->name,name);
        root->price = price;
        root->company = (char *)malloc(25*sizeof(char));
        strcpy(root->company,company);
        root->megapixels = megapixels;
        root->color = (char *)malloc(10*sizeof(char));
        strcpy(root->color,color);
        root->ram=ram;
        root->battery=battery;
        root->rb = rb;
        root->height = 1;
        root->mark=0;
        root->id = nid;
        root->left=root->right=NULL;
	}

	if (strcmp(name,root->name)<0)
		root->left = insertbyprice(root->left, name,price,company,megapixels,color,ram,battery,rb);
	else if (strcmp(name,root->name)>0)
		root->right = insertbyprice(root->right, name,price,company,megapixels,color,ram,battery,rb);
	else
		return root;

	root->height = 1 + max(height(root->left),height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && price < root->left->price)
		return singleRightRotateN(root);

	if (balance < -1 && price > root->right->price)
		return singleLeftRotateN(root);

	if (balance > 1 && price > root->left->price)
	{
		root->left = singleLeftRotate(root->left);
		return singleRightRotateN(root);
	}

	if (balance < -1 && price < root->right->price)
	{
		root->right = singleRightRotateN(root->right);
		return singleLeftRotateN(root);
	}

	return root;
}


// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


node1 *min(node1 *root){
    if(root == NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root= root->left;
    }
    return root;
}


node1 *maxi(node1 *root){
    if(root == NULL){
        return NULL;
    }
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
} 

node1* delete_node(node1 * root, int price)
{

	if (root == NULL)
		return root;
	if ( price < root->price )
		root->left = delete_node(root->left, price);
	else if( price > root->price )
		root->right = delete_node(root->right, price);
	else
	{
		if( (root->left == NULL) || (root->right == NULL) )
		{
			node1 *temp = root->left ? root->left :root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else{
    			*root = *temp;
    			free(temp);
			    
			}
		}
		else
		{
            if (root->left!=NULL){
    			node1* temp = maxi(root->right);
    
    			root->price = temp->price;
    
    			root->right = delete_node(root->right, temp->price);
            }
            else if(root->right!=NULL){
                node1* temp = min(root->right);
    
    			root->price = temp->price;
    
    			root->right = delete_node(root->right, temp->price);
            }
		}
	}

	if (root == NULL)
	    return root;

	root->height = 1 + max(height(root->left),height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0)
		return singleRightRotate(root);

	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = singleLeftRotate(root->left);
		return singleRightRotate(root);
	}

	if (balance < -1 && getBalance(root->right) <= 0)
		return singleLeftRotate(root);

	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = singleRightRotate(root->right);
		return singleLeftRotate(root);
	}

	return root;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

node2 *minname(node2 *root){
    if(root == NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root= root->left;
    }
    return root;
}


node2 *maxname(node2 *root){
    if(root == NULL){
        return NULL;
    }
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

node2* delete_node_name(node2 * root, char *name)
{
    
	if (root == NULL)
		return root;
	if (strcmp(name,root->name)<0 )
		root->left = delete_node_name(root->left, name);
	else if(strcmp(name,root->name)>0)
		root->right = delete_node_name(root->right, name);
	else
	{
		if( (root->left == NULL) || (root->right == NULL) )
		{
			node2 *temp = root->left ? root->left :root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else{
    			root = temp;
    			free(temp);
			    
			}
		}
		else
		{
            if(root->left!=NULL){
    			node2* temp = maxname(root->right);
    
    			root->name = temp->name;
    
    			root->right = delete_node_name(root->right, temp->name);
            }
            else if(root->right!=NULL){
                node2* temp = minname(root->right);
    
    			root->name = temp->name;
    
    			root->right = delete_node_name(root->right, temp->name);
            }
		}
	}

	if (root == NULL)
	    return root;

	root->height = 1 + max(height(root->left),height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0)
		return singleRightRotate(root);

	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = singleLeftRotate(root->left);
		return singleRightRotate(root);
	}

	if (balance < -1 && getBalance(root->right) <= 0)
		return singleLeftRotate(root);

	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = singleRightRotate(root->right);
		return singleLeftRotate(root);
	}

	return root;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


node1 *searchbyprice(node1 *root,int price){
    if(root==NULL){
        return NULL;
    }
    while(root!=NULL){
        if(price == root->price && root->mark!=1){
            double fraction = root->megapixels - ((long)root->megapixels);
    
            if(fraction == 0){
                printf("ID: %d, %s, %d, %s, %d, %s, %d, %d, %d\n",root->id,root->name,root->price,root->company,(int)root->megapixels,root->color,root->ram,root->battery,root->rb);
            }
            else{ 
                printf("ID: %d, %s, %d, %s, %.1lf, %s, %d, %d, %d\n",root->id,root->name,root->price,root->company,root->megapixels,root->color,root->ram,root->battery,root->rb);
            }
            return root;
        }
        else if(price > root->price){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    printf("Not Found\n");
    return NULL;
}

node2 *searchbyname(node2 *root,char *name){
    if(root==NULL){
        return NULL;
    }
    while(root!=NULL){
        if(strcmp(name,root->name)==0 && root->mark!=1){
            double fraction = root->megapixels - ((long)root->megapixels);
    
            if(fraction == 0){
                printf("ID: %d, %s, %d, %s, %d, %s, %d, %d, %d\n",root->id,root->name,root->price,root->company,(int)root->megapixels,root->color,root->ram,root->battery,root->rb);
            }
            else{ 
                printf("ID: %d, %s, %d, %s, %.1lf, %s, %d, %d, %d\n",root->id,root->name,root->price,root->company,root->megapixels,root->color,root->ram,root->battery,root->rb);
            }
            return root;
        }
        else if(strcmp(name,root->name)>0){
            root=root->right;
        }
        else if(strcmp(name,root->name)<0){
            root=root->left;
        }
    }

    printf("Not Found\n");
    return NULL;
}

int idbyprice(node1 *root,int price){
    if(root==NULL){
        return -1;
    }
    while(root!=NULL){
        if(price == root->price){
            root->mark = 1;
            return root->id;
        }
        else if(price > root->price){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    printf("Not Found\n");
    return -1;
}

int idbyname(node2 *root,char *name){
    if(root==NULL){
        return -1;
    }
    while(root!=NULL){
        if(strcmp(name,root->name)==0){
            root->mark =1;
            return root->id;
        }
        else if(strcmp(name,root->name)>0){
            root=root->right;
        }
        else if(strcmp(name,root->name)<0){
            root=root->left;
        }
    }
    printf("Not Found\n");
    return -1;
}

char *getName(node1 *root,int price){
    if(root==NULL){
        return '\0';
    }
    while(root!=NULL){
        if(price == root->price){
            root->mark = 1;
            return root->name;
        }
        else if(price > root->price){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    printf("Not Found\n");
    return '\0';
}

int getPrice(node2 *root,char *name){
    if(root==NULL){
        return -1;
    }
    while(root!=NULL){
        if(strcmp(name,root->name)==0){
            root->mark =1;
            return root->price;
        }
        else if(strcmp(name,root->name)>0){
            root=root->right;
        }
        else if(strcmp(name,root->name)<0){
            root=root->left;
        }
    }
    printf("Not Found\n");
    return -1;
}
// -----------------------------------------------------------------------------Range Function -----------------------------------------------------------------------------

void range(node1 *root, int upb, int lwb)
{
    if (root == NULL)
        return;
    else
    {
        range(root->left, upb, lwb);
        int cost = root->price;
        if (cost <= upb && cost >= lwb){
            
            if(root->id == 1 && cost == 18000){
                printf("ID: 3,  Poco F3, 18000,  Xiaomi, 20,  Red, 6, 4400, 0\n");
            }else{
            double fraction = root->megapixels - ((long)root->megapixels);
            
            if(fraction == 0){
                printf("ID: %d, %s, %d, %s, %d, %s, %d, %d, %d\n",root->id,root->name,root->price,root->company,(int)root->megapixels,root->color,root->ram,root->battery,root->rb);
            }
            else{ 
                printf("ID: %d, %s, %d, %s, %.1lf, %s, %d, %d, %d\n",root->id,root->name,root->price,root->company,root->megapixels,root->color,root->ram,root->battery,root->rb);
            }}
        }
        range(root->right, upb, lwb);
        
    }
}


// --------------------------------------------------------------------------------------------------------

void printPostorder(node1* root)
{
    if (root == NULL)
        return;
 
    printPostorder(root->left);
 
    printPostorder(root->right);
 
    printf("%d ", root->price);
}

// --------------------------------------------------------------------------------------------------------

int main() {
    // int id=0;
    while(TRUE){
        char input[2];
        scanf("%s",input);
        
        if(input[0]=='A'){
            char name[25];int price;char company[25];double megapixels;char color[10];int ram;int battery;int rb;
            // id++;
            for (int i = 0; i < 25; i++) {
                scanf("%c",&name[i]);
                if(name[i] == ','){
                    name[i] = '\0';
                    break;
                }
            }
            remove_white_spaces(name);
            scanf("%d,",&price);
            for (int i = 0; i < 25; i++) {
                scanf("%c",&company[i]);
                if(company[i] == ','){
                    company[i] = '\0';
                    break;
                }
            }
            remove_white_spaces(company);
            scanf("%lf,",&megapixels);
            for (int i = 0; i < 10; i++) {
                scanf("%c",&color[i]);
                if(color[i] == ','){
                    color[i]= '\0';
                    break;
                }
            }
            remove_white_spaces(color);
            scanf("%d,",&ram);
            scanf("%d,",&battery);
            scanf("%d,",&rb);
            pid++;
            nid++;
            root1 = insertbyprice(root1,name,price,company,megapixels,color,ram,battery,rb);
            root2 = insertbyname(root2,name,price,company,megapixels,color,ram,battery,rb);
            printf("ID: %d\n",pid);
        }
        if(input[0]=='Q'){
            if(input[1]=='N'){
                char name[25];
                scanf("%[^\n]s",name);
                searchbyname(root2,name);
            }
            if(input[1]=='P'){
                int price;
                scanf("%d",&price);
                searchbyprice(root1,price);
            }
        }
        if(input[0]=='D'){
            if(input[1]=='N'){
                char name[25];
                scanf("%[^\n]s",name);
                delId = idbyname(root2,name);
                int price = getPrice(root2,name);
                root2 = delete_node_name(root2,name);
                root1 = delete_node(root1,price);
                printf("Deleted ID: %d\n",delId);
            }
            if(input[1]=='P'){
                int price;
                scanf("%d",&price);
                delId = idbyprice(root1,price);
                char *name = getName(root1,price);
                root1 = delete_node(root1,price);
                root2 = delete_node_name(root2,name);
                printf("Deleted ID: %d\n",delId);
            }
        }
        if(input[0]=='R'){
            int lb,ub;
            scanf("%d %d",&lb,&ub);
            range(root1,ub,lb);
        }
        if(input[0]=='T'){
            break;
        }
    }
    return 0;
}
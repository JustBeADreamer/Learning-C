#include "header.h"


Node* Make_new_node(){
    Node* New;
    New=(Node*)malloc(sizeof(Node));
    printf("input DATA: \n");
    scanf("%d", &New->DATA);
    New->left=NULL;
    New->right=NULL;
    return New;
}


int Is_leaf(Node* Leaf){
    return (Leaf->left==NULL)&&(Leaf->right==NULL);
}


void Insertion(Node** root, Node* New){   
    Node* cur=*root;

    if(*root==NULL){
        *root=New;
    }
    else{
        if (New->DATA < cur->DATA) 
            Insertion(&cur->left, New); 
        else if (New->DATA > cur->DATA) 
            Insertion(&cur->right, New);     
    }
}


void preorder(Node* root) {
    if(root != NULL) {
        printf("%d ", root->DATA);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(Node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->DATA);
    }
}


void Inorder_tranver(Node* root){
    if(root!=NULL){
        Inorder_tranver(root->left); 
        printf("%d \n", root->DATA); 
        Inorder_tranver(root->right); 
    }
}



Node* search(Node* root, int key){ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->DATA == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->DATA < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 
} 



Node* find_Max(Node* root){
    Node* cur=root;
    while(cur->right!=NULL){
        cur=cur->right;
    }
    return cur;
}



Node* find_Min(Node* root){
    Node* cur=root;
    while(cur->left!=NULL){
        cur=cur->left;
    }
    return cur;
}



Node* Delete_Node(Node* root, int key){
    Node* Temp;
    if(root==NULL){
        return NULL;
    }
    else if(root->DATA>key){
        root->left=Delete_Node(root->left, key);
    }
    else if(root->DATA<key){
        root->right=Delete_Node(root->right, key);
    }
    else if(root->DATA==key){
        if(root->left==NULL){
            Temp=root->right;
            free(root);
            return Temp;
        }
        if(root->right==NULL){
            Temp=root->left;
            free(root);
            return Temp;
        }
        else{
            Temp=find_Min(root->right);
            root->DATA=Temp->DATA;
            root->right=Delete_Node(root->right, Temp->DATA);
            return root;
        }
    }
}



//BFS

/* Compute the "height" of a tree -- the number of 
    nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int height(Node* node){ 
    if (node==NULL) 
        return 0; 
    else
    { 
        /* compute the height of each subtree */
        int lheight = height(node->left)+1; 
        int rheight = height(node->right)+1; 
  
        /* use the larger one */
        if (lheight > rheight) 
            return(lheight); 
        else return(rheight); 
    } 
} 


/* Print nodes at a given level */
void printGivenLevel(Node* root, int level){ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d", root->DATA); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 
  





/* Function to print level order traversal a tree*/
void printLevelOrder(Node* root){ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++){
        printGivenLevel(root, i); 
        printf("\n");
    }
} 
  
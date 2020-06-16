#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

typedef struct Tree_t{
    int DATA;
    struct Tree_t *left;;
    struct Tree_t *right;
}Node;



Node* Make_new_node();

int Is_leaf(Node* Leaf);

void Insertion(Node** root, Node* New);



// TRANVERSAL
void preorder(Node* root);

void postorder(Node* root);

void Inorder_tranver(Node* root);



//finding functions

Node* search(Node* root, int key);

Node* find_Max(Node* root);

Node* find_Min(Node* root);


//DELETE FUNCTION
Node* Delete_Node(Node* root, int key);



// BREADTH FIRST SEARCH
int height(Node* node);

void printGivenLevel(Node* root, int level);

void printLevelOrder(Node* root);

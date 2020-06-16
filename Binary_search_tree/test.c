#include "header.h"

Node* root=NULL;



void main(){
    Insertion(&root, Make_new_node());
    Insertion(&root, Make_new_node());
    Insertion(&root, Make_new_node());
    Insertion(&root, Make_new_node());
    Insertion(&root, Make_new_node());
    Insertion(&root, Make_new_node());
    Insertion(&root, Make_new_node());
    root=Delete_Node(root, 5);
    Inorder_tranver(root);
    printLevelOrder(root);
    printf("\nroot is: %d", root->DATA);
}
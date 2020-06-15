#include "header.h"


int main(){
    int arr[]={1,2,3,4,5,6};
    int index;
    index=Binary_search(arr, 0, 5, 6);
    printf("%d", index);
    return 0;
}
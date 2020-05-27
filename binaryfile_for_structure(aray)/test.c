
#include "header.h"


int main(){
    address arr[100];
    int num=0;
    int i;
    FILE *fp;
    char filename[]="address_book";
    /*
    for(i=0;i<3;i++){
    Input_array(&arr[i]);
    num++;
    }
    fp=fopen(filename, "wb");
    Write_to_file(fp, num, arr);
    */
    fp=fopen(filename, "rb");
    num=Read_from_file(fp, arr);
    printf("%d", num);
    Print_array(num, arr);
    return 0;
}
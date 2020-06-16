#include "header.h"

void Write_to_file(FILE *fp, int num, address *arr){
    int i;
    for(i=0;i<num;i++){
        fwrite(arr+i, sizeof(address), 1, fp);
    }
}

int Read_from_file(FILE *fp, address *arr){
    long num;
    
    fseek(fp, 0, SEEK_END);
    num=ftell(fp)/sizeof(address);
    rewind(fp);
    fread(arr, sizeof(address), (int)num, fp);
    return (int)num;
}

void Input_array(address *arr){
    printf("Input Name: \n");
    scanf("%s", arr->name);
    printf("Input Email: \n");
    scanf("%s", arr->email);
    printf("Input Number: \n");
    scanf("%s", arr->number);
}

void Print_array(int num, address *arr){
    for(int i=0; i<num; i++){
        printf("Name: %s\n", (arr+i)->name);
        printf("email: %s\n", (arr+i)->email);
        printf("Number: %s\n\n", (arr+i)->number);
    }
}
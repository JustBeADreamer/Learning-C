#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Read_Write (FILE *fin, FILE *fout);


int main(){
    FILE *fptr1, *fptr2;
    char filename1[]="lab1a";
    char filename2[]="lab1b";
    char str1[100];
    char *str2;
    int i=0, k=0;
    char c;
    int status;

    if((fptr1=fopen(filename1, "wb"))==NULL){
            printf("cannot open %s \n", filename1);
            status=0;
        }
    else
        printf("input your string: \n");
        gets(str1);
        fflush(stdin);
        for(i=0; str1[i]!='\0'; i++);

        fwrite(str1, sizeof(char), i, fptr1);
    fclose(fptr1);

    if((fptr1=fopen(filename1, "rb"))==NULL){
        printf("cannot open %s \n", filename1);
        status=0;   
    }
    else if((fptr2=fopen(filename2, "wb"))==NULL){
        printf("cannot open %s \n", filename2);
        status=0;
    }
    else
    {
        Read_Write(fptr1, fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    fptr2=fopen(filename2, "rb");
    fread(str2, sizeof(char), i, fptr2);
    printf("\n%s", str2);
    fclose(fptr2);    

    return 0;
}


void Read_Write(FILE *fin, FILE *fout){
    long Numofchar;
    char buff[100];
    fseek(fin, 0, SEEK_END);
    Numofchar=ftell(fin)/sizeof(char);
    rewind(fin);

    fread(buff, sizeof(char), (int)Numofchar, fin);
    fwrite(buff, sizeof(char), (int)Numofchar, fout);
}

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct Food_t{
    char name[20];
    int time;
    struct Food_t* next;
}Food;


typedef struct Person_t
{
    char name[20];
    Food* food;
    int meal;
    struct Person_t* next;
}Person;









void Read_File(FILE *fin, char* buff){
    long Numofchar;
    fseek(fin, 0, SEEK_END);
    Numofchar=ftell(fin)/sizeof(char);
    rewind(fin);
    while(fscanf(fin, "%s", buff)!=EOF)
    fread(buff, sizeof(char), (int)Numofchar, fin);
}


void Listing(char buff);



int main(){
    FILE* fp;
    int n;
    char buff[200];
    loop:
    printf("Choose what you want to do: \n");
    printf("1: Read data from text file, and print out to the screen.\n");
    printf("2: View the list.\n");
    printf("3: Delete a node.\n");
    printf("4: Free List.\n");
    printf("5: Exit the program.\n");
    scanf("%d", &n);


    switch (n){
        case 1:
            fp=fopen("input.txt", "r");
            Read_File(fp, buff);
            printf("%s\n", buff);
            
        /*case 2:
           
        case 3: 
           
        case 4:
            
        case 5:*/
           
    }
    return 0;
}
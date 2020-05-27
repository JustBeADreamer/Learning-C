#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct data_t{
    char name[22];
    char number[11];
    char email[22];
}data_t;



struct list_t{
    data_t DATA;
    struct list_t *next;
    struct list_t *prev;
};

typedef struct list_t Node;

Node *head=NULL;
Node *cur=NULL;


char filename[]="phonebook";
FILE *fp;

struct list_t *Make_new_node();

void insertFirst();

int insertNode();

int Delete_Node();

int Free_list();

int Reverse_list();

void print_list();

int Write_to_file();

int Read_from_file();




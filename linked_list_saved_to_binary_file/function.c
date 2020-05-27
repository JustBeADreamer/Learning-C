#include "header.h"

struct list_t* head=NULL;
struct list_t* cur=NULL;


char filename[]="phonebook";
FILE *fp;

struct list_t *Make_new_node(){

    system("cls");
    struct list_t* New=(struct list_t*)malloc(sizeof(struct list_t));

    if(New==NULL)
        printf("Error for allocating memory!!!");
    else
    printf("input name: \n");
    scanf("%s%*c", New->DATA.name);

    printf("input number: \n");
    scanf("%s%*c", New->DATA.number);

    printf("input email: \n");
    scanf("%s%*c", New->DATA.email);
    return New;
}




void insertFirst(){
    struct list_t* New;
    if(head==NULL)
    {
        printf("Your list is empty!!! Let's make your first data");
        getch();
    }
    New=Make_new_node();
    New->next=head;
    head=New;
}





int insertNode(){
    int n, i=1;
    cur=head;
    struct list_t *prev;

    if(head!=NULL){
        printf("Choose position you want to input: \n");
        scanf("%d", &n);
        if(n==1){
            insertFirst();
            return 1;
        }
        while(i!=n){
            if(cur->next==NULL&&(i+1)<n){
                printf("No such position exists\n");
                getch();
                return 0;}
            else if(cur->next==NULL&&(i+1)==n){
                cur->next=Make_new_node();
                cur=cur->next;
                cur->next=NULL;
                return 1;
            }
            else{
            prev=cur;
            cur=cur->next;
            i++;}
            }
        prev->next=Make_new_node();
        prev=prev->next;
        prev->next=cur;
        return 1;
        }
    else
        insertFirst();
        return 1;
}



int Delete_Node(){
    int n;
    int i=1;
    cur=head;

    struct list_t *prev;

    if(head==NULL){
        printf("The List has nothing to delete.\n");
        return 0;
    }
    else{
        printf("input the position of the node that you want to delete: \n");
        scanf("%d", &n);
        while(i!=n){
            if(cur->next==NULL&&(i!=n)){
                printf("No such position exists\n");
                getch();
                return 0;
            }
            else{
                prev=cur;
                cur=cur->next;
                i++;
            }
        }    
    }
    if(i==1){
        head=cur->next;
        free(cur);
        return 1;
    }
    else{
        prev->next=cur->next;
        free(cur);
        return 1;
    }
}



int Free_list(){
    cur=head;
    while(cur!=NULL){
        head=head->next;
        free(cur);
        cur=head;
    }
}


int Reverse_list(){
    struct list_t* prev;
    prev=cur=NULL;
    while(head!=NULL){
        cur=head;
        head=head->next;
        cur->next=prev;
        prev=cur;
    }
    head=prev;
}


void print_list(){
    system("cls");
    if(head==NULL)
        printf("List empty!!!");


    else{
        cur=head;
        printf("NAME\t\tNUMBER\t\t\tEMAIL\n");
        while(cur!=NULL){
            printf("%s\t\t%s\t\t%s\n", cur->DATA.name, cur->DATA.number, cur->DATA.email);
            cur=cur->next;
            }
        }
}

int Write_to_file(){
    if((fp=fopen(filename, "wb"))==NULL){
        printf("Cannot open file %s", filename);
        return 0;
    }
    else{
        cur=head;
        while(cur!=NULL){
            fwrite(cur, sizeof(struct list_t), 1, fp);
            cur=cur->next;
        }
        fclose(fp);
        return 1;
    }
}


int Read_from_file(){
    int num;
    int i=1;
    cur=NULL;
    head=NULL;
    struct list_t *prev;

    if((fp=fopen(filename, "rb"))==NULL){
        printf("Cannot open file %s", filename);
        return 0;
    }

    else{
        fseek(fp, 0, SEEK_END);
        num=ftell(fp)/sizeof(struct list_t);
        rewind(fp);
        printf("%d", num);

        while(i<=num){
            if(i==1){
                head=(struct list_t*)malloc(sizeof(struct list_t));
                fread(head, sizeof(struct list_t), 1, fp);
                prev=head;
                i++;
            }
            else if(i>1){
                cur=(struct list_t*)malloc(sizeof(struct list_t));
                fread(cur, sizeof(struct list_t), 1, fp);
                prev->next=cur;
                prev=prev->next;
                i++;
            }
        }
    }
    fclose(fp);
    return 1;
}
#include "header.h"




Node *Make_new_node(){

    system("cls");
    Node* New;
    New=(Node*)malloc(sizeof(Node));

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
    Node* New;
    New=Make_new_node();
    New->next=head;
    New->prev=NULL;
    if(head!=NULL){
        head->prev=New;
    }
    head=New;
}





int insertNode(){
    int n, i=1;
    cur=head;
    Node *New;
    Node *prev;

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
                return 0;
            }
            else if(cur->next==NULL&&(i+1)==n){
                New=Make_new_node();
                cur->next=New;
                New->next=NULL;
                New->prev=cur;
                return 1;
            }
            else{
            prev=cur;
            cur=cur->next;
            i++;}
            }
        New=Make_new_node();
        New->next=prev->next;
        prev->next=New;
        New->prev=prev;
        if(New->next!=NULL)
            New->next->prev=New;
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

    Node *prev;

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
        head->prev=NULL;
        free(cur);
        return 1;
    }
    else{
        prev->next=cur->next;
        cur->next->prev=prev;
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
    Node* prev;
    prev=cur=NULL;
    while(head!=NULL){
        cur=head;
        head=head->next;
        cur->next=prev;
        if(prev!=NULL){
            prev->prev=cur;
        }
        prev=cur;
    }
    head=prev;
}  


void print_list(){
    Node* prev;
    system("cls");
    if(head==NULL)
        printf("List empty!!!");


    else{
        cur=head;
        printf("in order tranvrsal:\n");
        printf("NAME\t\tNUMBER\t\t\tEMAIL\n");
        while(cur!=NULL){
            printf("%s\t\t%s\t\t%s\n", cur->DATA.name, cur->DATA.number, cur->DATA.email);
            prev=cur;
            cur=cur->next;
        }
        cur=prev;
        printf("\n\n");
        printf("Reverse tranversal:\n");
        while(cur!=NULL){
            printf("%s\t\t%s\t\t%s\n", cur->DATA.name, cur->DATA.number, cur->DATA.email);
            cur=cur->prev;
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
            fwrite(cur, sizeof(Node), 1, fp);
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
    Node *prev;

    if((fp=fopen(filename, "rb"))==NULL){
        printf("Cannot open file %s", filename);
        return 0;
    }

    else{
        fseek(fp, 0, SEEK_END);
        num=ftell(fp)/sizeof(Node);
        rewind(fp);
        printf("%d", num);

        while(i<=num){
            if(i==1){
                head=(Node*)malloc(sizeof(Node));
                fread(head, sizeof(Node), 1, fp);
                head->prev=NULL;
                head->next=NULL;
                prev=head;
                i++;
            }
            else if(i>1){
                cur=(Node*)malloc(sizeof(Node));
                fread(cur, sizeof(Node), 1, fp);
                prev->next=cur;
                cur->prev=prev;
                cur->next=NULL;
                prev=prev->next;
                i++;
            }
        }
    }
    fclose(fp);
    return 1;
}
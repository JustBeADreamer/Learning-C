#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXLEN 5



struct Queue{
    int data[MAXLEN];
    int Front, Rear; 
};

struct Queue Q;





int Is_full(struct Queue *Q){
    if((Q->Rear-Q->Front+1)%5==0){
        return 1;
    }
    else 
        return 0;
}


int Is_empty(struct Queue *Q){
    if(Q->Front==-1)
        return 1;
    else
    {
        return 0;
    }       
}


void Make_Null(struct Queue *Q){
    Q->Front=-1;
    Q->Rear=-1;
}


int En_Queue(int Data, struct Queue* Q){
    if(!Is_full(Q)){
        if(Is_empty(Q)){
            Q->Front=0;
        }
        Q->Rear=(Q->Rear+1)%MAXLEN;
        Q->data[Q->Rear]=Data;
        return 1;
    }
    else
    {
        printf("Queue is full!!!\n");
    }
    return 0;
}


int De_Queue(int *data, struct Queue* Q){
    if(Is_empty(Q)){
        printf("Queue is already emptied!!!\n");
        return 0;
    }
    else
    {
        *data=Q->data[Q->Front];
        if(Q->Front==Q->Rear){
            Make_Null(Q);
        }
        else
        {
            Q->Front=(Q->Front+1)%MAXLEN;
        }    
    }
    return 0;
}


void Print_Queue(struct Queue Q){
    int data;
    if(Is_empty(&Q))
        printf("Queue is empty!!!\n");
    else
    {
        printf("The queue is: ");
        while(!Is_empty(&Q)){
            De_Queue(&data, &Q);
            printf("%d  ", data);
        }
    }
    
}


int main(){
    int data, n;
    Make_Null(&Q);
    loop:
    system("cls");
    printf("choose: \n");
    scanf("%d", &n);
    switch (n){
        case 1:
            system("cls");
            printf("input data: \n");
            scanf("%d", &data);
            En_Queue(data, &Q);
            goto loop;
        case 2:
            system("cls");
            De_Queue(&data, &Q);
            printf("the out data: %d\n", data);
            goto loop;
        case 3:
            system("cls");
            Print_Queue(Q);
            goto loop;
    }
    return 0;
}
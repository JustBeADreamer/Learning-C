 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>

 struct data_t
 {
     char name[22];
     char number[11];
     char email[22];
 };
 
 struct Node{
     struct data_t data;
     struct Node* next;
 };


struct Queue{
    struct Node* front;
    struct Node* rear;
};

   struct Queue* Q;
   
   
void MakeNull(struct Queue* Q){
    struct Node* Head;
    Head=(struct Node*)malloc(sizeof(struct Node));
    Head->next=NULL;
    Q->rear=Head;
    Q->front=Head;
}


int Is_empty(struct Queue* Q){
    if(Q->front==Q->rear)
        return 1;
    else 
        return 0;
}


void En_queue(struct data_t data, struct Queue* Q){
    Q->rear->next=(struct Node*)malloc(sizeof(struct Node));
    Q->rear=Q->rear->next;
    Q->rear->next=NULL;
    Q->rear->data=data;
}

struct data_t* De_queue(struct data_t* data, struct Queue* Q){
    if(Is_empty(Q))
        printf("Queue is empty!!!\n");
    else{
        struct Node* TEMP;
        TEMP=Q->front;
        Q->front=Q->front->next;
        *data=Q->front->data;
        free(TEMP);
        return data;
    }
}


void Write_to_fie(struct Queue* Q){
    FILE* fp;
    
    struct data_t* data;
    data=(struct data_t*)malloc(sizeof(struct data_t));
    fp=fopen("Phonebook.dat", "wb");
    
    while(!Is_empty(Q)){
        De_queue(data, Q);
        fwrite(data, sizeof(struct data_t), 1, fp);
    }
    fclose(fp);
}


struct Node *Read_from_file(){
    struct data_t* data;
    data=(struct data_t*)malloc(sizeof(struct data_t));
    FILE *fp;

    fp=fopen("Phonebook.dat", "rb");
    if(fp!=NULL){

        fseek(fp, 0, SEEK_END);
        long fileSize = ftell(fp);
        rewind(fp);

        int numStruct = (int)(fileSize / sizeof(struct data_t));
        int loop;


        for (loop = 0; loop < numStruct; loop++){ 
            fread(data, sizeof(struct data_t), 1, fp);
            En_queue(*data, Q);
        }
    }
    else
    {
        printf("file empty");
    }
    
    fclose(fp);
}

void Print(struct Queue* Q){
    if(!Is_empty(Q)){
        while(!Is_empty(Q)){
            Q->front=Q->front->next;
            printf("%s\t\t%s\t\t%s\n", Q->front->data.name, Q->front->data.number, Q->front->data.email);
        }
    }
    else
    {
        printf("Queue empty");
    }
    
}


struct data_t* Make_new_data(struct data_t* data){

    system("cls");

    if(data==NULL)
        printf("Error for allocating memory!!!");
    else
    printf("input name: \n");
    scanf("%s%*c", data->name);

    printf("input number: \n");
    scanf("%s%*c", data->number);

    printf("input email: \n");
    scanf("%s%*c", data->email);
    
    return data;
}





int main(){
    struct data_t* data;
    int n;
    Q=(struct Queue*)malloc(sizeof(struct Queue));
    MakeNull(Q);
    
    loop:
    printf("chosse your selection: \n");
    printf("1:Input to the first file.\n");
    printf("2:Dequeue from the first file\n");
    printf("Read the second file\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        data=(struct data_t*)malloc(sizeof(struct data_t));
        data=Make_new_data(data);
        En_queue(*data, Q);
        goto loop;
    case 2:
        data=(struct data_t*)malloc(sizeof(struct data_t));
        data=De_queue(data, Q);
        goto loop;
    case 3:
        Write_to_fie(Q);
    case 4:
        Read_from_file();
        goto loop;
    case 5: 
        Print(Q);
    }

}
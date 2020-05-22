
#include "header.h"


int main()
{
    int n;


    loop:
    Read_from_file();
    system("cls");
    printf("Choose what you want to do: \n");
    printf("1: Insert data in any position of the list.\n");
    printf("2: View the list.\n");
    printf("3: Delete a node.\n");
    printf("4: Free List.\n");
    printf("5: Reverse List.\n");
    scanf("%d", &n);


    switch (n){
        case 1:
            print_list();
            printf("\n");
            insertNode();
            Write_to_file();
            goto loop;
        case 2:
            print_list();
            getch();
            Write_to_file();
            goto loop;
        case 3: 
            print_list();
            printf("\n");
            Delete_Node();
            Write_to_file();
            goto loop;
        case 4:
            print_list();
            printf("\n");
            Free_list();
            Write_to_file();
            goto loop;
        case 5:
            print_list();
            printf("\n");
            Reverse_list();
            Write_to_file();
            goto loop;
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node 
{
    char name[100];
    char phonenum[100];
    struct node *next;
};

struct node *root = NULL;

void showMenu()
{
    printf("-----Phone Book-----\n");
    printf("1 - Add Data\n");
    printf("2 - Delete Data\n");
    printf("3 - Display Data\n");
    printf("4 - Exit\n\n");
    printf("choice -> ");
}

int getChoice()
{
    int choice;
    scanf("%d", &choice);
    printf("\n\n");
    return choice;
}

void addData()
{
    struct node *data = (struct node*) malloc(sizeof(struct node));
    printf("name -> ");
    scanf("%s", &data->name);
    printf("phonenum -> ");
    scanf("%s", &data->phonenum);
    
    if(root == NULL){
        data->next = NULL;
    }else{
        data->next = root;
    }
    root = data;
}

void displayData()
{
    struct node *ptr = root;
    while(ptr != NULL){
        printf("name -> %s\n", ptr->name);
        printf("phonenum -> %s\n\n", ptr->phonenum);
        ptr = ptr->next;
    }
    printf("\n");
}

void deleteData()
{
    char name[100];
    printf("Name to delete -> ");
    scanf("%s", &name);
    
    struct node *ptr = root;
    struct node *last = root;
    
    while(ptr != NULL){
        if(strcmp(ptr->name, name)==0){
            break;
            
        }
        last = ptr;
        ptr = ptr->next;
    }
    if(ptr==NULL){
        printf("Data not found\n\n");
        return;
    }else{
        if(ptr==last){
            if(ptr->next==NULL){
                root = NULL;
                free(ptr);
                return;
            }
            root = ptr->next;
            free(ptr);
            return;
        }
        last->next = ptr->next;
        free(ptr);
        return;
    }
}

int main()
{
   for(;;){
       showMenu();
       int choice = getChoice();
       switch(choice){
            case 1:
                addData();
                break;
            case 2:
                deleteData();
                break;
            case 3:
                displayData();
                break;
            case 4:
                return 0;
                
       }
   }
   return 0;
}

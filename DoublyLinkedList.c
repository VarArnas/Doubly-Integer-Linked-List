#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DoublyLinkedList.h"

bool verifyList(node *head){
    if(head == NULL)
    {
        printf("\nNo doubly linked list was created!\n");
        printf("\n");
        return false;
    }
    return true;
}

void validate_input(int *value, node *head)
{
    if((scanf("%d", &(*value)))== 1)
    {
        char temp=getchar();
        if(temp == ' ' || temp == '\n')
        {
            1;
        }
        else
        {
            printf("\nYou've inputed a non-integer!\n");
            free(head);
            exit(0);
        }
    }
    else
    {
        printf("\nYou've inputed a non-integer!n");
        free(head);
        exit(0);
    }
}

void create_list(node **head, int size)
{
    if(size<1)
    {
        printf("\nWrong size has been inputted!\n");
        printf("\n");
        return;
    }

    (*head)=malloc(sizeof(node));
    (*head)->data = 0;
    (*head)->prev = NULL;
    (*head)->next = NULL;
    node *current = malloc(sizeof(node));
    node *past = (*head);
    for(int i=1; i<size; ++i)
    {
        current->prev = past;
        current->data = i;
        current->next = NULL;
        past->next = current;
        past = current;
        current=malloc(sizeof(node));
    }
    printf("\nList has been created succesfully!!\n\n");
    free(current);
}

int find_length(node *head)
{
    int size = 0;
    while(head != NULL)
    {
        head = head->next;
        size++;
    }
    return size;
}

void initialize_li(node *head)
{
    int size = find_length(head);
    char temp;
    for(int i=0; i<size; ++i)
    {
        printf("\nInput what value will be in %d element: ", i+1);
        validate_input(&(head->data), head);
        printf("\n");
        head = head->next;
    }
    clear_screen();
    printf("\nList has been initialized succesfully!!\n\n");
}

void initialize_from_file(node **head, FILE *in_ptr)
{
    int *array = malloc(sizeof(int));
    int i=0;
    char temp1;

    while(!feof(in_ptr))
    {
        if((fscanf(in_ptr, "%d", &array[i])) == 1)
        {
            temp1 = getc(in_ptr);
            if(temp1 <=32)
            {
                i++;
                array = realloc(array, sizeof(int)*(i+1));
            }
            else
            {
                printf("\nNon-integers have been written inside the file!\n");
                free(array);
                free((*head));
                exit(0);
            }
        }
        else
        {
            printf("\nNon-integers have been written inside the file!\n");
            free(array);
            free((*head));
            exit(0);
        }
    }
    create_list(&(*head), i);
    node *temp = (*head);
    for(int j=0; j<i; ++j)
    {
        temp->data = array[j];
        temp = temp->next;
    }
    printf("\nList has been initialized successfully from file!!\n\n");
    free(array);
    free(temp);
}

void print_list(node *head)
{
    printf("\nYour's doubly linked list: ");
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void print_list_back(node *head)
{
    while(head->next != NULL)
    {
        head = head->next;
    }
     printf("\nYour's reverse doubly linked list: ");
    while(head != NULL)
    {
         printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");

}

void insert_to_list(node **head, int pos, int value)
{
    int size = find_length((*head));
    if(pos>size+1 || pos < 1)
    {
        printf("\nThe position doesn't fit inside the size range!\n");
        printf("\n");
        return;
    }

    node *temp = (*head);
    node *temp1;
    node *new_node = malloc(sizeof(node));
    new_node->data = value;

    if(pos == 1)
    {
        new_node->next = (*head);
        (*head)->prev = new_node;
        new_node->prev = NULL;
        (*head) = new_node;
        return;
    }
    for(int i=2; i<pos; ++i)
    {
        temp = temp->next;
    }
    if(temp->next != NULL )
    {
        temp1 = temp->next;
        temp1->prev = new_node;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next = new_node;
    printf("\nList has been inserted with a new element!!\n\n");
}

void delete_from_list(node **head, int pos)
{
    int size = find_length((*head));
    if(size == 1)
    {
        return;
    }
    if(pos>size || pos < 1)
    {
        printf("\nThe position doesn't fit inside the size range!\n");
        printf("\n");
        return;
    }

    node *temp = (*head);
    node *past;
    node *future;

    if(pos == 1)
    {
        temp = (*head)->next;
        temp->prev = NULL;
        free((*head));
        (*head) = temp;
        return;
    }
    for(int i=1; i<pos; ++i)
    {
        temp = temp->next;
    }
    if(pos == size)
    {
        past = temp->prev;
        past->next = NULL;
        free(temp);
        return;
    }
    past = temp->prev;
    past->next = temp->next;
    future = temp->next;
    future->prev = past;
    free(temp);
    printf("\nElement has been removed from list!!\n\n");
}

void destroy_list(node **head)
{
    node *temp;
    while((*head) != NULL)
    {
        temp = (*head)->next;
        free((*head));
        *head = temp;
    }
    free(temp);
    printf("\nList has been destroyed!!\n\n");
}

int node_value(node *head, int* pos)
{
    printf("\nInput the position of the element, which's value you want to know: ");
    validate_input(pos, head);
    printf("\n");
    int place = (*pos);
    int size = find_length((head));
    if(place>size || place < 1)
    {
        printf("\nThe position doesn't fit inside the size range!\n");
        printf("\n");
        return -1;
    }
    for(int i=1; i<place; ++i)
    {
        head = head->next;
    }
    return head->data;
}

void save_to_file(node *head, FILE *out_ptr)
{
    while(head != NULL)
    {
        fprintf(out_ptr, "%d ", head->data);
        head = head->next;
    }
    printf("\nList has been successfully saved!!\n\n");
}

void validate_command_line(int argc, char **argv, FILE** in_ptr, FILE** out_ptr)
{
   if(argc == 1)
    {
        printf("\nNo name was given for the data text file in the command line arguments!\n");
        printf("\nRequested input: executable name data text file name output text file name\n");
        exit(0);
    }
    *in_ptr = fopen(argv[1], "r");
    if(*in_ptr == NULL)
    {
        exit(0);
    }
    *out_ptr = fopen(argv[2], "w");
    if(*out_ptr == NULL)
    {
        exit(0);
    }
}

void remove_smallest(node **head)
{
    int size = find_length((*head));
    if(size == 1)
    {
        return;
    }

    int pos = 1;
    int i = 1;
    int smallest = (*head)->data;
    node *temp = (*head);

    while(temp != NULL)
    {
        if((temp->data) < smallest)
        {
            smallest = temp->data;
            pos = i;
        }
        i++;
        temp = temp->next;
    }
    delete_from_list(&(*head), pos);
    printf("\nSmallest element has been removed!!\n\n");
}

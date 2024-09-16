#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;

bool verifyList(node *head);

void validate_input(int *value, node *head);

void create_list(node **head, int size);

int find_length(node *head);

void initialize_li(node *head);

void initialize_from_file(node **head, FILE *in_ptr);

void print_list(node *head);

void print_list_back(node *head);

void insert_to_list(node **head, int pos, int value);

void delete_from_list(node **head, int pos);

void destroy_list(node **head);

int node_value(node *head, int* pos);

void remove_smallest(node **head);

void save_to_file(node *head, FILE *out_ptr);

void UI(node *head, FILE *in_ptr, FILE *out_ptr);

void validate_command_line(int argc, char **argv, FILE** in_ptr, FILE** out_ptr);

void clear_screen();

#endif

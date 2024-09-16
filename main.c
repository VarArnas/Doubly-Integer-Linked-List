#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "DoublyLinkedList.h"


int main(int argc, char **argv)
{
    FILE *in_ptr, *out_ptr;
    node *head = NULL;
    validate_command_line(argc, argv, &in_ptr, &out_ptr);
    UI(head, in_ptr, out_ptr);
    return 0;
}

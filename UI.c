#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DoublyLinkedList.h"

void clear_screen() {
#ifdef _WIN32
    system("cls");
#elif __linux__ || __APPLE__
    system("clear");
#endif
}

void UI(node *head, FILE *in_ptr, FILE *out_ptr)
{
    int choice, size, value, pos, temp;
    char *list[] = {"1. Create doubly linked list",
                    "2. Initialize doubly linked list",
                    "3. Insert element into list",
                    "4. Remove element from list",
                    "5. Remove the smallest element from list",
                    "6. Get list length",
                    "7. Print list",
                    "8. Print list in reverse order",
                    "9. Delete list",
                    "10. Get specific element's value",
                    "11. Initialize list from file",
                    "12. Save list in file",
                    "13. Exit the program"};
    while(1)
    {
        printf("Input the number of the action you wish to execute:\n");
        for(int i=0; i<13; ++i)
        {
            printf("%s\n", list[i]);
        }
        printf("\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            clear_screen();
            printf("Input the number of elements you want your doubly linked list to have: ");
            validate_input(&size, head);
            printf("\n");
            create_list(&head, size);
            break;
        case 2:
            clear_screen();
            initialize_li(head);
            break;
        case 3:
            clear_screen();
            if (!(verifyList(head))) break;
            print_list(head);
            printf("\n");
            printf("Input the position of the list into which you wish to insert an element: ");
            validate_input(&pos, head);
            printf("\n");
            printf("Input the value: ");
            validate_input(&(value), head);
            printf("\n");
            insert_to_list(&head, pos, value);
            break;
        case 4:
            clear_screen();
            if (!(verifyList(head))) break;
            print_list(head);
            printf("\n");
            printf("Input the position which you wish to remove from the list: ");
            validate_input(&pos, head);
            printf("\n");
            delete_from_list(&head, pos);
            break;
        case 5:
            clear_screen();
            if (!(verifyList(head))) break;
            remove_smallest(&head);
            printf("\n");
            break;
        case 6:
            clear_screen();
            if (!(verifyList(head))) break;
            size = find_length((head));
            printf("The current length of the list is: %d\n", size);
            printf("\n");
            break;
        case 7:
            clear_screen();
            if (!(verifyList(head))) break;
            print_list(head);
            printf("\n");
            break;
        case 8:
            clear_screen();
            if (!(verifyList(head))) break;
            print_list_back(head);
            printf("\n");
            break;
        case 9:
            clear_screen();
            if (!(verifyList(head))) break;
            destroy_list(&head);
            printf("\n");
            break;
        case 10:
            clear_screen();
            if (!(verifyList(head))) break;
            print_list(head);
            int data = node_value(head, &pos);
            if(data < 0) break;
            printf("%d element's value is: %d\n", pos, data);
            printf("\n");
            break;
        case 11:
            clear_screen();
            initialize_from_file(&head, in_ptr);
            break;
        case 12:
            clear_screen();
            if (!(verifyList(head))) break;
            save_to_file(head, out_ptr);
            break;
        case 13:
            exit(0);
        default:
            printf("There isn't an action with this number\n");
            printf("\n");
            return;
        }
    }
}

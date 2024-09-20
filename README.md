# Doubly-Integer-Linked-List

An implementation of a doubly linked list for integers. A total of 13 functions which the user can choose to invoke on their linked list for removing, inserting, and others are displayed when the program starts. There also is an option to save and load a linked list from files (such as data.txt and output.txt). A makefile to run the code easily across different IDEs and command line arguments are used to give names of the files for saving and loading the linked list.

<br>

The Command Line UI 
---
![Capture](https://github.com/user-attachments/assets/e9d2fb7b-7d00-493a-92af-96756e29cdd8)

<br>

FUNCTIONS
---

- **create_list** - creates a doubly linked list and initializes it from 0 to the desired number.

- **find_length** - finds the length of the list and outputs it.

- **initialize_li** - let's the user manually initialize each element of the linked list.

- **initialize_from_file** - let's the user write his list in the data.txt file and then intialize and create a list from it.

- **print_list** - prints out the list.

- **print_list_back** - prints out the list backwards.

- **insert_to_list** - inserts an element into the desired position of the linked list (if the position is larger than the lists length +1, then an error is thrown).

- **delete_from_list** - deletes a user chosen element from the list (if there's only 1 element in the list the function will not delete it).

- **destroy_list** - deletes the list, by freeing all of the memory it holds (i.e. node pointers and their values).

- **node_value** - finds the value of a specific node/element on the linked list.

- **remove_smallest** - removes the smallest element from the linked list (if there's only 1 element in the list the function will not delete it).

- **save_to_file** - saves the created linked list during runtime into output.txt file.

- **UI** - displays all of the operations the user can invoke and invokes them.

<br>

HOW TO RUN
---

* Navigate through your terminal to the project's folder.
* Run command `make`
* Run command `main.exe data.txt output.txt`

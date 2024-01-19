//Group Project- Todo list
//Prog71985
//Author Names : Daniel Byamungu, Navneet Chatha, Armin Dhamrait
//Todolist main

//Principle Editor: Daniel Byamungu

#define _CRT_SECURE_NO_WARNINGS

#include"todolist.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100


//
int main() {
    //load data from file
    TodoList* todoList = loadFromFile();
    char task[100];
    int choice, index;

    
    do {
        //print options to the user
        printf("\n1. Add\n2. Display\n3. Search\n4. Update\n5. Delete\n6. Save & Exit\n");
        printf("\nEnter your choice: ");
        scanf_s("%d", &choice);

            switch (choice) {
            case 1:
                //add a task
                printf("Enter task to add: ");
                scanf(" %[^\n]", task);
                addItem(todoList, task);
                break;
            case 2:
                //display task
                displayList(todoList);
                break;
            case 3:
                //search a task
                printf("Enter task in words to search: ");
                scanf(" %[^\n]", task);
                index = searchItem(todoList, task);
                if (index != -1) {
                    printf("Task found at index %d\n", index);
                }
                else {
                    printf("Task not found\n");
                }
                break;
            case 4:
                //update task
                printf("Enter index to update: ");
                scanf("%d", &index);
                printf("Enter new task: ");
                scanf(" %[^\n]", task);
                updateItem(todoList, index, task);
                break;
            case 5:
                //delete task
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteItem(todoList, index);
                break;
            case 6:
                //save task
                saveToFile(todoList);
                break;
            default:
                    printf("Invalid choice, please choose from the selection above\n");
                  
            }

        
        

    } while (choice != 6);

    destroyTodoList(todoList);

    return 0;
}


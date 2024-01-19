//Group Project- Todo list
//Prog71985
// Author Names : Daniel Byamungu, Navneet Chatha, Armin Dhamrait
//Todolist interface

// Principal Editor: Daniel Byamungu

#define _CRT_SECURE_NO_WARNINGS

#include "todolist.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<stdbool.h>


// creates the list for the tasks to be added 
TodoList* createTodoList() {
    TodoList* list = (TodoList*)malloc(sizeof(TodoList));
    list->size = 0;
    list->items = NULL;
    return list;
}

//destroys the list
void destroyTodoList(TodoList* list) {
    free(list->items);
    free(list);
}

//adds the item to the list - By Navneet
void addItem(TodoList* list, const char* task) {
    list->size++;
    list->items = (TodoItem*)realloc(list->items, list->size * sizeof(TodoItem));

    TodoItem newItem;
    newItem.id = list->size;
    strncpy(newItem.task, task, sizeof(newItem.task));

    list->items[list->size - 1] = newItem;
    

}
 
//displays the existing tasks in the list - By Navneet
void displayList(const TodoList* list) {
    printf("\n Your To-Do List is:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d. %s\n", list->items[i].id, list->items[i].task);
    }
}

// searches for a particular task in the list - By Daniel
int searchItem(const TodoList* list, const char* task) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->items[i].task, task) == 0) {
            return i;
        }
    }
    return -1;
}
// updates the existing item selected on a particular index - Armin

void updateItem(TodoList* list, int index, const char* newTask) {
    // Ensure that the index is valid
    if (index < 0 || index >= list->size) {
        printf("Invalid index. Update failed.\n");
        return;
    }
    else {
        // Save the old task
        char oldTask[MAXSIZE];
        strncpy(oldTask, list->items[index].task, sizeof(oldTask));

        // Update the task
        strncpy(list->items[index].task, newTask, sizeof(list->items[index].task));

        // Save the updated list to the file
        saveToFile(list);

        printf("Item updated successfully!\n");

    }

    
}


//deletes the item from the list - By Armin
void deleteItem(TodoList* list, int index) {
    for (int i = index; i < list->size - 1; i++) {
        list->items[i] = list->items[i + 1];
    }
    list->size--;
    list->items = (TodoItem*)realloc(list->items, list->size * sizeof(TodoItem));
    printf("Item deleted successfully!\n");
}

//saves the data on the list to a txt file - By Daniel
void saveToFile(const TodoList* list) {
    FILE* file = fopen("todolist.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < list->size; i++) {
        fprintf(file, "%d %s\n", list->items[i].id, list->items[i].task);
    }

    fclose(file);
}

//loads the data from the txt file - By Navneet
TodoList* loadFromFile() {
    FILE* file = fopen("todolist.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    TodoList* list = createTodoList();
    TodoItem item;

    while (fscanf(file, "%d %[^\n]", &item.id, item.task) == 2) {
        addItem(list, item.task);
    }

    fclose(file);
    return list;
}

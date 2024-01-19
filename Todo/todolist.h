//Group Project- Todo list
//Prog71985
//Author Names : Daniel Byamungu, Navneet Chatha, Armin Dhamrait
//Todolist ADTs

#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//#ifndef LIST_H
//#define LIST_H
#define MAXSIZE 100

typedef struct TodoItem {
    int id;
    char task[MAXSIZE];
} TodoItem;

typedef struct TodoList {
    TodoItem* items;
    int size;
} TodoList;

TodoList* createTodoList();
void destroyTodoList(TodoList* list);

void addItem(TodoList* list, const char* task);
void displayList(const TodoList* list);
int searchItem(const TodoList* list, const char* task);
void updateItem(TodoList* list, int index, const char* newTask);
void deleteItem(TodoList* list, int index);

void saveToFile(const TodoList* list);
TodoList* loadFromFile();

//#endif

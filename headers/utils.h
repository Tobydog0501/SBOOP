#define UTILS_H
#ifndef TODO_LIST_H
#include "todolist.h"
#endif
void addTask(todolist *list,string *name, string *category, bool *completed, unsigned int *importance, string *date, string *time, string *description, vector<string*> *tag);
void viewTasks(todolist *list,vector<Mode*> *mode);
void editTask(todolist *list,string *name,string *newname, string *category, bool *completed, unsigned int *importance, string *date, string *time, string *description, vector<string*> *tag);
void deleteTask(todolist *list,vector<Mode*> *mode);
time_t dateTimeToTimestamp(std::string* date, std::string* time);
bool timepassed(time_t *timestamp);
bool filter(task *t, Mode *mode);
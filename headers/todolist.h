#include "task.h"
#include "mode.h"
#define TODO_LIST_H

class todolist{
    private:
        string *filename = new string("./list.txt");
        vector<task*> *tasks;
    public:
        todolist(); // read file with existing filename
        ~todolist();
        // todolist(string *filename); // read file with filename
        bool addTask(task *task);
        void viewTasks(vector<Mode*> *mode);
        void editTask(task* tas,string *name, string *category, bool *completed, unsigned int *importance, string *date, string *time, string *description, vector<string*> *tag);
        void deleteTask(vector<Mode*> *mode);
        void save();
        task* getTask(string *name);
};
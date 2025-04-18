#include "../headers/all.h"

void addTask(todolist *list,string *name, string *category, bool *completed, unsigned int *importance, string *date, string *time, string *description, vector<string*> *tag){
    task *new_task = new task(name, category, completed, importance, date, time, description, tag);
    bool *result = new bool(list->addTask(new_task));
    if(*result){
        cout << "Task added successfully" << endl;
    }else{
        cout << "Task with name:" << name << " already exists" << endl;
    }
    delete result;
}

void viewTasks(todolist *list,vector<Mode*> *mode){
    list->viewTasks(mode);
}

void deleteTask(todolist *list,vector<Mode*> *mode){
    list->deleteTask(mode);
    // delete mode;
}

void editTask(todolist *list,string *name,string *newname, string *category, bool *completed, unsigned int *importance, string *date, string *time, string *description, vector<string*> *tag){
    task *tas = list->getTask(name);
    list->editTask(tas,newname,category,completed,importance,date,time,description,tag);
}

time_t dateTimeToTimestamp(string *date, string *time) {
    string *datetime = new string;
    if(*date == "NONE"){
        *datetime = NULLDATETIME;
        deprint("Datetime is NULL\n");
    }else if(*time == "NONE"){
        *datetime = *date + " " + "00:00";
        deprint("Time is NULL\n");
    }else{
        *datetime = *date + " " + *time; // "2025/01/03 05:10"
        deprint("Datetime is not NULL\n%s %s\n%p %p\n", date->c_str(), time->c_str(),date,time);
    }
    // cout << *datetime << "\n";
    static tm *tm = new struct tm;
    istringstream *ss = new istringstream(*datetime);
    *ss >> get_time(tm, "%Y/%m/%d %H:%M");
    
    if ((*ss).fail()) {
        throw runtime_error("Failed to parse datetime");
    }
    delete datetime;
    // Return as UTC
    delete ss;
    return mktime(tm)+(8 * 3600);
}

void timestampToDateTime(time_t timestamp, string *date, string *time) {
    tm* tm = gmtime(&timestamp);
    ostringstream *date_ss = new ostringstream;
    *date_ss << put_time(tm, "%Y/%m/%d");
    *date = (*date_ss).str();
    
    ostringstream *time_ss = new ostringstream;
    *time_ss << put_time(tm, "%H:%M");
    *time = (*time_ss).str();
    delete date_ss;
    delete time_ss;
}

bool timepassed(time_t timestamp){
    if(difftime(time(NULL),timestamp)<0){
        return 0;
    }
    return 1;
}

bool filter(task *t, Mode *mode){
    deprint("test %s\n",mode->mode->c_str());
    if(*mode->mode == "all"){
        return 1;
    }else if(*mode->mode == "name"){
        if(t->get_name() == *mode->identifier){
            return 1;
        }
    }else if(*mode->mode == "category"){
        if(t->get_category() == *mode->identifier){
            return 1;
        }
    }else if(*mode->mode == "completed"){
        if(t->get_completed() == *mode->completed){
            return 1;
        }
    }else if(*mode->mode == "tag"){
        if(t->get_tag() == *mode->identifier){
            return 1;
        }
    }else if(*mode->mode == "passed"){
        deprint("%d\n",*(mode->completed));
        if(timepassed(t->get_timestamp()) == *(mode->completed)){
            return 1;
        }
    }else if(*mode->mode == "complete"){
        if(t->get_completed() == *mode->completed){
            return 1;
        }
    }
    return 0;
}
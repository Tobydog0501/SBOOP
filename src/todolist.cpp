#include "../headers/all.h"
#include <fstream>

todolist::todolist(){
    this->tasks = new vector<task*>(0);
    ifstream *file = new ifstream(*this->filename);

    string *input = new string;
    while (getline (*file, *input)) {
        vector<string*> *v = new vector<string*>;
        stringstream *ss = new stringstream(*input);
        string *s = new string;
        while (getline(*ss, *s, '\\')) {
            deprint("%p %s\n",s, s->c_str());
            v->push_back(s);
            s = new string;
        }
        vector<string*> *tag = new vector<string*>(0);
        stringstream *ss2 = new stringstream(*(*v)[7]);
        while (getline(*ss2, *s, ',')) {
            tag->push_back(s);
        }
        bool *a = new bool(stoi((*(*v)[2]).c_str()));
        unsigned int *b = new unsigned int(static_cast<unsigned int>(stoi((*(*v)[3]).c_str())));
        deprint("%s %s\n",(*v)[4]->c_str(), (*v)[5]->c_str());
        task *new_task = new task((*v)[0], (*v)[1], a, b, (*v)[4], (*v)[5], (*v)[6], tag);
        this->addTask(new_task);
        delete v;
        delete ss,ss2;
        delete s;
    }
}

todolist::~todolist(){
    for(auto t : *this->tasks){
        delete t;
    }
    delete this->tasks;
    delete this->filename; // Also clean up filename
}

bool todolist::addTask(task *task){
    for(auto it = this->tasks->begin(); it != this->tasks->end(); it++){
        if((*it)->get_name() == task->get_name()){
            return 0;
        }
    }
    // printf("%p",tasks);
    this->tasks->push_back(task);
    return 1;
}

void todolist::viewTasks(vector<Mode*> *mode){
    vector<task*> *cp_tasks = new vector<task*>(0);
    copy(this->tasks->begin(), this->tasks->end(), back_inserter(*cp_tasks));
    cout << "================================== Tasks ==================================\n";
    bool *sorts = new bool(0);
    for(auto m:*mode){
        if(*m->mode=="importance"){
            deprint("Sorting by importance\n");
            *sorts = 1;
            continue;
        }
        for(vector<task*>::iterator t = cp_tasks->begin(); t != cp_tasks->end();){
            if(filter(*t,m)){
                t++;
            }else{
                cp_tasks->erase(t);
            }
        }
    }
    if(*sorts){
        vector<task*> *sorted_tasks = new vector<task*>(0);
        copy(cp_tasks->begin(), cp_tasks->end(), back_inserter(*sorted_tasks));
        sort(sorted_tasks->begin(), sorted_tasks->end(), [](task *a, task *b){
            // decenting order
            return a->get_importance() > b->get_importance();
        });
        for(auto t:*sorted_tasks){
            cout << "Name:" << t->get_name() << "\n";
            cout << "Category:" << t->get_category() << "\n";
            cout << "Completed:" << t->get_completed() << "\n";
            cout << "Importance:" << t->get_importance() << "\n";
            cout << "Date:" << t->get_date() << "\n";
            cout << "Time:" << t->get_time() << "\n";
            cout << "Description:" << t->get_description() << "\n";
            cout << "Tag:" << t->get_tag() << "\n";
            cout << "=========================================================================\n";
        }
        delete sorted_tasks;
    }else{
        for(auto t:*cp_tasks){
            cout << "Name:" << t->get_name() << "\n";
            cout << "Category:" << t->get_category() << "\n";
            cout << "Completed:" << t->get_completed() << "\n";
            cout << "Importance:" << t->get_importance() << "\n";
            cout << "Date:" << t->get_date() << "\n";
            cout << "Time:" << t->get_time() << "\n";
            cout << "Description:" << t->get_description() << "\n";
            cout << "Tag:" << t->get_tag() << "\n";
            cout << "=========================================================================\n";
        }
    }
}

void todolist::deleteTask(vector<Mode*> *mode){
    for(auto m:*mode){
        for(vector<task*>::iterator t = this->tasks->begin(); t != this->tasks->end();){
            if(filter(*t,m)){
                cout << "DELETE TASK:" << (*t)->get_name() << "\n";
                task *tp = *t;
                this->tasks->erase(t);
                delete tp;
                deprint("DELETED\n");
            }else{
                t++;
            }
            deprint("NOUT\n");
        }
        deprint("OUT\n");
    }
    deprint("ok\n");
    
}

void todolist::editTask(task* tas,string *name, string *category, bool *completed, unsigned int *importance, string *date, string *time, string *description, vector<string*> *tag){
    if(tas!=NULL){
        if(name!=NULL) tas->set_name(name);
        if(category!=NULL) tas->set_category(category);
        if(completed!=NULL) tas->set_completed(completed);
        if(importance!=NULL) tas->set_importance(importance);
        if(date!=NULL){
            if(time==NULL) time = new string("NONE");
            time_t *timestamp = new time_t(dateTimeToTimestamp(date,time));
            tas->set_timestamp(timestamp);
            delete time;
        }
        if(description!=NULL) tas->set_description(description);
        if(tag!=NULL) tas->set_tag(tag);
    }
}

task* todolist::getTask(string *name){
    for(auto t:*this->tasks){
        if(t->get_name() == *name){
            return t;
        }
    }
    return NULL;
}

void todolist::save(){
    ofstream file(*this->filename);
    for(auto t:*this->tasks){
        file << t->get_name() << "\\";
        file << t->get_category() << "\\";
        file << t->get_completed() << "\\";
        file << t->get_importance() << "\\";
        file << t->get_date() << "\\";
        file << t->get_time() << "\\";
        file << t->get_description() << "\\";
        file << t->get_tag() << "\\";
        file << "\n";
    }
    file.close();
}
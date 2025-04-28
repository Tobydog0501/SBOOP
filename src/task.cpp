#include "../headers/all.h"

Basic_task::Basic_task(string *name, string *category, bool *completed){
    this->name = new string(*name);
    this->category = new string(*category);
    this->completed = new bool(*completed);
}
Basic_task::~Basic_task(){
    deprint("Destructing basic task\n");
    delete this->name;
    delete this->category;
    delete this->completed;
}
string Basic_task::get_name(){
    return *this->name;
}
string Basic_task::get_category(){
    return *this->category;
}
bool Basic_task::get_completed(){
    return *this->completed;
}
unsigned int Basic_task::get_importance(){
    return 0;
}
time_t Basic_task::get_timestamp(){
    return 0;
}
string Basic_task::get_description(){
    return "";
}
string Basic_task::get_tag(){
    return "";
}
string Basic_task::get_date(){
    return "";
}
string Basic_task::get_time(){
    return "";
}
void Basic_task::set_name(string *name){
    this->name = new string(*name);
}
void Basic_task::set_category(string *category){
    this->category = new string(*category);
}
void Basic_task::set_completed(bool *completed){
    this->completed = new bool(*completed);
}
void Basic_task::set_importance(unsigned int *importance){
    return;
}
void Basic_task::set_timestamp(time_t *timestamp){
    return;
}
void Basic_task::set_description(string *description){
    return;
}
void Basic_task::set_tag(vector<string*> *tag){
    return ;
}



task::task(string *name, string *category, bool *completed, unsigned int *importance, string *date, string *time, string *description, vector<string*> *tag):Basic_task(name, category, completed){
    deprint("Constructing task\n%s %s\n",date->c_str(),time->c_str());
    this->importance = new unsigned int(*importance);
    this->timestamp = new time_t(dateTimeToTimestamp(date,time));
    this->description = new string(*description);
    this->tag = new vector<string*>;
    copy((*tag).begin(),(*tag).end(),back_inserter(*this->tag));
}

task::~task(){
    delete this->importance;
    delete this->timestamp;
    delete this->description;
    for(vector<string*>::iterator it = this->tag->begin(); it != this->tag->end(); it++){
        delete *it;
    }
    delete this->tag;
}


time_t task::get_timestamp(){
    return *this->timestamp;
}

string task::get_date(){
    tm* tm = gmtime(this->timestamp);
    ostringstream date_ss;
    date_ss << put_time(tm, "%Y/%m/%d");
    return date_ss.str();
}

string task::get_time(){
    tm* tm = gmtime(this->timestamp);
    ostringstream time_ss;
    time_ss << put_time(tm, "%H:%M");
    return time_ss.str();
}

string task::get_description(){
    return *this->description;
}

string task::get_tag(){
    static string *tags = new string;
    tags->clear();
    for(vector<string*>::iterator it = this->tag->begin(); it != this->tag->end(); it++){
        *tags += **it;
        if(it != (this->tag->end()-1)){
            *tags += ",";
        }
    }
    return *tags;
}

unsigned int task::get_importance(){
    return *this->importance;
}

void task::set_timestamp(time_t *timestamp){
    this->timestamp = new time_t(*timestamp);
}

void task::set_description(string *description){
    this->description = new string(*description);
}

void task::set_tag(vector<string*> *tag){
    vector<string*> *tags = new vector<string*>;
    // copy(tag.begin(),tag.end(),*tags);
    delete this->tag;
    this->tag = tags;
}


void task::set_importance(unsigned int *importance){
    this->importance = new unsigned int(*importance);
}


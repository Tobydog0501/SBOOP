#include "../headers/all.h"


processer::processer(){
    this->command = new string;
    this->database = new todolist();
    this->valid_modes = new vector<string*>;
    this->valid_modes->push_back(new string("all"));
    this->valid_modes->push_back(new string("completed"));
    this->valid_modes->push_back(new string("importance"));
    this->valid_modes->push_back(new string("date"));
    this->valid_modes->push_back(new string("category"));
    this->valid_modes->push_back(new string("name"));
    this->valid_modes->push_back(new string("tag"));
}

void processer::read_command(string *input){
    stringstream *ss = new stringstream(*input);
    string *s = new string;
    vector<string*> *v = new vector<string*>;
    while (getline(*ss, *s, ' ')) {
        transform((*s).begin(), (*s).end(), (*s).begin(),[](unsigned char c){ return tolower(c); });
        (*v).push_back(s);
    }

    if(*((*v)[0])=="help"||*((*v)[0])=="h"||*((*v)[0])=="?"){
        cout << "Help Mesage:" << "\n";
        cout << HELP_MESSAGE << "\n";
    }else if(*((*v)[0])=="view"){
        this->view_subprocess();
    }else if(*((*v)[0])=="add"){
        this->add_subprocess();
    }else if(*((*v)[0])=="edit"){
        this->edit_subprocess();
    }else if(*((*v)[0])=="delete"){
        this->delete_subprocess();
    }else if(*((*v)[0])=="exit"||*((*v)[0])=="save"){
        this->database->save();
    }
 
}

void processer::view_subprocess(){
    string *md = new string;
    // cout << "Viewing tasks" << "\n";
    vector<Mode*> *mode = new vector<Mode*>;
    bool *complete = new bool;
    string *identifier = new string;
    bool *loop = new bool(1);
    while(*loop){
        cout << "Enter mode(stop to stop):" << "\n";
        cin >> *md;
        // if(*loop){
        // }
        Mode *m;
        switch(check_valid_mode(md)){
            case INVALID:
                cout << "Invalid mode: " << *md << "\n";
                return;
            case NONE:
                m = new Mode(md);
                mode->push_back(m);
                break;
            case COMPLETED:
                cout << "Enter completed status:" << "\n";
                cin >> *complete;
                m = new Mode(md,complete);
                mode->push_back(m);
                break;
            case IDENTIFIER:
                cout << "Enter identifier:" << "\n";
                cin >> *identifier;
                m = new Mode(md,identifier);
                mode->push_back(m);
                break;
            case STOP:
                *loop = 0;
                break;
        }
        if(*md=="all"||*md=="name") break;
    }
    // for(auto m:*mode){
    //     cout << *m->mode << *m->identifier << "\n";
    // }
    viewTasks(this->database,mode);
    delete loop;
    delete identifier;
    delete complete;
    delete md;
    // viewTasks(this->database,);
}

ModeType processer::check_valid_mode(string *mode){
    static string *lmode = new string;
    *lmode = *mode;
    bool *check = new bool(0);
    transform((*lmode).begin(), (*lmode).end(), (*lmode).begin(),[](unsigned char c){ return tolower(c); });
    for (string *m : *this->valid_modes) {
        if(*m==*mode){
            *check = 1;
        }
    }
    if(*mode=="all"||*mode=="importance") return NONE;
    if(*mode=="completed") return COMPLETED;
    if(*mode=="stop") return STOP;
    if(!check) return INVALID;
    return IDENTIFIER;
}

void processer::add_subprocess(){
    string *name = new string;
    string *category = new string;
    bool *completed = new bool(0);
    unsigned int *importance = new unsigned int;
    string *date = new string;
    string *time = new string;
    string *description = new string;
    vector<string*> *tag = new vector<string*>;
    // bool *loop = new bool(1);
    cout << "Enter name:" << "\n";
    cin >> *name;
    cout << "Enter category:" << "\n";
    cin >> *category;
    cout << "Enter importance:" << "\n";
    cin >> *importance;
    cout << "Enter date(Format YYYY/MM/DD, or NONE): " << "\n";
    cin >> *date;
    cout << "Enter time(Format HH:MM, or NONE): " << "\n";
    cin >> *time;
    cout << "Enter description:" << "\n";
    cin >> *description;
    // *description;
    cout << "Enter tags(stop to stop):" << "\n";
    string *t = NULL;
    while(t==NULL ||*t!="stop"){
        t = new string;
        cin >> *t;
        if(*t=="stop") break;
        tag->push_back(t);
    }
    addTask(this->database,name,category,completed,importance,date,time,description,tag);
    delete description;
    delete time;
    delete date;
    delete importance;
    delete completed;
    delete category;
    delete name;
}

void processer::edit_subprocess(){
    string *name = new string;
    string *newname = NULL;
    string *category = NULL;
    bool *completed = NULL;
    unsigned int *importance = NULL;
    string *date = NULL;
    string *time = NULL;
    string *description = NULL;
    vector<string*> *tag = NULL;
    // bool *loop = new bool(1);
    string *type = new string;
    cout << "Enter task name:" << "\n";
    cin >> *name;
    cout << "Enter type: " << "\n";
    cin >> *type;
    if(*type=="name"){
        newname = new string;
        cout << "Enter new name:" << "\n";
        cin >> *newname;
    }else if(*type=="category"){
        category = new string;
        cout << "Enter new category:" << "\n";
        cin >> *category;
    }else if(*type=="completed"){
        completed = new bool;
        cout << "Enter new completed status:" << "\n";
        cin >> *completed;
    }else if(*type=="importance"){
        importance = new unsigned int;
        cout << "Enter new importance:" << "\n";
        cin >> *importance;
    }else if(*type=="date"){
        date = new string;
        cout << "Enter new date:" << "\n";
        cin >> *date;
        time = new string;
        cout << "Enter new time:" << "\n";
        cin >> *time;
    }else if(*type=="description"){
        description = new string;
        cout << "Enter new description:" << "\n";
        cin >> *description;
    }else if(*type=="tag"){
        tag = new vector<string*>;
        cout << "Enter new tags(stop to stop):" << "\n";
        string *t;
        while(*t!="stop"){
            t = new string;
            cin >> *t;
            tag->push_back(t);
        }
    }

    editTask(this->database,name,newname,category,completed,importance,date,time,description,tag);
    // delete loop;
    cout << "Task edited!" << "\n";
    delete description;
    delete time;
    delete date;
    delete importance;
    delete completed;
    delete category;
    delete newname;
    delete name;
    delete type;

}

void processer::delete_subprocess(){
    string *md = new string;
    // cout << "Viewing tasks" << "\n";
    vector<Mode*> *mode = new vector<Mode*>;
    bool *complete = new bool;
    string *identifier = new string;
    bool *loop = new bool(1);
    while(*loop){
        cout << "Enter mode(stop to stop):" << "\n";
        cin >> *md;
        // if(*loop){
        // }
        Mode *m;
        ModeType *type = new ModeType;
        *type = check_valid_mode(md);
        switch(*type){
            case INVALID:
                cout << "Invalid mode: " << *md << "\n";
                return;
            case NONE:
                m = new Mode(md);
                mode->push_back(m);
                break;
            case COMPLETED:
                cout << "Enter completed status:" << "\n";
                cin >> *complete;
                m = new Mode(md,complete);
                mode->push_back(m);
                break;
            case IDENTIFIER:
                cout << "Enter identifier:" << "\n";
                cin >> *identifier;
                m = new Mode(md,identifier);
                mode->push_back(m);
                break;
            case STOP:
                *loop = 0;
                break;
        }
        delete type;
        if(*md=="all"||*md=="name") break;
    }
    // cout << *(mode->at(0)->mode) << " " << *(mode->at(0)->identifier) << "\n";
    deleteTask(this->database,mode);
    delete loop;
    delete identifier;
    delete complete;
    delete md;
    // viewTasks(this->database,);
}
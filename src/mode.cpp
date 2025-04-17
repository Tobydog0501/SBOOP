#include "../headers/all.h"


Mode::Mode(string *mode){
    this->mode = new string(*mode);
}

Mode::Mode(string *mode, string *identifier){
    this->mode = new string(*mode);
    this->identifier = new string(*identifier);
}

Mode::Mode(string *mode, bool *completed){
    this->mode = new string(*mode);
    this->completed = new bool(*completed);
}

Mode::Mode(){
    this->mode = new string("all");
    this->identifier = new string("");
}

Mode::~Mode(){
    delete mode;
    delete identifier;
    delete completed;
}
#include "./headers/all.h"
using namespace std;

int main(){
    processer *p = new processer();
    string *inp = new string();
    while(1){
        cout << "Enter command:" << "\n";
        cin >> *inp;
        if(*inp=="exit") break;
        p->read_command(inp);
    }
    string *exit = new string("exit");
    p->read_command(exit);
    delete p;
    delete inp;
    return 0;
}

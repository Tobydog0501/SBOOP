#define MODE_H
#include <string>
using namespace std;

class Mode{
    public:
        string *mode;
        string *identifier;
        bool *completed;
    public:
        Mode(string* mode);
        Mode(string* mode, bool *completed);
        Mode(string* mode, string *identifier);
        Mode();
        ~Mode();
};

typedef enum mode_type{
    IDENTIFIER,
    COMPLETED,
    NONE,
    INVALID,
    STOP
} ModeType;
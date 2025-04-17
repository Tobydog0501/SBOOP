

class processer{
    private:
        string *command;
        todolist *database;
        vector<string*> *valid_modes;
    public:
        processer();
        void print();
        void set_command(string *command);
        void read_command(string *input);
        void view_subprocess();
        void add_subprocess();
        void edit_subprocess();
        void delete_subprocess();
        ModeType check_valid_mode(string *mode);
};

#define HELP_MESSAGE "Commands: view, add, edit, delete, save, help, exit\nModes: all, completed, importance, date, category, name, tag\n"

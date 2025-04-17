#include "common.h"
#define TASK_H

class Basic_task{
    protected:
        string *name;
        string *category;
        bool *completed;
    public:
        Basic_task(string *name, string *category, bool *completed);
        virtual string get_name();
        virtual string get_category();
        virtual bool get_completed();
        virtual unsigned int get_importance();
        virtual time_t get_timestamp();
        virtual string get_description();
        virtual string get_tag();
        virtual string get_date();
        virtual string get_time();
        virtual void set_name(string *name);
        virtual void set_category(string *category);
        virtual void set_completed(bool *completed);
        virtual void set_importance(unsigned int *importance);
        virtual void set_timestamp(time_t *timestamp);
        virtual void set_description(string *description);
        virtual void set_tag(vector<string*> *tag);
        ~Basic_task();
};

class task:public Basic_task{
    private:
        unsigned int *importance;
        time_t *timestamp;
        string *description;
        vector<string*> *tag;
    public:
        task(string *name, string *category, bool *completed, unsigned int *importance, string *date, string *time, string *description, vector<string*> *tag);
        unsigned int get_importance() override;
        time_t get_timestamp() override;
        string get_description() override;
        string get_tag() override;
        string get_date() override;
        string get_time() override;
        void set_importance(unsigned int *importance) override;
        void set_timestamp(time_t *timestamp) override;
        void set_description(string *description) override;
        void set_tag(vector<string*> *tag) override;
        ~task();
};
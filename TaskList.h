
#ifndef CHECKLIST_TASKLIST_H
#define CHECKLIST_TASKLIST_H

#include "Task.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sys/stat.h>

using namespace std;
class TaskList {
private:
    string Title;
vector<Task> collection;
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &a, const unsigned version){
        a & Title;
        a & collection;
    }
public:
    TaskList(const string &title, const vector<Task> &collection) : Title(title), collection(collection){}

    const string &getTitle() const;

    void setTitle(const string &title);

    void AddTask(Task );
    void DelTask (int i );
    Task getTask (int i);
    void modTask(int i, const string& Title, const string& descr );
    void Print() const;
    void save() const;
    void load();
};


#endif //CHECKLIST_TASKLIST_H

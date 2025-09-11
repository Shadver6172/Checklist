#ifndef CHECKLIST_TASKCOLLECTION_H
#define CHECKLIST_TASKCOLLECTION_H
#include <iostream>
#include <vector>
#include <fstream>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include "TaskList.cpp"
using namespace std;

class TaskCollection {
private:
    string Title;
    vector<TaskList> collection;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &a, const unsigned version) {
        a & Title;
        a & collection;
    }

public:
    explicit TaskCollection(const string &title) : Title(title) {
    }

    TaskCollection() {
    };


    const string &getTitle() const;

    void setTitle(const string &title);

    void AddTaskList(TaskList i);

    void DelTaskList(int i);

    TaskList &getTaskList(int i);

    void save() const;

    void load();

    const vector<TaskList> &getCollection() const;

    void setCollection(const vector<TaskList> &collection);
};

#endif

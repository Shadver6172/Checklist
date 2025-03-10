
#include <iostream>
#include <vector>
#include <fstream>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "TaskList.h"


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
    TaskCollection(const string &title, const vector<TaskList> &collection) : Title(title), collection(collection) {}

    TaskCollection();

    const string &getTitle() const;

    void setTitle(const string &title);

    void AddTaskList(TaskList i);

    void DelTaskList(int i);

    TaskList getTaskList(int i);

    void save() const;

    void load();

    const vector<TaskList> &getCollection() const;

    void setCollection(const vector<TaskList> &collection);
};


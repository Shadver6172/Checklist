//
// Created by marco on 20/10/2022.
//

#ifndef CHECKLIST_TASKS_H
#define CHECKLIST_TASKS_H

#include "ListItem.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;
class Tasks {
private:
vector<ListItem> collection;
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &a, const unsigned version){
        a & collection;
    }
public:
    Tasks(){}
    const vector<ListItem> &getCollection() const {
        return collection;
    }

    void setCollection(const vector<ListItem> &collection) {
        Tasks::collection = collection;
    }
    void AddTask( ListItem );
    void DelTask (const int i );
    void modTask( const int i, const string& Title, const string& descr );
    void Print() const;
    void save() const;
    void load();
};


#endif //CHECKLIST_TASKS_H

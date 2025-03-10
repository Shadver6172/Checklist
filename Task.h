//
// Created by marco on 31/07/2022.
//

#ifndef CHECKLIST_TASK_H
#define CHECKLIST_TASK_H

#include <utility>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "string"
#include <iostream>
#include "ctime"

class Task {
private:
    std::string Title;
    std::string Description;
    std::string Date;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &a, const unsigned version) {
        a & Title;
        a & Description;
        a & Date;
    }

public:
    Task() {}

    Task(std::string title, std::string description, std::string Date) : Title(title), Description(description),
                                                                         Date(Date) {}

    std::string getTitle() const {
        return Title;
    }

    void setTitle(const std::string &title) {
        Title = title;
    }

    const std::string &getDescription() const {
        return Description;
    }

    void setDescription(const std::string &description) {
        Description = description;
    }

    const std::string &getDate() const {
        return Date;
    }

    void setDate(const std::string &date) {
        Date = date;
    }

};


#endif //CHECKLIST_TASK_H

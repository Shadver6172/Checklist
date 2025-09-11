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
    struct tm Date;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &a, const unsigned version) {
        a & Title;
        a & Description;
        a & Date.tm_mday;
        a & Date.tm_mon;
        a & Date.tm_year;
    }

public:
    Task() {
    }

    Task(std::string title, std::string description,  struct tm Date) : Title(title), Description(description),
                                                                         Date(Date) {
    }

    const std::string &getTitle() const {
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

    const  struct tm &getDate() const {
        return Date;
    }

    void setDate(const  struct tm &date) {
        Date = date;
    }
};


#endif //CHECKLIST_TASK_H

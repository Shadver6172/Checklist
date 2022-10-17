//
// Created by marco on 31/07/2022.
//

#ifndef CHECKLIST_LISTITEM_H
#define CHECKLIST_LISTITEM_H
#include <utility>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "string"
#include <iostream>
class ListItem {
private:
    std::string Title;
    std::string Description;
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &a, const unsigned version){
        a & Title & Description;
    }
public:
    ListItem(){}

    ListItem(const std::string &title, const std::string &description) : Title(title), Description(description) {}

    const std::string getTitle() const {
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
};


#endif //CHECKLIST_LISTITEM_H

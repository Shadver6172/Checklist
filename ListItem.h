//
// Created by marco on 31/07/2022.
//

#ifndef CHECKLIST_LISTITEM_H
#define CHECKLIST_LISTITEM_H
#include <utility>

#include "string"
#include <iostream>
class ListItem {
private:
    std::string Title;

public:
    ListItem(const std::string &title) : Title(title) {}

    const std::string getTitle() const {
        return Title;
    }

    void setTitle(const std::string &title) {
        Title = title;
    }





};


#endif //CHECKLIST_LISTITEM_H

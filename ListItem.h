//
// Created by marco on 31/07/2022.
//

#ifndef CHECKLIST_LISTITEM_H
#define CHECKLIST_LISTITEM_H
#include <utility>

#include "string"
#include "datetimeapi.h"

class ListItem {
private:
    std::string Title;
    bool status;
    int id;
public:
    ListItem(std::string title, bool status, int id=-1) : Title(std::move(title)), status(FALSE) {}

    
};


#endif //CHECKLIST_LISTITEM_H

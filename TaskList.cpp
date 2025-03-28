
#include "TaskList.h"

void TaskList::Print() const {
    int i = 0;
    for (auto it = collection.begin(); it != collection.end(); ++it)
        std::cout << i++ << " || Title: " << it->getTitle() << " || " << "Description: " << it->getDescription()
                  << "\n";
}


Task TaskList::getTask(const int i) {
    return collection[i];
}

void TaskList::AddTask(Task Task) {
    collection.push_back(Task);

}

void TaskList::DelTask(const int i) {
    collection.erase(collection.begin() + i);
}

void TaskList::modTask(const int i, const string &Title, const string &Descr) {
    collection[i].setTitle(Title);
    collection[i].setDescription(Descr);

}

void TaskList::save() const {
    std::ofstream outfile("TaskList.dat");
    boost::archive::text_oarchive archive(outfile);
    archive << collection;

}


vector<Task> TaskList::get_collection()  {
    return collection;
}

void TaskList::set_collection(const vector<Task> &collection) {
    this->collection = collection;
}

void TaskList::load() {
    const char *file = "TaskList.dat";

    struct stat sb;

    if (stat(file, &sb) == 0 && !(sb.st_mode & S_IFDIR)) {
        std::ifstream ifs("TaskList.dat");
        boost::archive::text_iarchive ar(ifs);
        ar & collection;
    }
}

const string &TaskList::getTitle() const {
    return Title;
}

void TaskList::setTitle(const string &title) {
    Title = title;
}




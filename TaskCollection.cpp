#include "TaskCollection.h"

const vector<TaskList> &TaskCollection::getCollection() const {
    return collection;
}

void TaskCollection::setCollection(const vector<TaskList> &collection) {
    TaskCollection::collection = collection;
}

const string &TaskCollection::getTitle() const {
    return Title;
}

void TaskCollection::setTitle(const std::string &title) {
    Title = title;
}

void TaskCollection::AddTaskList(TaskList i) {

    collection.push_back(i);
}

void TaskCollection::DelTaskList(int i) {
    collection.erase(collection.begin() + i);
}

TaskList TaskCollection::getTaskList(int i) {
    return collection[i];
}

void TaskCollection::save() const {
    std::ofstream outfile("TaskList.dat");
    boost::archive::text_oarchive archive(outfile);
    archive << Title;
    archive << collection;

}

void TaskCollection::load() {
    const char *file = "cmake-build-release-mingw/TaskList.dat";

    struct stat sb;

    if (stat(file, &sb) == 0 && !(sb.st_mode & S_IFDIR)) {
        std::ifstream ifs("TaskList.dat");
        boost::archive::text_iarchive ar(ifs);
        ar & Title;
        ar & collection;
    }
}
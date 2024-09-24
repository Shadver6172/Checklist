
#include "Tasks.h"
void Tasks::Print() const
{
    int i=0;
    for (auto it = collection.begin() ; it != collection.end(); ++it)
    std::cout <<i++<< " || Title: " << it->getTitle()<<" || " << "Description: " <<it->getDescription()<<"\n";
}
ListItem Tasks::getTask(const int i) {
    return collection[i];
}
void Tasks::AddTask(  ListItem Task )
{
    collection.push_back( Task );

}
void Tasks::DelTask( const int i )
{
    collection.erase(collection.begin()+i);
}
void Tasks::modTask( const int i, const string& Title, const string& Descr )
{
    collection[i].setTitle(Title);
    collection[i].setDescription(Descr);

}
void Tasks::save() const {
    std::ofstream outfile("Tasks.dat");
    boost::archive::text_oarchive archive(outfile);
    archive << collection;
    
}
void Tasks::load() {
    const char* file = "cmake-build-release-mingw/Tasks.dat";

    struct stat sb;

    if (stat(file, &sb) == 0 && !(sb.st_mode & S_IFDIR)) {
        std::ifstream ifs("Tasks.dat");
        boost::archive::text_iarchive ar(ifs);
        ar & collection;
    }
}
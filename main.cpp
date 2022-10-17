#include <iostream>
#include <fstream>
#include "Version.h"
#include "ListItem.cpp"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
using namespace std;
void Save_New_Task(ListItem t);
int main() {
    cout << VERSION << std::endl;
    ListItem tmp("pulire casa","pulisci");
    Save_New_Task(tmp);
    return 0;
}
void Save_New_Task(ListItem t){

    std::ofstream outfile("Tasks.txt");
    boost::archive::text_oarchive archive(outfile);
    archive << t;
}
#include <iostream>
#include <fstream>
#include "Version.h"
#include "ListItem.cpp"

using namespace std;
void Save_New_Task(ListItem t);
int main() {
    std::cout << VERSION << std::endl;
    ListItem tmp("pulire casa");
    Save_New_Task(tmp);
    return 0;
}
void Save_New_Task(ListItem t){

    ofstream off("Tasks.txt", ios::app);

    if( !off ) {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    off << t.getTitle() << '\n' ;
}
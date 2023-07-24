#include <iostream>
#include <fstream>
#include "Version.h"
#include "ListItem.cpp"
#include "Tasks.cpp"
#include <vector>

using namespace std;

int main() {
    cout << VERSION << std::endl;
    Tasks *col=new Tasks();
    col->load();
    ListItem *tmp=new ListItem("Cane","Porta fuori il cane");
    vector<ListItem> v=col->getCollection();
    col->AddTask(*tmp);
    col->Print();
    col->DelTask(0);
    col->Print();
    return 0;
}
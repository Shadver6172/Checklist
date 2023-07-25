#include <iostream>
#include <fstream>
#include "Version.h"
#include "ListItem.cpp"
#include "Tasks.cpp"
#include <vector>

using namespace std;

int main() {
    cout << VERSION << std::endl;
    int ON=1,x;
    string t,d;
    Tasks *col=new Tasks();
    col->load();
    ListItem *tmp;
    while(ON) {
        cout<< "Seleziona un operazione :\n 1 | Aggiungi nuova task \n 2 | Modifica task \n 3 | Elimina Task \n 4 | Mostra task \n 5 | Chiudi programma\n";
        cin>>x;
        switch (x) {
            case 1:
                cout<< "Inserisci Titolo\n";
                cin>>t;
                cout<< "Inserisci Descrizione\n";
                cin>>d;
                tmp=new ListItem(t,d);
                col->AddTask(*tmp);
                break;
            case 2:
                cout<< "Seleziona Task da modificare\n";
                cin>>x;
                cout<< "Inserisci Titolo\n";
                cin>>t;
                cout<< "Inserisci Descrizione\n";
                cin>>d;
                col->modTask(x,t,d);
                break;
            case 3:
                cout<< "Seleziona Task da Eliminare \n";
                cin>>x;
                col->DelTask(x);
                break;
            case 4:
                col->Print();
                break;
            case 5:
             col->save();
             ON=0;
                break;
        }
    }
    return 0;
}
#include <ncurses.h>

#include "TaskCollection.cpp"

void Display(const TaskCollection &temp);

std::string getstring();

void Modify_win(TaskCollection temp);

void ModifyTl_win(TaskCollection temp);

void Add_win(TaskCollection temp);

void Create_win(TaskCollection temp);

void DeleteTl_win(TaskCollection temp);

void Delete_win(TaskCollection temp);

void reset_input_mode();

void startwindow();

struct tm Date_input();
void startwindow() {
    TaskCollection temp;
    flushinp();
    ifstream menuFile;
    menuFile.open("MenuOptions.txt");
    if (!menuFile) {
        cout << "Impossibile aprire MenuOptions.txt" << endl;
        exit(1);
    }


    int count = 0;
    int maxOptionLength = 0;
    string menuOption;
    while (getline(menuFile, menuOption)) {
        count++;
        if (menuOption.length() > maxOptionLength)
            maxOptionLength = menuOption.length();
    }


    menuFile.clear();
    menuFile.seekg(0, ios::beg);


    string *menuOptions = new string[count];
    for (int i = 0; i < count; i++) {
        getline(menuFile, menuOption);
        menuOptions[i] = menuOption;
    }


    initscr();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    move(10,30);

    int input = 0;
    int selected = 1;

    while (input != KEY_F(1)) {
        temp.load();

        clear();

        mvprintw(1, 12, "Menu Principale");
        for (int i = 0; i < count; i++) {
            mvprintw(i + 2, 15, "%s", menuOptions[i].c_str());
        }
        if (selected > 0 && selected < (count + 1))
            mvchgat(selected+1, 15, maxOptionLength, A_STANDOUT, 1, NULL);


        refresh();


        flushinp();
        int ch;
        nodelay(stdscr, TRUE);
        while ((ch = getch()) != ERR) {
        }
        nodelay(stdscr, FALSE);
        reset_input_mode();
        input = getch();


        if (input == KEY_DOWN && selected < (count)) selected++;
        if (input == KEY_UP && selected > 1) selected--;

        if (input == 10) {
            clear();
            input = 0;
            if (selected - 1 == 0) {
                Display(temp);
                getch();
            } else if (selected - 1 == 1) {
                Modify_win(temp);
            } else if (selected - 1 == 2) {
                ModifyTl_win(temp);
            } else if (selected - 1 == 3) {
                Add_win(temp);
            } else if (selected - 1 == 4) {
                Create_win(temp);
            } else if (selected - 1 == 5) {
                Delete_win(temp);
            } else if (selected - 1 == 6) {
                DeleteTl_win(temp);
            }
        }
    }

    endwin();
    delete [] menuOptions;
}

void Display(const TaskCollection &temp) {
    int x = 2;
    for (auto i: temp.getCollection()) {
        int y = 3;
        mvprintw(y - 1, x + 5, "%s", i.getTitle().c_str());
        for (auto j: i.get_collection()) {
            mvprintw(y++, x, "Titolo:  %s", j.getTitle().c_str());
            mvprintw(y++, x, "Descrizione:  %s", j.getDescription().c_str());
            mvprintw(y++, x, "Scadenza:  %d/%d/%d", j.getDate().tm_mday,j.getDate().tm_mon ,j.getDate().tm_year+1900);
            mvprintw(y++, x, "                        ");
        }
        x += 30;
    }

    refresh();

}


std::string getstring() {
    std::string input;
    move((getmaxy(stdscr) / 2)+1, (getmaxx(stdscr) / 2+1));
    nocbreak();
    int ch;
    while (ch != '\n') {
        input.push_back(ch);
        ch = getch();
        move((getmaxy(stdscr) / 2)+1, (getmaxx(stdscr) / 2+1));
        refresh();

    }
    return input;
}

void Modify_win(TaskCollection temp) {
    ciclo2:
    int i;
    int input;
    int input2 = 0;
    int input3 = 0;
    std::string input4;
    int x = 10;
    mvprintw(0, getmaxx(stdscr) / 2, "Quale lista vuoi modificare?");
    Display(temp);
    for (i = 0; i < temp.getCollection().size(); i++) {
        mvprintw(1, x, "%d", i);
        x += 30;
    }
    refresh();

    try{input2 = stoi(getstring());}
    catch (std::invalid_argument const& ex) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "valore non valido | non è un numero ");
        refresh();
        getch();
        clear();
        goto ciclo2;

    }
    if (input2<0 || input2>=temp.getCollection().size()) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Valore non valido | Lista inesistente ");
        refresh();
        getch();
        clear();
        goto ciclo2;
    }

    ciclo1:
    clear();
    mvprintw(0, getmaxy(stdscr) / 2, "%s", temp.getTaskList(input2).getTitle().c_str());
    mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Quale attività vuoi modificare?");
    x = 2;
    i = 0;


    for (const auto &j: temp.getTaskList(input2).get_collection()) {
        int y = 3;
        mvprintw(y, x + 5, "%d", i++);
        mvprintw(++y, x, "Titolo:  %s", j.getTitle().c_str());
        mvprintw(++y, x, "Descrizione:  %s", j.getDescription().c_str());
        mvprintw(++y, x, "                        ");
        x += 30;
    }
    refresh();

    try{input3 = stoi(getstring());}
    catch (std::invalid_argument const& ex) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "valore non valido | non è un numero ");
        refresh();
        getch();
        clear();
        goto ciclo1;

    }
    if (input3<0 || input3>=temp.getTaskList(input2).get_collection().size()) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Valore non valido | Attività inesistente ");
        refresh();
        getch();
        clear();
        goto ciclo1;
    }
    ciclo:
    clear();
    x = 2;
    int y = 3;
    mvprintw(++y, x, "Titolo: %s", temp.getTaskList(input2).getTask(input3).getTitle().c_str());
    mvprintw(++y, x, "Descrizione:  %s",
             temp.getTaskList(input2).getTask(input3).getDescription().c_str());
    mvprintw(++y, x, "                        ");
    mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2,"Cosa vuoi modificare?\n 0: Titolo | 1: Descrizione | 2: Data ");

    try{input = stoi(getstring());}
    catch (std::invalid_argument const& ex) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "valore non valido | non è un numero ");
        refresh();
        getch();
        clear();
        goto ciclo;

    }
    if (input<0 || input>2) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Valore non valido");
        refresh();
        getch();
        clear();
        goto ciclo;
    }


    switch (input) {
        case 0:
            clear();
            mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Inserisci il nuovo titolo");
            refresh();
            input4 = getstring();
            temp.getTaskList(input2).getTask(input3).setTitle(input4);
            temp.save();
            clear();
            mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Titolo modificato");
            getch();
            break;

        case 1:
            clear();
            mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Inserisci la nuova descrizione");
            refresh();
            input4 = getch();
            temp.getTaskList(input2).getTask(input3).setDescription(input4);
            temp.save();
            clear();
            mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Descrizione modificata");
            getch();
            break;

        case 2:
            struct tm data=Date_input();
            clear();
            temp.getTaskList(input2).getTask(input3).setDate(data);
            mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Data modificata");
            temp.save();
            getch();
            break;


    }
}

void ModifyTl_win(TaskCollection temp) {
    ciclo:
    int i;
    int c;
    int input = 0;
    std::string input2;
    clear();
    int x = 2;
    int y = 3;
    mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Cosa vuoi modificare?\n 0: Collezione | 1:  Lista");

    try{ c=stoi(getstring());}
    catch (std::invalid_argument const& ex) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "valore non valido | non è un numero ");
        refresh();
        getch();
        clear();
        goto ciclo;

    }
    if (c<0 || c>1) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Valore non valido");
        refresh();
        getch();
        clear();
        goto ciclo;
    }
    switch (c) {
        case 0:
            clear();
            mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Inserisci il nuovo titolo");
            refresh();
            input2 = getstring();
            temp.setTitle(input2);
            temp.save();
            clear();
            mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Titolo modificato");
            getch();
            break;

        case 1:
            ciclo1:
            clear();
            x = 10;
            mvprintw(0, getmaxx(stdscr) / 2, "Quale lista vuoi modificare?");
            Display(temp);
            for (i = 0; i < temp.getCollection().size(); i++) {
                mvprintw(1, x, "%d", i);
                x += 30;
            }
            try{input = stoi(getstring());}
            catch (std::invalid_argument const& ex) {
                clear();
                mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "valore non valido | non è un numero ");
                refresh();
                getch();
                clear();
                goto ciclo1;

            }
            if (input<0 || input>=temp.getCollection().size()) {
                clear();
                mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Valore non valido | Lista inesistente ");
                refresh();
                getch();
                clear();
                goto ciclo1;
            }
            clear();
            mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Inserisci il nuovo titolo");
            refresh();

            input2 = getstring();
            temp.getTaskList(input).setTitle(input2);
            temp.save();
            clear();
            mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Lista modificata");
            getch();
            break;



    }
}

void Add_win(TaskCollection temp) {
    ciclo:
    int input = 0;
    std::string input2;
    std::string input3;
    clear();
    int x = 10;
    mvprintw(0, getmaxx(stdscr) / 2, "A Quale lista vuoi Aggiungere un'attività?");
    Display(temp);
    for (int i = 0; i < temp.getCollection().size(); i++) {
        mvprintw(1, x, "%d", i);
        x += 30;
    }
    try{input = stoi(getstring());}
    catch (std::invalid_argument const& ex) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "valore non valido | non è un numero ");
        refresh();
        getch();
        clear();
        goto ciclo;

    }
    if (input<0 || input>=temp.getCollection().size()) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Valore non valido | attività inesistente ");
        refresh();
        getch();
        clear();
        goto ciclo;
    }
    clear();
    mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Inserisci il titolo");
    refresh();
    input2 = getstring();
    mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Inserisci la descrizione");
    refresh();
    input3 = getstring();
    Task *task = new Task(input2, input3, Date_input());
    temp.getTaskList(input).AddTask(*task);
    temp.save();
    free(task);
    clear();
    mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Attività aggiunta");
    getch();
}

void Create_win(TaskCollection temp) {
    std::string input;
    clear();
    int x = 10;
    mvprintw(0, getmaxx(stdscr) / 2, "Scegli il nome della nuova lista");
    input = getstring();
    clear();
    TaskList *tasks = new TaskList(input);
    temp.AddTaskList(*tasks);
    temp.save();
    clear();
    free(tasks);
    mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Attività aggiunta");
    getch();
}

void Delete_win(TaskCollection temp) {
    ciclo:
    int i;
    int input = 0;
    int input2 = 0;
    int x = 10;
    mvprintw(0, getmaxx(stdscr) / 2, "Quale lista vuoi modificare?");
    Display(temp);
    for (i = 0; i < temp.getCollection().size(); i++) {
        mvprintw(1, x, "%d", i);
        x += 30;
    }
    refresh();
    try{input = stoi(getstring());}
    catch (std::invalid_argument const& ex) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "valore non valido | non è un numero ");
        refresh();
        getch();
        clear();
        goto ciclo;

    }
    if (input<0 || input>=temp.getCollection().size()) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Valore non valido | lista inesistente ");
        refresh();
        getch();
        clear();
        goto ciclo;
    }
    ciclo2:
    clear();
    mvprintw(0, getmaxy(stdscr) / 2, "%s", temp.getTaskList(input).getTitle().c_str());
    mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Quale task vuoi eliminare?");
    x = 2;
    i = 0;
    for (const auto &j: temp.getTaskList(input).get_collection()) {
        int y = 3;
        mvprintw(y, x + 5, "%d", i++);
        mvprintw(++y, x, "Titolo:  %s", j.getTitle().c_str());
        mvprintw(++y, x, "Descrizione:  %s", j.getDescription().c_str());
        mvprintw(++y, x, "                        ");
        x += 30;
    }
    refresh();
    try{input2 = stoi(getstring());}
    catch (std::invalid_argument const& ex) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "valore non valido | non è un numero ");
        refresh();
        getch();
        clear();
        goto ciclo2;

    }
    if (input2<0 || input2>=temp.getTaskList(input).get_collection().size()) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Valore non valido | attività inesistente ");
        refresh();
        getch();
        clear();
        goto ciclo2;
    }
    temp.getTaskList(input).DelTask(input2);
    clear();
    mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Attività eliminata");
    temp.save();
    getch();
}

void DeleteTl_win(TaskCollection temp) {
    ciclo:
    int i;
    int input = 0;
    std::string input4;
    int x = 10;
    clear();
    mvprintw(0, getmaxx(stdscr) / 2, "Quale lista vuoi eliminare?");
    Display(temp);
    for (i = 0; i < temp.getCollection().size(); i++) {
        mvprintw(1, x, "%d", i);
        x += 30;
    }
    refresh();
    try{input = stoi(getstring());}
    catch (std::invalid_argument const& ex) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "valore non valido | non è un numero ");
        refresh();
        getch();
        clear();
        goto ciclo;

    }
    if (input<0 || input>=temp.getCollection().size()) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Valore non valido | Lista inesistente ");
        refresh();
        getch();
        clear();
        goto ciclo;
    }


    temp.DelTaskList(input);
    mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Lista eliminata");
    temp.save();
    refresh();
    getch();
}

void reset_input_mode() {
    keypad(stdscr, TRUE);
    cbreak();
}
struct tm Date_input() {
   ciclo:
    clear();
    mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Inserisci data in formato dd/mm/yy");
    refresh();
    struct tm date;
    std::string input=getstring();
    if (!strptime(input.c_str(), "%d/%m/%Y", &date)) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2, "Data non valida ");
        refresh();
        getch();

        goto ciclo;
    }
    return date;
}


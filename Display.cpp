#include <ncurses.h>

#include "TaskCollection.cpp"

WINDOW *display_win(int height, int width, int starty, int startx);

void destroy_win(WINDOW *local_win);

void startwindow() {



    initscr();
    cbreak();
    noecho();
    refresh();
    WINDOW *win = newwin(100, 100, 1, 0);
    keypad(win, true);
    box(win, 0, 0);
    wrefresh(win);


    while (1) {
        int c = wgetch(win);
        switch (c) {
            case KEY_UP: destroy_win(win);

                win=display_win(getmaxy(win), getmaxx(win), 0, 0);

                break;


            case KEY_DOWN: mvwprintw(stdscr, 40, 30, "down");
                break;

            case KEY_RIGHT: mvwprintw(stdscr, 30, 3, "right");
                break;

            case KEY_LEFT: mvwprintw(stdscr, 3, 40, "left");
                break;
        }
        wrefresh(win);
        refresh();

        if (c == 10) {
            delwin(win);
            endwin();
            break;
        }
    }
}

WINDOW *display_win(int height, int width, int starty, int startx) {
    WINDOW *local_win;
    TaskCollection temp;

    int x=2;
    temp.load();
    local_win = newwin(height, width, starty, startx);
    box(local_win, 0, 0);
    mvwprintw(local_win, 0, getmaxy(local_win) / 2, "%s",temp.getTitle().c_str());
    for (auto i:temp.getCollection() ) {
        int y=3;

        for (auto j: i.get_collection()) {

            mvwprintw(local_win, y++, x, "Titolo:  %s" , j.getTitle().c_str());
            mvwprintw(local_win, y++, x, "Descrizione:  %s" , j.getDescription().c_str());
        }
        x+=30;
    }

    wrefresh(local_win);

    return local_win;
}

void destroy_win(WINDOW *local_win) {
    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(local_win);
    delwin(local_win);
}

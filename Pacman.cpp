#include "PacMan.h"
#include <conio.h>

PacMan::PacMan(int pocx, int pocy) : Character(pocx, pocy, 'C') {}

void PacMan::moving(int sirina, int visina, const std::vector<std::vector<char>>& mapa) {
    char input = _getch();
    int x_novi = x;
    int y_novi = y;

    if (input == 'W' || input == 'w') {
        y_novi--;
    }
    else if (input == 'S' || input == 's') {
        y_novi++;
    }
    else if (input == 'A' || input == 'a') {
        x_novi--;
    }
    else if (input == 'D' || input == 'd') {
        x_novi++;
    }

    if (x_novi >= 0 && x_novi < sirina && y_novi >= 0 && y_novi < visina && mapa[y_novi][x_novi] != '#') {
        x = x_novi;
        y = y_novi;
    }
}

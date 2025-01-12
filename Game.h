#pragma once
#ifndef GAME_H
#define GAME_H

#include "PacMan.h"
#include "Enemy.h"
#include <vector>

class Game {
private:
    PacMan pacman;
    std::vector<Enemy> duhovi;
    int score;
    int preostale_tocke;
    std::vector<std::vector<char>> mapa;
    std::vector<std::vector<char>> mapa_pozadina;

    void kreiraj_mapu();
    void mapa_update();
    void display();
    void provjeri();

public:
    Game(int sirina, int visina, int br_enemy);
    void run();
};

#endif // GAME_H

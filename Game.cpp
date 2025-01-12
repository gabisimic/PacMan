#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <algorithm>
#include <conio.h>

using namespace std;

void Game::kreiraj_mapu() {
    for (int i = 0; i < mapa.size(); i++) {
        for (int j = 0; j < mapa[i].size(); j++) {
            if (i == 0 || i == mapa.size() - 1 || j == 0 || j == mapa[i].size() - 1) {
                mapa[i][j] = '#';
                mapa_pozadina[i][j] = '#';
            }
            else {
                mapa[i][j] = '.';
                mapa_pozadina[i][j] = '.';
            }
        }
    }

    for (int i = 1; i < mapa.size() - 1; i++) {
        for (int j = 1; j < mapa[i].size() - 1; j++) {
            if (rand() % 7 == 0) {
                bool blokirano = true;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if ((di == 0 || dj == 0) && di != dj) {
                            int ni = i + di, nj = j + dj;
                            if (mapa_pozadina[ni][nj] != '#') {
                                blokirano = false;
                            }
                        }
                    }
                }
                if (!blokirano) {
                    mapa[i][j] = '#';
                    mapa_pozadina[i][j] = '#';
                }
            }
        }
    }

    mapa[pacman.gety()][pacman.getx()] = pacman.getsimbol();
    mapa_pozadina[pacman.gety()][pacman.getx()] = ' ';

    for (auto& enemy : duhovi) {
        mapa[enemy.gety()][enemy.getx()] = enemy.getsimbol();
        mapa_pozadina[enemy.gety()][enemy.getx()] = '.';
    }

    preostale_tocke = 0;
    for (auto& row : mapa_pozadina) {
        preostale_tocke += count(row.begin(), row.end(), '.');
    }
}

void Game::mapa_update() {
    for (int i = 0; i < mapa.size(); i++) {
        for (int j = 0; j < mapa[i].size(); j++) {
            if (mapa[i][j] != '#') {
                mapa[i][j] = mapa_pozadina[i][j];
            }
        }
    }

    if (mapa_pozadina[pacman.gety()][pacman.getx()] == '.') {
        score++;
        preostale_tocke--;
        mapa_pozadina[pacman.gety()][pacman.getx()] = ' ';
    }

    mapa[pacman.gety()][pacman.getx()] = pacman.getsimbol();

    for (const auto& enemy : duhovi) {
        mapa[enemy.gety()][enemy.getx()] = enemy.getsimbol();
    }
}

void Game::display() {
    system("cls");
    for (const auto& row : mapa) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

void Game::provjeri() {
    for (const auto& enemy : duhovi) {
        if (pacman.getx() == enemy.getx() && pacman.gety() == enemy.gety()) {
            throw runtime_error("Game Over! Pac-Man je ulovljen!");
        }
    }
}

Game::Game(int sirina, int visina, int br_enemy) : mapa(visina, vector<char>(sirina, '.')),
mapa_pozadina(visina, vector<char>(sirina, '.')), pacman(sirina / 2, visina / 2),
score(0) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < br_enemy; i++) {
        int x, y;
        do {
            x = rand() % sirina;
            y = rand() % visina;
        } while (mapa[y][x] != '.');
        duhovi.emplace_back(x, y);
    }
    kreiraj_mapu();
}

void Game::run() {
    while (true) {
        display();
        pacman.moving(mapa[0].size(), mapa.size(), mapa);
        for (auto& enemy : duhovi) {
            enemy.moving(mapa[0].size(), mapa.size(), mapa);
        }
        provjeri();
        mapa_update();

        if (preostale_tocke <= 0) {
            cout << "Pobjeda! Sve tockice su prikupljene!" << endl;
            break;
        }
    }
}

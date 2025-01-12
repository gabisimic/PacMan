#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy(int pocx, int pocy) : Character(pocx, pocy, 'E') {}

void Enemy::moving(int sirina, int visina, const std::vector<std::vector<char>>& mapa) {
    int ex = (rand() % 3) - 1;
    int ey = (rand() % 3) - 1;
    int novi_x = x + ex;
    int novi_y = y + ey;

    if (novi_x >= 0 && novi_x < sirina && novi_y >= 0 && novi_y < visina && mapa[novi_y][novi_x] != '#') {
        x = novi_x;
        y = novi_y;
    }
}

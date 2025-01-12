#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
public:
    Enemy(int pocx, int pocy);
    void moving(int sirina, int visina, const std::vector<std::vector<char>>& mapa) override;
};

#endif
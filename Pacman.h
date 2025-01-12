#pragma once
#ifndef PACMAN_H
#define PACMAN_H

#include "Character.h"

class PacMan : public Character {
public:
    PacMan(int pocx, int pocy);
    void moving(int sirina, int visina, const std::vector<std::vector<char>>& mapa) override;
};

#endif 

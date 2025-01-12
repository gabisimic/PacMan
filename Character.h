#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>

class Character {
protected:
    int x;
    int y;
    char simbol;
public:
    Character(int pocx, int pocy, char simb);
    virtual ~Character();

    int getx() const;
    int gety() const;
    char getsimbol() const;

    virtual void moving(int sirina, int visina, const std::vector<std::vector<char>>& mapa) = 0;
};

#endif

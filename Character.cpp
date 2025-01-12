#include "Character.h"

Character::Character(int pocx, int pocy, char simb) : x(pocx), y(pocy), simbol(simb) {}

Character::~Character() {}

int Character::getx() const { return x; }
int Character::gety() const { return y; }
char Character::getsimbol() const { return simbol; }

#pragma once
#include <iostream>
#include <string>
using namespace std;
class Jeu {
public:
    Jeu();
    virtual void jouer() = 0;
    virtual ~Jeu();
};
#pragma once
#include <iostream>
#include <string>
using namespace std;

// Classe Matrice pour manipuler des couples de cha�nes de caract�res
class Matrice {
public:
    string first;
    string second;
    Matrice();
    Matrice(const string& a, const string& b);
    ~Matrice() {}
};


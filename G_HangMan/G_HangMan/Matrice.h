#pragma once
#include <iostream>
#include <string>
using namespace std;

// Classe Matrice pour manipuler des couples de chaînes de caractères
class Matrice {
public:
    string first;
    string second;
    Matrice();
    Matrice(const string& a, const string& b);
    ~Matrice() {}
};


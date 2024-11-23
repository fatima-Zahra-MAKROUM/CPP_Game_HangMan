#pragma once
#include <iostream>
#include <string>
#include"Matrice.h"
using namespace std;
class GestionnaireMots {
private:
    Matrice mots[10];

public:
    GestionnaireMots();
    ~GestionnaireMots();
    Matrice choisirMotAleatoire();
};

#pragma once
#include <iostream>
#include <string>
#include "Jeu.h"
#include"GestionnaireMots.h"

using namespace std;

class JeuPendu : public Jeu {
private:
    GestionnaireMots gestionnaireMots;
    string motADeviner;
    string motCache;
    string indication;
    int vies;
    static const int MAX_TAILLE = 26; // Taille maximale pour les lettres tentées (alphabet)
    char lettresTentees[MAX_TAILLE];
    int lettresTenteesCount;


public:
    JeuPendu();
    void initialiser();
    void afficherEtat() const;
    bool verifierLettre(char lettre);
    bool lettreDejaTentee(char lettre) const;
    void afficherDessin() const;
    bool aGagne() const;
    void jouer() override;
    ~JeuPendu();
};


#include "GestionnaireMots.h"

GestionnaireMots::GestionnaireMots() {
    cout << "GestionnaireMots: Constructeur appele.\n";
    mots[0] = { "programmation", "L'art d'ecrire du code informatique" };
    mots[1] = { "ordinateur", "Machine que vous utilisez en ce moment" };
    mots[2] = { "pendu", "Un jeu classique pour deviner des mots" };
    mots[3] = { "developpement", "Processus de creation d'un logiciel" };
    mots[4] = { "jeu", "Activite ludique pour se divertir" };
    mots[5] = { "algorithme", "Une suite d'instructions pour resoudre un problème" };
    mots[6] = { "intelligence", "Ce qui distingue les humains des machines (jusqu'a un certain point !)" };
    mots[7] = { "mathematiques", "Discipline qui etudie les nombres et les formes" };
    mots[8] = { "technologie", "Ensemble d'outils avances crees par les humains" };
    mots[9] = { "innovation", "Processus de création de nouvelles idees ou solutions" };
}

GestionnaireMots::~GestionnaireMots()
{
    cout << "GestionnaireMots: Destructeur appele.\n";
}


Matrice GestionnaireMots::choisirMotAleatoire()
{
    srand(time(0));
    return mots[rand() % 10];
}

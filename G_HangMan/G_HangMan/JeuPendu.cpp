#include "JeuPendu.h"

JeuPendu::JeuPendu() : vies(7), motCache(""), lettresTenteesCount(0)
{
    cout << "JeuPendu: Constructeur appele.\n";
}

void JeuPendu::initialiser()
{
    Matrice motEtIndication = gestionnaireMots.choisirMotAleatoire();
    motADeviner = motEtIndication.first;
    indication = motEtIndication.second;
    motCache = string(motADeviner.size(), '_');
    lettresTenteesCount = 0;
    vies = 7;
}
void JeuPendu::afficherEtat() const
{
    cout << "\033[38;5;218m"; // Rose bébé
    cout << "\n==============================\n";
    cout << "-> Vies restantes : " << vies << endl;
    cout << "-> Indication : " << indication << endl;
    cout << "-> Mot a deviner : " << motCache << endl;

    cout << "-> Lettres tentees : ";
    for (int i = 0; i < lettresTenteesCount; ++i) {
        cout << lettresTentees[i] << " ";
    }
    cout << endl;
    cout << "==============================\n\n";
    cout << "\033[0m"; // Réinitialiser la couleur
}


bool JeuPendu::verifierLettre(char lettre)
{
    bool trouve = false;
    for (int i = 0; i < motADeviner.size(); ++i) {
        if (motADeviner[i] == lettre) {
            motCache[i] = motADeviner[i];
            trouve = true;
        }
    }
    return trouve;
}

bool JeuPendu::lettreDejaTentee(char lettre) const
{
    for (int i = 0; i < lettresTenteesCount; ++i) {
        if (lettresTentees[i] == lettre) {
            return true;
        }
    }
    return false;
}

void JeuPendu::afficherDessin() const
{
    // Affichage du dessin en Jaune si les vies > 0
    cout << "\nEtat du pendu :\n";
    if (vies > 0) {
        cout << "\033[33m"; // Jaune
        switch (vies) {
        case 7:
            cout << "    ___\n    |      |\n           |\n           |\n           |\n           |\n  _____\n";
            break;
        case 6:
            cout << "    ___\n    |      |\n    O      |\n           |\n           |\n           |\n  _____\n";
            break;
        case 5:
            cout << "    ___\n    |      |\n    O      |\n    |      |\n           |\n           |\n  _____\n";
            break;
        case 4:
            cout << "    ___\n    |      |\n    O      |\n   /|      |\n           |\n           |\n  _____\n";
            break;
        case 3:
            cout << "    ___\n    |      |\n    O      |\n   /|\\     |\n           |\n           |\n  _____\n";
            break;
        case 2:
            cout << "    ___\n    |      |\n    O      |\n   /|\\     |\n   /       |\n           |\n  _____\n";
            break;
        case 1:
            cout << "    ___\n    |      |\n    O      |\n   /|\\     |\n   / \\     |\n           |\n  _____\n";
            break;
        }
        cout << "\033[0m"; // Réinitialiser la couleur
    }
    // Affichage du dessin en Rouge quand les vies == 0
    else {
        cout << "\033[31m"; // Rouge
        cout << "    ___\n";
        cout << "      |\n";
        cout << "      |\n";
        cout << "      |\n";
        cout << "      |\n";
        cout << "      O\n";
        cout << "     /|\\\n";
        cout << "    / \\\n";
        cout << "\033[0m"; // Réinitialiser la couleur
    }
    cout << "\n";
}

bool JeuPendu::aGagne() const
{
    return motCache == motADeviner;
}

void JeuPendu::jouer()
{
    initialiser();

    // Menu en Cyan
    cout << "\033[36m"; // Cyan
    cout << "\n************ Bienvenue dans le jeu de Pendu ! ************" << endl;
    cout << "\033[0m"; // Réinitialiser la couleur

    while (vies > 0) {
        afficherEtat();
        afficherDessin();

        cout << "\nEntrez une lettre : ";
        string entree;
        cin >> entree;

        if (entree.size() != 1 || !isalpha(entree[0])) {
            // Message en Orange
            cout << "\033[38;5;214m"; // Orange
            cout << "\n**** Attention : Veuillez entrer une seule lettre valide. ****\n" << endl;
            cout << "\033[0m"; // Réinitialiser la couleur
            continue;
        }

        char lettre = entree[0];

        if (lettreDejaTentee(lettre)) {
            // Message en Orange
            cout << "\033[38;5;214m"; // Orange
            cout << "\n**** Attention : Lettre deja tentee. ****\n" << endl;
            cout << "\033[0m"; // Réinitialiser la couleur
            continue;
        }

        lettresTentees[lettresTenteesCount++] = lettre;

        if (!verifierLettre(lettre)) {
            vies--;
            // Message en Orange
            cout << "\033[38;5;214m"; // Orange
            cout << "\n**** Mauvaise lettre ! Vies restantes : " << vies << " ****\n" << endl;
            cout << "\033[0m"; // Réinitialiser la couleur
        }
        else {
            // Message de "Bonne lettre" en Vert
            cout << "\033[32m"; // Vert
            cout << "\nBonne lettre !\n";
            cout << "\033[0m"; // Réinitialiser la couleur
        }

        if (aGagne()) {
            // Message de Félicitations en Vert
            cout << "\033[32m"; // Vert
            cout << "\n************ Felicitations ! Vous avez trouve le mot : " << motADeviner << " ************" << endl;
            cout << "\033[0m"; // Réinitialiser la couleur
            return;
        }
    }

    // Affichage du dessin final en Rouge lors de la perte
    afficherDessin();
    cout << "\033[31m"; // Rouge
    cout << "\n************ Perdu ! Le mot etait : " << motADeviner << " ************\n" << endl;
    cout << "Vous avez perdu !" << endl;
    cout << "\033[0m"; // Réinitialiser la couleur
}

JeuPendu::~JeuPendu()
{
    cout << "\n\nJeuPendu: Destructeur appele.\n";
}

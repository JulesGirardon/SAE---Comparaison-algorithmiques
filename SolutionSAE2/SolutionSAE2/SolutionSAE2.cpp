#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#include <iostream>
#include <fstream>
#include <array>

#include "fonctions.h"

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif // _WIN32

    std::vector<TabFunction> tabFunction = { initTabAleat, initTabPresqueTri, initTabPresqueTriDeb, initTabPresqueTriDebFin, initTabPresqueTriFin };    // On initialise un tableau de pointeurs vers fonctions. Les fonctions sont celles de la g�n�ration de tableau.

    std::vector<TabTrie> tabTrie = {triSelection, triBulles, triBullesOpti, triPeigne, triInsertion, triRapide_short, triCocktail, triPairImpair, triParComptage, triParBase, triShell, triFaireValoir_short, triTas};   // On initialise un deuxi�me tableau de pointeurs vers fonctions. Les fonctions sont celles de tri du tableau.
    std::vector<std::string> nomTrie = { "Select.", "Bulles", "BullesOpti", "Peigne",  "Insertion", "Rapide", "Cocktail", "PairImpair", "Comptage", "Base", "Shell", "FaireValoir", "Tas"};     // Ce tableau r�pertorie les noms des tries. Ce tableau sera utile pour l'ent�te du CSV.

    std::array<std::string, 6> tab_sortie = { "N","Aleat", "PresqueTri", "PresqueTriDeb", "PresqueTriDebFin", "PresqueTriFin" };        // Ce tableau r�pertorie les nom des diff�rentes m�thodes de g�n�ration du tableau ainsi que N, le nombre d'�l�ments du tableau.

    std::ofstream out("tri.csv");        // On cr�e le fichier CSV

    if (!out.is_open()) {
        std::cerr << "Impossible d'ouvir le fichier";
        exit(EXIT_FAILURE);
    }

    out << "N;";                                                // On ajoute l'ent�te.
    for (size_t i = 0; i < nomTrie.size(); i++)                 // Cette boucle permet d'associer les m�thodes de g�n�ration des tableaux avec leur m�thode de trie. Par exemple, pour la m�thode de tri Cocktail nous aurons : N | Aleat Cocktail | PresqueTri Cocktail |....
        for (size_t j = 1; j < tab_sortie.size(); j++)
            out << tab_sortie[j] + " " + nomTrie[i] << ";";     // Le -> ; permet de se d�placer de 1 case vers la droite dans le CSV.
    out << "\n";                                                // Retour � la ligne dans le CSV
    
    std::srand(std::time(0));                                   // Al�atoire un peu plus al�atoire
    for (int i = 0; i < 10; ++i) {                              // On cr�e 10 tableaux
        size_t N = std::rand() % 60 + 3;                             // On g�n�re un N qui va �tre la taille de notre.
        while (N < 2)
            N = std::rand() % 60 + 3;
        out << N;                                               // On le met dans le CSV

        for (const auto& triFunc : tabTrie) {                   // Pour chaque m�thode de tri :
            for (const auto& initFunc : tabFunction) {
                std::vector<int> tab = initFunc(N);             // On g�n�re des tableaux avec les m�thodes de g�n�ration
                out << ';' << triFunc(tab);                     // Puis on rentre directement le nombre de comparaison dans le CSV.
                verifTri(tab);                                  // On v�rifie si le tableau est bien tri�
            }
        }
        out << '\n';                                            // On saute une ligne
    }
}


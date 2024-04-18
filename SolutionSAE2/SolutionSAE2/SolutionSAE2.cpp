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

    std::vector<TabFunction> tabFunction = { initTabAleat, initTabPresqueTri, initTabPresqueTriDeb, initTabPresqueTriDebFin, initTabPresqueTriFin };    // On initialise un tableau de pointeurs vers fonctions. Les fonctions sont celles de la génération de tableau.

    std::vector<TabTrie> tabTrie = {triSelection, triBulles, triBullesOpti, triPeigne, triInsertion, triRapide_short, triCocktail, triPairImpair, triParComptage, triParBase, triShell, triFaireValoir_short, triTas};   // On initialise un deuxième tableau de pointeurs vers fonctions. Les fonctions sont celles de tri du tableau.
    std::vector<std::string> nomTrie = { "Select.", "Bulles", "BullesOpti", "Peigne",  "Insertion", "Rapide", "Cocktail", "PairImpair", "Comptage", "Base", "Shell", "FaireValoir", "Tas"};     // Ce tableau répertorie les noms des tries. Ce tableau sera utile pour l'entête du CSV.

    std::array<std::string, 6> tab_sortie = { "N","Aleat", "PresqueTri", "PresqueTriDeb", "PresqueTriDebFin", "PresqueTriFin" };        // Ce tableau répertorie les nom des différentes méthodes de génération du tableau ainsi que N, le nombre d'éléments du tableau.

    std::ofstream out("tri.csv");        // On crée le fichier CSV

    if (!out.is_open()) {
        std::cerr << "Impossible d'ouvir le fichier";
        exit(EXIT_FAILURE);
    }

    out << "N;";                                                // On ajoute l'entête.
    for (size_t i = 0; i < nomTrie.size(); i++)                 // Cette boucle permet d'associer les méthodes de génération des tableaux avec leur méthode de trie. Par exemple, pour la méthode de tri Cocktail nous aurons : N | Aleat Cocktail | PresqueTri Cocktail |....
        for (size_t j = 1; j < tab_sortie.size(); j++)
            out << tab_sortie[j] + " " + nomTrie[i] << ";";     // Le -> ; permet de se déplacer de 1 case vers la droite dans le CSV.
    out << "\n";                                                // Retour à la ligne dans le CSV
    
    std::srand(std::time(0));                                   // Aléatoire un peu plus aléatoire
    for (int i = 0; i < 10; ++i) {                              // On crée 10 tableaux
        size_t N = std::rand() % 60 + 3;                             // On génère un N qui va être la taille de notre.
        while (N < 2)
            N = std::rand() % 60 + 3;
        out << N;                                               // On le met dans le CSV

        for (const auto& triFunc : tabTrie) {                   // Pour chaque méthode de tri :
            for (const auto& initFunc : tabFunction) {
                std::vector<int> tab = initFunc(N);             // On génère des tableaux avec les méthodes de génération
                out << ';' << triFunc(tab);                     // Puis on rentre directement le nombre de comparaison dans le CSV.
                verifTri(tab);                                  // On vérifie si le tableau est bien trié
            }
        }
        out << '\n';                                            // On saute une ligne
    }
}


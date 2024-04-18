/**
 * \file fonctions.h
 *
 * Déclaration des fonctions fournies.
 */
#pragma once
#include <vector>
#include <string>

using TabTrie = unsigned int(*)(std::vector<int>& tab);
using TabFunction = std::vector<int>(*)(size_t);

//!\brief Crée un tableau aléatoire
std::vector<int> initTabAleat(size_t N);

//!\brief Crée un tableau presque trié
std::vector<int> initTabPresqueTri(size_t N);

//!\brief Crée un tableau presque trié au début
std::vector<int> initTabPresqueTriDeb(size_t N);

//!\brief Crée un tableau presque trié à la fin
std::vector<int> initTabPresqueTriFin(size_t N);

//!\brief Crée un tableau presque trié entre le début et la fin
std::vector<int> initTabPresqueTriDebFin(size_t N);

//!\brief Vérifie qu'un tableau est correctement trié
void verifTri(const std::vector<int>& tab, const std::string& algoName = {});

//!\brief Effectue le tri d'un tableau par sélection
unsigned int	triSelection			(std::vector<int>& tab);

//!\brief Effectue le tri a bulles
unsigned int	triBulles				(std::vector<int>& tab);

//!\brief Effectue le tri a bulles optimisé
unsigned int	triBullesOpti			(std::vector<int>& tab);

//!\brief Effectue le tri a peigne
unsigned int	triPeigne				(std::vector<int>& tab);

//!\brief Effectue le tri rapide
unsigned int	triRapide				(std::vector<int>& tab, int premier, int dernier);
unsigned int	triRapide_short			(std::vector<int>& tab);

//!\brief Effectue le tri shell
unsigned int	triShell				(std::vector<int>& tab);

//!\brief Effectue le tri stupide
unsigned int	triStupide				(std::vector<int>& tab);

//!\brief Effectue le tri a insertion
unsigned int	triInsertion			(std::vector<int>& tab);

//!\brief Effectue le tri par tas
void			tamiser					(std::vector<int>& arbre, int noeud, int n, unsigned int& nb_comparaison);
unsigned int	triTas					(std::vector<int>& tab);

//!\brief Effectue le tri cocktail
unsigned int	triCocktail				(std::vector<int>& tab);

//!\brief Effectue le tri PairImpair
unsigned int	triPairImpair			(std::vector<int>& tab);

//!\brief Effectue le tri par comptage
unsigned int	triParComptage			(std::vector<int>& tab);

//!\brief Effectue le tri par base
unsigned int	triParBase				(std::vector<int>& tab);

//!\brief Effectue le tri par faire valoir
unsigned int	triFaireValoir			(std::vector<int>& tab, int i, int j);
unsigned int	triFaireValoir_short	(std::vector<int>& tab);
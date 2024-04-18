/**
 * \file fonctions.cpp
 * 
 * Définition des fonctions fournies.
 */
#include "fonctions.h"
#include <iostream>
#include <ctime>
#include <algorithm>

/**
 * Crée un tableau d'entiers dont tous les éléments sont choisis aléatoirement.
 * 
 * Un tel tableau peut par exemple être 30968 28073 31177 2882 6140 17999 13828 20039 2310 24865.
 * 
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabAleat(size_t N)
{
  std::vector<int> tab(N);
  for (auto& val : tab)
    val = rand();
  return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Chaque élément est quasiment à sa place définitive, échangé éventuellement d'une place.
 * 
 * Un tel tableau peut par exemple être 1 3 2 4 6 5 8 7 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTri(size_t N)
{
  std::vector<int> tab(N);
  for (int i = 0; i < N; i++)
    tab[i] = i;
  for (int i = 0; i < N-1; i++)
  {
    if (rand() % 2 == 0)
    {
      std::swap(tab[i], tab[i + 1]);
      ++i;
    }
  }
  return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le deuxième élément sont échangés.
 *
 * Un tel tableau peut par exemple être 2 1 3 4 5 6 7 8 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDeb(size_t N)
{
  std::vector<int> tab(N);
  for (int i = 0; i < N; i++)
    tab[i] = i;
  std::swap(tab[0], tab[1]);
  return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le dernier et l'avant dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 1 2 3 4 5 6 7 8 10 9.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriFin(size_t N)
{
  std::vector<int> tab(N);
  for (int i = 0; i < N; i++)
    tab[i] = i;
  std::swap(tab[N - 1], tab[N - 2]);
  return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 10 2 3 4 5 6 7 8 9 1.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDebFin(size_t N)
{
  std::vector<int> tab(N);
  for (int i = 0; i < N; i++)
    tab[i] = i;
  std::swap(tab[N - 1], tab[0]);
  return tab;
}

/**
 * Vérifie qu'un tableau est correctement trié. Si le tableau est mal trié, un message d'erreur est
 * affiché sur le flux d'erreur et le programme est terminé.
 * 
 * \param[in] tab Le tableau à vérifier
 * \param[in] algoName Le nom de l'algorithme de tri qui a été utilisé. Ce paramètre est optionnel.
 */
void verifTri(const std::vector<int>& tab, const std::string& algoName)
{
  const size_t taille = tab.size();
  for (size_t i = 1; i < taille; i++)
  {
    if (tab[i - 1] > tab[i])
    {
      std::cerr << "Erreur dans le tri " << algoName << (algoName.empty() ? "!" : " !") << '\n';
      exit(EXIT_FAILURE);
    }
  }
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri par sélection
 *
 * Fonctionnement : On commence à l'indice 0 puis, dans le tableau, on cherche le plus petit élément du tableau restant et on le met à l'indice 0.
 *                  Ensuite, on passe à l'indice 1 et on recherche de nouveau le plus petit élément du tableau restant puis on le met à l'indice 1.
 *                  On fait cela jusqu'à que le tableau soit trié.
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison qui est un unsigned int
 */
unsigned int triSelection(std::vector<int>& tab) {
    unsigned int nb_comparaison = 0;
    int n = tab.size();

    for (size_t i = 0; i < n; i++) {
        int min = i;

        for (size_t j = i+1; j < n; j++) {
            nb_comparaison++;
            if (tab[j] < tab[min]) {
                min = j;
            }
        }

        if (min != i) {
            std::swap(tab[i], tab[min]);
        }
    }   
    return nb_comparaison;
}


/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri par bulles
 *
 * Fonctionnement : Jusqu'à que le tableau soit trié, on compare l'élément actuel avec le prochain élément.
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison qui est un unsigned int
 */
unsigned int triBulles(std::vector<int>& tab) {
    unsigned int nb_comparaison = 0;
    
    for (size_t i = tab.size() - 1; i > 0; i--) {
        for (size_t j = 0; j < i; j++) {
            nb_comparaison++;
            if (tab[j + 1] < tab[j])
                std::swap(tab[j + 1], tab[j]);
        }
    }
    return nb_comparaison;
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri par bulles optimisés
 *
 * Fonctionnement : Cette méthode de tri est similaire au tri par bulle cependant, le tri est interrompu
 *                  dès qu'une suite d'éléments consécutifs censé être en désordres sont dans le bon ordre.
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison qui est un unsigned int
 */
unsigned int triBullesOpti(std::vector<int>& tab) {
    const size_t taille = tab.size();
    unsigned int nb_comparaison = 0;
    for (size_t i = taille - 1; i > 0; i--) {
        bool tableau_trie = true;
        for (size_t j = 0; j < i; j++) {
            nb_comparaison++;
            if (tab[j + 1] < tab[j]) {
                std::swap(tab[j + 1], tab[j]);
                tableau_trie = false;
            }
        }
        if (tableau_trie)
            return nb_comparaison;

    }
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri àr peigne
 * 
 * Fonctionnement : Cela fonctionne comme le tri à bulles cependant, l'écart entre les deux valeurs observées
 *                  est plus grand. Au fur et à mesure de l'avancement du tri, cet écart se réduit jusqu'à atteindre 1.
 *                  Une fois 1 atteint, le tableau est trié.
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison qui est un unsigned int
 */
unsigned int triPeigne(std::vector<int>& tab) {
	unsigned int nb_comparaison = 0;
    size_t intervalle = tab.size();
    bool echange = true;

    while(intervalle > 1 || echange) {

        intervalle = int(intervalle / 1.3);
        if (intervalle < 1)
            intervalle = 1;

        int i = 0;
        echange = false;

        while(i < tab.size() - intervalle) {
            if(tab[i] > tab[i + intervalle]) {
                nb_comparaison++;
                std::swap(tab[i], tab[i + intervalle] );
                echange = true;
            }
            i++;
        }
    }
    return nb_comparaison;
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri rapide
 *
 * Fonctionnement : Cette méthode de tri est basé sur le principe de diviser pour régner.
 *                  On choisit un pivot puis, à partir de ce pivot, on divise le tableau en deux sous tableau
 *                  Puis dans les deux sous tableaux, on trouve un nouveau pivot et on refait deux sous tableau à partir du pivot
 *                  Une fois que nous avons deux sous tableaux, on compare les valeurs et on les mets dans l'ordre.
 *                  On réassemble tous les sous_tableaux. Ainsi le tableau est trié.
 * 
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \param[in] premier est l'indice du premier élément du tableau
 * \param[in] dernier est l'indice du dernier élément du tableau
 * \return le nombre de comparaison qui est un unsigned int
 */
unsigned int triRapide(std::vector<int>& tab, int premier, int dernier) {
    unsigned int nb_comparaisons = 0;

    if (premier < dernier) {
        int pivotIndex = premier + (dernier - premier) / 2;
        int pivot = tab[pivotIndex];
        int i = premier;
        int j = dernier;
        while (i <= j) {
            while (tab[i] < pivot) {
                i++;
                nb_comparaisons++;
            }
            while (tab[j] > pivot) {
                j--;
                nb_comparaisons++;
            }

            if (i <= j) {
                std::swap(tab[i], tab[j]);
                i++;
                j--;
            }
        }
        nb_comparaisons += triRapide(tab, premier, j);
        nb_comparaisons += triRapide(tab, i, dernier);
    }
    return nb_comparaisons;
}

/**
 * Permet d'appeler la fonction triRapide. Cette fonction est nécessaire car :
 *    Pour rappel, la fonction triRapide prends 3 paramètres
 *    Or, dans le programme principal, nous avons un tableau de pointeurs de fonctions qui prends
 *    des fonctions avec un seul paramètre
 *    Ainsi, cette fonction permet d'appeler la fonction triRapide à partir du tableau de pointeurs vers fonctions
 *
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison qui est un unsigned int
 */
unsigned int triRapide_short(std::vector<int>& tab) {
    int nb_comparaison = triRapide(tab, 0, tab.size() - 1);
    return nb_comparaison;
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri shell
 *
 * Fonctionnement : Ce tri est une version améliorée du tri par insertion.
 *                  Cela consiste a faire des sous tableaux de n éléments d'écarts
 *                  (si n = 2; [1,2,3,4] -> [1,3] et [2,4]
 *                  Ces sous tableaux sont triés et l'écarts entre les éléments se réduit au fur et à mesure.
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison qui est un unsigned int
 */
unsigned int triShell(std::vector<int>& tab) {
	unsigned int nb_comparaison = 0;
    size_t n = tab.size();
    for (int r = n/2; r > 0; r /= 2) {
        for (int i = r; i < n; i++) {
            int x = tab[i];
            int j;
            for (j = i; j >= r && tab[j - r] > x; j -= r) {
                tab[j] = tab[j - r];
                nb_comparaison++;
            }
		    tab[j] = x;
			}
		}

    return nb_comparaison;
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri stupide
 *
 * Fonctionnement : Ce tri mélange le tableau jusqu'à que le tableau soit trié.
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison qui est un unsigned int
 */
unsigned int triStupide(std::vector<int>& tab) {
	unsigned int nb_comparaison = 0;
	std::srand(std::time(0));
    while (!std::is_sorted(tab.begin(), tab.end())) {
        std::random_shuffle(tab.begin(), tab.end());
        nb_comparaison++;
    }
    return nb_comparaison;
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri par insertion
 *
 * Fonctionnement : Ce trie consiste, au fur et à mesure du parcours de ce tableau, 
                    à insérer à sa place chaque élément dans le début déjà trié.
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison qui est un unsigned int
 */
unsigned int triInsertion(std::vector<int>& tab) {
	unsigned int nb_comparaison = 0;
    int taille = tab.size();
	for (int i = 1; i < taille; ++i) {
		
		int x = tab[i];
		int j = i;
		while (j > 0 && tab[j - 1] > x) {
			nb_comparaison++;
			tab[j] = tab[j - 1];
			--j;
		}
		tab[j] = x;
	}
    return nb_comparaison;
}

/**
 * Fonction complémentaire à la fonction TriTas
 *
 * Fonctionnement : Consiste à organiser les tas entre eux pour pouvoir appliquer la fonction trie tas
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \param[in] int x
 * \param[in] int n
 * \param[in] unsigned int& nb_comparaison
 */
void tamiser(std::vector<int>& tab, int x, int n, unsigned int& nb_comparaison) {
    int k = x;
    int j = 2*k;
    while(j <= n) {
        if( j < n && tab[j-1] < tab[j])
            j++;

        if (tab[k-1] < tab[j-1]) {
            std::swap(tab[k-1], tab[j-1]);
            k = j;
            j = 2 * k;
            nb_comparaison++;
        } else
            j = n + 1;
    }
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri par tas
 *
 * Fonctionnement : Comme l'élément maximum du tableau est stocké à la racine, 
                    On peut le placer dans sa position finale correcte en l'échangeant avec le dernier élément du tableau.
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison qui est un unsigned int
 */
unsigned int triTas(std::vector<int>& tab) {
	unsigned int nb_comparaison = 0;
    int n = tab.size();

    for(int i = n/2; i > 0; i--)
        tamiser(tab, i, tab.size(), nb_comparaison);

    for(int i = n; i > 1; i--) {
        std::swap(tab[i-1], tab[0]);
        tamiser(tab, 1, i - 1, nb_comparaison);
    }
    return nb_comparaison;
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri cocktail
 *
 * Fonctionnement : Le tri cocktail est une variante du tri à bulles.
 *                  Cependant, par rapport au tri à bulles,
 *                  Au lieu de se déplacer de gauche à droite
 *                  On se déplacement alternativement de gauche à droite et de droite à gauche
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison qui est un unsigned int
 */
unsigned int triCocktail(std::vector<int>& tab) {
    unsigned int nb_comparaison = 0;
    bool echange = true;
    while (echange) {
        echange = false;
        
        for (size_t i = 0; i < tab.size() - 2; i++) {
            nb_comparaison++;
            if (tab[i] > tab[i + 1]) {
                std::swap(tab[i], tab[i + 1]);
                echange = true;
            }
        }
        for (size_t i = tab.size() - 2; i > 0; i--) {
            nb_comparaison++;
            if (tab[i] > tab[i + 1]) {
                std::swap(tab[i], tab[i + 1]);
                echange = true;
            }
        }
    }
    return nb_comparaison;
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri pair impair
 *
 * Fonctionnement : Ce tri compare les couples d'éléments dont les indices sont pairs et impairs
 *                  Exemple : [3,1,2,7] -> [3,2] et [1,7]. 
 *                   indice -> 0 1 2 3
 *                  On compare donc les éléments avec les indices pairs entre eux et les éléments avec un indice impairs entre eux. 
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison qui est un unsigned int
 */
unsigned int triPairImpair(std::vector<int>& tab) {
    unsigned int nb_comparaison = 0;
    bool trie = false;

    while (!trie) {
        trie = true;
        for (size_t i = 0; i < tab.size()-1; i += 2) {
            nb_comparaison++;
            if (tab[i] > tab[i + 1]) {
                std::swap(tab[i], tab[i + 1]);
                trie = false;
            }
        }
        for (size_t i = 1; i < tab.size() - 1; i += 2) {
            nb_comparaison++;
            if (tab[i] > tab[i + 1]) {
                std::swap(tab[i], tab[i + 1]);
                trie = false;
            }
        }
    }

    return nb_comparaison;
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri par comptage
 *
 * Fonctionnement : Ce tri compte le nombre d'occurence de chaque valeurs dans l'ensemble de données,
                    puis il classe les valeurs dans l'ordre en fonction de leur nombre d'occurences.
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison
 */
unsigned int triParComptage(std::vector<int>& tab) {
    unsigned int nb_comparaison = 0;
    int borneSuperieure = 0;

    for (int k = 0; k < tab.size(); k++) {
        nb_comparaison++;
        if (tab[k] > borneSuperieure)
            borneSuperieure = tab[k];
    }

    std::vector<int> comptage(borneSuperieure + 1, 0);

    for (int k = 0; k < tab.size(); k++)
        comptage[tab[k]]++;

    int cpt = 0;

    for (int i = 0; i <= borneSuperieure; i++) {
        for (int j = 0; j < comptage[i]; j++) {
            tab[cpt] = i;
            cpt++;
        }
    }
    return nb_comparaison;
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri faire valoir
 *
 * Fonctionnement : On prends les deux premiers tiers du tableau qu'on trie
 *                  Puis, on trie les deux dernier tiers du tableau
 *                  Ensuite on retrie les deux premiers tiers du tableau.
 *                  On fait ceci jusqu'à que le tableau soit trié.
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \param[in] int i -> premier élément du tableau
 * \param[in] int j -> dernier élément du tableau
 * \return le nombre de comparaison
 */
unsigned int triFaireValoir(std::vector<int>& tab, int i, int j) {
    int nb_comparaison = 1;
    if (tab[i] > tab[j]) {
        std::swap(tab[i], tab[j]);
    }

    if (j - i + 1 > 2) {
        int t = (j - i + 1) / 3;

        nb_comparaison += triFaireValoir(tab, i, j - t);
        nb_comparaison += triFaireValoir(tab, i + t, j);
        nb_comparaison += triFaireValoir(tab, i, j - t);
    }
    return nb_comparaison;

}
/**
 * Permet d'appeler la fonction triFaireValoir. Cette fonction est nécessaire car :
 *    Pour rappel, la fonction triFaireValoir prends 3 paramètres
 *    Or, dans le programme principal, nous avons un tableau de pointeurs de fonctions qui prends
 *    des fonctions avec un seul paramètres
 *    Ainsi, cette fonction permet d'appeler la fonction triFaireValoir à partir du tableau de pointeurs vers fonctions
 *
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison
 */
unsigned triFaireValoir_short(std::vector<int>& tab) {
    unsigned int nb_comparaison = triFaireValoir(tab, 0, tab.size()-1);
    return nb_comparaison;
}

/**
 * Permet de trier le tableau mis en paramètre avec la méthode de tri par base
 * 
 * Fonctionnement : Ce tri classe les valeurs par :
 *                      - Les unités de la valeur
 *                      - Les dizaines de la valeur
 *                      - Les centaines de la valeur
 *                      - Ainsi de suite
 * 
 * \param[in] std::vector<int>& tab -> Vecteur d'int par référence
 * \return le nombre de comparaison
 */
unsigned int triParBase(std::vector<int>& tab) {
   unsigned int nb_comparaison = 0;

    auto maxtab = std::max_element(tab.begin(), tab.end());
    int maxtab_int = (maxtab != tab.end()) ? *maxtab : 0;

    for (int exp = 1; maxtab_int / exp > 0; exp *= 10) {
        std::vector<int> tab_sortie(tab.size());
        std::vector<int> count(10, 0);

        for (int i = 0; i < tab.size(); i++) {
            count[(tab[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = tab.size() - 1; i >= 0; i--) {
            tab_sortie[count[(tab[i] / exp) % 10] - 1] = tab[i];
            count[(tab[i] / exp) % 10]--;
            nb_comparaison++;
        }

        for (int i = 0; i < tab.size(); i++) {
            tab[i] = tab_sortie[i];
        }
    }
    return nb_comparaison;
}
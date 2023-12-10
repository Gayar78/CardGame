#ifndef JEU_H_
#define JEU_H_
#include <iostream>
#include <string>
#include <vector>
#include "joueur.h"

using namespace std;


class Jeu {
  vector<Carte> _reserve;
  Joueur _joueur1;
  Joueur _joueur2;

public:
  /* Jeu()
   * Constructeur de la classe Jeu. Donne des valeurs de base à la réserve de
   * cartes, et aux joueurs 1 et 2.
   */
  Jeu();

  /* Jeu()
   * Constructeur de la classe Jeu. Permet à l'utilisateur de donner des valeurs
   * aux attributs privés de la classe.
   *
   * Entrée : vector<Carte> une réserve de cartes, Joueur le joueur 1 et Joueur
   * le joueur 2.
   */
  Jeu(const vector<Carte> &, const Joueur &, const Joueur &);

 /* getJ1() et getJ2()
  * Permet d'avoir accès à ._joueur1 et ._joueur2 qui ne sont pas publique
  */
  Joueur getJ1()const;
  Joueur getJ2()const;

  
  /* joueEtMetAJour()
   * joue un tour du jeu actuel en faisant jouer une carte pour chaque joueur et
   * affiche leurs stats à la fin du tour.
   *
   * Entrée : aucune
   * Sortie : aucune
   */

  void joueEtMetAJour();
  void joueEtMetAJourIA();

  /* LaPartieEstFinie()
   * Teste si la partie est finie
   *
   * Entrée : aucune
   * Sortie : booléen, indique si la partie est finie.
   */
  bool LaPartieEstFinie() const;

  /* vainqueurPartie()
   * Indique le vainqueur de la partie. 0 : égalité, 1 : Joueur 2, 2 : Joueur 1
   *
   * Entrée : aucune
   * Sortie : entier, valeur indiquant qui a gagné la partie.
   */
  int vainqueurPartie() const;
};

/* trierCartes
 * utilise la fonction comparerCartes pour trier les cartes dans l'ordre
 * alphabétique de leur nom
 *
 * Entrée : vector<Carte> une réserve de cartes
 * Sortie : aucune
 */
void trierCartes(vector<Carte> &);

/* rangCartesAtkCroiss
 * trie un vector<vector<int>> qui contient la position, l'attaque, la défense, et la magie d'une carte en fonction de son attaque décroissante
 *
 * Entrée : vector<vector<int>> le vecteur 2D
 * Sortie : aucune
 */
void rangCartesAtkCroiss(vector<vector<int>> &);

/* rangCartesAtkDecroiss
 * trie un vector<vector<int>> qui contient la position, l'attaque, la défense, et la magie d'une carte en fonction de son attaque décroissante
 *
 * Entrée : vector<vector<int>> le vecteur 2D
 * Sortie : aucune
 */
void rangCartesAtkDecroiss(vector<vector<int>> &);

/* rangCartesDefCroiss
 * trie un vector<vector<int>> qui contient la position, l'attaque, la défense, et la magie d'une carte en fonction de sa défense croissante
 *
 * Entrée : vector<vector<int>> le vecteur 2D
 * Sortie : aucune
 */
void rangCartesDefCroiss(vector<vector<int>> &);

/* rangCartesDefDecroiss
 * trie un vector<vector<int>> qui contient la position, l'attaque, la défense, et la magie d'une carte en fonction de sa défense décroissante
 *
 * Entrée : vector<vector<int>> le vecteur 2D
 * Sortie : aucune
 */
void rangCartesDefDecroiss(vector<vector<int>> &);

/* rangCartesMagieCroiss
 * trie un vector<vector<int>> qui contient la position, l'attaque, la défense, et la magie d'une carte en fonction de sa magie croissante
 *
 * Entrée : vector<vector<int>> le vecteur 2D
 * Sortie : aucune
 */
void rangCartesMagieCroiss(vector<vector<int>> &);

/* rangCartesMagieDecroiss
 * trie un vector<vector<int>> qui contient la position, l'attaque, la défense, et la magie d'une carte en fonction de sa magie décroissante
 *
 * Entrée : vector<vector<int>> le vecteur 2D
 * Sortie : aucune
 */
void rangCartesMagieDecroiss(vector<vector<int>> &);

/* rangCartesDecroiss
 * trie un vector<vector<int>> qui contient la position, l'attaque, la défense, et la magie d'une carte en fonction de son attaque décroissante, puis de sa magie décroissante, puis de sa défense décroissante
 *
 * Entrée : vector<vector<int>> le vecteur 2D
 * Sortie : aucune
 */
void rangCartesDecroiss(vector<vector<int>>&);

/* rangCartesScoreDecroiss
 * trie un vector<vector<int>> qui contient la position, l'attaque, la défense, et la magie d'une carte en fonction de son score décroissant, c'est-à-dire de la somme de son attaque, de sa défense, et de sa magie.
 *
 * Entrée : vector<vector<int>> le vecteur 2D
 * Sortie : aucune
 */
void rangCartesScoreDecroiss(vector<Carte> &);

/* remplir()
 * remplit la réserve de cartes du jeu actuel en lisant un fichier texte qui
 * contient les cartes au bon format ("nom",[attaque (int)],[défense
 * (int)],[magie] (int))
 *
 * Entrée : aucune
 * Sortie : aucune
 */
void remplir();

/* search
 * Recherche un entier dans un vecteur d'entier
 * 
 * Entrée : vector<int> un tableau d'entiers, int un entier à rechercher dans le tableau
 * Sortie : un booléen, true si la valeur a été trouvée, false sinon.
 */
bool search(vector<int> &, int);

/* InitialisationDePartie1v1
 * initialise une partie joueur contre joueur, en mettant toutes les caractéristiques nécessaires pour le bon déroulement de la partie
 * 
 * Entrée : int le nombre de points de prestige des deux joueurs, string les deux noms des joueurs, par référence pour pouvoir les réutiliser tout au long de la partie.
 * Sortie : un élément de la classe Jeu, celui qui va être joué ensuite.
 */
Jeu initialisationDePartie1V1(int, string &, string &);

class Deck {
  int _id;
  int _points;
  vector<int> _liste;

public:
  /* Deck()
   * Constructeur de la classe Deck. Permet à l'utilisateur de donner des 
   * valeurs aux attributs privés de la classe.
   *
   * Entrée : int un id de de Deck, int un nombre de point du Deck 
   * et vector<int> une pile/liste de Cartes qui repose sur la reserve comme pour
   * les joueurs.
   */
  Deck(int, int, const vector<int> &);

  int getPoints();
  int getId();
  vector<int> getListe();

  void AfficheDeck()const;

  void deckAlea();

  vector<Deck>GenererDeck(int);

  void Combat(Deck & , int);

  void changeDeck(vector<int> newDeck);

};

void TousCombats(vector<Deck> &, int);
int MaxPointDeck(vector<Deck> & );
vector<Deck> DecksMaxPoints(vector<Deck> & );
Deck Recursiv(vector<Deck> & , int, int, int);
Jeu initialisationDePartieIA(string &, int);

#endif


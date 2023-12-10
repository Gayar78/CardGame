#ifndef JOUEUR_H_
#define JOUEUR_H_
#include "carte.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Joueur {
  string _nom;
  int _prestige;
  vector<int> _pileCarte;

public:
  /* Joueur()
   * Constructeur de la classe Joueur, remplit le nom, le prestige, et la pile
   * de cartes avec des valeurs par défaut
   */
  Joueur();

  /* Joueur()
   * Constructeur de la classe Joueur, qui permet à l'utilisateur de remplir ses
   * paramètres
   *
   * Entrée : chaîne de caractères (nom), int (prestige), vector<int> (pile de
   * cartes)
   */
  Joueur(const string &, int, const vector<int> &);
  /* getPrestige()
   * Renvoie la valeur de prestige du Joueur actuel
   *
   * Entrée : aucune
   * Sortie : entier, prestige du joueur actuel
   */
  int getPrestige() const;

  /*
   * getTaillePile()
   * renvoie la taille de la pile de cartes du joueur actuel
   *
   * Entrée : aucune
   * Sortie : entier, taille de la pile du joueur actuel
   */
  int getTaillePile() const;

  //retourne la pile complette du joueur en question
  vector<int> getPile()const;

  /*sonNom()
   * Affiche le nom du joueur actuel ainsi que son nombre de points de prestige.
   *
   * Entrée : aucune
   * Sortie : aucune
   */
  void sonNom() const;

  /* afficheStatJ()
   * Affiche le nom du joueur actuel ainsi que son nombre de points de prestige,
   * et le nombre de cartes restantes dans sa pile
   *
   * Entrée : aucune
   * Sortie : aucune
   */
  void afficheStatJ() const;

  /* InitialiseDeck()
   * Affiche la réserve de cartes du joueur actuel et lui demande la nouvelle
   * position de chaque carte.
   *
   * Entrée : aucune
   * Sortie : aucune
   */
  void initialiseDeck();

  /* estCeQueVieCarte()
   * Teste si le joueur actuel a encore des points de prestige ou encore des
   * cartes. Renvoie vrai si le joueur a encore des cartes et des points de
   * prestige, faux sinon
   *
   * Entrée : aucune
   * Sortie : booléen, valeur de l'état du joueur actuel
   */
  bool estCeQueVieCarte() const;

  /* carteSuiv()
   * Affiche la carte suivante dans la pile de carte du joueur actuel. Renvoie
   * une erreur si cela est impossible
   *
   * Entrée : Carte actuelle jouée par le joueur
   * Sortie : aucune
   */
  void carteSuiv(Carte &);

  /* carteSuivIA()
   * Renvoie
   * une erreur si la carte suivante dans la pile de carte du joueur n'existe
   * pas
   *
   * Entrée : Carte actuelle jouée par le joueur
   * Sortie : aucune
   */
  void carteSuivIA(Carte &c);

  /* jouentUneCarte()
   * N'affiche rien pour garder de la performance
   * Fait jouer une carte à chaque joueur, calcule les dégats subis par chacuns
   * et change les points de prestige de chaque joueur en conséquence
   *
   * Entrée : Le Joueur avec qui le joueur actuel joue
   * Sortie : aucune
   */
  void jouentUneCarte(Joueur &);

  /* jouentUneCarte()
   * Fait jouer une carte à chaque joueur, calcule les dégats subis par chacuns
   * et change les points de prestige de chaque joueur en conséquence
   * Mais utilise la methode carteSuivIA qui n'affiche rien, pour gagner de la
   * performance
   *
   * Entrée : Le Joueur avec qui le joueur actuel joue
   * Sortie : aucune
   */
  void jouentUneCarteIA(Joueur &);

  /* deckAlea()
   * Génère un deck aléatoire
   *
   * Entrée : aucune
   * Sortie : aucune
   */
  void deckAlea();

  /* AfficheTouteCartes()
   * Affiche toutes les cartes de la pile de cartes du joueur actuel
   *
   * Entrée : aucune
   * Sortie : aucune
   */
  void AfficheTouteCartes() const;

  /* remplirDeck()
   * Remplit le deck du joueur en question en fonction d'un vecteur de vecteur
   * d'entier où les entiers sont trié dans un certain ordre et font référence à
   * la position d'une carte dans la reserve
   *
   * Entrée : vector<vector<int>>&
   * Sortie : aucune
   */
  void remplirDeck(vector<vector<int>> &);
};
/* afficheReserv()
 * Affiche la réserve de cartes d'un joueur du jeu actuel
 *
 * Entrée : vector<Carte> la réserve du joueur
 * Sortie : aucune
 */
void afficheReserv(const vector<Carte> & = reserve);

#endif

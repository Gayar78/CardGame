#ifndef CARTE_H_
#define CARTE_H_
#include <iostream>
#include <string>
#include <vector>
#include "jeu.h"
#include "joueur.h"

using namespace std;

class Carte {
  string _nom;
  int _attaque;
  int _defense;
  int _magie;

public:
  /* Carte();
   * Constructeur de la classe Carte, donne des valeurs de base
   */
  Carte();

  /* Carte()
   * Constructeur de la classe Carte, peut être rempli par l'utilisateur.
   *
   *Entrée : chaîne de caractère (nom), entier (attaque), entier (défense),
   *entier (magie)
   */
  Carte(const string &, int, int, int);

  /* affichageL()
   * Affichage long de la carte actuelle.
   *
   * Entrée: un flux de sortie (ostream) pour l'affichage des données de la
   * carte Sortie: aucune
   */
  void affichageL(ostream &out = cout) const;

  /* affichageC()
   * affichage court de la carte actuelle, sur une seule ligne.
   *
   * Entrée: un flux de sortie (ostream) pour l'affichage des données de la
   * carte Sortie: aucune
   */
  void affichageC(ostream & = cout) const;

  /* degatPhysiques()
   * calcule les dégats physiques d'une attaque.
   * Renvoie une valeur négative si le joueur1 prend les dégats, positive sinon.
   *
   * Entrée: Une carte, celle du joueur 2
   * Sortie: un entier, la valeur des dégats.
   */
  int degatPhysique(const Carte &) const;

  /* degatMagique()
   * calcule les dégats magiques d'une attaque.
   * Renvoie une valeur négative si le joueur1 prend les dégats, positive sinon.
   *
   * Entrée: une carte, celle du joueur 2
   * Sortie: un entier, la valeur des dégats.
   */
  int degatMagique(const Carte &) const;

  /*operator +
   * opérateur qui applique degatPhysiques aux deux cartes qui le concernent.
   */
  int operator+(const Carte &) const;

  /* operator *
   * opérateur qui applique degatMagique aux deux cartes qui le concernent.
   */
  int operator*(const Carte &) const;

  /* remplir()
   * Remplit une carte avec les valeurs données sur un string.
   *
   * Entrée : une ligne de texte, correspondant aux données d'une carte
   * Sortie : aucune
   */
  void remplir(const string &ligne);

  /* getName();
   * Renvoie le nom de la carte actuelle.
   *
   * Entrée : aucune
   * Sortie : une chaîne de caractères qui correspond au nom de la carte.
   */
  string getName() const;

/* getAttaque();
   * Renvoie l'attaque' de la carte actuelle.
   *
   * Entrée : aucune
   * Sortie : un entier qui correspond à l'attaque de la carte.
   */
  int getAttaque() const;

/* getDefense();
   * Renvoie la défense de la carte actuelle.
   *
   * Entrée : aucune
   * Sortie : un entier qui correspond à la défense de la carte
   */
  int getDefense() const;

/* getMagie);
   * Renvoie la puissance magique de la carte actuelle.
   *
   * Entrée : aucune
   * Sortie : un entier qui correspond à la puissance magique de la carte.
   */
  int getMagie() const;

/* score
   * calcule le score d'une carte en faisant la somme entre son attaque, sa défense et sa magie. Est utile à la fonction rangCartesScoreDecroiss.
   *
   * Entrée : aucune
   * Sortie : un entier, le score de la carte
   */
  int score();
};

extern vector<Carte> reserve;

/* operator<<
 * Permet d'afficher les cartes sur un ostream.
 *
 * Entrée : flux de sortie (ostream) pour l'affichage des cartes, carte à
 * afficher. Sortie : aucune.
 */
void operator<<(ostream &, const Carte &);

/* comparerCartes()
 * Compare le nom de deux cartes, après avoir tout mis en minuscules
 *
 * Entrée : deux Cartes, celles que l'on va comparer
 * Sortie : booléen : vrai si le nom de la première carte est "plus petit" que le nom de la seconde
 */
bool comparerCartes(const Carte &, const Carte &);

#endif

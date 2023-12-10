#include "jeu.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Jeu::Jeu() {
  _reserve =
      vector<Carte>{Carte("MainDroite", 1, 0, 0), Carte("MainGauche", 0, 1, 0),
                    Carte("Tête", 1, -2, 0), Carte("Bouche", 1, -1, 2),
                    Carte("Genou", 2, 0, 0)};
  _joueur1 = Joueur();
  _joueur2 = Joueur();
}

Jeu::Jeu(const vector<Carte> &reserve, const Joueur &joueur1,
         const Joueur &joueur2) {
  _reserve = reserve;
  _joueur1 = joueur1;
  _joueur2 = joueur2;
}

Joueur Jeu::getJ1() const { return (_joueur1); }
Joueur Jeu::getJ2() const { return (_joueur2); }

void Jeu::joueEtMetAJour() {
  _joueur1.jouentUneCarte(_joueur2);
  _joueur1.afficheStatJ();
  _joueur2.afficheStatJ();
}

void Jeu::joueEtMetAJourIA() { _joueur1.jouentUneCarteIA(_joueur2); }

bool Jeu::LaPartieEstFinie() const {
  bool test = (_joueur1.estCeQueVieCarte() && _joueur2.estCeQueVieCarte());
  return !test;
}

int Jeu::vainqueurPartie() const {
  int resultatPartie = 0;
  if (LaPartieEstFinie()) {
    if (_joueur1.getPrestige() < _joueur2.getPrestige()) {
      resultatPartie = 1;
    }
    if (_joueur2.getPrestige() < _joueur1.getPrestige()) {
      resultatPartie = -1;
    }
  }
  return resultatPartie;
}

void trierCartes(vector<Carte> &reserve1) {
  sort(reserve1.begin(), reserve1.end(), comparerCartes);
}

void rangCartesAtkCroiss(vector<vector<int>> &reserve1) {
  sort(reserve1.begin(), reserve1.end(),
       [](const vector<int> &donnees1, const vector<int> &donnees2) {
         return donnees1[1] > donnees2[1];
       });
}

void rangCartesAtkDecroiss(vector<vector<int>> &reserve1) {
  sort(reserve1.begin(), reserve1.end(),
       [](const vector<int> &donnees1, const vector<int> &donnees2) {
         return donnees1[1] < donnees2[1];
       });
}

void rangCartesDefCroiss(vector<vector<int>> &reserve1) {
  sort(reserve1.begin(), reserve1.end(),
       [](const vector<int> &donnees1, const vector<int> &donnees2) {
         return donnees1[2] > donnees2[2];
       });
}

void rangCartesDefDecroiss(vector<vector<int>> &reserve1) {
  sort(reserve1.begin(), reserve1.end(),
       [](const vector<int> &donnees1, const vector<int> &donnees2) {
         return donnees1[2] < donnees2[2];
       });
}

void rangCartesMagieCroiss(vector<vector<int>> &reserve1) {
  sort(reserve1.begin(), reserve1.end(),
       [](const vector<int> &donnees1, const vector<int> &donnees2) {
         return donnees1[3] > donnees2[3];
       });
}

void rangCartesMagieDecroiss(vector<vector<int>> &reserve1) {
  sort(reserve1.begin(), reserve1.end(),
       [](const vector<int> &donnees1, const vector<int> &donnees2) {
         return donnees1[3] < donnees2[3];
       });
}

void rangCartesDecroiss(vector<vector<int>> &referenceReserve) {
  sort(referenceReserve.begin(), referenceReserve.end(),
       [](const vector<int> &donnees1, const vector<int> &donnees2) {
         if (donnees1[1] != donnees2[1]) {
           return donnees1[1] < donnees2[1];
         } else if (donnees1[3] != donnees2[3]) {
           return donnees1[3] < donnees2[3];
         } else {
           return donnees1[2] < donnees2[2];
         }
       });
}

void remplir() { // ne surtout pas toucher
  ifstream input("cartes.txt");
  if (input.is_open()) {
    string ligne;
    while (getline(input, ligne)) {
      Carte carte;
      carte.remplir(ligne);
      reserve.push_back(carte);
    }
  }
  input.close();
  trierCartes(reserve);
}

bool search(vector<int> &vec, int value) {
  // Parcours du vecteur pour vérifier si l'entier "value" y est présent
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == value) {
      // L'entier "value" a été trouvé dans le vecteur, on renvoie true
      return true;
    }
  }

  // L'entier "value" n'a pas été trouvé dans le vecteur, on renvoie false
  return false;
}

Jeu initialisationDePartie1V1(int Prestige, string &nom1, string &nom2) {
  vector<vector<int>> referenceReserve(reserve.size(), {0, 0, 0, 0});
  int reponse;
  cout << "Initialisation des pseudos de chaque joueur:" << endl;
  cout << "Comment veut se nommer le premier joueur ?" << endl;
  cin >> nom1;
  cout << "Comment veut se nommer le second joueur ?" << endl;
  cin >> nom2;
  Joueur J1(nom1, Prestige, {}); // on initialise les joueur ici pour
                                 // avoir directement un joueur qui
  Joueur J2(nom2, Prestige,
            {}); // possède son nombre de points de prestige et son nom
  cout << "\n################################\n" << endl;
  cout << "Voici le blazon de chaque joueur:" << endl;
  J1.sonNom();
  J2.sonNom();
  cout << "\n################################\n" << endl;
  cout << "Initialisation des decks :" << endl;
  for (int i = 0; i < reserve.size(); i++) {
    referenceReserve[i][0] = i;
    referenceReserve[i][1] = reserve[i].getAttaque();
    referenceReserve[i][2] = reserve[i].getDefense();
    referenceReserve[i][3] = reserve[i].getMagie();
  }
  do {
    cout << nom1
         << " ! \nVoulez vous un deck: \n(1) Aléatoire, \n(2) Fait main,\n(3) "
            "Rangé par ordre croissant d'attaque (carte la plus faible au "
            "début),\n(4) Rangé par ordre décroissant d'attaque (carte la plus "
            "forte au début),\n(5) Rangé par ordre croissant de défense,\n(6) "
            "Rangé par ordre décroissant de défense,\n(7) Rangé par ordre "
            "croissant de Magie,\n(8) Rangé par ordre décroissant de "
            "Magie\n(9) Rangé par ordre décroissant d'attaque, puis de magie, "
            "puis de défense"
         << endl;
    cin >> reponse;
  } while (not(reponse == 1 || reponse == 2 || reponse == 3 || reponse == 4 ||
               reponse == 5 || reponse == 6 || reponse == 7 || reponse == 8 ||
               reponse == 9));
  switch (reponse) {
  case 1:
    J1.deckAlea();
    break;
  case 2:
    afficheReserv(reserve);
    J1.initialiseDeck();
    break;
  case 3:
    rangCartesAtkCroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  case 4:
    rangCartesAtkDecroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  case 5:
    rangCartesDefCroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  case 6:
    rangCartesDefDecroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  case 7:
    rangCartesMagieCroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  case 8:
    rangCartesMagieDecroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  case 9:
    rangCartesDecroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  }

  cout << "\n################################\n" << endl;
  do {
    cout << nom2
         << " ! \nVoulez vous un deck: \n(1) Aléatoire, \n(2) Fait main,\n(3) "
            "Rangé par ordre croissant d'attaque (carte la plus faible au "
            "début),\n(4) Rangé par ordre décroissant d'attaque (carte la plus "
            "forte au début),\n(5) Rangé par ordre croissant de défense,\n(6) "
            "Rangé par ordre décroissant de défense,\n(7) Rangé par ordre "
            "croissant de Magie,\n(8) Rangé par ordre décroissant de "
            "Magie\n(9) Rangé par ordre décroissant d'attaque, puis de magie, "
            "puis de défense"
         << endl;
    cin >> reponse;
  } while (not(reponse == 1 || reponse == 2 || reponse == 3 || reponse == 4 ||
               reponse == 5 || reponse == 6 || reponse == 7 || reponse == 8 ||
               reponse == 9));
  switch (reponse) {
  case 1:
    J2.deckAlea();
    J2.AfficheTouteCartes();
    break;
  case 2:
    afficheReserv(reserve);
    J2.initialiseDeck();
    break;
  case 3:
    rangCartesAtkCroiss(referenceReserve);
    J2.remplirDeck(referenceReserve);
    break;
  case 4:
    rangCartesAtkDecroiss(referenceReserve);
    J2.remplirDeck(referenceReserve);
    break;
  case 5:
    rangCartesDefCroiss(referenceReserve);
    J2.remplirDeck(referenceReserve);
    break;
  case 6:
    rangCartesDefDecroiss(referenceReserve);
    J2.remplirDeck(referenceReserve);
    break;
  case 7:
    rangCartesMagieCroiss(referenceReserve);
    J2.remplirDeck(referenceReserve);
    break;
  case 8:
    rangCartesMagieDecroiss(referenceReserve);
    J2.remplirDeck(referenceReserve);
    break;
  case 9:
    rangCartesDecroiss(referenceReserve);
    J2.remplirDeck(referenceReserve);
    break;
  }
  cout << "\n################################\n" << endl;
  return Jeu(reserve, J1, J2);
}

//#########################################################

// Avant de commancer, je tien à rappelr que touts ces fonctions auront surement
// besoin des fonctions créées préalablement

// Classe Deck
// int _id
// int _points
// vector<int> _liste

Deck::Deck(int id, int points, const vector<int> &liste) {
  _id = id;
  _points = points;
  _liste = liste;
}

int Deck::getPoints() { return (_points); }

int Deck::getId() { return (_id); }

vector<int> Deck::getListe() { return (_liste); }

void Deck::AfficheDeck() const {
  cout << "[";
  for (int i = 0; i < _liste.size() - 1; i++) {
    cout << _liste[i] << ", ";
  }
  cout << _liste[_liste.size() - 1] << "]" << endl;
}

void Deck::deckAlea() {
  _liste = {};
  vector<int> LISTE = {};
  for (int i = 0; i < reserve.size(); i++) {
    _liste.push_back(i);
  }
  random_shuffle(_liste.begin(), _liste.end());
  for (int j = 0; j < 20; j++) {
    LISTE.push_back(_liste[j]);
  }
  _liste = LISTE;
}

void Deck::changeDeck(vector<int> newDeck) { _liste = newDeck; }

// vector<Deck> GenererDeck(int n);
// génère n Deck tous différents les uns des autre
vector<Deck> GenererDeck(int nombre) {
  vector<vector<int>> referenceReserve(reserve.size(), {0, 0, 0, 0});
  for (int i = 0; i < reserve.size(); i++) {
    referenceReserve[i][0] = i;
    referenceReserve[i][1] = reserve[i].getAttaque();
    referenceReserve[i][2] = reserve[i].getDefense();
    referenceReserve[i][3] = reserve[i].getMagie();
  }
  Joueur J1("tempo", 1, {});
  vector<Deck> decks;
  int i;
  for (i = 0; i < nombre; i++) {
    int id = i;
    int points = 0;
    Deck Dn(id, points, {});
    Dn.deckAlea();
    decks.push_back(Dn);
  }
  rangCartesDecroiss(referenceReserve);
  J1.remplirDeck(referenceReserve);
  Deck Dm(i + 1, 0, J1.getPile());
  decks.push_back(Dm);
  return decks;
}

// void Combat(Deck & D1, Deck & D2);
// Joueur j1("nomj1",prestigeDefinis, D1._liste)
// Joueur j2("nomj2",prestigeDefinis, D2._liste)
// Jeu J(reserve, j1, j2)

void Deck::Combat(Deck &D2, int prestigeDefinis) {
  Joueur j1("nomj1", prestigeDefinis, _liste);
  Joueur j2("nomj2", prestigeDefinis, D2._liste);
  Jeu Jeu(reserve, j1, j2);
  do { // déroulement de la partie
    Jeu.joueEtMetAJourIA();
  } while (Jeu.LaPartieEstFinie() == false);
  int vainqueur = Jeu.vainqueurPartie();
  switch (vainqueur) {
  case -1:
    _points += 1;
    break;
  case 1:
    D2._points += 1;
    break;
  }
}

// void TousCombats(vector<Deck> &, prestigeDefinis);
// Tous les Deck affrontent tous les Deck en utilisant :
// Combat(Deck &, Deck &, int prestigeDefinis)
// Exemple: TousCombat({D1, D2, D3, D4}, 30)
// Combat(D1, D2)
// Combat(D1, D3)
// Combat(D1, D4)            //Ici chaque Deck a disputé 3 combats
// Combat(D2, D3)            //Les points des Deck ont augmenté selon l'issue
// Combat(D2, D4)            //de chaque Combat
// Combat(D3, D4)            //ici D1 n'est qu'une représentation de (1,_points,
// _liste)
void TousCombats(vector<Deck> &decks, int prestigeDefinis) {
  for (int i = 0; i < decks.size(); i++) {
    for (int j = i + 1; j < decks.size(); j++) {
      decks[i].Combat(decks[j], prestigeDefinis);
    }
  }
}

// int MaxPointDeck(vector<Deck> &);
// On cherche le nombre Maximum de points que peut posséder un Deck
// C'est une recherche de brute parmis tous les _points de tous les Deck
int MaxPointDeck(vector<Deck> &L) {
  int Pmax = L[0].getPoints();
  int compteur = 0;
  int attend;
  while (compteur < L.size()) {
    if (Pmax < L[compteur].getPoints()) {
      Pmax = L[compteur].getPoints();
    }
    compteur += 1;
  }
  return (Pmax);
}

// vector<Deck> DecksMaxPoin(vector<Deck> & decks);
// On cré un vector<Deck> qui stoque tous les Deck qui ont un nombre de point
// égale au Max de point qu'on a trouvé juste avant
vector<Deck> DecksMaxPoints(vector<Deck> &decks) {
  int maxPoints = MaxPointDeck(decks);
  vector<Deck> maxDecks = {};
  for (int i = 0; i < decks.size(); i++) {
    if (decks[i].getPoints() == maxPoints) {
      maxDecks.push_back(decks[i]);
    }
  }
  return maxDecks;
}

/*
On pourrait se faire affronter tous ces Deck pour connaitres les plus forts des
plus forts. Mais cela serait peut être un peu long pour un PC comme ceux que
nous avons à disposition.
*/

Deck Recursiv(vector<Deck> &decks, int prestigeDefinis, int sizeNew,
              int sizeOld) {
  TousCombats(decks, prestigeDefinis);
  decks = DecksMaxPoints(decks);
  if (sizeNew == sizeOld) {
    return (decks[0]);
  } else {
    Recursiv(decks, prestigeDefinis, decks.size(), sizeNew);
  }
  return (decks[0]);
}

// On prend donc la liste du premier deck au nombre de points égale au max :
// Et on l'attribut à la valeur du deck de notre Joueur IA("IA",
// prestigeDefinis, {})

Jeu initialisationDePartieIA(string &nom, int Prestige) {
  vector<vector<int>> referenceReserve(reserve.size(), {0, 0, 0, 0});
  int reponse;
  cout << "Initialisation du pseudo !" << endl;
  cout << "Comment voulez vous vous nommer ?" << endl;
  cin >> nom;
  cout << "\n################################\n" << endl;
  Joueur J1(nom, Prestige, {});
  cout << "Initialisation du deck :" << endl;
  for (int i = 0; i < reserve.size(); i++) {
    referenceReserve[i][0] = i;
    referenceReserve[i][1] = reserve[i].getAttaque();
    referenceReserve[i][2] = reserve[i].getDefense();
    referenceReserve[i][3] = reserve[i].getMagie();
  }
  do {
    cout << nom
         << " ! \nVoulez vous un deck: \n(1) Aléatoire, \n(2) Fait main,\n(3) "
            "Rangé par ordre croissant d'attaque (carte la plus faible au "
            "début),\n(4) Rangé par ordre décroissant d'attaque (carte la plus "
            "forte au début),\n(5) Rangé par ordre croissant de défense,\n(6) "
            "Rangé par ordre décroissant de défense,\n(7) Rangé par ordre "
            "croissant de Magie,\n(8) Rangé par ordre décroissant de "
            "Magie\n(9) Rangé par ordre décroissant d'attaque, puis de magie, "
            "puis de défense"
         << endl;
    cin >> reponse;
  } while (not(reponse == 1 || reponse == 2 || reponse == 3 || reponse == 4 ||
               reponse == 5 || reponse == 6 || reponse == 7 || reponse == 8 ||
               reponse == 9));
  switch (reponse) {
  case 1:
    J1.deckAlea();
    break;
  case 2:
    afficheReserv(reserve);
    J1.initialiseDeck();
    break;
  case 3:
    rangCartesAtkCroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  case 4:
    rangCartesAtkDecroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  case 5:
    rangCartesDefCroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  case 6:
    rangCartesDefDecroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  case 7:
    rangCartesMagieCroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  case 8:
    rangCartesMagieDecroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  case 9:
    rangCartesDecroiss(referenceReserve);
    J1.remplirDeck(referenceReserve);
    break;
  }

  cout << "\n################################\n" << endl;
  cout << "Quel type d'IA voulez vous affronter ?" << endl;
  do {
    cout << "(1) IA faible, \n(2) IA moyenne, \n(3) IA forte" << endl;
    cin >> reponse;
  } while (not(reponse == 1 || reponse == 2 || reponse == 3));
  cout << "\n################################\n" << endl;
  if (reponse == 1) {
    vector<Deck> decks = GenererDeck(100);
    Joueur J2("IA", Prestige,
              Recursiv(decks, Prestige, decks.size(), 0).getListe());
    Jeu G(reserve, J1, J2);
    return (G);
  }
  if (reponse == 2) {
    cout << "Patientez 30 secondes..." << endl;
    vector<Deck> decks = GenererDeck(1000);
    Joueur J2("IA", Prestige,
              Recursiv(decks, Prestige, decks.size(), 0).getListe());
    Jeu G(reserve, J1, J2);
    return (G);
  }
  if (reponse == 3) {
    cout << "Patientez 2 minute..." << endl;
    vector<Deck> decks = GenererDeck(10000);
    Joueur J2("IA", Prestige,
              Recursiv(decks, Prestige, decks.size(), 0).getListe());
    Jeu G(reserve, J1, J2);
    return (G);
  }
}

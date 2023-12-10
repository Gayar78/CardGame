#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include "jeu.h"


using namespace std;

Joueur::Joueur() {
  _nom = "Yugi";
  _prestige = 25;
  _pileCarte = {1,2,3};
};

Joueur::Joueur(const string &nom, int prestige, const vector<int> &pileCarte) {
  _nom = nom;
  _prestige = prestige;
  _pileCarte = pileCarte;
};

int Joueur::getPrestige() const { return (_prestige); }
int Joueur::getTaillePile() const { return (_pileCarte.size()); }
vector<int> Joueur::getPile()const { return(_pileCarte); }

void Joueur::sonNom() const {
  cout << "______________" << endl;
  cout << "Nom joueur: " << _nom << endl;
  cout << "Points Prestige: " << _prestige << endl;
  cout << "______________" << endl;
};

void Joueur::afficheStatJ() const {
  cout << "Le joueur " << _nom << " a " << _prestige
       << " points de prestige, il reste " << _pileCarte.size()
       << " cartes dans sa pile." << endl;
};

void Joueur::initialiseDeck() {
  int numCarte = 0;
  bool test;
  afficheReserv();
  cout << "Choisissez une carte parmis les cartes présentes dans la réserve en "
          "tappant son numero (0 à "
       << reserve.size() - 1 << " )" << endl;
  for (int i = 0; i < reserve.size(); i++) {
    do {
      cout << "Carte n " << i << " : " << endl;
      cin >> numCarte;
      test = search(_pileCarte, numCarte);
      if (!(numCarte >= 0 && numCarte <= reserve.size() - 1)) {
        cout << "Numero de carte invalide. Veuillez entrer un numero compris "
                "entre 0 et "
             << reserve.size() - 1 << endl;
      } else if (test) {
        cout << "Cette carte a deja ete ajoutee a votre deck. Veuillez entrer "
                "un numero de carte valide."
             << endl;
      }
    } while (!(numCarte >= 0 && numCarte <= reserve.size() - 1) || test);
    _pileCarte.push_back(numCarte);
  }
};

void Joueur::remplirDeck(vector<vector<int>> &reserveDeck) {
  for (int i = reserveDeck.size()-20; i < reserveDeck.size(); i++) {
    _pileCarte.push_back(reserveDeck[i][0]);
  }
}

bool Joueur::estCeQueVieCarte() const {
  bool test = (_prestige <= 0 || _pileCarte.size() <= 0);
  return !(test);
  // si test est faux alors, le joueur n'a plus de carte dans son deck ou est
  // mort. si non, le joueur est encore en vie et a encore des cartes dans son
  // deck.
};

void Joueur::carteSuiv(Carte &c) {
  if (_pileCarte.size() > 0) {
    c = reserve[_pileCarte.back()]; // c = à la carte la plus au dessus du
                                    // packet
    _pileCarte.pop_back();          // on enlève cette carte
    cout << "La carte de " << _nom << " est: ";
    c.affichageC();
  } else {
    throw(_nom);
  }
};

void Joueur::carteSuivIA(Carte &c) {
  if (_pileCarte.size() > 0) {
    c = reserve[_pileCarte.back()]; // c = à la carte la plus au dessus du
                                    // packet
    _pileCarte.pop_back();          // on enlève cette carte
  } else {
    throw(_nom);
  }
};

void Joueur::jouentUneCarte(Joueur &J2) {
  int degPhy = 0;
  int degMag = 0;
  Carte cJ1;
  Carte cJ2;
  try {
    cout<<"---"<<endl;
    carteSuiv(cJ1);
    J2.carteSuiv(cJ2);
    cout<<"---"<<endl;
    degPhy = cJ1.degatPhysique(cJ2);
    degMag = cJ1.degatMagique(cJ2);
    if (estCeQueVieCarte()) {
      if (degPhy >= 0) {
        _prestige -= degPhy;
      } else {
        J2._prestige += degPhy;
      }
      if (degMag >= 0) {
        _prestige -= degMag;
      } else {
        J2._prestige += degMag;
      }
    }
  } catch (const string &e) {
    cerr << "ATTENTION : le joueur " << e << " n'a plus de cartes !" << endl;
  }
};

void Joueur::jouentUneCarteIA(Joueur &J2) {
  int degPhy = 0;
  int degMag = 0;
  Carte cJ1;
  Carte cJ2;
  try {
    carteSuivIA(cJ1);
    J2.carteSuivIA(cJ2);
    degPhy = cJ1.degatPhysique(cJ2);
    degMag = cJ1.degatMagique(cJ2);
    if (estCeQueVieCarte()) {
      if (degPhy >= 0) {
        _prestige -= degPhy;
      } else {
        J2._prestige += degPhy;
      }
      if (degMag >= 0) {
        _prestige -= degMag;
      } else {
        J2._prestige += degMag;
      }
    }
  } catch (const string &e) {
    cerr << "ATTENTION : le joueur " << e << " n'a plus de cartes !" << endl;
  }
};

void Joueur::deckAlea() {
  _pileCarte = {};
  for(int i =0; i<20; i++){
    _pileCarte.push_back(i);
  }
  random_shuffle(_pileCarte.begin(), _pileCarte.end());
  cout << "Le deck a été généré aléatoirement !" << endl;
}

void Joueur::AfficheTouteCartes() const {
  cout<<"[";
  for (int i = 0; i < _pileCarte.size()-1; i++) {
    cout << _pileCarte[i]<<", ";
  }
  cout<<_pileCarte[_pileCarte.size()-1]<<"]"<<endl;
}

// affiche la réserve entrée en paramètre
void afficheReserv(const vector<Carte> &reserve) {
  cout << "Voici toutes les carte que vous pouvez choisir" << endl;
  for (int i = 0; i < reserve.size(); i++) {
    cout << "Carte n" << i << " : " << endl;
    reserve[i].affichageC();
  }
}
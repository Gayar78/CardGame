#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include "jeu.h"

using namespace std;

Carte::Carte() {
  _nom = "Mains nues";
  _attaque = 1;
  _defense = 1;
  _magie = 0;
}

Carte::Carte(const string &nom, int atk, int def, int magie) {
  _nom = nom;
  _attaque = atk;
  _defense = def;
  _magie = magie;
}

void Carte::affichageL(ostream &out) const {
  out << "****************" << endl
      << "nom : " << _nom << endl
      << "Attaque : " << _attaque << endl
      << "Défense : " << _defense << endl
      << "Magie : " << _magie << endl
      << "****************" << endl;
}

void Carte::affichageC(ostream &) const {
  cout << _nom << " [" << _attaque << " ; " << _defense << " ; " << _magie
       << "]" << endl;
}

int Carte::degatPhysique(const Carte &c) const {
  int dmg;
  if (_attaque > c._attaque && _attaque > c._defense) {
    dmg = -(_attaque - c._defense);
  } else if (c._attaque > _attaque && c._attaque > _defense) {
    dmg = abs(c._attaque - _defense);
  } else {
    dmg = 0;
  }
  return (dmg);
}

int Carte::degatMagique(const Carte &c) const {
  int dmg;
  if (c._magie > _magie) {
    dmg = c._magie - _magie;
  } else {
    dmg = -(_magie - c._magie);
  }
  return dmg;
}

int Carte::operator+(const Carte &c) const { return degatPhysique(c); }

int Carte::operator*(const Carte &c) const { return degatMagique(c); }

void operator<<(ostream &os, const Carte &c) { c.affichageC(os); }

void Carte::remplir(const string &ligne) {
  stringstream ss(ligne);
  getline(ss, _nom, ',');
  ss >> _attaque;
  ss.ignore();
  ss >> _defense;
  ss.ignore();
  ss >> _magie;
}

string Carte::getName() const { return (_nom); }
int Carte::getAttaque() const { return (_attaque); }
int Carte::getDefense() const { return (_defense); }
int Carte::getMagie() const { return (_magie); }

int Carte::score(){
  return(_attaque + _defense + _magie);
}

bool comparerCartes(const Carte &Carte1, const Carte &Carte2) {
  string nom1 = "";
  string nom2 = "";
  for (int i = 0; i < Carte1.getName().size(); i++) {
    nom1.push_back(tolower(Carte1.getName()[i]));
  }
  for (int i = 0; i < Carte2.getName().size(); i++) {
    nom2.push_back(tolower(Carte2.getName()[i]));
  }
  return (nom1 < nom2);
}

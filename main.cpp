//#define TESTING
#include "jeu.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<Carte> reserve;

#ifdef TESTING
int main() {
  try {
    int TestCarte = 0;
    int TestJoueur = 0;
    int TestJeu = 0;
    // Voici tous les test de méthode que nous avons pu faire pour toutes nos
    // methode et méthodes Relatives à la class Carte
    Carte ct1;
    Carte ct2("trinité", 10, 10, 10);
    cout << "\n---------------------    Carte    ------------------------\n"
         << endl;
    if (ct1.getName() == "Mains nues") {
      cout << " *** La méthode getName() fontionne                      OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** La méthode getName() ne fontionne pas               ERR "
           << endl;
    }

    if (ct2.getAttaque() == 10) {
      cout << " *** La méthode getAttaque() fontionne                   OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** La méthode getAttaque() ne fontionne pas            ERR "
           << endl;
    }

    if (ct2.getDefense() == 10) {
      cout << " *** La méthode getDefense() fontionne                   OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** La méthode getDefense() ne fontionne pas            ERR "
           << endl;
    }

    if (ct1.getMagie() == 0) {
      cout << " *** La méthode getMagie() fontionne                     OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** La méthode getMagie() ne fontionne pas              ERR "
           << endl;
    }

    if (ct1.getName() == "Mains nues" && ct1.getAttaque() == 1 &&
        ct1.getMagie() == 0 && ct1.getDefense() == 1) {
      cout << " *** L'initialisateur de Carte de base fontionne         OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** L'initialisateur de Carte de base ne fontionne pas  ERR "
           << endl;
    }

    if (ct2.getName() == "trinité" && ct2.getAttaque() == 10 &&
        ct2.getMagie() == 10 && ct2.getDefense() == 10) {
      cout << " *** L'initialisateur de Carte personnalisable fontionne OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** L'initialisateur de Carte personnalisable ne fontionne "
              "pas ERR "
           << endl;
    }

    if (ct2.degatPhysique(ct1) == -9) {
      cout << " *** Le calcul des dégats physiques fontionne            OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** Erreur dans le calcul des dégats physiques          ERR "
           << endl;
    }
    if (ct2.degatMagique(ct1) == -10) {
      cout << " *** Le calcul des dégats magiques fontionne             OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** Erreur dans le calcul des dégats magiques           ERR "
           << endl;
    }
    if (ct2 + ct1 == -9) {
      cout << " *** L'opérateur + pour les dégats physiques fontionne   OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** L'opérateur + pour les dégats physiques ne fontionne pas "
              "ERR "
           << endl;
    }
    if (ct2 * ct1 == -10) {
      cout << " *** L'opérateur * pour les dégats magiques fontionne    OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** L'opérateur * pour les dégats magiques fontionne    ERR "
           << endl;
    }
    ct1.remplir("mini trinité,5,5,5");
    if (ct1.getName() == "mini trinité" && ct1.getAttaque() == 5 &&
        ct1.getDefense() == 5 && ct1.getMagie() == 5) {
      cout << " *** La fonction remplir() fontionne                     OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** La fonction remplir() ne fontionne pas              ERR "
           << endl;
    }

    if (ct2.score() == 30) {
      cout << " *** La méthode score() fontionne                        OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** La méthode score() ne fontionne pas                 ERR "
           << endl;
    }
    void operator<<(ostream &, const Carte &);

    if (comparerCartes(ct1, ct2) == true) {
      cout << " *** La méthode comparerCartes() fontionne               OK "
           << endl;
      TestCarte += 1;
    } else {
      cout << " *** La méthode comparerCartes() ne fontionne pas        ERR "
           << endl;
    }
    cout << "\nTOTAL TEST CORRECTE : " << TestCarte << "/13" << endl;

    // Fin test Carte
    cout << "\n---------------------    Joueur    ------------------------\n"
         << endl;
    // Voici tous les tests de méthodes que nous avons pu faire pour toutes nos
    // fonctions et méthodes Relatives à la classe Joueur
    remplir();
    Carte ct3("trinité double", 20, 20, 20);
    Joueur jt1;
    Joueur jt2("Darius", 30, {1, 2, 3});
    if (jt1.getPrestige() == 25) {
      cout << " *** La méthode getPrestige() fontionne                  OK "
           << endl;
      TestJoueur += 1;
    } else {
      cout << " *** La méthode getPrestige() ne fontionne pas           ERR "
           << endl;
    }

    if (jt1.getTaillePile() == 3) {
      cout << " *** La méthode getTaillePile() fontionne                OK "
           << endl;
      TestJoueur += 1;
    } else {
      cout << " *** La méthode getTaillePile() ne fontionne pas         ERR "
           << endl;
    }

    if (jt1.estCeQueVieCarte() == 1) {
      cout << " *** La méthode estCeQueVieCarte() fontionne             OK "
           << endl;
      TestJoueur += 1;
    } else {
      cout << " *** La méthode estCeQueVieCarte() ne fontionne pas      ERR "
           << endl;
    }

    if (jt1.getPrestige() == 25 && jt1.getTaillePile() == 3 &&
        jt1.estCeQueVieCarte() == 1) {
      cout << " *** L'initialisation de Joueur de base fontionne        OK "
           << endl;
      TestJoueur += 1;
    } else {
      cout << " *** L'initialisation de Joueur de base ne fontionne pas ERR "
           << endl;
    }

    if (jt2.getPrestige() == 30 && jt2.getTaillePile() == 3 &&
        jt2.estCeQueVieCarte() == 1) {
      cout << " *** L'initialisation de Joueur personalisable fontionne OK "
           << endl;
      TestJoueur += 1;
    } else {
      cout << " *** L'initialisation de Joueur personalisable ne fontionne pas "
              "ERR "
           << endl;
    }

    jt2.carteSuiv(ct3);
    if (ct3.getName() == reserve[3].getName() &&
        ct3.getAttaque() == reserve[3].getAttaque() &&
        ct3.getDefense() == reserve[3].getDefense() &&
        ct3.getMagie() == reserve[3].getMagie()) {
      cout << " *** La méthode carteSuiv() fontionne                    OK "
           << endl;
      TestJoueur += 1;
    } else {
      cout << " *** La méthode CarteSuiv() ne fontionne pas             ERR "
           << endl;
    }
    jt1.deckAlea();
    if (jt1.getTaillePile() == 20) {
      cout << " *** La méthode deckAlea() fontionne                     OK "
           << endl;
      TestJoueur += 1;
    } else {
      cout << " *** La méthode deckAlea() ne fontionne pas              ERR "
           << endl;
    }

    vector<vector<int>> referenceReserve;
    for (int i = 0; i < reserve.size(); i++) {
      referenceReserve[i][0] = i;
      referenceReserve[i][1] = reserve[i].getAttaque();
      referenceReserve[i][2] = reserve[i].getDefense();
      referenceReserve[i][3] = reserve[i].getMagie();
    }
    jt1.remplirDeck(referenceReserve);
    if (jt1.getTaillePile() == 20) {
      cout << " *** La méthode remplirDeck() fontionne                  OK "
           << endl;
      TestJoueur += 1;
    } else {
      cout << " *** La méthode remplirDeck() ne fontionne pas           ERR "
           << endl;
    }
    jt1.jouentUneCarte(jt2);
    if (jt1.getTaillePile() == 19) {
      cout << " *** La méthode jouentUneCarte() fontionne               OK "
           << endl;
      TestJoueur += 1;
    } else {
      cout << " *** La méthode jouentUneCarte() ne fontionne pas        ERR "
           << endl;
    }
    cout << "\nTOTAL TEST CORRECTE : " << TestJoueur << "/9" << endl;
    // Fin test Joueur
    cout << "\n----------------------    Jeu    -------------------------\n"
         << endl;
    // Voici tous les tests de méthodes que nous avons pu faire pour toutes nos
    // fonctions et méthodes Relatives à la classe Jeu

    Jeu JT1;
    Jeu JT2(reserve, jt1, jt2);
    if (JT1.getJ1().getPrestige() == 25 && JT1.getJ2().getPrestige() == 25) {
      cout << " *** La méthode getJ1() fontionne                        OK "
           << endl;
      TestJeu += 1;
    } else {
      cout << " *** La méthode getJ1() ne fontionne pas                 ERR "
           << endl;
    }
    if (JT1.getJ1().getPrestige() == 25 && JT1.getJ2().getPrestige() == 25 &&
        JT1.getJ1().getTaillePile() == 3 && JT1.getJ2().getTaillePile() == 3) {
      cout << " *** L'initialisateur de Jeu de base fontionne           OK "
           << endl;
      TestJeu += 1;
    } else {
      cout << " *** L'initialisateur de Jeu de base ne fontionne pas    ERR "
           << endl;
    }
    if (JT2.getJ1().getPrestige() == 25 && JT2.getJ2().getPrestige() == 30 &&
        JT2.getJ1().getTaillePile() == 19 && JT2.getJ2().getTaillePile() == 1) {
      cout << " *** L'initialisateur de Jeu personalisable fontionne    OK "
           << endl;
      TestJeu += 1;
    } else {
      cout
          << " *** L'initialisateur de Jeu personalisable ne fontionne pas ERR "
          << endl;
    }
    JT1.joueEtMetAJour();
    if (JT1.getJ1().getPrestige() == 25 && JT1.getJ2().getPrestige() &&
        JT1.getJ1().getTaillePile() == 2 && JT1.getJ2().getTaillePile() == 2) {
      cout << " *** La méthode joueEtMetAJour() fontionne               OK "
           << endl;
      TestJeu += 1;
    } else {
      cout << " *** La méthode joueEtMetAJour() ne fontionne pas        ERR "
           << endl;
    }
    JT2.joueEtMetAJour();
    if (JT2.LaPartieEstFinie() == 1) {
      cout << "*** La méthode LaPartieEstFinie() fontionne              OK "
           << endl;
      TestJeu += 1;
    } else {
      cout << "*** La méthode LaPartieEstFinie() ne fontionne pas       ERR "
           << endl;
    }
    Joueur jt4("Diana", 0, {});
    Joueur jt5("Warwick", 25, {});
    Jeu JT3(reserve, jt4, jt5);
    Jeu JT4(reserve, jt5, jt4);
    Jeu JT5(reserve, jt4, jt4);
    if (JT3.vainqueurPartie() == 1 && JT4.vainqueurPartie() == -1 &&
        JT5.vainqueurPartie() == 0) {
      cout << "*** La méthode vainqueurPartie() fontionne               OK "
           << endl;
      TestJeu += 1;
    } else {
      cout << "*** La méthode vainqueurPartie() ne fontionne pas        ERR "
           << endl;
    }
    vector<Carte> reserve2 = {
        Carte("dague", 4, 0, 0),          Carte("émeraude", 0, -1, 2),
        Carte("couteau", 2, 0, 0),        Carte("parchemin", -1, -1, 5),
        Carte("planche", 0, 3, 0),        Carte("esquive", 0, 4, 2),
        Carte("rondache", 0, 6, 0),       Carte("couronne", -99, 1, 4),
        Carte("diademe", -99, 0, 5),      Carte("armure", 0, 7, 0),
        Carte("ange_gardien", 0, 99, -5), Carte("lame_infini", 10, -4, -3),
        Carte("rabadon", -3, -3, 10),     Carte("baton", 1, 1, 3),
        Carte("epee", 5, 1, 0),           Carte("arc", 4, -1, 0),
        Carte("lyandri", 0, -2, 8),       Carte("lance", 7, 0, 0),
        Carte("bouclier", 0, 5, 0),       Carte("couvercle", 0, 2, 0),
        Carte("cuillere", 2, 0, 0),       Carte("Silmaril", -2, -2, 9),
        Carte("zonia", 0, 0, 5),          Carte("gourdin", 4, 1, 0),
        Carte("excalibur", 6, 0, 3)};
    vector<Carte> triAlpha = {
        Carte("ange_gardien", 0, 99, -5), Carte("arc", 4, -1, 0),
        Carte("armure", 0, 7, 0),         Carte("baton", 1, 1, 3),
        Carte("bouclier", 0, 5, 0),       Carte("couronne", -99, 1, 4),
        Carte("couteau", 2, 0, 0),        Carte("couvercle", 0, 2, 0),
        Carte("cuillere", 2, 0, 0),       Carte("dague", 4, 0, 0),
        Carte("diademe", -99, 0, 5),      Carte("epee", 5, 1, 0),
        Carte("esquive", 0, 4, 2),        Carte("excalibur", 6, 0, 3),
        Carte("gourdin", 4, 1, 0),        Carte("lame_infini", 10, -4, -3),
        Carte("lance", 7, 0, 0),          Carte("lyandri", 0, -2, 8),
        Carte("parchemin", -1, -1, 5),    Carte("planche", 0, 3, 0),
        Carte("rabadon", -3, -3, 10),     Carte("rondache", 0, 6, 0),
        Carte("Silmaril", -2, -2, 9),     Carte("zonia", 0, 0, 5),
        Carte("émeraude", 0, -1, 2)};
    bool test = true;
    trierCartes(reserve2);
    for (int i = 0; i < reserve2.size(); i++) {
      if (reserve2[i].getName() != triAlpha[i].getName()) {
        test = false;
      }
    }
    if (test == true) {
      cout << "***La méthode trierCartes fonctionne                     OK"
           << endl;
      TestJeu += 1;
    } else {
      cout << "*** La méthode trierCartes ne fonctionne pas      ERR" << endl;
    }

    vector<int> ordreAtkCr = {15, 16, 13, 11, 1, 9, 14, 6,  8,  3,  24, 0, 23,
                              21, 19, 17, 12, 7, 4, 2,  18, 22, 20, 10, 5};
    bool test2 = true;
    rangCartesAtkCroiss(referenceReserve);
    for (int i = 0; i < referenceReserve.size(); i++) {
      if (referenceReserve[i][0] != ordreAtkCr[i]) {
        test2 = false;
      }
    }
    if (test2 == true) {
      cout << "***La méthode rangCartesAtkCroiss fonctionne             OK"
           << endl;
      TestJeu += 1;
    } else {
      cout << "***La méthode rangCartesAtkCroiss ne fonctionne pas       ERR"
           << endl;
    }
    vector<int> ordreAtkDecr = {5, 10, 20, 22, 18, 12, 24, 13, 21, 19, 17, 0, 7,
                                4, 2,  3,  8,  6,  14, 9,  1,  11, 13, 16, 15};
    bool test3 = true;
    rangCartesAtkDecroiss(referenceReserve);
    for (int i = 0; i < referenceReserve.size(); i++) {
      if (referenceReserve[i][0] != ordreAtkDecr[i]) {
        test3 = false;
      }
    }
    if (test3 == true) {
      cout << "***La méthode rangCartesAtkDecroiss fonctionne           OK"
           << endl;
      TestJeu += 1;
    } else {
      cout << "***La méthode rangCartesAtkDecroiss ne fonctionne pas       ERR"
           << endl;
    }

    vector<int> ordreDefCr = {0, 2,  21, 4,  12, 19, 7,  11, 5,  14, 3,  6, 8,
                              9, 10, 13, 23, 16, 24, 18, 1,  17, 22, 20, 15};
    bool test4 = true;
    rangCartesDefCroiss(referenceReserve);
    for (int i = 0; i < referenceReserve.size(); i++) {
      if (referenceReserve[i][0] != ordreDefCr[i]) {
        test4 = false;
      }
    }
    if (test4 == true) {
      cout << "***La méthode rangCartesDefCroiss fonctionne             OK"
           << endl;
      TestJeu += 1;
    } else {
      cout << "***La méthode rangCartesDefCroiss ne fonctionne pas       ERR"
           << endl;
    }

    vector<int> ordreDefDecr = {15, 20, 22, 17, 1,  24, 18, 8, 23,
                                16, 6,  13, 10, 9,  11, 14, 5, 3,
                                7,  19, 12, 4,  21, 2,  0};
    bool test5 = true;
    rangCartesDefCroiss(referenceReserve);
    for (int i = 0; i < referenceReserve.size(); i++) {
      if (referenceReserve[i][0] != ordreDefDecr[i]) {
        test5 = false;
      }
    }
    if (test5 == true) {
      cout << "***La méthode rangCartesDefDecroiss fonctionne           OK"
           << endl;
      TestJeu += 1;
    } else {
      cout << "***La méthode rangCartesDefDecroiss ne fonctionne pas       ERR"
           << endl;
    }

    vector<int> ordreMagieCr = {20, 22, 17, 23, 18, 10, 5, 3, 13,
                                12, 24, 11, 9,  14, 16, 8, 7, 19,
                                6,  21, 4,  2,  1,  15, 0};
    bool test6 = true;
    rangCartesDefCroiss(referenceReserve);
    for (int i = 0; i < referenceReserve.size(); i++) {
      if (referenceReserve[i][0] != ordreMagieCr[i]) {
        test6 = false;
      }
    }
    if (test6 == true) {
      cout << "***La méthode rangCartesMagieCroiss fonctionne           OK"
           << endl;
      TestJeu += 1;
    } else {
      cout << "***La méthode rangCartesMagieCroiss ne fonctionne pas       ERR"
           << endl;
    }
    vector<int> ordreMagieDecr = {0, 15, 1,  2,  4,  21, 6,  7,  8,
                                  9, 19, 11, 16, 14, 24, 12, 13, 3,
                                  5, 18, 10, 23, 17, 22, 20};
    bool test7 = true;
    rangCartesDefCroiss(referenceReserve);
    for (int i = 0; i < referenceReserve.size(); i++) {
      if (referenceReserve[i][0] != ordreMagieDecr[i]) {
        test7 = false;
      }
    }
    if (test7 == true) {
      cout << "***La méthode rangCartesMagieDecroiss fonctionne         OK"
           << endl;
      TestJeu += 1;
    } else {
      cout
          << "***La méthode rangCartesMagieDecroiss ne fonctionne pas       ERR"
          << endl;
    }
    vector<int> ordreDecr = {5,  10, 20, 22, 18, 0, 7, 19, 4,  21, 2,  14, 12,
                             23, 17, 3,  8,  6,  1, 9, 14, 11, 13, 16, 15};
    bool test8 = true;
    rangCartesDefCroiss(referenceReserve);
    for (int i = 0; i < referenceReserve.size(); i++) {
      if (referenceReserve[i][0] != ordreDecr[i]) {
        test8 = false;
      }
    }
    if (test8 == true) {
      cout << "***La méthode rangCartesDecroiss fonctionne              OK"
           << endl;
      TestJeu += 1;
    } else {
      cout << "***La méthode rangCartesDecroiss ne fonctionne pas       ERR"
           << endl;
    }

    vector<int> vecT = {1, 6, 4, 8, 3, 5, 79, 2, 5, 68, 41, 36, 87, 2, 9};
    if (search(vecT, 3) == 1 && search(vecT, 10) == 0) {
      cout << "*** La fonction search() fontionne                       OK "
           << endl;
      TestJeu += 1;
    } else {
      cout << "*** La fonction search() ne fontionne pas                ERR "
           << endl;
    }

    cout << "\nTOTAL TEST CORRECTE : " << TestJeu << "/15" << endl;
  } catch (invalid_argument i) {
    // si l'utilisateur ne repond pas correctement, il y a une exeption
    cout << i.what() << endl;
    return 0;
  }
}

#else

int main() { // méthode principal
  try {
    char recommencer;     // charactère clé pour recommencer une partie
    string nom1, nom2;    // initialisation des nom des deux joueurs
    Jeu Jeu;              // initialisation du Jeu
    bool rejouer = false; // booléen clé pour recommencer une partie
    remplir(); // méthode qui remplit la reserve à partir d'un fichier text
    int reponse, generalPrestige; // reponse permettra de connaitre la reponse
                                  // de l'utilisateur
    // generalPrestige permettra de connaitre le nombre de point de prestige
    // durant toute la durée de la méthode principal
    generalPrestige = 25;
    do {   // Demande pour recommencer la partie
      do { // Choix entre deux modes de jeu: (1) IA, (2) 1V1
        cout << "Choisissez un mode de jeu: \n(1) IA, \n(2) 1V1" << endl;
        cin >> reponse;
      } while (not(reponse == 1 || reponse == 2));
      if (reponse == 1) { // mode de jeu IA
        Jeu = initialisationDePartieIA(nom1, generalPrestige);
        cout << "Deck de " << nom1 << " :" << endl;
        Jeu.getJ1().AfficheTouteCartes();
        cout << "\nDeck IA :" << endl;
        Jeu.getJ2().AfficheTouteCartes();
        cout << "\n################################\n" << endl;
      } else if (reponse == 2) { // mode de jeu 1V1
        Jeu = initialisationDePartie1V1(generalPrestige, nom1, nom2);
      }
      do { // déroulement de la partie
        Jeu.joueEtMetAJour();
      } while (Jeu.LaPartieEstFinie() == false);
      int vainqueur = Jeu.vainqueurPartie();
      cout << "\n################################\n" << endl;
      switch (vainqueur) {
      case -1:
        cout << "\nLE  VAINQUEUR EST :" << endl;
        Jeu.getJ1().sonNom();
        break;
      case 1:
        cout << "\nLE  VAINQUEUR EST :" << endl;
        Jeu.getJ2().sonNom();
        break;
      case 0:
        cout << "\nEGALITE ! " << endl;
      }
      //###############################################################
      cout << "\n################################\n" << endl;
      cout << "Voulez-vous rejouer ? \n(O) Oui, \n(N) Non" << endl;
      cin >> recommencer;
      recommencer = tolower(recommencer);
      if (recommencer == 'o') {
        rejouer = true;
        cout << "\n################################\n" << endl;
      } else {
        rejouer = false;
      }
    } while (rejouer);
  } catch (invalid_argument i) {
    // si l'utilisateur ne repond pas correctement, il y a une exeption
    cout << i.what() << endl;
  }
  return 0;
}
#endif

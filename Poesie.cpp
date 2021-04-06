#include "Poesie.h"
#include <iostream>
#include <string>
using namespace std;

Poesie::Poesie() {};
Poesie::Poesie(int code,int numISBN, std::string auteur,std::string titre, std::string editeur, std::string pub, std::string etat,std::string categorie,int code_emprunt, std::string indicateur): Livre (code, numISBN, auteur,titre, editeur, pub, etat, categorie,code_emprunt)
{this-> indicateur=indicateur;}


void Poesie::affiche(){
cout << "code: " << code <<", titre: " << titre << ", etat: " << etat << ", indicateur: " << indicateur <<endl;}




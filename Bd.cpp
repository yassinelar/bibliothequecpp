#include "Bd.h"
#include <iostream>
#include <string>
using namespace std;

Bd::Bd() {};
Bd::Bd(int code,int numISBN, std::string auteur,std::string titre, std::string editeur, std::string pub, std::string etat,std::string categorie,int code_emprunt, std::string dessinateur): Livre (code, numISBN, auteur,titre, editeur, pub, etat, categorie, code_emprunt)
{this-> dessinateur=dessinateur;}


void Bd::affiche(){
cout << "code: " << code <<", titre: " << titre << ", etat: " << etat << ", dessinateur: " << dessinateur <<endl;}




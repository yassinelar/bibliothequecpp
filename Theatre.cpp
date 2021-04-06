#include "Theatre.h"
#include <iostream>
#include <string>
using namespace std;

Theatre::Theatre() {};
Theatre::Theatre(int code,int numISBN, std::string auteur,std::string titre, std::string editeur, std::string pub, std::string etat,std::string categorie,int code_emprunt, int siecle): Livre (code, numISBN, auteur,titre, editeur, pub, etat, categorie, code_emprunt)
{this-> siecle=siecle;}


void Theatre::affiche(){
cout << "code: " << code <<", titre: " << titre << ", etat: " << etat << ", siecle: " << siecle <<endl;}





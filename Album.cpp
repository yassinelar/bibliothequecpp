#include "Album.h"
#include <iostream>
#include <string>
using namespace std;

Album::Album() {};
Album::Album(int code,int numISBN, std::string auteur,std::string titre, std::string editeur, std::string pub, std::string etat,std::string categorie,int code_emprunt, std::string illustration): Livre (code, numISBN, auteur,titre, editeur, pub, etat, categorie, code_emprunt)
{this-> illustration=illustration;}


void Album::affiche(){
cout << "code: " << code <<", titre: " << titre << ", etat: " << etat << ", illustration: " << illustration <<endl;}






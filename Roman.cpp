#include "Roman.h"
#include <iostream>
#include <string>
using namespace std;

Roman::Roman() {};
Roman::Roman(int code,int numISBN, std::string auteur,std::string titre, std::string editeur, std::string pub, std::string etat, std::string categorie,int code_emprunt, std::string genre): Livre (code, numISBN, auteur,titre, editeur, pub, etat, categorie, code_emprunt)
{this-> genre=genre;}


void Roman::affiche(){
cout << "code: " << code <<", titre: " << titre << ", etat: " << etat << ", genre: " << genre <<endl;}





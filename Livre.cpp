#include "Livre.h"
#include "Poesie.h"
#include "Roman.h"
#include "Theatre.h"
#include "Bd.h"
#include "Album.h"

#include <iostream>
#include <string>
using namespace std;

Livre::Livre(){
}
Livre::Livre(int code,const int numISBN, const std::string auteur, const std::string titre,const std::string editeur,const std::string pub, std::string etat, std::string categorie, int code_emprunt)
       {
           this-> code=code;
           this-> auteur=auteur;
           this-> titre=titre;
           this-> editeur=editeur;
           this-> numISBN = numISBN;
           this-> pub=pub;
           this-> etat=etat;
           this-> categorie=categorie;
           this-> code_emprunt=code_emprunt;
       }

void Livre::affiche(){
    cout << "Code livre: "<< numISBN << " Titre: " << titre <<", Etat: " << etat <<", Code emprunt: " << code_emprunt <<endl;}




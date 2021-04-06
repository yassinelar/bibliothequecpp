
#include "Bibliotheque.h"
#include "Livre.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Bibliotheque::Bibliotheque(){};
Bibliotheque::Bibliotheque(std::string nom, std::string adresse, int code, std::vector<Livre> livres)
{
    this-> nom=nom;
    this-> adresse=adresse;
    this-> code=code;
    this-> livres=livres;
};

void Bibliotheque::ajouter_livre(Livre livre)
    {
        livres.push_back(livre);
    }


void Bibliotheque::affiche()
{
    cout<< "Nom de la bibliotheque: " << nom << ", adresse: " << adresse << endl;
}

void Bibliotheque::affiche_livres()
{   cout << nom << endl;
    for (int i=0; i< livres.size(); i++){
        cout << " Livre " << i+1 <<" " ;
        livres[i].affiche();
        cout << endl;
    }
}

void Bibliotheque::supprime_livre(int code)
{
     for (int i=0; i< livres.size(); i++){
        if (code == livres[i].getCode()){
            livres.erase(livres.begin() + i);
            cout<< "Le livre de code "<< code<< " a ete supprime avec succes de la bibliotheque " << nom << endl;
        }
     }
}


Bibliotheque Bibliotheque::demande_livre(int numISBN, Bibliotheque autreBibliotheque)
    {bool exist = false;
    Livre livre;
    int code_trouve;
    int i=0;
    while((exist==false) && (i<= autreBibliotheque.getLivres().size()))
        {
            if((autreBibliotheque.livres[i].getNumisbn()== numISBN) && (autreBibliotheque.livres[i].getEtat()=="Libre"))
                {
                    exist=true;
                    livre= autreBibliotheque.livres[i];
                    code_trouve= livre.getCode();
                    cout << livre.getNumisbn() << endl;
                    livre.setCodeEmprunt(autreBibliotheque.getCode());
                    ajouter_livre(livre);
                    autreBibliotheque.livres[i].setEtat("Prete");
                }
            else
                {
                   i=i+1;
                }
        }
   /* if (exist==true)
        {
            cout << code_trouve << endl;
            livre.setEtat("Emprunte");
            ajouter_livre(livre);

            autreBibliotheque.supprime_livre(code_trouve);
            autreBibliotheque.affiche_livres();
        }*/
    if (exist==false)
        {
            cout<< "le livre n'existe pas dans la bibliotheque " << autreBibliotheque.getNom() << endl;}

    return autreBibliotheque;}


int Bibliotheque::cherche_livre (int code_livre){
    bool exist=false;
    int j=0;
    int pos=-1;
    while ((exist==false)&&(j<=livres.size()))
        {
           if(livres[j].getNumisbn()==code_livre){
            exist=true;
            pos=j;
           }
           else{
            j=j+1;
           }
        }
    //cout<< "position:" <<pos <<endl;
    return pos;
    }


std::vector <Bibliotheque> Bibliotheque::retourne_livre(std::vector <Bibliotheque> liste_bibliotheque){
    int c=0;
    int pos=-1;

    int code_livre;
    vector<int> indice_a_supprime;
    for(int i=0; i<=livres.size(); i++)
    {   c=livres[i].getCodeEmprunt();
        //cout<< "code_emprunt= " <<c <<endl;
        code_livre=livres[i].getNumisbn();
        //cout<< "code_livre= " <<code_livre <<endl;
        if ((c!=0) && (livres[i].getEtat()=="Libre")){
            int j=0;

            bool exist=false;
            while ((exist==false)&& (j<liste_bibliotheque.size())){
                int n = liste_bibliotheque[j].getCode();
                if (c == n){
                    exist=true;
                    indice_a_supprime.push_back(i);
                    //supprime_livre(livres[i].getCode());
                    //cout<< "j= "<<j <<endl;
                    pos=liste_bibliotheque[j].cherche_livre(code_livre);
                    if (pos!=-1){
                    /*cout<< "etaaat1: " << liste_bibliotheque[j].getLivres()[pos].getEtat()<<endl*/;
                    liste_bibliotheque[j].livres[pos].setEtat("Libre");
                    /*cout<< "etaaat2: " << liste_bibliotheque[j].getLivres()[pos].getEtat()<<endl;*/}
                }
                else {j=j+1;}
            }
        }
    }
    for (int k =0; k<indice_a_supprime.size();k++){
        supprime_livre(livres[indice_a_supprime[k]].getCode());
    }
    //cout<<"resultat: "<<liste_bibliotheque[1].livres[0].getEtat()<<endl;
    return liste_bibliotheque;
}





#include "Livre.h"
#include "Bibliotheque.h"
#include "Adherant.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Adherant::Adherant(){};

Adherant::Adherant(std::string nom, std::string prenom, std::string adresse, int num_adherant, std::vector<Bibliotheque> biblio_inscri, std::vector <Livre> livre_emprunte, int nb_livre)
{
    this-> nom=nom;
    this-> prenom=prenom;
    this-> adresse=adresse;
    this-> num_adherant=num_adherant;
    this-> biblio_inscri=biblio_inscri;
    this-> livre_emprunte=livre_emprunte;
    this-> nb_livre=nb_livre;
};


void Adherant::affiche_livres_adherant()
{   cout << nom << endl;
    for (int i=0; i< livre_emprunte.size(); i++){
        cout << " Livre " << i+1 <<" " ;
        livre_emprunte[i].affiche();
        cout << endl;
    }
}


std::vector<Bibliotheque> Adherant::inscrire (int code_bibliotheque, std::vector <Bibliotheque> biblio_disponible){
    bool exist=false;
    int i=0;
    while((i<biblio_disponible.size())&&(exist==false)){
        if (code_bibliotheque==biblio_disponible[i].getCode()){
            exist=true;
            biblio_inscri.push_back(biblio_disponible[i]);
        }
        else {
            i=i+1;
        }
    }
    return biblio_inscri;
}



Bibliotheque Adherant::emprunter(int code_livre, Bibliotheque bibliotheque_dispo){
    if (livre_emprunte.size()<nb_livre){
            int i=0;
            int code=0;
            Livre livre;
            bool exist= false;
            while((i<bibliotheque_dispo.getLivres().size())&& (exist==false)){
                code= bibliotheque_dispo.getLivres()[i].getCode();
                livre=bibliotheque_dispo.getLivres()[i];
                if((code_livre==code) && (livre.getEtat()== "Libre")){
                    exist=true;
                    livre.setEtat("Emprunte");
                    livre.setCodeEmprunt(bibliotheque_dispo.getCode());
                    livre_emprunte.push_back(livre);
                    //cout << "etaaat1 : "<<bibliotheque_dispo.getLivres()[i].getEtat()<<endl;
                    bibliotheque_dispo.livres[i].setEtat("Prete");
                    //cout <<"etaaat2: " <<bibliotheque_dispo.getLivres()[i].getEtat()<<endl;
                }
                else{
                    i=i+1;
                }
            }
            if(exist==false){cout<< "Le livre n'existe pas" <<endl;}
            else{cout<< "Livre prete avec succes" <<endl;}
    }
    else{
        cout << "Nombre max de livre atteint, vous ne pouvez plus emprunter des livres";
    }
    return bibliotheque_dispo;
}


void Adherant::supprime_livre_adherant(int code){
    for (int i=0; i< livre_emprunte.size(); i++){
        if (code == livre_emprunte[i].getNumisbn()){
            livre_emprunte.erase(livre_emprunte.begin() + i);
            cout<< "livre supprime avec succes" << endl;
        }
     }
}

std::vector <Bibliotheque> Adherant::rendre_livre(int code_livre, std::vector <Bibliotheque> biblio_inscri){
    int j=0;
    int pos=-1;
    bool exist=false;
    while ((j<biblio_inscri.size())&&(exist==false)){
           pos=biblio_inscri[j].cherche_livre(code_livre);
           if (pos!=-1){
                exist=true;
                biblio_inscri[j].livres[pos].setEtat("Libre");
                supprime_livre_adherant(code_livre);
           }
           else{j=j+1;}
    }
    return biblio_inscri;
}


void  Adherant:: affiche() {
cout<< "Nom: " << nom << ", code_Adherant: " << num_adherant <<endl;}



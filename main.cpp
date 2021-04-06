#include "Bibliotheque.h"
#include "Livre.h"
#include "Adherant.h"
#include "Album.h"
#include "Poesie.h"
#include "Theatre.h"
#include "Bd.h"
#include "Roman.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Travail avec saisi utilisateur

Bibliotheque ajouter_nouvelle_bibliotheque(){
std::string nom;
std::string adresse;
int code;
    cout<< "entrer le nom de la bibliotheque" <<endl;
    cin>>nom;
    cout<< "entrer l'adresse de la bibliotheque" <<endl;
    cin>>adresse;
    cout<< "entrer le code de la bibliotheque" <<endl;
    cin>>code;
    Bibliotheque nouvelleBibliotheque(nom,adresse,code);
    nouvelleBibliotheque.affiche();
    return nouvelleBibliotheque;
}

Bibliotheque ajouter_nouveau_livre(Bibliotheque bibliotheque)
{int code;
std::string auteur;
std::string titre;
std::string editeur;
std::string categorie;
std::string pub;
int numISBN;
    cout<< "entrer le code du livre" <<endl;
    cin>>code;
    cout<< "entrer l'auteur du livre" <<endl;
    cin>>auteur;
    cout<< "entrer le titre du livre" <<endl;
    cin>>titre;
    cout<< "entrer l'editeur du livre" <<endl;
    cin>>editeur;
    cout<< "entrer le num ISBN du livre" <<endl;
    cin>>numISBN;
    cout<< "entrer le public du livre" <<endl;
    cin>>pub;
    cout<< "entrer la categorie du livre" <<endl;
    cin>>categorie;
    //Livre nouveauLivre;
    /*if(categorie=="Roman"){
        std::string genre;
        cout<< "entrer le genre du roman" <<endl;
        cin>>genre;
        Roman nouveauLivre (code, numISBN, auteur, titre, editeur, pub, "Libre", categorie,0, genre);
    }*/
    //else{

    //}
    Livre nouveauLivre (code, numISBN, auteur, titre, editeur, pub, "Libre", categorie);
    nouveauLivre.affiche();
    bibliotheque.ajouter_livre(nouveauLivre);
    bibliotheque.affiche_livres();
    return bibliotheque;
}

Adherant ajouter_nouveau_adherant(){
    std::string nom;
    std::string prenom;
    std::string adresse;
    int num_adherant;
    cout<< "entrer le nom du nouveau adherant" <<endl;
    cin>>nom;
    cout<< "entrer le prenom du nouveau adherant" <<endl;
    cin>>prenom;
    cout<< "entrer l'adresse du nouveau adherant" <<endl;
    cin>>adresse;
    cout<< "entrer le numero d'adherant" <<endl;
    cin>>num_adherant;
    Adherant nouveauAdherant(nom, prenom,adresse,num_adherant);
    return nouveauAdherant;}


//Travail avec fichier

void ajouter_livre_fichier(Livre livre){
    ofstream fichier("D:/projet.txt", ios::out | ios::app);
    fichier.seekp(0,ios::end);
    if(fichier)
    {
        cout<< "ouverture du fichier pour ajout d'un livre" <<endl;
        int code= livre.getNumisbn();
        std::string etat=livre.getEtat();
        int code_emprunt=livre.getCodeEmprunt();
        cout<< "code du livre a ajouter: " <<code<<endl;
        fichier << "Livre de code: "<< code <<", Etat: " << etat <<", Code Emprunt: " << code_emprunt <<endl;
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }


void ajouter_bibliotheque_fichier(Bibliotheque bibliotheque){
        ofstream fichier("D:/projet.txt", ios::out | ios::app);  // ouverture en écriture sans effacement du fichier ouvert
        fichier.seekp(0,ios::end);
        if(fichier)
        {       cout<< "ouverture du fichier avec succes"<<endl;
                std::string nom=bibliotheque.getNom();
                std::string adresse= bibliotheque.getAdresse();
                int code= bibliotheque.getCode();
                Livre livre;
                fichier << "Bibliotheque: " << nom <<" de code:"<< code << endl;
                for(int i=0; i<bibliotheque.getLivres().size();i++){
                   livre=bibliotheque.getLivres()[i];
                   ajouter_livre_fichier(livre);
                }
                //ajouter_livre_fichier(bibliotheque.getLivres()[0]);
                fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

}


void ajouter_adherant_fichier(Adherant adherant){
        ofstream fichier("D:/projet.txt", ios::out | ios::app);  // ouverture en écriture sans effacement du contenu
        fichier.seekp(0,ios::end);
        if(fichier)
        {       cout<< "ouverture du fichier avec succes"<<endl;
                std::string nom=adherant.getNom();
                std::string prenom=adherant.getPrenom();
                std::string adresse= adherant.getAdresse();
                int num= adherant.getNumAdherant();
                Livre livre;
                fichier << "Adherant: " << nom <<", Numero adherant:"<< num << endl;
                for(int i=0; i<adherant.getLivreEmprunte().size();i++){
                   livre=adherant.getLivreEmprunte()[i];
                   ajouter_livre_fichier(livre) ;
                }
                //ajouter_livre_fichier(bibliotheque.getLivres()[0]);
                fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

}






int main(){
    cout <<"***Partie 1: Manipulation de Livres***" <<endl;

    Livre livre1(1256, 516494, "Hugo", "Livre1","Plume", "Tout","Libre","Livre");
	Livre livre2(1548, 514875, "Gilbert", "Livre2", "Plume", "Adultes","Libre","Livre");
	Livre livre3(5489, 216545, "Marie", "Livre3", "France Loisirs", "Jeunes","Libre","Livre");
	Livre livre4(3451, 123452, "Louis", "Livre4", "Edition Feret", "Tout","Prete","Livre");
	Livre livre5(9874, 987541, "Alice", "Livre5", "France Loisirs", "Jeunes","Libre","Livre");
	Livre livre6(5912, 541236, "Caroline", "Livre6", "Plume", "Tout", "Libre","Livre");
	Roman livre7(4251, 124568, "Antoine", "Roman", "France Loisirs", "Jeunes", "Libre","tout",0,"tragedique");
	Album livre8(2254, 854263, "Alberto", "Album", "Plume", "Tout", "Libre","tout",0,"illustration");
	livre1.affiche();
	livre2.affiche();
	livre7.affiche();
	livre8.affiche();

    cout <<"***Partie 2: Manipulation de bibliotheque***" <<endl;

    std::vector<Bibliotheque> liste_bibliotheque;
	Bibliotheque B1 ("Marseille", "Rue Juliot curie", 1234);
	cout<< "Le nom de la bibliotheque 1 est: "<< B1.getNom() << endl;
	B1.affiche();
	Bibliotheque B2 ("Vieux port", "Rue Louis Leprince-Ringuet", 7896);
    liste_bibliotheque.push_back(B2);
    B2.affiche();
    Bibliotheque B3 ("Lyon", "Rue Louis Neel", 3458);
    liste_bibliotheque.push_back(B3);
    B3.affiche();

	B1.ajouter_livre(livre1);
	B1.ajouter_livre(livre5);
	liste_bibliotheque[0].ajouter_livre(livre2);
	liste_bibliotheque[0].ajouter_livre(livre3);
	liste_bibliotheque[0].ajouter_livre(livre4);
	liste_bibliotheque[1].ajouter_livre(livre6);

	cout<< "Etats initiaux des bibliotheques" << endl;
	B1.affiche_livres();
	liste_bibliotheque[0].affiche_livres();
	liste_bibliotheque[1].affiche_livres();

    cout<< "Emprunt de livres" << endl;
    liste_bibliotheque[0]=B1.demande_livre(111111, liste_bibliotheque[0]);
    liste_bibliotheque[0]=B1.demande_livre(514875, liste_bibliotheque[0]);
    liste_bibliotheque[0]=B1.demande_livre(123452, liste_bibliotheque[0]);
    liste_bibliotheque[1]=B1.demande_livre(541236, liste_bibliotheque[1]);

	cout<< "Etats des bibliotheques apres emprunts" << endl;
	B1.affiche_livres();
	liste_bibliotheque[0].affiche_livres();
	liste_bibliotheque[1].affiche_livres();

    cout<< "Retour des livres empruntes et non pretes a des adherants"<< endl;
	liste_bibliotheque=B1.retourne_livre(liste_bibliotheque);
	B1.affiche_livres();
	liste_bibliotheque[0].affiche_livres();
	liste_bibliotheque[1].affiche_livres();

    cout <<"***Partie 3: Manipulation des adherants***" <<endl;
    std::vector<Bibliotheque> bibliotheque_disponible;
    Adherant client1("Antoine", "Paul", "Marseille", 1);
    Adherant client2("Lenglet", "Chris", "Paris", 2);
    client1.affiche();
    client2.affiche();

    cout <<"S'inscrire dans un biblio" <<endl;
    bibliotheque_disponible.push_back(B1);
    bibliotheque_disponible.push_back(liste_bibliotheque[0]);
    bibliotheque_disponible.push_back(liste_bibliotheque[1]);
    bibliotheque_disponible[0].affiche_livres();
    client1.inscrire(1234, bibliotheque_disponible);
    cout<< client1.getBiblioInscri().size()<<endl;

    cout <<"Emprunt de livres" <<endl;
    bibliotheque_disponible[0]=client1.emprunter(1256, bibliotheque_disponible[0]);
    bibliotheque_disponible[1]=client1.emprunter(9874, bibliotheque_disponible[0]);
    cout << "livre emprunte: " <<client1.getLivreEmprunte().size() << endl;
    bibliotheque_disponible[0].affiche_livres();
    client1.affiche_livres_adherant();
    /* client1.supprime_livre_adherant(516495615);
    cout<< client1.getLivreEmprunte().size()<<endl; */
    cout <<"Retour livre" <<endl;
    bibliotheque_disponible= client1.rendre_livre(516494, bibliotheque_disponible);
    bibliotheque_disponible[0].affiche_livres();
    cout<< client1.getLivreEmprunte().size()<<endl;

    cout<<"***Partie 5: travail des fichiers***"<<endl;
    ajouter_bibliotheque_fichier(B1);

    ajouter_adherant_fichier(client1);

    cout<<"***Partie 4: travail avec saisi utilisateur***"<<endl;
    Bibliotheque nouvelle_bibliotheque=ajouter_nouvelle_bibliotheque();
    nouvelle_bibliotheque=ajouter_nouveau_livre(nouvelle_bibliotheque);
    Roman roman(5912,541236,"Jacques","Roman","Plume", "Tout", "Libre","tout",0,"tragedique");
    nouvelle_bibliotheque.ajouter_livre(livre2);
    nouvelle_bibliotheque.affiche_livres();

    return 0;
}

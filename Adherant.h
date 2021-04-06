#ifndef ADHERANT_H_
#define ADHERANT_H_

#include <string>
#include <vector>

#include "Bibliotheque.h"
#include "Livre.h"


class Adherant{
    protected:
        std::string nom;
        std::string prenom;
        std::string adresse;
        int num_adherant;
        std::vector <Bibliotheque> biblio_inscri;
        std::vector <Livre> livre_emprunte;
        int nb_livre;

    public:
        Adherant();
        Adherant(std::string nom, std::string prenom, std::string adresse, int num_adherant, std::vector<Bibliotheque> biblio_inscri={}, std::vector <Livre> livre_emprunte={}, int nb_livre=3);

        std::string getNom()
        {
            return nom;
        }
        void setNom(std::string nom)
        {
            this-> nom= nom;
        }

        std::string getPrenom()
        {
            return prenom;
        }
        void setPrenom(std::string prenom)
        {
            this-> prenom= prenom;
        }

        std::string getAdresse()
        {
            return adresse;
        }
        void setAdresse(std::string adresse)
        {
            this-> adresse= adresse;
        }

        int getNumAdherant()
        {
            return num_adherant;
        }
        void setNumAdherant(int num_adherant)
        {
            this-> num_adherant= num_adherant;
        }

        std::vector< Bibliotheque> getBiblioInscri(){
        return biblio_inscri; }

        std::vector< Livre> getLivreEmprunte(){
        return livre_emprunte; }


        std::vector<Bibliotheque> inscrire (int code_bibliotheque, std::vector <Bibliotheque> biblio_disponible);
        Bibliotheque emprunter(int numIsbn, Bibliotheque bibliotheque_dispo);
        void supprime_livre_adherant(int code);
        std::vector <Bibliotheque> rendre_livre(int numIsbn, std::vector <Bibliotheque> biblio_inscri);
        void affiche_livres_adherant();
        void affiche();

};



#endif // ADHERANT_H_


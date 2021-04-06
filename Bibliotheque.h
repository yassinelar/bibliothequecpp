#ifndef BIBLIOTHEQUE_H_
#define BIBLIOTHEQUE_H_

#include <string>
#include <vector>

#include "Livre.h"
//#include "Adherant.h"



class Bibliotheque {
    protected:
    std::string nom;
    std::string adresse;
    int code;

    public:
    std::vector <Livre> livres;
    //std::vector <Adherant> adherants;
    Bibliotheque();
    Bibliotheque(std::string nom, std::string adresse, int code, std::vector <Livre> livres={});

    std::string getNom()
    {
        return nom;
    }

    void setNom (std::string nom)
    {
        this-> nom=nom;
    }

    std::string getAdresse()
    {
        return adresse;
    }
    void setAdresse (std::string adresse)
    {
        this-> adresse=adresse;
    }

    int getCode() const
    {
        return code;
    }

    void setCode (int code)
    {
        this-> code=code;
    }

    std::vector <Livre> getLivres()
    {
    return livres;
    }



    void affiche();
    void affiche_livres();

    void ajouter_livre(Livre livre);
    void supprime_livre(int code);

    Bibliotheque demande_livre(int numISBN, Bibliotheque autreBibilotheque);
    int cherche_livre(int code_livre);
    std::vector <Bibliotheque> retourne_livre(std::vector <Bibliotheque> liste_bibliotheque);

};


#endif // BIBLIOTHEQUE_H_


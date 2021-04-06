#ifndef POESIE_H_
#define POESIE_H_

#include <string>
#include "Livre.h"

class Poesie: public Livre {
    private:
        std::string indicateur;

    public:
        Poesie();
        Poesie(int code,int numISBN,std::string auteur, std::string titre, std::string editeur, std::string pub, std::string etat,std::string categorie,int code_emprunt, std::string indicateur);


        std::string getIndicateur() const
        {
            return indicateur;
        }
        void setIndicateur(std::string indicateur)
        {
            this->indicateur=indicateur;
        }

        void affiche();
    };






#endif /* POESIE_H_ */



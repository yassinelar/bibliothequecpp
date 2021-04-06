#ifndef THEATRE_H_
#define THEATRE_H_

#include <string>
#include "Livre.h"

class Theatre: public Livre {
    private:
        int siecle;

    public:
        Theatre();
        Theatre(int code,int numISBN,std::string auteur, std::string titre, std::string editeur, std::string pub, std::string etat,std::string categorie,int code_emprunt, int siecle);


        int getSiecle() const
        {
            return siecle;
        }
        void setSiecle(int siecle)
        {
            this->siecle=siecle;
        }

        void affiche();
    };






#endif /* THEATRE_H_ */





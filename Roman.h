#ifndef ROMAN_H_
#define ROMAN_H_

#include <string>
#include "Livre.h"

class Roman: public Livre {
    private:
        std::string genre;

    public:
        Roman();
        Roman(int code,int numISBN,std::string auteur, std::string titre, std::string editeur, std::string pub, std::string etat,std::string categorie,int code_emprunt, std::string genre);


        std::string getGenre() const
        {
            return genre;
        }
        void setGenre(std::string genre)
        {
            this->genre=genre;
        }

        void affiche();
    };






#endif /* ROMAN_H_ */




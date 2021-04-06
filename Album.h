#ifndef ALBUM_H_
#define ALBUM_H_

#include <string>
#include "Livre.h"

class Album: public Livre {
    private:
        std::string illustration;

    public:
        Album();
        Album(int code,int numISBN,std::string auteur, std::string titre, std::string editeur, std::string pub, std::string etat,std::string categorie,int code_emprunt, std::string illustration);


        std::string getIllustration() const
        {
            return illustration;
        }
        void setIllustration(std::string illustration)
        {
            this->illustration=illustration;
        }

        void affiche();
    };



#endif /* ALBUM_H_ */




#ifndef BD_H_
#define BD_H_

#include <string>
#include "Livre.h"

class Bd: public Livre {
    private:
        std::string dessinateur;

    public:
        Bd();
        Bd(int code,int numISBN,std::string auteur, std::string titre, std::string editeur, std::string pub, std::string etat,std::string categorie,int code_emprunt, std::string dessinateur);


        std::string getDessinateur() const
        {
            return dessinateur;
        }
        void setDessinateur(std::string dessinateur)
        {
            this-> dessinateur=dessinateur;
        }

        void affiche();
    };






#endif /* BD_H_ */


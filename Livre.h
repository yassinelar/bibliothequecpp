#ifndef LIVRE_H_
#define LIVRE_H_


#include <string>

class Livre {
    protected:
        int code;
        std::string auteur;
        std::string titre;
        std::string editeur;
        int numISBN;
        std::string pub;
        std::string etat;
        int code_emprunt ;
        std::string categorie;

    public:
        Livre();
        Livre(int code,const int numISBN,std::string auteur, std::string titre,std::string editeur, std::string pub, std::string etat,std::string categorie,int code_emprunt=0);


        int getCode(){
			return code;}
        void setCode(int code){
			this-> code=code;}

        std::string getAuteur(){
			return auteur;}
        void setAuteur( std::string  auteur){
			this-> auteur=auteur;}

        std::string getTitre() ;
        void setTitre( std::string  titre);

        std::string getEditeur(){
			return editeur;}
        void setEditeur( std::string  editeur){
			this-> editeur=editeur;}

        int getNumisbn() const{
			return numISBN;}
        void setNumisbn(const int numISBN){
			this-> numISBN= numISBN;}


        std::string getPub() const{
			return pub;}
        void setPub(const std::string  pub){
			this->pub=pub;}

        std::string  getEtat(){
			return etat;}
        void setEtat(std::string  etat){
			this-> etat=etat;}

        std::string  getCategorie() const{
			return categorie;}
        void setCategorie(std::string  categorie){
			this-> categorie=categorie;}

        int getCodeEmprunt() {
			return code_emprunt;}
        void setCodeEmprunt(int code_emprunt){
			this-> code_emprunt= code_emprunt;}

        void affiche();
};

#endif /* LIVRE_H_ */


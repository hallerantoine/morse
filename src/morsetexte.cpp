#include <iostream>
#include <map>
#include <string>
#include "../include/morsetexte.h"


void texte::init_dicos(){
    texte::remplir_fr_to_mo();
    texte::remplir_mo_to_fr();

}

void texte::remplir_fr_to_mo(){
fr_to_mo["A"]="._";
fr_to_mo["B"]="_...";
}

void texte::remplir_mo_to_fr(){
mo_to_fr["._"]="A";
mo_to_fr["_..."]="B";
}

std::string texte::afficher(){
    return fr.append("C");
}

void texte::set_fr(std::string entree_fr){
    fr=entree_fr;
}

void texte::set_mo(std::string entree_mo){
    fr=entree_mo;
}

std::string texte::get_mo(){
    return mo;
}


void texte::trad_fr_to_mo(){
    int n=fr.size();
    for (int i=0;i<n;i++){
        if (int(fr[i])==32){
            mo.append("  ");
        }
        else{
            std::string lettre(1,fr[i]);

            mo.append(fr_to_mo[lettre]);
        }
        if (i<std::max(n-1,0)){
        mo.append(" ");
        }
    }

}
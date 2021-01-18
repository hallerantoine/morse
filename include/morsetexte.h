#include <iostream>
#include <map>
#include <string>
#pragma once


class texte{

    public:
    void init_dicos();
    void remplir_fr_to_mo();
    void remplir_mo_to_fr();

    std::string test();

    void set_fr(std::string entree_fr);
    void set_mo(std::string entree_mo);

    std::string get_mo();
    std::string get_fr();

    void trad_fr_to_mo();
    void trad_mo_to_fr();


    private:
    std::map<std::string,std::string> fr_to_mo;
    std::map<std::string,std::string> mo_to_fr;
    std::string fr;
    std::string mo;

};
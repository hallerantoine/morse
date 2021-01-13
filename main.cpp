#include <iostream>
#include <map>
#include <string>
#include "src/class.cpp"
#include "src/morsetexte.cpp"

int main(){

    texte t;
    t.init_dicos();
    t.set_fr("AB A B");
    t.trad_fr_to_mo();
    std::string res=t.get_mo();

    std::cout << res << "\n";
    return 0;
}
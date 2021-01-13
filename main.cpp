#include <iostream>
#include <map>
#include <string>
#include "src/class.cpp"
#include "src/morsetexte.cpp"

int main(){

    texte t;
    t.init_dicos();
    t.set_mo("._ _...   ._");
    t.trad_mo_to_fr();
    std::string res=t.get_fr();

    std::cout << res << "\n";
    return 0;
}
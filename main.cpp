#include <iostream>
#include <map>
#include <string>
#include "src/class.cpp"
#include "src/morsetexte.cpp"
#include "src/wave.cpp"

int main(int argc, char *argv[]){

    texte t;    
    t.init_dicos();
    t.set_fr("BONJOUR");
    t.trad_fr_to_mo();
    std::string mo=t.get_mo();

    wave w;

    w.morse_to_wave(mo,"bonjour.wav");
    std::string res = w.read_wav("bonjour.wav");

    
    std::cout<< res << "\n";
    std::cout<<mo<<"\n";



    return 0;
}
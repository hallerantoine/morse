#include <iostream>
#include <map>
#include <string>
#include "src/class.cpp"
#include "src/morsetexte.cpp"
#include "src/wave.cpp"

int main(int argc, char *argv[]){

    texte t;    
    t.init_dicos();
    t.set_fr("BONJOUR AU REVOIR");
    t.trad_fr_to_mo();
    std::string mo=t.get_mo();

    wave w;
    w.morse_to_wave(mo,"bonjour.wav");



    return 0;
}
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
fr_to_mo["C"]="_._.";
fr_to_mo["D"]="_..";
fr_to_mo["E"]=".";
fr_to_mo["F"]=".._.";
fr_to_mo["G"]="__.";
fr_to_mo["H"]="....";
fr_to_mo["I"]="..";
fr_to_mo["J"]=".___";
fr_to_mo["K"]="_._";
fr_to_mo["L"]="._..";
fr_to_mo["M"]="__";
fr_to_mo["N"]="_.";
fr_to_mo["O"]="___";
fr_to_mo["P"]=".__.";
fr_to_mo["Q"]="__._";
fr_to_mo["R"]="._.";
fr_to_mo["S"]="...";
fr_to_mo["T"]="_";
fr_to_mo["U"]=".._";
fr_to_mo["V"]="..._";
fr_to_mo["W"]=".__";
fr_to_mo["X"]="_.._";
fr_to_mo["Y"]="_.__";
fr_to_mo["Z"]="__..";
fr_to_mo["0"]="_____";
fr_to_mo["1"]=".____";
fr_to_mo["2"]="..___";
fr_to_mo["3"]="...__";
fr_to_mo["4"]="...._";
fr_to_mo["5"]=".....";
fr_to_mo["6"]="_....";
fr_to_mo["7"]="__...";
fr_to_mo["8"]="___..";
fr_to_mo["9"]="____.";
}

void texte::remplir_mo_to_fr(){
mo_to_fr[fr_to_mo["A"]]="A";
mo_to_fr[fr_to_mo["B"]]="B";
mo_to_fr[fr_to_mo["C"]]="C";
mo_to_fr[fr_to_mo["D"]]="D";
mo_to_fr[fr_to_mo["E"]]="E";
mo_to_fr[fr_to_mo["F"]]="F";
mo_to_fr[fr_to_mo["G"]]="G";
mo_to_fr[fr_to_mo["H"]]="H";
mo_to_fr[fr_to_mo["I"]]="I";
mo_to_fr[fr_to_mo["J"]]="J";
mo_to_fr[fr_to_mo["K"]]="K";
mo_to_fr[fr_to_mo["L"]]="L";
mo_to_fr[fr_to_mo["M"]]="M";
mo_to_fr[fr_to_mo["N"]]="N";
mo_to_fr[fr_to_mo["O"]]="O";
mo_to_fr[fr_to_mo["P"]]="P";
mo_to_fr[fr_to_mo["Q"]]="Q";
mo_to_fr[fr_to_mo["R"]]="R";
mo_to_fr[fr_to_mo["S"]]="S";
mo_to_fr[fr_to_mo["T"]]="T";
mo_to_fr[fr_to_mo["U"]]="U";
mo_to_fr[fr_to_mo["V"]]="V";
mo_to_fr[fr_to_mo["W"]]="W";
mo_to_fr[fr_to_mo["X"]]="X";
mo_to_fr[fr_to_mo["Y"]]="Y";
mo_to_fr[fr_to_mo["Z"]]="Z";
mo_to_fr[fr_to_mo["0"]]="0";
mo_to_fr[fr_to_mo["1"]]="1";
mo_to_fr[fr_to_mo["2"]]="2";
mo_to_fr[fr_to_mo["3"]]="3";
mo_to_fr[fr_to_mo["4"]]="4";
mo_to_fr[fr_to_mo["5"]]="5";
mo_to_fr[fr_to_mo["6"]]="6";
mo_to_fr[fr_to_mo["7"]]="7";
mo_to_fr[fr_to_mo["8"]]="8";
mo_to_fr[fr_to_mo["9"]]="9";
}

std::string texte::afficher(){
    return fr.append("C");
}

void texte::set_fr(std::string entree_fr){
    fr=entree_fr;
}

void texte::set_mo(std::string entree_mo){
    mo=entree_mo;
}

std::string texte::get_mo(){
    return mo;
}

std::string texte::get_fr(){
    return fr;
}


void texte::trad_fr_to_mo(){
    int n=fr.size();
    mo.clear();
    for (int i=0;i<n;i++){
        if (int(fr[i])==32){
            mo.append(" ");
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

void texte::trad_mo_to_fr(){
    int n=mo.size();
    fr.clear();
    std::string lettre;
    for (int i=0;i<n;i++){
        if (int(mo[i])==32 && int(mo[i+1])==32 &&int(mo[i+2])==32){
            fr.append(mo_to_fr[lettre]);
            lettre.clear();
            fr.append(" ");
        }
        else{
            if (int (mo[i])!=32){
                std::string charactere(1,mo[i]);
                lettre.append(charactere);
            }
            else if (int (mo[i])==32){
                fr.append(mo_to_fr[lettre]);
                lettre.clear();
            }
            
        }
        
    }
    fr.append(mo_to_fr[lettre]);
    lettre.clear();
}
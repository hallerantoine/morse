#include <iostream>
#include <map>
#include <string>
#include "src/morsetexte.cpp"
#include "src/wave.cpp"

int main(int argc, char *argv[]){

    char dep;
    char arr;
    std::cout<<"Langage de départ (A=français en majuscules; B=morse; C=wav)"<<std::endl;
    std::cin>>dep;
    std::cout<<"Langage d'arrivée (A=français en majuscules; B=morse; C=wav)"<<std::endl;
    std::cin>>arr;

    texte t;
    t.init_dicos();
    wave w;

    if (int(dep)==65){
        std::cout<<"Entrer le texte en français en MAJUSCULES"<<std::endl;
        std::string francais;
        std::cin>>francais;
        t.set_fr(francais);
        t.trad_fr_to_mo();
        std::string mo=t.get_mo();
        if (int(arr)==66){
            std::cout<<mo<<"\n";
        }
        else if (int(arr)==67){
            std::string titre;
            std::cout<<"entrer le titre (doit finir par .wav)"<<std::endl;
            std::cin>>titre;
            w.morse_to_wave(mo,titre);
            std::cout<<"conversion terminée, le fichier se trouve dans le dossier"<<std::endl;
        }
    }
    else if(int(dep)==66){
        std::cout<<"Entrer le texte sous forme morse (avec la convention .=ti; _=ta; 1 espace entre chaquel lettre; 3 espaces entre chaque mot"<<std::endl;
        std::string morse;
        std::cin>>morse;
        t.set_mo(morse);
        if (int(arr)==65){
            t.trad_mo_to_fr();
            std::string francais=t.get_fr();
            std::cout<<francais<<"\n";
        }
        else if (int(arr)==67){
            std::string titre;
            std::cout<<"entrer le titre (doit finir par .wav)"<<std::endl;
            std::cin>>titre;
            w.morse_to_wave(morse,titre);
        }
    }

    else if(int(dep)==67){
        std::cout<<"Entrer le nom du fichier (doit se trouver dans le dossier source et finir par .wav)"<<std::endl;
        std::string titre;
        std::cin>>titre;
        std::string morse =w.read_wav(titre);
        t.set_mo(morse);
        if (int(arr)==66){
            std::cout<<morse<<"\n";
        }
        else if (int(arr)==65){
            t.trad_mo_to_fr();
            std::string francais=t.get_fr();
            std::cout<<francais<<"\n";         
        }
    }


    


    return 0;
}
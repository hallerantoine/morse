#include <cmath>
#include <fstream>
#include <iostream>
#include "../include/wave.h"
using namespace std;

namespace little_endian_io
{
  template <typename Word>
  std::ostream& write_word( std::ostream& outs, Word value, unsigned size = sizeof( Word ) )
  {
    for (; size; --size, value >>= 8)
      outs.put( static_cast <char> (value & 0xFF) );
    return outs;
  }
}
using namespace little_endian_io;
/* j'ai trouvé ce code du little endian sur internet*/



void wave::morse_to_wave(std::string mo, std::string titre){
    ofstream fichier ( titre, ios::binary);


    /*initialisaion du fichier, on remplacera zzzz avec la taille du fichier et yyyy à la fin*/
    fichier << "RIFFzzzzWAVEfmt ";
    write_word(fichier,16,4);
    write_word(fichier,AudioFormat,2);
    write_word(fichier,NbrCanaux,2);
    write_word(fichier,Frequence,4);
    write_word(fichier,BytePerSec,4);
    write_word(fichier,BytePerBloc,2);
    write_word(fichier,BitsPerSample,2);
    fichier << "datayyyy";

    int n=mo.size();
    for (int i=0;i<n;i++){
        /* Si c'est un point*/
        if (int(mo[i])==46){
            int duree=Frequence*LongueurElementaire/1000;
            for (int j=0; j<duree; j++){
                write_word(fichier,(int)(AmplitudeMax * sin(2*pi*j*FrequenceNote/FrequenceFloat) ),2);
            }
            /*il faut rajouter un petit temps*/
            for (int j=0; j<duree; j++){
                write_word(fichier,(int)(0) ,2);
            }
        }
       /* Si c'est un underscore*/
        else if (int(mo[i])==95){
            int duree=Frequence*LongueurElementaire/1000;
            for (int j=0; j<3*duree; j++){
                write_word(fichier,(int)(AmplitudeMax * sin(2*pi*j*FrequenceNote/FrequenceFloat) ),2);
            }
            /*il faut rajouter un petit temps*/
            for (int j=0; j<duree; j++){
                write_word(fichier,(int)(0) ,2);
            }


        }
        /* Si c'est un espace*/
        else if (int(mo[i])==32){
           int duree=Frequence*LongueurElementaire/1000;
            for (int j=0; j<duree; j++){
                write_word(fichier,(int)(0) ,2);
            }
        }
    }
    
    /*il reste à remplir les informations fichier manquantes*/
    size_t taille_fichier = fichier.tellp();

    /*on se place au bon endroit dans le fichier*/
    fichier.seekp(40);
    write_word(fichier,taille_fichier-32,4);

    fichier.seekp(4);
    write_word(fichier,taille_fichier-8,4); 

}


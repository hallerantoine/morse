#include <vector>
#include <string>
#include <iostream>
#include <fstream>


class wave{

    public:
    void morse_to_wave(std::string mo,std::string titre);

    private:
    /*j'utilise les noms utilisés dans la page Wikipédia pour s'y retrouver*/
    int AudioFormat=1;
    int NbrCanaux=1;
    int Frequence=11025;
    int BytePerSec=11025;
    int BytePerBloc=2;
    int BitsPerSample=16;


    int LongueurElementaire=150; /*en ms*/
    double AmplitudeMax= 32760;
    double FrequenceFloat=11025;
    double FrequenceNote= 440; /*la standard*/
    const double pi = 3.141592653589793238463; 

};

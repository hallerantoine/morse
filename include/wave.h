#include <vector>
#include <string>
#include <iostream>
#include <fstream>


class wave{

    public:
    void set_standard_wave();

    void morse_to_wave(std::string mo,std::string titre);

    std::string read_wav(std::string titre);

    int get_size();


    private:
    /*j'utilise les noms utilisés dans la page Wikipédia pour s'y retrouver*/
    int FileSize=0;
    int BlocSize=16;
    int AudioFormat=1;
    int NbrCanaux=1;
    int Frequence=11025;
    int BytePerSec=11025;
    int BytePerBloc=2;
    int BitsPerSample=16;
    int DataSize=44;

    int ret=0;

    std::vector<int> son;

    char RIFF[4] = {0};
    char WAVE[4] = {0};
    char fmt[4] = {0};
    char data[4] = {0};


    int LongueurElementaire=150; /*en ms*/
    double AmplitudeMax= 32760;
    double FrequenceFloat=11025;
    double FrequenceNote= 440; /*la standard*/
    const double pi = 3.141592653589793238463; 

};

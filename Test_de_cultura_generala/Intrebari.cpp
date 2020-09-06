#include "Intrebari.h"

raspunsuri::raspunsuri() : nr{'x'},raspuns{"Neinitalizat"} {};
raspunsuri::raspunsuri(char nr , std::string raspuns) : nr{nr}, raspuns{raspuns} {};
raspunsuri::~raspunsuri() {};

intrebare::intrebare () :intrb{"Neinitializat"}, variante{}, raspuns_corect{'x'} {};
intrebare::intrebare (std::string intrb, std::vector <raspunsuri> variante, char raspuns_corect, int numerotare) :intrb{intrb}, variante{variante},raspuns_corect{raspuns_corect}, numerotare{numerotare} {};
intrebare::~intrebare () {};

void intrebare::print() {
    std::cout<<"======================================="<<std::endl;
    std::cout<<numerotare<<". "<<intrb<<". "<<std::endl;
    for(auto vr: variante){
        std::cout<<"    "<<vr.nr<<". "<<vr.raspuns<<". "<<std::endl;
    }
}

bool intrebare::verif_raspuns(char alegere){
    if(alegere == raspuns_corect)
        return true;
    else
        return false;
}
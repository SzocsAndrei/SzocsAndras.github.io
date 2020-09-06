#pragma once
#include <iostream>
#include <string>
#include <vector>
class raspunsuri{
public :
    char nr {};
    std::string raspuns {};
raspunsuri () ;
raspunsuri(char nr , std::string raspuns);
~raspunsuri();
};

class intrebare {
public:
    std::string intrb {};
    std::vector<raspunsuri> variante {};
    char raspuns_corect {};
    int numerotare {};
    intrebare ();
    intrebare(std::string intrb, std::vector <raspunsuri> variante, char raspuns_corect, int numerotare);
    ~intrebare ();
    void print();
    bool verif_raspuns (char alegere);
};
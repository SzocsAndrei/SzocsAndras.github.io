//Proiect realizat de Szocs Andras 

#include <iostream>
#include "Intrebari.h" //fisieri pentru initializarea si definirea claselor 
#include "Intrebari_Initializate.h"//fisier pentru initializarea obiectelor de tip intrebare si variante
using namespace std;



int main()
{   cout<<"Test de cultura generala."<<endl<<endl;
    int scor {0};
    char alegere {};
    
    //Bucla pentru repetarea proceduri de afisare si primire a raspunsului pentru fiecare intrebare 
    for(auto in : intrebari){
	in.print();
    cout<<"Indroduce-ti raspunsul ales : ";
    cin>>alegere;
    cin.clear();
    cin.ignore(10000,'\n');
    if(in.verif_raspuns(alegere)){
        cout<<"Raspuns corect."<<endl;
        scor++;}
    else{
        cout<<"Raspuns gresit."<<endl<<"Raspunsul corect este  "<<intr1.raspuns_corect<<endl;}
    }
    
    //Afisarea rezultatului
    cout<<endl<<endl<<"Punctajul final este de "<<scor<<"/10 puncte."<<endl;
	return 0;
}

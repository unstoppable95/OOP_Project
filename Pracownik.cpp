//
// Created by Piotr on 2016-11-08.
//


#include "Pracownik.h"
#include <iostream>

using namespace std;

Pracownik::Pracownik(string imie, string nazwisko, int id1 ,int typpracownika1):Czlowiek::Czlowiek(imie,nazwisko){
    id=id1;
    typpracownika=typpracownika1;
}

void Pracownik::Przedstawsie(){

    cout<<"Nazywam sie"<< " ";
    cout<<Czlowiek::Zwrocimie();
    cout<< " ";
    cout<<Czlowiek::Zwrocnazwisko()<< " ";
    cout<<"a moj numer identyfikacyjny to "<< this->id << endl;
}

int Pracownik::Zwrocid(){
    return id;
}
int Pracownik::Zwrocpracownika() {
    return typpracownika;
}


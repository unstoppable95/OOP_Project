//
// Created by Piotr on 2016-11-08.
//

#include "Programista.h"

Programista::Programista(string imie,string nazwisko,int id , int stazpracy1):Pracownik::Pracownik(imie,nazwisko,id,1){

    stazpracy=stazpracy1;
}

void Programista::Przedstawsie(){

    Pracownik::Przedstawsie();
    cout << "pracuje w tej firmie od " << this->stazpracy << " lat" <<"."<<endl;
}

int Programista::Zwrocwlasciwosc()  {return stazpracy;}
//
// Created by Piotr on 2016-11-08.
//

#ifndef PROJEKT_CPP_PRACOWNIK_H
#define PROJEKT_CPP_PRACOWNIK_H
#include <iostream>
#include <string>
#include "Czlowiek.h"
using namespace std;

class Pracownik :public Czlowiek{
private:
    int id;
    int typpracownika;
public :

    void Przedstawsie();
    virtual int Zwrocwlasciwosc()=0;
    Pracownik(string imie, string nazwisko, int id,int  typpracownika);
    int Zwrocid();
    int Zwrocpracownika();
    ~Pracownik();

};


#endif //PROJEKT_CPP_PRACOWNIK_H

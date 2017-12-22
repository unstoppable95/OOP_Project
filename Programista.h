//
// Created by Piotr on 2016-11-08.
//

#ifndef PROJEKT_CPP_PROGRAMISTA_H
#define PROJEKT_CPP_PROGRAMISTA_H
#include <iostream>
#include <string>
#include "Pracownik.h"

using namespace std;


class Programista:public Pracownik {
private:
    int stazpracy;
public:

    void Przedstawsie();
    Programista(string imie, string nazwisko , int id , int stazpracy );
    int Zwrocwlasciwosc();
};


#endif //PROJEKT_CPP_PROGRAMISTA_H

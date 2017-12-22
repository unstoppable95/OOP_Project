//
// Created by Piotr on 2016-11-08.
//

#ifndef PROJEKT_CPP_CZLOWIEK_H
#define PROJEKT_CPP_CZLOWIEK_H

#include <iostream>
#include <string>
using namespace std;

class Czlowiek {
private:
    string imie;
    string nazwisko;
public:
  //  virtual void Zamowposilek()=0;
    virtual void Przedstawsie()=0;
    Czlowiek(string imie ,string nazwisko);
    string Zwrocimie();
    string Zwrocnazwisko();

};


#endif //PROJEKT_CPP_CZLOWIEK_H

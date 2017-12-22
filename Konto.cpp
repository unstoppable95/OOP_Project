//
// Created by Piotr on 2016-11-08.
//

#include "Konto.h"
Konto::Konto(double stankonta1,Pracownik * wskpracownik1){
    stankonta=stankonta1;
    wskpracownik=wskpracownik1;
}

double  Konto::Zwrocstan() {return stankonta;}
Konto &Konto::operator+=(double kasa) {
    stankonta+=kasa;
    return (*this);
}

Konto &Konto::operator-=(double kasa) {
    stankonta-=kasa;
    return (*this);
}

Pracownik* Konto::zwrocinf() {

    return wskpracownik;

}
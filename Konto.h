//
// Created by Piotr on 2016-11-08.
//

#ifndef PROJEKT_CPP_KONTO_H
#define PROJEKT_CPP_KONTO_H


#include "Pracownik.h"

class Konto {
private:
    double stankonta;
    Pracownik * wskpracownik;
public :

    Konto &operator+=(double kasa);
    Konto &operator-=(double kasa);
    Pracownik* zwrocinf();
    Konto(double stankonta, Pracownik* wskpracownik);
    double Zwrocstan();

};
//przeciazone metody dodawania i odejmowania

#endif //PROJEKT_CPP_KONTO_H

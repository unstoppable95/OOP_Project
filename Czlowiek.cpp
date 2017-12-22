//
// Created by Piotr on 2016-11-08.
//

#include "Czlowiek.h"
using namespace std;

//KONSTRUKTOR
Czlowiek::Czlowiek(string imie1, string nazwisko1){
    imie=imie1;
    nazwisko=nazwisko1;
}
string Czlowiek::Zwrocimie(){
    return imie;
}
string Czlowiek::Zwrocnazwisko(){
    return nazwisko;
}
//
// Created by Piotr on 2016-11-08.
//

#ifndef PROJEKT_CPP_STUDENT_H
#define PROJEKT_CPP_STUDENT_H
#include <iostream>
#include <string>
#include "Pracownik.h"

using namespace std;

class Student :public Pracownik{
private:
    int rokstudiow;
public:
    void Przedstawsie();
    Student(string imie , string nazwisko , int id , int rokstudiow);
    int Zwrocwlasciwosc();
};


#endif //PROJEKT_CPP_STUDENT_H

//
// Created by Piotr on 2016-11-08.
//

#include "Student.h"


Student::Student(string imie, string nazwisko, int id, int rokstudiow1):Pracownik::Pracownik(imie,nazwisko,id,2){

    rokstudiow=rokstudiow1;
}
void Student::Przedstawsie() {

    Pracownik::Przedstawsie();
    cout << "i jestem na " << this->rokstudiow << " roku studiow " <<"."<<endl;
}

int Student::Zwrocwlasciwosc() {
    return rokstudiow;
}
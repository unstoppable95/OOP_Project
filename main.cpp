#include <iostream>
#include <unistd.h>
#include "Kasa.cpp"
#include "Konto.h"
#include "Student.h"
#include "Programista.h"

using namespace std;

//kasa w main
Kasa<Konto> *kasamain = new Kasa<Konto>();
void addkonto(){
etykieta:

    cout<< "Kto bedzie wlascicielem konta ?"<< endl;
    cout<< "Student -> wpisz s"<<endl;
    cout<< "Programista -> wpisz p"<<endl;
    char pom;
    cin>> pom;
    if ((pom=='s') || (pom=='p')) {
        string imie, nazwisko;
        int id;
        int rokstudiow;
        int stazpracy;
        cout << "Podaj imie pracownika :" << endl;
        cin >> imie;
        cout << "Podaj nazwisko pracownika :" << endl;
        cin >> nazwisko;
        cout << "Podaj identyfikator pracownika, ktorego chcesz umiescic w bazie" << endl;
        cin >> id;

        Konto *konto;
        Student *student;
        Programista *programista;
        if (pom == 's') {
            cout << "Podaj na ktorym roku studiow jest student:" << endl;
            cin >> rokstudiow;
            student = new Student(imie, nazwisko, id, rokstudiow);
            konto = new Konto(0, student);
            kasamain->dodajkonto(konto);
        }
        if (pom == 'p') {
            cout << "Podaj od ilu lat pracownik pracuje w naszej firmie : " << endl;
            cin >> stazpracy;
            programista = new Programista(imie, nazwisko, id, stazpracy);
            konto = new Konto(0, programista);
            kasamain->dodajkonto(konto);
        }
        cout << "---KONTO DODANO POMYSLNIE---" << endl;
    } else {

        cout << "Podaj poprawne dane"<<endl; goto etykieta;

    }
}

int main() {
    kasamain->read();
while(1) {
    system( "cls" );
    cout << "------MENU------" << endl;
    cout << "1. Dodaj konto" << endl;
    cout << "2. Usun konto " << endl;
    cout << "3. Wykonaj przelew pomiedzy kontami" << endl;
    cout << "4. Wyswietl saldo kasy " << endl;
    cout << "5. Wyswietl stan  konta + informacje o pracowniku " << endl;
    cout << "6. Edytuj saldo konta" << endl;
    cout << "7. Wyswietl stan wszystkich kont" << endl;
    cout << "8. Zakoncz" << endl;
    int opcja;
    cin >> opcja;
    switch (opcja) {
        case 1: {
            addkonto();
            kasamain->save();
            sleep(2);
            break;
        }
        case 2: {
            int id;
            cout << "Podaj id konta do usuniecia :" << endl;
            cin >> id;
            kasamain->usunkonto(id);
            kasamain->save();
            sleep(5);
            break;
        }
        case 3: {
            int id1, id2;
            double kwota;
            cout<<"Wprowadz id nadawcy przelewu"<<endl;
            cin>> id1;
            cout<<"Wprowadz id odbiorcy przelewu"<<endl;
            cin>> id2;
            kasamain->przelew(id1,id2);
            sleep(5);
            break;
        }
        case 4: {
            kasamain->stankont();
            sleep(5);
            break;
        }
        case 5: {
            int id;
            cout << "Wprowadz id konta, ktorego informacje chcesz wyswietlic" << endl;
            cin>>id;
            kasamain->wyswietlinformacje(id);
            sleep(5);
            break;
        }
        case 6: {
            int id;
            double kwota;

            cout << "Podaj id konta ktorego saldo chcesz wyedytowac " << endl;
            cin >> id;
            cout << "Podaj kwote o ktora chcesz zmienic zmienic saldo" << endl;
            cout<<"Wprowadz + lub - oraz kwote o ktora chcesz zmienic saldo konta"<<endl;
            cin >> kwota;
            kasamain->edytujsaldo(id, kwota);
            kasamain->save();
            sleep(5);
            break;
        }
        case 7: {
            kasamain->stanwszystkich();
            sleep(5);
            break;

        }
        case 8: {
            return 0;
            break;
        }

    }

}







    return 0;
}
//
// Created by Piotr on 2016-11-08.
//

#include <iostream>
#include <string>
#include<fstream>
#include "Programista.h"
#include "Konto.h"
#include "Student.h"
#include<vector>
using namespace std;

template <class T>
class Kasa {
private:
    vector <T*> Kasawektor;
    float saldo;
public :
   void read (){
            ifstream plik;

            int id,stazpracy,rokstudiow;
            string imie,nazwisko;
            double stankonta;
            int typpracownika;

            plik.open("projekt.txt");
            if (plik.good()) {
                while(!plik.eof()){
                    plik >> imie >> nazwisko >> id >> typpracownika;
                    if(plik.eof()) break;
                    if(typpracownika == 1){
                        plik>> stazpracy >> stankonta;
                        Programista *programista = new Programista(imie,nazwisko,id,stazpracy);

                        Konto *konto = new Konto(stankonta,programista);
                        dodajkonto(konto);
                    }
                    else if(typpracownika == 2){
                        plik >> rokstudiow >>stankonta;
                        Student *student = new Student(imie,nazwisko,id,rokstudiow);
                        Konto *konto = new Konto(stankonta,student);
                        dodajkonto(konto);

                    }

                }
                plik.close();

            }
    }

    void save (){

        ofstream plik;
        string pracownik;
        int id,stazpracy,rokstudiow;
        string imie,nazwisko;
        double stankonta;
        bool opcja;
        plik.open("projekt.txt");
        if (plik.good()) {
          for (int i=0;i<Kasawektor.size() ;i++)  {
              plik << Kasawektor[i]->zwrocinf()->Zwrocimie()<<" " ;
              plik <<Kasawektor[i]->zwrocinf()->Zwrocnazwisko() <<" ";
              plik <<Kasawektor[i]->zwrocinf()->Zwrocid()<< " ";

              plik <<Kasawektor[i]->zwrocinf()->Zwrocpracownika()<<" ";

              if (Kasawektor[i]->zwrocinf()->Zwrocpracownika()==1){

                  plik<<Kasawektor[i]->zwrocinf()->Zwrocwlasciwosc()<<" ";

              }
              if (Kasawektor[i]->zwrocinf()->Zwrocpracownika()==2){
                  plik<<Kasawektor[i]->zwrocinf()->Zwrocwlasciwosc()<<" ";
              }

              plik<< Kasawektor[i]->Zwrocstan()<< " ";
              plik <<"\n";

          }
            plik.close();
        }
    }

void przelew(int id1 , int id2 ){
    try{
    int x;
    double kwota;
    int idnadawca=0;
    int idodbiorca=0;
    bool znaleziononadawce;
    bool znalezionodbiorce;
    for (int i=0 ; i<Kasawektor.size(); i++){

        if(Kasawektor[i]->zwrocinf()->Zwrocid()==id1){
            idnadawca=i;
            znaleziononadawce=true;
        }
        if(Kasawektor[i]->zwrocinf()->Zwrocid()==id2){
            idodbiorca=i;
            znalezionodbiorce=true;
        }
        if(idodbiorca!=0 && idnadawca!=0){
            break;
        } }
    if((znalezionodbiorce==false )|| (znaleziononadawce==false)) {
        cout<<"Podano niepoprawce ID"<<endl;
        return;
    }

    x=Kasawektor[idodbiorca]->zwrocinf()->Zwrocpracownika();
    if (x==2) {
        throw x=2;
    }

        cout << "Jaka kwote chcesz przelac ? " <<endl;
        cin>> kwota;
        *Kasawektor[idnadawca]-=kwota;
        *Kasawektor[idodbiorca]+=kwota;
        cout<<"---WYKONANO PRZELEW----"<<endl;
}
catch(int x){
    cout<<"-----UWAGA-------"<<endl;
    cout<< "Nie mozna pozyczac studentowi" <<endl;
    cout<<"------------------"<<endl;
    return;
}
}


    void wyswietlinformacje(int id){
        try{
        int pom;
        bool pom1;
        for (int i = 0; i < Kasawektor.size(); i++) {
            pom=Kasawektor[i]->zwrocinf()->Zwrocid();
            if (pom==id){
                pom1=true;
                cout<<"---------------------" <<endl;
                cout << " Saldo konta : " << Kasawektor[i] ->Zwrocstan() <<endl;
                cout<<"---------------------" <<endl;
                Kasawektor[i]->zwrocinf()->Przedstawsie();
            }
        }
            if(pom1==false) { throw pom1=false; } }

        catch(bool x){
            cout<<"----UWAGA----"<<endl;
            cout<<"Nie ma konta o podanym ID ktorego informacje moznaby wyswietlic"<<endl;
            cout<<"-------------"<<endl;
        }
    }


    void stankont(){
        double  pom;
        for (int i=0 ; i< Kasawektor.size(); i++)
        {
            pom+=Kasawektor[i]->Zwrocstan();
        }
            cout<<"----------------------------"<<endl;
            cout<< "Saldo kasy wynosi : " << endl<<endl<<pom <<endl <<endl;
            cout<<"----------------------------"<<endl;
    }

    void dodajkonto(T* Konto){
        Kasawektor.push_back(Konto);
    }
    void usunkonto(int id ){
        int pom2=1;
        for (int i=0; i<Kasawektor.size(); i++){
            int pom1=Kasawektor[i]->zwrocinf()->Zwrocid();
            if (pom1==id){
                if (Kasawektor[i]->Zwrocstan() ==0){

                    Kasawektor.erase(Kasawektor.begin()+i);
                    pom2=2;
                    cout<<"-----KONTO USUNIETE POMYSLNIE-----"<<endl;
                }   else cout<<"Saldo kasy jest rozne od zera" <<endl;
            }
            }
        if (pom2==1) cout<<"Nie znaleziono konta o podanym nr ID "<< endl;
        }


    void stanwszystkich(){
        int x;
        cout<<"----------------"<<endl;
        for (int i =0; i<Kasawektor.size(); i++){
            cout<<"Stan konta : "<<Kasawektor[i]->Zwrocstan()<<endl ;
            cout <<"Imie : "<<Kasawektor[i]->zwrocinf()->Zwrocimie()<<endl;
            cout <<"Nazwisko : "<<Kasawektor[i]->zwrocinf()->Zwrocnazwisko()<<endl;
            cout <<"Numer id : "<<Kasawektor[i]->zwrocinf()->Zwrocid()<<endl;
            x=Kasawektor[i]->zwrocinf()->Zwrocpracownika();
            if (x==1){
                cout<<"Staz pracy (w latach) : " <<Kasawektor[i]->zwrocinf()->Zwrocwlasciwosc()<<endl;
            } else {
                cout<<"Rok studiow : " <<Kasawektor[i]->zwrocinf()->Zwrocwlasciwosc()<<endl;
            }
            cout<<"----------------"<<endl;
        }
    }

    void edytujsaldo(int id, double kwota){
    int i,nrkonta;
     bool pom;
        for ( i=0 ; i<Kasawektor.size();i++){
            int pom1=Kasawektor[i]->zwrocinf()->Zwrocid();
            if (pom1==id){
                pom=true;
                *Kasawektor[i]+=kwota;
                nrkonta=i;
            }
        }
        if(pom==false) {
            cout<<"------UWAGA------"<<endl;
            cout<<"Nie znaleziona konta do edycji o podanym ID w bazie"<<endl;
            cout<<"----------------"<<endl;
        }
        else{
            cout<<"---------------"<<endl;
            cout<<"Nowe saldo konta wynosi :" << " " <<Kasawektor[nrkonta]->Zwrocstan();}
    }
};
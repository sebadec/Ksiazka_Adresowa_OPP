#ifndef UZYTKONIKMENAGER_H
#define UZYTKONIKMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class UzytkonikMenager{

int idZalogowanegoUzytkownika = 0;
vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;


public:
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszytskichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void wylogowanieUzytkownikaUM();
    void zmianaHaslaZalogowanegoUzytkownikaUM (int idZalogowanegoUzytkownika);
    UzytkonikMenager(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){};
    int pobierzIdZalogowanegoUzytkownika();
    //static int idZalogowanegoUzytkownikaPublic = idZalogowanegoUzytkownika;

};

#endif

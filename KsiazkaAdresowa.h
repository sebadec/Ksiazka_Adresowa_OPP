#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkonikMenager.h"
#include "AdresatMenager.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkonikMenager uzytkownikMenager;
    AdresatMenager adresatMenager;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenager(nazwaPlikuZUzytkownikami)
    {
        uzytkownikMenager.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void dodajAdresata();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wczytajAdresatowZalogowanegoUzytkownikaZPlikuKA();
};

#endif

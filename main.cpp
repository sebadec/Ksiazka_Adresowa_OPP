#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy22.txt", "Adresaci22.txt");

    ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPlikuKA();

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    ksiazkaAdresowa.rejestracjaUzytkownika();

    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();

    ksiazkaAdresowa.dodajAdresata();

    ksiazkaAdresowa.wylogowanieUzytkownika();

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    return 0;
}

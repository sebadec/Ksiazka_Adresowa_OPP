#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    ksiazkaAdresowa.rejestracjaUzytkownika();

    cin.sync();

    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPlikuKA();

    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();

    ksiazkaAdresowa.dodajAdresata();

    ksiazkaAdresowa.dodajAdresata();

    ksiazkaAdresowa.usunAdresata();

    ksiazkaAdresowa.edytujAdresata();

    ksiazkaAdresowa.wylogowanieUzytkownika();

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    return 0;
}

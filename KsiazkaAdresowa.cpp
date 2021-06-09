#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenager.wypiszWszytskichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenager.logowanieUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenager.wylogowanieUzytkownikaUM();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenager.dodajAdresataAM();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownikaUM(uzytkownikMenager.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPlikuKA()
{
    adresatMenager.wczytajAdresatowZalogowanegoUzytkownikaZPlikuAM();
}

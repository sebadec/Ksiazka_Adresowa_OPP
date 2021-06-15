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
    if (uzytkownikMenager.czyUzytkownikJestZalogowany())
    {
        adresatMenager = new AdresatMenager(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenager.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownikaUM();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenager.wylogowanieUzytkownikaUM();
    delete adresatMenager;
    adresatMenager = NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
    if (uzytkownikMenager.czyUzytkownikJestZalogowany())
    {
        adresatMenager->dodajAdresataAM();
    }
    else
    {
    cout << "Pierw sie zaloguj" << endl;
    system("pause");
    }
}

void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPlikuKA()
{
    adresatMenager.wczytajAdresatowZalogowanegoUzytkownikaZPlikuAM();
}

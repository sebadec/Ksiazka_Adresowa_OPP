#include "AdresatMenager.h"

int AdresatMenager::dodajAdresataAM()
{
    Adresat adresat;

    //idZalogowanegoUzytkownikaAM = UzytkonikMenager::pobierzIdZalogowanegoUzytkownika();
    idZalogowanegoUzytkownikaAM = 1;


    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

Adresat AdresatMenager::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownikaAM);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj numer telefonu: ";
    adresat.ustawNowyNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

/*
int AdresatMenager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
*/

void AdresatMenager::wczytajAdresatowZalogowanegoUzytkownikaZPlikuAM()
{
    plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

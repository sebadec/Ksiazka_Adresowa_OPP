#include "AdresatMenager.h"

void AdresatMenager::dodajAdresataAM()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany." << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;
    system("pause");
}

Adresat AdresatMenager::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustawId( (plikZAdresatami.pobierzIdOstatniegoAdresata() + 1) );
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

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

void AdresatMenager::wczytajAdresatowZalogowanegoUzytkownikaZPlikuAM(int idZalogowanegoUzytkownikaAM)
{
    plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownikaAM);
}

void AdresatMenager::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> Adresat::pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.usunWybranaLinieWPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return;
}

int AdresatMenager::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenager::edytujAdresata()
{
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if ( adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                //adresaci[i].imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].imie);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                //adresaci[i].nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].nazwisko);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNowyNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

void AdresatMenager::zaktualizujDaneWybranegoAdresata(Adresat adresat)
{
    plikZAdresatami.edytujWybranaLinieWPliku(adresat);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

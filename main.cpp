#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

class Uzytkownik
{
public:
    struct UzytkownikKsiazki
    {
        int idUzytkownika;
        string nazwa, haslo;
    };
    vector <UzytkownikKsiazki> uzytkownicy;

public:
    void wczytywanieUzytkownikowZPliku()
    {
        string linia;
        fstream plik;
        plik.open("Uzytkownicy.txt", ios::in);

        if (plik.good() == false)
        {

        }
        else
        {
            for (int i = 0; !plik.eof(); i++)
            {
                getline (plik,linia);
                if (linia!="")
                {
                    string s = linia;
                    string delimiter = "|";
                    size_t pos = 0;
                    string token[3];
                    int i = 0;
                    while ((pos = s.find(delimiter)) != string::npos)
                    {
                        token[i] = s.substr(0, pos);
                        s.erase(0, pos + delimiter.length());
                        i++;
                    }
                    UzytkownikKsiazki adres;
                    adres.idUzytkownika = atoi(token[0].c_str());
                    cout << "Id: " << adres.idUzytkownika << endl;
                    adres.nazwa = token[1];
                    cout << "Nazwa: " << adres.nazwa << endl;
                    adres.haslo = token[2];
                    cout << "Haslo: " << adres.haslo << endl;

                    uzytkownicy.push_back(adres);
                }
            }
        }
        plik.close();
        system("pause");
    };

    void logowanieUzytkownika()
    {
        system("cls");
        string imieUzytkownika, hasloUzytkownika;
        int idUzytkownikaStala, maxIdAdresataStala;
        cout << "Podaj login: ";
        cin >> imieUzytkownika;
        for (int i = 0; i<uzytkownicy.size(); i++)
        {
            if (imieUzytkownika == uzytkownicy[i].nazwa)
            {
                cout << "Podaj haslo: ";
                cin >> hasloUzytkownika;
                if (hasloUzytkownika == uzytkownicy[i].haslo)
                {
                    cout << "Logowanie udane" << endl;
                    idUzytkownikaStala = uzytkownicy[i].idUzytkownika;
                    //maxIdAdresataStala = wyznaczanieMaxIdAdresata();
                    //menu(idUzytkownikaStala);
                    system("pause");
                    return;
                }
                else
                {
                    cout << "Podane haslo jest nieprawidlowe." << endl;
                    system("pause");
                    return;
                }
            }
        }
        cout << "Brak uzytkownika o podanym loginie." << endl;
        system("pause");
    };
    void dodajUzytkownika()
    {
        UzytkownikKsiazki adres;
        if (uzytkownicy.size()==0)
        {
            adres.idUzytkownika = 0;
        }
        else
        {
            adres.idUzytkownika = uzytkownicy[uzytkownicy.size()-1].idUzytkownika+1;
        }
        cout << "Podaj login:";
        cin >> adres.nazwa;
        cout << "Podaj haslo:";
        cin >> adres.haslo;

        uzytkownicy.push_back(adres);

        fstream plik;
        plik.open("Uzytkownicy.txt", ios::out | ios::app);
        if (plik.good())
        {
            plik << adres.idUzytkownika << "|" << adres.nazwa << "|" << adres.haslo << "|" <<  endl;

            plik.close();

            cout << "Uzytkownik zostala dodany." << endl;
        }
        else
        {
            cout << "Nie mozna otworzyc pliku: Uzytkownicy.txt" << endl;
        }
        system("pause");
    }
};

int main()
{
    Uzytkownik XXXX;

    char wybor;

    XXXX.wczytywanieUzytkownikowZPliku();

    while (true)
    {
        system("cls");
        cout << "1. Logowanie" << endl;
        cout << "2. Rejestracja" << endl;
        cout << "3. Zamknij program" << endl;
        cin >> wybor;

        if (wybor == '1')
        {
            XXXX.logowanieUzytkownika();
        }
        else if (wybor == '2')
        {
            XXXX.dodajUzytkownika();
        }
        else if (wybor == '3')
        {
            exit(0);
        }
    }

    return 0;
}

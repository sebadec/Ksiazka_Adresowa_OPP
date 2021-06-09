#ifndef ADRESATMENAGER_H
#define ADRESATMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "UzytkonikMenager.h"
//#include "KsiazkaAdresowa.h"

using namespace std;

class AdresatMenager{

string nazwaPlikuZAdresatami = "Adresaci.txt";
int idOstatniegoAdresata;
vector <Adresat> adresaci;
int idZalogowanegoUzytkownikaAM;

    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata();

public:
    AdresatMenager(){};
    int dodajAdresataAM();
    void wczytajAdresatowZalogowanegoUzytkownikaZPlikuAM();



};

#endif

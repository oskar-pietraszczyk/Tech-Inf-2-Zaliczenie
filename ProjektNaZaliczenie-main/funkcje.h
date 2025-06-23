#ifndef FUNKCJE_H
#define FUNKCJE_H

typedef struct {
    char marka[50];
    char model[50];
    int rok;
    int przebieg;
    float cena;
} Samochod;

void dodajSamochod(Samochod** baza, int* liczbaSamochodow);
void zapiszDoPliku(Samochod* baza, int liczbaSamochodow, const char* nazwaPliku);
void wczytajZPliku(Samochod** baza, int* liczbaSamochodow, const char* nazwaPliku);
void wyswietlBaze(Samochod* baza, int liczbaSamochodow);
void zwolnijPamiec(Samochod* baza);

#endif

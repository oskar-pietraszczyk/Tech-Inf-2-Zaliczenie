#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

int main() {
    Samochod* baza = NULL;
    int liczbaSamochodow = 0;
    char nazwaPliku[] = "baza_samochodow.txt";

    int wybor;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Dodaj samochod\n");
        printf("2. Wyswietl baze\n");
        printf("3. Zapisz do pliku\n");
        printf("4. Wczytaj z pliku\n");
        printf("0. Wyjscie\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1: dodajSamochod(&baza, &liczbaSamochodow); break;
            case 2: wyswietlBaze(baza, liczbaSamochodow); break;
            case 3: zapiszDoPliku(baza, liczbaSamochodow, nazwaPliku); break;
            case 4: wczytajZPliku(&baza, &liczbaSamochodow, nazwaPliku); break;
            case 0: break;
            default: printf("Niepoprawny wybór!\n");
        }
    } while (wybor != 0);

    zwolnijPamiec(baza);
    return 0;
}

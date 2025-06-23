#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje.h"

void dodajSamochod(Samochod** baza, int* liczbaSamochodow) {
    *baza = realloc(*baza, (*liczbaSamochodow + 1) * sizeof(Samochod));
    if (*baza == NULL) {
        printf("Błąd alokacji pamięci!\n");
        exit(1);
    }

    Samochod* nowy = &((*baza)[*liczbaSamochodow]);

    printf("Podaj markę: ");
    scanf(" %[^\n]", nowy->marka);
    printf("Podaj model: ");
    scanf(" %[^\n]", nowy->model);
    printf("Podaj rok produkcji: ");
    scanf("%d", &nowy->rok);
    printf("Podaj przebieg (km): ");
    scanf("%d", &nowy->przebieg);
    printf("Podaj cenę (PLN): ");
    scanf("%f", &nowy->cena);

    (*liczbaSamochodow)++;
    printf("Samochód dodany.\n");
}

void zapiszDoPliku(Samochod* baza, int liczbaSamochodow, const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku, "w");
    if (!plik) {
        printf("Nie można otworzyć pliku do zapisu.\n");
        return;
    }

    for (int i = 0; i < liczbaSamochodow; i++) {
        fprintf(plik, "%s\n%s\n%d\n%d\n%.2f\n",
                baza[i].marka,
                baza[i].model,
                baza[i].rok,
                baza[i].przebieg,
                baza[i].cena);
    }

    fclose(plik);
    printf("Dane zapisane do pliku '%s'.\n", nazwaPliku);
}

void wczytajZPliku(Samochod** baza, int* liczbaSamochodow, const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku, "r");
    if (!plik) {
        printf("Nie można otworzyć pliku do odczytu.\n");
        return;
    }

    *liczbaSamochodow = 0;
    *baza = NULL;
    Samochod temp;

    while (fgets(temp.marka, sizeof(temp.marka), plik) &&
           fgets(temp.model, sizeof(temp.model), plik) &&
           fscanf(plik, "%d\n%d\n%f\n", &temp.rok, &temp.przebieg, &temp.cena) == 3) {
        // Usuwanie znaku nowej linii z nazwy/modelu
        temp.marka[strcspn(temp.marka, "\n")] = '\0';
        temp.model[strcspn(temp.model, "\n")] = '\0';

        *baza = realloc(*baza, (*liczbaSamochodow + 1) * sizeof(Samochod));
        if (*baza == NULL) {
            printf("Błąd alokacji pamięci przy wczytywaniu!\n");
            exit(1);
        }

        (*baza)[*liczbaSamochodow] = temp;
        (*liczbaSamochodow)++;
    }

    fclose(plik);
    printf("Dane wczytane z pliku '%s'.\n", nazwaPliku);
}

void wyswietlBaze(Samochod* baza, int liczbaSamochodow) {
    if (liczbaSamochodow == 0) {
        printf("Baza jest pusta.\n");
        return;
    }

    for (int i = 0; i < liczbaSamochodow; i++) {
        printf("\nSamochód #%d:\n", i + 1);
        printf("Marka: %s\n", baza[i].marka);
        printf("Model: %s\n", baza[i].model);
        printf("Rok produkcji: %d\n", baza[i].rok);
        printf("Przebieg: %d km\n", baza[i].przebieg);
        printf("Cena: %.2f PLN\n", baza[i].cena);
    }
}

void zwolnijPamiec(Samochod* baza) {
    free(baza);
}

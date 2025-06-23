#include <stdio.h>

void male_litery(char *ciag)
{
    while (*ciag)
    {
        if ('A' <= *ciag && *ciag <= 'Z')
        {
            *ciag += ('a' - 'A');
        }
        ciag++;
    }
}

void wielkie_litery(char *ciag)
{
    while (*ciag)
    {
        if ('a' <= *ciag && *ciag <= 'z')
        {
            *ciag -= ('a' - 'A');
        }
        ciag++;
    }
}

int dlugosc(char*ciag)
{
    int i;
    while(*ciag)
    {
        i++;
        ciag++;
    }
    return i;
}

int main() {

    char ciag[] = "Leo lEo 15";
    printf("Tekst: %s\n", ciag);


    male_litery(ciag);
    printf("Male litery: %s\n", ciag);


    wielkie_litery(ciag);
    printf("Wielkie litery: %s\n", ciag);


    printf("Dlugosc tekstu to %d symboli\n", dlugosc(ciag));


    return 0;
}

//dobry kodzik sdsadaisjdaisd
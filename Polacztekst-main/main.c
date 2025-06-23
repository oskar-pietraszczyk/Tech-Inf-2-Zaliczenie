#include <stdio.h>

int polaczTekst(char *source1, char *source2, char *destination){
    while (*source1) {
        *destination++ = *source1++;
    }
    while (*source2) {
        *destination++ = *source2++;
    }
    *destination = '\0';
    return 0;
}
int main(){

    char str1[] = "Aleksandr";
    char str2[] = " ma klota i gupota.";
    char str3[80] = "";
    printf("\nPierwszy tekst: %s\n\n", str1);
    printf("Drugi tekst: %s\n\n", str2);
    polaczTekst(str1,str2,str3);
    printf("Polaczony tekst: %s\n\n", str3);

    return 0;
}
#include <iostream>
#include "kolo.h"

int main() {
    double r;
    std::cout << "Podaj promien kola: ";
    std::cin >> r;

    Kolo kolo(r);

    std::cout << "Promien: " << kolo.getPromien() << std::endl;
    std::cout << "Srednica: " << kolo.getSrednica() << std::endl;
    std::cout << "Obwod: " << kolo.getObwod() << std::endl;

    return 0;
}
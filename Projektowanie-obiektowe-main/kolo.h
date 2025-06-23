#ifndef KOLO_H
#define KOLO_H

class Kolo {
private:
    double promien;

public:
    Kolo(double r);          // Konstruktor
    double getPromien() const;
    double getSrednica() const;
    double getObwod() const;
};

#endif

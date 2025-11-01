#pragma once
#include <iostream>

class Polinom
{
    int* coeficienti;
    int nrCoeficienti;

    bool esteInvalid() const;

    int getNrMinimCoeficienti(const Polinom& p) const;
    int getNrMaximCoeficienti(const Polinom& p) const;

public:

    Polinom(const int& nrCoeficienti = 0, const int* const& coeficienti = nullptr);
    Polinom(const Polinom& polinom);
    Polinom& operator=(const Polinom& polinom);
    ~Polinom();

    const int getGrad() const;

    // operatorul de indexare (returneaza un coeficient din polinom pe baza index-ului primit)

    int& operator[](const int& index);
    const int& operator[](const int& index) const;

    // operatorul sageata

    Polinom* operator->();

    // operatorul - care returneaza opusul unui polinom (-p)

    Polinom operator-() const;

    // operatorii de incrementare / decrementare (formele prefixate si postfixate)
    // incrementeaza / decrementeaza doar termenul liber

    Polinom& operator++(); // prefixat (++p)
    Polinom& operator--(); // prefixat (--p)

    Polinom operator++(int); // postfixat (p++)
    Polinom operator--(int); // postfixat (p--)

    // operatorii aritmetici supraincarcati ca functii membre

    Polinom operator+(const Polinom& polinom) const;
    Polinom operator-(const Polinom& polinom) const;
    Polinom operator*(const Polinom& polinom) const;

    // operatorii logici de testare a egalitatii

    bool operator==(const Polinom& polinom) const;
    bool operator!=(const Polinom& polinom) const;

    // operatorii aritmetici supraincarcati ca functii friend

    friend Polinom operator+(const Polinom& polinom, const int& scalar);
    friend Polinom operator+(const int& scalar, const Polinom& polinom);

    friend Polinom operator-(const Polinom& polinom, const int& scalar);
    friend Polinom operator-(const int& scalar, const Polinom& polinom);

    friend Polinom operator*(const Polinom& polinom, const int& scalar);
    friend Polinom operator*(const int& scalar, const Polinom& polinom);

    // operatorul de afisare supraincarcat ca functie friend

    friend std::ostream& operator<<(std::ostream& out, const Polinom& polinom);
};
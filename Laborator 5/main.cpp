#include "Polinom.h"

int main()
{
    int nrCoef1 = 5;
    int nrCoef2 = 4;

    int* coef1 = new int [nrCoef1] { -1, 5, 0, -2, 3 };
    int* coef2 = new int [nrCoef2] { 6, -2, 4, -1 };

    Polinom p(nrCoef1, coef1);
    Polinom q(nrCoef2, coef2);

    std::cout << "Polinomul p este egal cu: " << p << '\n';
    std::cout << "Polinomul q este egal cu: " << q << '\n';

    Polinom r = p + q;

    std::cout << "\n==================== Adunare ====================\n\n" << r << '\n';
    r = q - p;
    std::cout << "\n==================== Scadere ====================\n\n" << r << '\n';
    r = p * q;
    std::cout << "\n==================== Inmultire ====================\n\n" << r << '\n';

    std::cout << "\n==================== Inmultire cu scalar ====================\n\n" << p * 2 << '\n';
    std::cout << "\n==================== Adunare cu scalar ====================\n\n" << q + 10 << '\n';

    std::cout << "\n==================== Polinom minus scalar ====================\n\n" << p - 2 << '\n';
    std::cout << "\n==================== Scalar minus polinom ====================\n\n" << 2 - q << '\n';

    std::cout << "\n==================== Incrementare prefixata ====================\n\n" << ++r << '\n';
    std::cout << "\n==================== Decrementare postfixata ====================\n\n" << r-- << '\n';


    std::cout << "\n==================== Polinomul opus ====================\n\n" << -q << '\n';

    if (p == q)
    {
        std::cout << "\nPolinoamele p si q sunt egale\n";
    }
    else
    {
        std::cout << "\nPolinoamele p si q sunt diferite\n";
    }

    if (p != r)
    {
        std::cout << "Polinoamele p si r sunt diferite\n\n";
    }
    else
    {
        std::cout << "Polinoamele p si r sunt egale\n\n";
    }

    std::cout << "Gradul polinomului p este: " << p.getGrad() << '\n';
    std::cout << "Gradul polinomului r este: " << r->getGrad() << '\n';
    std::cout << "Termenul liber al polinomului q este: " << q[0] << "\n\n";

    delete[] coef1;
    delete[] coef2;
    return 0;
}
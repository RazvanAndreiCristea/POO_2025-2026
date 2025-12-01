#include "Coada.h"

int main()
{
    Coada<int> ci;

    ci.enQueue(4);
    ci.enQueue(-1);
    ci.enQueue(5);
    ci.enQueue(10);

    std::cout << ci << '\n';
    ci.deQueue();
    std::cout << ci << '\n';

    int* vi = ci.toVector();
    sortareVector(vi, ci.getSize());
    afisareVector(vi, ci.getSize());

    delete[] vi;

    Coada<double> cd;

    cd.enQueue(9.5);
    cd.enQueue(-0.5);
    cd.enQueue(5.25);
    cd.enQueue(10.8);

    std::cout << cd << '\n';
    cd.deQueue();
    std::cout << cd << '\n';

    cd.enQueue(9.14);
    cd.enQueue(100.0);

    double* vd = cd.toVector();
    sortareVector(vd, cd.getSize());
    afisareVector(vd, cd.getSize());

    delete[] vd;

    Coada<NrComplex> cc;

    cc.enQueue(NrComplex(5, -2));
    cc.enQueue(NrComplex(4, 0));
    cc.enQueue(NrComplex(-3, 2));
    cc.enQueue(NrComplex(2, -1));

    std::cout << cc << '\n';
    cc.deQueue();
    std::cout << cc << '\n';

    cc.enQueue(NrComplex(1, 1));
    cc.enQueue(NrComplex(-6, 8));

    NrComplex* vc = cc.toVector();
    sortareVector(vc, cc.getSize());
    afisareVector(vc, cc.getSize());

    delete[] vc;
    return 0;
}
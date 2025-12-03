#include "Cub.h"
#include "Sfera.h"
#include "Cilindru.h"
#include "Tetraedru.h"
#include "ConCircular.h"
#include "VectorHelper.h"

int main()
{
    int nrCorpuri = 18;
    CorpGeometric** corpuri = new CorpGeometric * [nrCorpuri];

    corpuri[0] = new Cub(2.5f, "Rosu");
    corpuri[1] = new Cilindru(3.0f, 10.0f, "Albastru");
    corpuri[2] = new Con(4.0f, 6.5f, 7.5f, "Verde");
    corpuri[3] = new Sfera(5.2f, "Galben");
    corpuri[4] = new Paralelipiped(2.0f, 3.5f, 4.0f, "Portocaliu");
    corpuri[5] = new Tetraedru(3.3f, "Mov");

    corpuri[6] = new Cub(1.8f, "Albastru");
    corpuri[7] = new Sfera(2.0f, "Rosu");
    corpuri[8] = new Con(2.5f, 7.0f, 7.5f, "Turcoaz");
    corpuri[9] = new Paralelipiped(4.0f, 2.5f, 6.0f, "Verde");
    corpuri[10] = new Cilindru(1.2f, 8.0f, "Roz");
    corpuri[11] = new Cub(4.1f, "Negru");

    corpuri[12] = new Tetraedru(2.2f, "Albastru");
    corpuri[13] = new Sfera(3.7f, "Verde");
    corpuri[14] = new Con(3.8f, 5.0f, 6.0f, "Portocaliu");
    corpuri[15] = new Paralelipiped(6.0f, 1.5f, 2.0f, "Alb");
    corpuri[16] = new Tetraedru(4.0f, "Galben");
    corpuri[17] = new Cilindru(2.0f, 12.0f, "Gri");

    afisareCorpuri(corpuri, nrCorpuri);

    std::cout << "============================================ Dupa partitionare ============================================\n\n";

    sortareCorpuri(corpuri, nrCorpuri);
    afisareCorpuri(corpuri, nrCorpuri);

    for (int i = 0; i < nrCorpuri; i++)
    {
        delete corpuri[i];
    }

    delete[] corpuri;
    return 0;
}
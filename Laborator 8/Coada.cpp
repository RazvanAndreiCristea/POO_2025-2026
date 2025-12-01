#include "Coada.h"

template <typename T>
Nod<T>::Nod(const T& info, Nod* next /*= nullptr*/)
{
    this->info = info;
    this->next = next;
}

template<typename T>
T Nod<T>::getInfo() const
{
    return info;
}

template<typename T>
Nod<T>* Nod<T>::getNext() const
{
    return next;
}

template <typename T>
Coada<T>::Coada()
{
    size = 0;
    front = rear = nullptr;
}

template<typename T>
Coada<T>::~Coada()
{
    while (front != nullptr)
    {
        Nod<T>* aux = front;
        front = front->next;
        delete aux;
        size--;
    }

    rear = nullptr;
}

template<typename T>
int Coada<T>::getSize() const
{
    return size;
}

template<typename T>
T Coada<T>::getRearInfo() const
{
    return rear->info;
}

template<typename T>
T Coada<T>::getFrontInfo() const
{
    return front->info;
}

template<typename T>
bool Coada<T>::isEmpty() const
{
    return front == nullptr && rear == nullptr;
}

template<typename T>
void Coada<T>::deQueue()
{
    if (isEmpty())
    {
        return;
    }

    Nod<T>* nodDeSters = front;

    if (front == rear)
    {
        front = rear = nullptr;
        delete nodDeSters;
        size--;

        return;
    }

    front = front->next;
    delete nodDeSters;
    size--;
}

template<typename T>
void Coada<T>::enQueue(const T& info)
{
    Nod<T>* noulNod = new Nod<T>(info);

    if (isEmpty())
    {
        front = rear = noulNod;
        size++;

        return;
    }

    rear->next = noulNod;
    rear = noulNod;
    size++;
}

template<typename T>
T* Coada<T>::toVector() const
{
    if (isEmpty())
    {
        return nullptr;
    }

    int index = 0;
    int dimensiune = size;
    T* vector = new T[dimensiune];

    Nod<T>* aux = front;

    while (aux != nullptr)
    {
        vector[index++] = aux->info;
        aux = aux->next;
    }

    return vector;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Coada<T>& coada)
{
    if (coada.isEmpty())
    {
        out << "Coada este goala nu avem ce afisa\n\n";
        return out;
    }

    Nod<T>* aux = coada.front;

    out << "Elementele din coada sunt: ";

    while (aux != nullptr)
    {
        out << aux->getInfo() << " ";
        aux = aux->getNext();
    }

    out << '\n';

    return out;
}

template<typename T>
void sortareVector(T*& vector, const int& dimensiune)
{
    if (vector == nullptr || dimensiune <= 0)
    {
        return;
    }

    for (int i = 0; i < dimensiune - 1; i++)
    {
        for (int j = i + 1; j < dimensiune; j++)
        {
            if (vector[i] > vector[j])
            {
                T aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

template<typename T>
void afisareVector(T*& vector, const int& dimensiune)
{
    if (vector == nullptr || dimensiune <= 0)
    {
        return;
    }

    for (int i = 0; i < dimensiune; i++)
    {
        std::cout << vector[i] << '\n';
    }

    std::cout << '\n';
}

void testTemplate()
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
}
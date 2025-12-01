#pragma once
#include "NrComplex.h"

template <typename T>
class Coada;

template <typename T>
class Nod
{
    T info;
    Nod* next;

public:
    friend class Coada<T>;
    Nod(const T& info, Nod* next = nullptr);

    T getInfo() const;
    Nod<T>* getNext() const;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Coada<T>& coada);

template <typename T>
class Coada
{
    int size;
    Nod<T>* front;
    Nod<T>* rear;

public:

    Coada();
    ~Coada();

    int getSize() const;

    T getRearInfo() const;
    T getFrontInfo() const;

    bool isEmpty() const;

    void deQueue();
    void enQueue(const T& info);

    T* toVector() const; // converteste coada intr-un vector de tipul T

    friend std::ostream& operator<< <>(std::ostream& out, const Coada& coada);
};

template<typename T>
void sortareVector(T*& vector, const int& dimensiune);

template<typename T>
void afisareVector(T*& vector, const int& dimensiune);
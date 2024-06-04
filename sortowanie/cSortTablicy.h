#pragma once
#include "cTablica.h"

class cSortTablicy
{
 private:
    cTablica* tablica;

public:
    cSortTablicy() : tablica(nullptr) {}

    ~cSortTablicy();

    void wprowadzZKlawiatury(int n);

    void losujElementy(int n);

    void sortujShakerSort();

    void sortujQuickSort();

    void pokazWyniki() const;
};


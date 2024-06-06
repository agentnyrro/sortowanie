#ifndef CSORTTABLICY_H
#define CSORTTABLICY_H

#include "cTablica.h"
#include <vector>
#include <iostream>

class cSortTablicy {
private:
    cTablica* tablica;

public:
    ~cSortTablicy();
    void wprowadzZKlawiatury(int n);
    void losujElementy(int n);
    void ustawElementy(const std::vector<int>& tab);
    std::vector<int> getElements() const; // Dodana metoda
    void sortujShakerSort();
    void sortujQuickSortLomuto();
    void sortujQuickSortHoare();
    void sortujHeapSort();
    void pokazWyniki() const;
};

#endif // CSORTTABLICY_H

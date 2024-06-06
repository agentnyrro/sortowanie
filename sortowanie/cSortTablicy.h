#ifndef CSORTTABLICY_H
#define CSORTTABLICY_H

#include "cTablica.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class cSortTablicy {
private:
    cTablica* tablica;
    enum rodzajTab {los, uporz, odwr, prawie};
    enum algorytm {shaker, qHoare, qLomuto, heap};
public:
    rodzajTab rTab;
    algorytm alg;
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
    void zapiszWyniki(ofstream& write);
};

#endif // CSORTTABLICY_H

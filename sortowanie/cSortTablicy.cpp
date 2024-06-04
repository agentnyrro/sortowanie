#include "cSortTablicy.h"

cSortTablicy::~cSortTablicy() {
    delete tablica;
}

void cSortTablicy::wprowadzZKlawiatury(int n) {
    std::vector<int> tab(n);
    std::cout << "Wprowadz " << n << " elementow: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> tab[i];
    }
    tablica = new cTablica(tab);
}

void cSortTablicy::losujElementy(int n) {
    std::vector<int> tab(n);
    std::srand(std::time(0));
    for (int i = 0; i < n; ++i) {
        tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
    }
    tablica = new cTablica(tab);
}

void cSortTablicy::sortujShakerSort() {
    if (tablica == nullptr) throw std::runtime_error("Tablica jest pusta");
    tablica->shakerSort();
}

void cSortTablicy::sortujQuickSort() {
    if (tablica == nullptr) throw std::runtime_error("Tablica jest pusta");
    tablica->quickSort(0, tablica->size() - 1);
}

void cSortTablicy::pokazWyniki() const {
    if (tablica == nullptr) throw std::runtime_error("Tablica jest pusta");
    std::cout << "Tablica po sortowaniu: ";
    tablica->print();
    std::cout << "Liczba porownan: " << tablica->getPorownania() << std::endl;
    std::cout << "Liczba przestawien: " << tablica->getPrzestawienia() << std::endl;
}
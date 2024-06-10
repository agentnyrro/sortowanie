#include "cSortTablicy.h"
#include <ctime>
#include <cstdlib>
//#include <stdexcept>
#include "myExceptions.h"
#include <algorithm>

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

    switch (rTab)
    {
    // tablica z losowymi liczbami
    case cSortTablicy::los:
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
        }
        ustawElementy(tab);
        break;

     // tablica z liczbami uporzadkowanymi rosnaco
    case cSortTablicy::uporz:
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
        }
        std::sort(tab.begin(), tab.end());
        ustawElementy(tab);
        break;

    // tablica z liczbami uporzadkowanymi malejaco
    case cSortTablicy::odwr:
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
        }
        std::sort(tab.begin(), tab.end(), std::greater<>());
        ustawElementy(tab);
        break;

    // tablica prawie posortowana
    case cSortTablicy::prawie:
        // najpierw utworz tablice i posortuj
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 899
        }
        std::sort(tab.begin(), tab.end());
        
        // zamien losowe 10% elementow
        for (int i = 0; i < n/20; i++)
        {
            int a = std::rand() % n;
            int b = std::rand() % n;
            std::swap(tab[a], tab[b]);
        }
        ustawElementy(tab);
        break;
    default:
        throw MyExceptions("Niewiadomy rodzaj tablicy.\n");
        break;
    }

}

void cSortTablicy::ustawElementy(const std::vector<int>& tab) {
    delete tablica;
    tablica = new cTablica(tab);
}

std::vector<int> cSortTablicy::getElements() const {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta");
    return tablica->getElements();
}

void cSortTablicy::sortujShakerSort() {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta");
    tablica->shakerSort();
}

void cSortTablicy::sortujQuickSortLomuto() {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta");
    tablica->quickSortLomuto(0, tablica->size() - 1);
}

void cSortTablicy::sortujQuickSortHoare() {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta");
    tablica->quickSortHoare(0, tablica->size() - 1);
}

void cSortTablicy::sortujHeapSort() {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta");
    tablica->heapSort();
}
void cSortTablicy::wypiszWyniki(ofstream& write)
{
    // Zapisz nazwe metody
    switch (alg)
    {
    case cSortTablicy::shaker:
        write << "Shaker sort\t\t\t";
        break;
    case cSortTablicy::qHoare:
        write << "Quick sort z podzialem Hoare'a\t";
        break;
    case cSortTablicy::qLomuto:
        write << "Quick sort z podzialem Lomuto\t";
        break;
    case cSortTablicy::heap:
        write << "Sortowanie przez kopcowanie\t";
        break;
    default:
        throw MyExceptions("Niewiadomy rodzaj sortowania\n");
        break;
    }

    // Zapisz dlugosc tablicy
    write << tablica->size() << '\t';

    // Zapisz rodzaj tablicy
    switch (rTab)
    {
    case cSortTablicy::los:
        write << "tablica uzupelniona losowymi liczbami\t\t";
        break;
    case cSortTablicy::uporz:
        write << "tablica z liczbami posortowanymi rosnaco\t";
        break;
    case cSortTablicy::odwr:
        write << "tablica z liczbami posortowanymi malejaco\t";
        break;
    case cSortTablicy::prawie:
        write << "tablica czesciowo uporzadkowana\t\t\t";
        break;
    default:
        throw MyExceptions("Niewiadomy rodzaj tablicy.\n");
        break;
    }

    // Zapisz liczbe porownan
    write << tablica->getPorownania() << "\t\t\t";

    // Zapisz liczbe przestawien
    write << tablica->getPrzestawienia() << "\t\n";
}

void cSortTablicy::pokazWyniki() const {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta");
    std::cout << "Tablica po sortowaniu: ";
    tablica->print();
    std::cout << "Liczba porownan: " << tablica->getPorownania() << std::endl;
    std::cout << "Liczba przestawien: " << tablica->getPrzestawienia() << std::endl;
}



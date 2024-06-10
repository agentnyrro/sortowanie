#include "cSortTablicy.h"
#include <ctime>
#include <cstdlib>
#include "myExceptions.h"
#include <algorithm>

// destruktor do zwolnienia dynamicznie alokowanej pamiêci
cSortTablicy::~cSortTablicy() {
    delete tablica;
}


void cSortTablicy::wprowadzZKlawiatury(int n) {
    std::vector<int> tab(n);
    std::cout << "Wprowadz " << n << " elementow: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> tab[i]; // wprowadzenie elementów do wektora
    }
    tablica = new cTablica(tab); // utworzenie nowej tablicy z wprowadzonymi elementami
}


void cSortTablicy::losujElementy(int n) {
    std::vector<int> tab(n);
    std::srand(std::time(0)); // ziarno generatora liczb losowych na podstawie aktualnego czasu

    switch (rTab)
    {
    case cSortTablicy::los: // losowe liczby
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
        }
        ustawElementy(tab); // ustawienie elementów w tablicy
        break;

    case cSortTablicy::uporz: // liczby posortowane rosn¹co
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
        }
        std::sort(tab.begin(), tab.end()); // sortowanie rosn¹co
        ustawElementy(tab); // ustawienie elementów w tablicy
        break;

    case cSortTablicy::odwr: // liczby posortowane malej¹co
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
        }
        std::sort(tab.begin(), tab.end(), std::greater<>()); // sortowanie malej¹co
        ustawElementy(tab); // ustawienie elementów w tablicy
        break;

    case cSortTablicy::prawie: // prawie posortowane (10% elementów jest nie na swoim miejscu)
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
        }
        std::sort(tab.begin(), tab.end()); // sortowanie rosn¹co

        // zamiana losowych 10% elementów
        for (int i = 0; i < n / 20; i++) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            std::swap(tab[a], tab[b]); // zamiana miejscami dwóch losowych elementów
        }
        ustawElementy(tab); // ustawienie elementów w tablicy
        break;

    default:
        throw MyExceptions("Niewiadomy rodzaj tablicy\n"); // obs³uga b³êdu w przypadku nieznanego typu tablicy
        break;
    }
}


void cSortTablicy::ustawElementy(const std::vector<int>& tab) {
    delete tablica; // zwolnienie starej tablicy
    tablica = new cTablica(tab); // utworzenie nowej tablicy z przekazanymi elementami
}


std::vector<int> cSortTablicy::getElements() const {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta"); // obs³uga b³êdu, gdy tablica jest pusta
    return tablica->getElements(); // zwrócenie elementów tablicy
}


void cSortTablicy::sortujShakerSort() {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta"); // obs³uga b³êdu, gdy tablica jest pusta
    tablica->shakerSort(); // wywo³anie metody sortuj¹cej
}


void cSortTablicy::sortujQuickSortLomuto() {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta"); // obs³uga b³êdu, gdy tablica jest pusta
    tablica->quickSortLomuto(0, tablica->size() - 1); // wywo³anie metody sortuj¹cej z podzia³em Lomuto
}


void cSortTablicy::sortujQuickSortHoare() {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta"); // obs³uga b³êdu, gdy tablica jest pusta
    tablica->quickSortHoare(0, tablica->size() - 1); // wywo³anie metody sortuj¹cej z podzia³em Hoare
}


void cSortTablicy::sortujHeapSort() {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta"); // obs³uga b³êdu, gdy tablica jest pusta
    tablica->heapSort(); // wywo³anie metody sortuj¹cej przez kopcowanie
}


void cSortTablicy::wypiszWyniki(ofstream& write) {
    // zapisz nazwê metody sortowania
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
        throw MyExceptions("Niewiadomy rodzaj sortowania\n"); // obs³uga b³êdu w przypadku nieznanego typu sortowania
        break;
    }

    // zapisz d³ugoœæ tablicy
    write << tablica->size() << '\t';

    // zapisz rodzaj tablicy
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
        throw MyExceptions("Niewiadomy rodzaj tablicy\n"); // obs³uga b³êdu w przypadku nieznanego typu tablicy
        break;
    }

    // zapisz liczbê porównañ
    write << tablica->getPorownania() << "\t\t\t";

    // zapisz liczbê przestawieñ
    write << tablica->getPrzestawienia() << "\t\n";
}


void cSortTablicy::pokazWyniki() const {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta"); // obs³uga b³êdu, gdy tablica jest pusta
    std::cout << "Tablica po sortowaniu: ";
    tablica->print(); // wyœwietlenie posortowanej tablicy
    std::cout << "Liczba porownan: " << tablica->getPorownania() << std::endl; // wyœwietlenie liczby porównañ
    std::cout << "Liczba przestawien: " << tablica->getPrzestawienia() << std::endl; // wyœwietlenie liczby przestawieñ
}

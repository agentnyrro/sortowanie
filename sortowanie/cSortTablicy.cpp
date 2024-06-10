#include "cSortTablicy.h"
#include <ctime>
#include <cstdlib>
#include "myExceptions.h"
#include <algorithm>

// destruktor do zwolnienia dynamicznie alokowanej pami�ci
cSortTablicy::~cSortTablicy() {
    delete tablica;
}

/**
 * @brief Wprowadza elementy z klawiatury
 * @param n Liczba element�w do wprowadzenia
 */
void cSortTablicy::wprowadzZKlawiatury(int n) {
    std::vector<int> tab(n);
    std::cout << "Wprowadz " << n << " elementow: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> tab[i]; // wprowadzenie element�w do wektora
    }
    tablica = new cTablica(tab); // utworzenie nowej tablicy z wprowadzonymi elementami
}

/**
 * @brief Generuje losowe elementy w zale�no�ci od rodzaju tablicy
 * @param n Liczba element�w do wygenerowania
 */
void cSortTablicy::losujElementy(int n) {
    std::vector<int> tab(n);
    std::srand(std::time(0)); // ziarno generatora liczb losowych na podstawie aktualnego czasu

    switch (rTab)
    {
    case cSortTablicy::los: // losowe liczby
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
        }
        ustawElementy(tab); // ustawienie element�w w tablicy
        break;

    case cSortTablicy::uporz: // liczby posortowane rosn�co
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
        }
        std::sort(tab.begin(), tab.end()); // sortowanie rosn�co
        ustawElementy(tab); // ustawienie element�w w tablicy
        break;

    case cSortTablicy::odwr: // liczby posortowane malej�co
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
        }
        std::sort(tab.begin(), tab.end(), std::greater<>()); // sortowanie malej�co
        ustawElementy(tab); // ustawienie element�w w tablicy
        break;

    case cSortTablicy::prawie: // prawie posortowane (10% element�w jest nie na swoim miejscu)
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
        }
        std::sort(tab.begin(), tab.end()); // sortowanie rosn�co

        // zamiana losowych 10% element�w
        for (int i = 0; i < n / 20; i++) {
            int a = std::rand() % n;
            int b = std::rand() % n;
            std::swap(tab[a], tab[b]); // zamiana miejscami dw�ch losowych element�w
        }
        ustawElementy(tab); // ustawienie element�w w tablicy
        break;

    default:
        throw MyExceptions("Niewiadomy rodzaj tablicy\n"); // obs�uga b��du w przypadku nieznanego typu tablicy
        break;
    }
}

/**
 * @brief Ustawia elementy w obiekcie cTablica
 * @param tab Wektor element�w do ustawienia
 */
void cSortTablicy::ustawElementy(const std::vector<int>& tab) {
    delete tablica; // zwolnienie starej tablicy
    tablica = new cTablica(tab); // utworzenie nowej tablicy z przekazanymi elementami
}

/**
 * @brief Zwraca elementy z obiektu cTablica
 * @return Wektor element�w
 */
std::vector<int> cSortTablicy::getElements() const {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta"); // obs�uga b��du, gdy tablica jest pusta
    return tablica->getElements(); // zwr�cenie element�w tablicy
}

/**
 * @brief Sortuje za pomoc� Shaker Sort
 */
void cSortTablicy::sortujShakerSort() {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta"); // obs�uga b��du, gdy tablica jest pusta
    tablica->shakerSort(); // wywo�anie metody sortuj�cej
}

/**
 * @brief Sortuje za pomoc� Quick Sort z podzia�em Lomuto
 */
void cSortTablicy::sortujQuickSortLomuto() {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta"); // obs�uga b��du, gdy tablica jest pusta
    tablica->quickSortLomuto(0, tablica->size() - 1); // wywo�anie metody sortuj�cej z podzia�em Lomuto
}

/**
 * @brief Sortuje za pomoc� Quick Sort z podzia�em Hoare
 */
void cSortTablicy::sortujQuickSortHoare() {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta"); // obs�uga b��du, gdy tablica jest pusta
    tablica->quickSortHoare(0, tablica->size() - 1); // wywo�anie metody sortuj�cej z podzia�em Hoare
}

/**
 * @brief Sortuje za pomoc� Heap Sort
 */
void cSortTablicy::sortujHeapSort() {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta"); // obs�uga b��du, gdy tablica jest pusta
    tablica->heapSort(); // wywo�anie metody sortuj�cej przez kopcowanie
}

/**
 * @brief Zapisuje wyniki do pliku
 * @param write Obiekt ofstream do zapisu wynik�w
 */
void cSortTablicy::wypiszWyniki(ofstream& write) {
    // zapisz nazw� metody sortowania
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
        throw MyExceptions("Niewiadomy rodzaj sortowania\n"); // obs�uga b��du w przypadku nieznanego typu sortowania
        break;
    }

    // zapisz d�ugo�� tablicy
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
        throw MyExceptions("Niewiadomy rodzaj tablicy\n"); // obs�uga b��du w przypadku nieznanego typu tablicy
        break;
    }

    // zapisz liczb� por�wna�
    write << tablica->getPorownania() << "\t\t\t";

    // zapisz liczb� przestawie�
    write << tablica->getPrzestawienia() << "\t\n";
}

/**
 * @brief Wy�wietla wyniki na konsoli
 */
void cSortTablicy::pokazWyniki() const {
    if (tablica == nullptr) throw MyExceptions("Tablica jest pusta"); // obs�uga b��du, gdy tablica jest pusta
    std::cout << "Tablica po sortowaniu: ";
    tablica->print(); // wy�wietlenie posortowanej tablicy
    std::cout << "Liczba porownan: " << tablica->getPorownania() << std::endl; // wy�wietlenie liczby por�wna�
    std::cout << "Liczba przestawien: " << tablica->getPrzestawienia() << std::endl; // wy�wietlenie liczby przestawie�
}

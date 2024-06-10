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
public:
    enum rodzajTab { los, uporz, odwr, prawie };
    enum algorytm { shaker, qHoare, qLomuto, heap };
    rodzajTab rTab;
    algorytm alg;
    ~cSortTablicy();

    /**
    * @brief Wprowadza elementy z klawiatury
    * @param n Liczba elementów do wprowadzenia
    */
    void wprowadzZKlawiatury(int n);

    /**
    * @brief Generuje losowe elementy w zale¿noœci od rodzaju tablicy
    * @param n Liczba elementów do wygenerowania
    */
    void losujElementy(int n);

    /**
    * @brief Ustawia elementy w obiekcie cTablica
    * @param tab Wektor elementów do ustawienia
    */
    void ustawElementy(const std::vector<int>& tab);

    /**
    * @brief Zwraca elementy z obiektu cTablica
    * @return Wektor elementów
    */
    std::vector<int> getElements() const; 

    /**
    * @brief Sortuje za pomoc¹ Shaker Sort
    */
    void sortujShakerSort();

    /**
    * @brief Sortuje za pomoc¹ Quick Sort z podzia³em Lomuto
    */
    void sortujQuickSortLomuto();

    /**
    * @brief Sortuje za pomoc¹ Quick Sort z podzia³em Hoare
    */
    void sortujQuickSortHoare();

    /**
     * @brief Sortuje za pomoc¹ Heap Sort
     */
    void sortujHeapSort();

    /**
    * @brief Wyœwietla wyniki na konsoli
    */
    void pokazWyniki() const;

    /**
    * @brief Zapisuje wyniki do pliku
    * @param write Obiekt ofstream do zapisu wyników
    */
    void wypiszWyniki(ofstream& write);
};

#endif // CSORTTABLICY_H

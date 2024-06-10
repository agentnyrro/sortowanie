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
    * @param n Liczba element�w do wprowadzenia
    */
    void wprowadzZKlawiatury(int n);

    /**
    * @brief Generuje losowe elementy w zale�no�ci od rodzaju tablicy
    * @param n Liczba element�w do wygenerowania
    */
    void losujElementy(int n);

    /**
    * @brief Ustawia elementy w obiekcie cTablica
    * @param tab Wektor element�w do ustawienia
    */
    void ustawElementy(const std::vector<int>& tab);

    /**
    * @brief Zwraca elementy z obiektu cTablica
    * @return Wektor element�w
    */
    std::vector<int> getElements() const; 

    /**
    * @brief Sortuje za pomoc� Shaker Sort
    */
    void sortujShakerSort();

    /**
    * @brief Sortuje za pomoc� Quick Sort z podzia�em Lomuto
    */
    void sortujQuickSortLomuto();

    /**
    * @brief Sortuje za pomoc� Quick Sort z podzia�em Hoare
    */
    void sortujQuickSortHoare();

    /**
     * @brief Sortuje za pomoc� Heap Sort
     */
    void sortujHeapSort();

    /**
    * @brief Wy�wietla wyniki na konsoli
    */
    void pokazWyniki() const;

    /**
    * @brief Zapisuje wyniki do pliku
    * @param write Obiekt ofstream do zapisu wynik�w
    */
    void wypiszWyniki(ofstream& write);
};

#endif // CSORTTABLICY_H

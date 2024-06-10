#ifndef CTABLICA_H
#define CTABLICA_H

#include <vector>
#include <iostream>

class cTablica {
private:
    std::vector<int> tablica;
    int porownania;
    int przestawienia;

    /**
     * @brief Resetuje liczniki porównañ i przestawieñ do zera
    */
    void resetCounts();

    /**
    * @brief Funkcja dziel¹ca dla Quick Sort z podzia³em Lomuto
    * @param low Indeks pocz¹tkowy
    * @param high Indeks koñcowy
    * @return Indeks podzia³u
    */
    int partitionLomuto(int low, int high);

    /**
    * @brief Funkcja dziel¹ca dla Quick Sort z podzia³em Hoare
    * @param low Indeks pocz¹tkowy
    * @param high Indeks koñcowy
    * @return Indeks podzia³u
    */
    int partitionHoare(int low, int high);

    /**
    * @brief Funkcja kopcuj¹ca dla Heap Sort
    * @param n Rozmiar kopca
    * @param i Indeks korzenia kopca
    */
    void heapify(int n, int i);

public:
    cTablica(const std::vector<int>& tab) : tablica(tab), porownania(0), przestawienia(0) {}

    /**
    * @brief Sortuje tablicê algorytmem Shaker Sort, który jest wariantem sortowania b¹belkowego
    */
    void shakerSort();

    /**
 * @brief Sortuje tablicê algorytmem Quick Sort z podzia³em Lomuto
 * @param low Indeks pocz¹tkowy
 * @param high Indeks koñcowy
 */
    void quickSortLomuto(int low, int high);

    /**
    * @brief Sortuje tablicê algorytmem Quick Sort z podzia³em Hoare
    * @param low Indeks pocz¹tkowy
    * @param high Indeks koñcowy
    */
    void quickSortHoare(int low, int high);

    /**
    * @brief Sortuje tablicê algorytmem Heap Sort
    */
    void heapSort();

    /**
    * @brief Zwraca elementy tablicy
    * @return Wektor elementów tablicy
    */
    std::vector<int> getElements() const;

    /**
    * @brief Zwraca liczbê porównañ wykonanych podczas sortowania
    * @return Liczba porównañ
    */
    int getPorownania() const;

    /**
     * @brief Zwraca liczbê przestawieñ wykonanych podczas sortowania
     * @return Liczba przestawieñ
     */
    int getPrzestawienia() const;

    /**
    * @brief Zwraca rozmiar tablicy
    * @return Rozmiar tablicy
    */
    int size() const;

    /**
    * @brief Wyœwietla elementy tablicy
    */
    void print() const;
};

#endif // CTABLICA_H

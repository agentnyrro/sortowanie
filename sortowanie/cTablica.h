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
     * @brief Resetuje liczniki por�wna� i przestawie� do zera
    */
    void resetCounts();

    /**
    * @brief Funkcja dziel�ca dla Quick Sort z podzia�em Lomuto
    * @param low Indeks pocz�tkowy
    * @param high Indeks ko�cowy
    * @return Indeks podzia�u
    */
    int partitionLomuto(int low, int high);

    /**
    * @brief Funkcja dziel�ca dla Quick Sort z podzia�em Hoare
    * @param low Indeks pocz�tkowy
    * @param high Indeks ko�cowy
    * @return Indeks podzia�u
    */
    int partitionHoare(int low, int high);

    /**
    * @brief Funkcja kopcuj�ca dla Heap Sort
    * @param n Rozmiar kopca
    * @param i Indeks korzenia kopca
    */
    void heapify(int n, int i);

public:
    cTablica(const std::vector<int>& tab) : tablica(tab), porownania(0), przestawienia(0) {}

    /**
    * @brief Sortuje tablic� algorytmem Shaker Sort, kt�ry jest wariantem sortowania b�belkowego
    */
    void shakerSort();

    /**
 * @brief Sortuje tablic� algorytmem Quick Sort z podzia�em Lomuto
 * @param low Indeks pocz�tkowy
 * @param high Indeks ko�cowy
 */
    void quickSortLomuto(int low, int high);

    /**
    * @brief Sortuje tablic� algorytmem Quick Sort z podzia�em Hoare
    * @param low Indeks pocz�tkowy
    * @param high Indeks ko�cowy
    */
    void quickSortHoare(int low, int high);

    /**
    * @brief Sortuje tablic� algorytmem Heap Sort
    */
    void heapSort();

    /**
    * @brief Zwraca elementy tablicy
    * @return Wektor element�w tablicy
    */
    std::vector<int> getElements() const;

    /**
    * @brief Zwraca liczb� por�wna� wykonanych podczas sortowania
    * @return Liczba por�wna�
    */
    int getPorownania() const;

    /**
     * @brief Zwraca liczb� przestawie� wykonanych podczas sortowania
     * @return Liczba przestawie�
     */
    int getPrzestawienia() const;

    /**
    * @brief Zwraca rozmiar tablicy
    * @return Rozmiar tablicy
    */
    int size() const;

    /**
    * @brief Wy�wietla elementy tablicy
    */
    void print() const;
};

#endif // CTABLICA_H

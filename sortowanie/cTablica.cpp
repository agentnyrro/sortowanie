#include "cTablica.h"
#include <algorithm>


void cTablica::resetCounts() {
    porownania = 0;
    przestawienia = 0;
}


void cTablica::shakerSort() {
    resetCounts(); // resetowanie liczników porównañ i przestawieñ
    bool swapped = true;
    int start = 0;
    int end = tablica.size() - 1;

    // pêtla kontynuowana, dopóki w poprzednim przebiegu nast¹pi³a zamiana
    while (swapped) {
        swapped = false;

        // przejœcie od pocz¹tku do koñca, przesuwanie najwiêkszych elementów na koniec
        for (int i = start; i < end; ++i) {
            porownania++;
            if (tablica[i] > tablica[i + 1]) { // porównanie s¹siednich elementów
                std::swap(tablica[i], tablica[i + 1]); // zamiana miejscami
                przestawienia++;
                swapped = true; // ustawienie flagi, ¿e nast¹pi³a zamiana
            }
        }

        if (!swapped) break; // jeœli nie by³o zamiany, zakoñcz sortowanie

        swapped = false;
        --end; // zmniejszenie koñca zakresu

        // przejœcie od koñca do pocz¹tku, przesuwanie najmniejszych elementów na pocz¹tek
        for (int i = end - 1; i >= start; --i) {
            porownania++;
            if (tablica[i] > tablica[i + 1]) { // porównanie s¹siednich elementów
                std::swap(tablica[i], tablica[i + 1]); // zamiana miejscami
                przestawienia++;
                swapped = true; // ustawienie flagi, ¿e nast¹pi³a zamiana
            }
        }
        ++start; // zwiêkszenie pocz¹tku zakresu
    }
}


void cTablica::quickSortLomuto(int low, int high) {
    if (low < high) {
        int pi = partitionLomuto(low, high); // uzyskanie indeksu podzia³u
        quickSortLomuto(low, pi - 1); // rekursywne sortowanie lewej czêœci
        quickSortLomuto(pi + 1, high); // rekursywne sortowanie prawej czêœci
    }
}


int cTablica::partitionLomuto(int low, int high) {
    int pivot = tablica[high]; // wybór pivota
    int i = low - 1; // indeks mniejszego elementu
    for (int j = low; j < high; j++) {
        porownania++;
        if (tablica[j] <= pivot) { // porównanie elementu z pivotem
            i++;
            std::swap(tablica[i], tablica[j]); // zamiana elementów
            przestawienia++;
        }
    }
    std::swap(tablica[i + 1], tablica[high]); // zamiana pivota na w³aœciwe miejsce
    przestawienia++;
    return i + 1; // zwrócenie indeksu podzia³u
}


void cTablica::quickSortHoare(int low, int high) {
    if (low < high) {
        int pi = partitionHoare(low, high); // uzyskanie indeksu podzia³u
        quickSortHoare(low, pi); // rekursywne sortowanie lewej czêœci
        quickSortHoare(pi + 1, high); // rekursywne sortowanie prawej czêœci
    }
}


int cTablica::partitionHoare(int low, int high) {
    int pivot = tablica[low]; // wybór pivota
    int i = low - 1; // indeks mniejszego elementu
    int j = high + 1; // indeks wiêkszego elementu
    while (true) {
        do {
            i++;
            porownania++;
        } while (tablica[i] < pivot); // znajdowanie elementu wiêkszego od pivota

        do {
            j--;
            porownania++;
        } while (tablica[j] > pivot); // znajdowanie elementu mniejszego od pivota

        if (i >= j)
            return j; // zwrócenie indeksu podzia³u

        std::swap(tablica[i], tablica[j]); // zamiana elementów
        przestawienia++;
    }
}


void cTablica::heapify(int n, int i) {
    int largest = i; // ustawienie najwiêkszego elementu jako korzeñ
    int left = 2 * i + 1; // lewy liœæ
    int right = 2 * i + 2; // prawy liœæ

    porownania++;
    if (left < n && tablica[left] > tablica[largest])
        largest = left; // ustawienie najwiêkszego elementu

    porownania++;
    if (right < n && tablica[right] > tablica[largest])
        largest = right; // ustawienie najwiêkszego elementu

    if (largest != i) {
        std::swap(tablica[i], tablica[largest]); // zamiana elementów
        przestawienia++;
        heapify(n, largest); // rekursywne wywo³anie kopcowania dla poddrzewa
    }
}


void cTablica::heapSort() {
    resetCounts(); // resetowanie liczników porównañ i przestawieñ
    int n = tablica.size();

    // tworzenie kopca
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    // wyci¹ganie elementów z kopca
    for (int i = n - 1; i > 0; i--) {
        std::swap(tablica[0], tablica[i]); // zamiana korzenia z ostatnim elementem
        przestawienia++;
        heapify(i, 0); // kopcowanie zmniejszonego kopca
    }
}


std::vector<int> cTablica::getElements() const {
    return tablica;
}


int cTablica::getPorownania() const {
    return porownania;
}


int cTablica::getPrzestawienia() const {
    return przestawienia;
}


int cTablica::size() const {
    return tablica.size();
}


void cTablica::print() const {
    for (int i : tablica) {
        std::cout << i << " "; // wyœwietlenie elementu tablicy
    }
    std::cout << std::endl; // zakoñczenie linii
}

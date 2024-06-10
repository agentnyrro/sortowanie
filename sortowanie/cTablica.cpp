#include "cTablica.h"
#include <algorithm>


void cTablica::resetCounts() {
    porownania = 0;
    przestawienia = 0;
}


void cTablica::shakerSort() {
    resetCounts(); // resetowanie licznik�w por�wna� i przestawie�
    bool swapped = true;
    int start = 0;
    int end = tablica.size() - 1;

    // p�tla kontynuowana, dop�ki w poprzednim przebiegu nast�pi�a zamiana
    while (swapped) {
        swapped = false;

        // przej�cie od pocz�tku do ko�ca, przesuwanie najwi�kszych element�w na koniec
        for (int i = start; i < end; ++i) {
            porownania++;
            if (tablica[i] > tablica[i + 1]) { // por�wnanie s�siednich element�w
                std::swap(tablica[i], tablica[i + 1]); // zamiana miejscami
                przestawienia++;
                swapped = true; // ustawienie flagi, �e nast�pi�a zamiana
            }
        }

        if (!swapped) break; // je�li nie by�o zamiany, zako�cz sortowanie

        swapped = false;
        --end; // zmniejszenie ko�ca zakresu

        // przej�cie od ko�ca do pocz�tku, przesuwanie najmniejszych element�w na pocz�tek
        for (int i = end - 1; i >= start; --i) {
            porownania++;
            if (tablica[i] > tablica[i + 1]) { // por�wnanie s�siednich element�w
                std::swap(tablica[i], tablica[i + 1]); // zamiana miejscami
                przestawienia++;
                swapped = true; // ustawienie flagi, �e nast�pi�a zamiana
            }
        }
        ++start; // zwi�kszenie pocz�tku zakresu
    }
}


void cTablica::quickSortLomuto(int low, int high) {
    if (low < high) {
        int pi = partitionLomuto(low, high); // uzyskanie indeksu podzia�u
        quickSortLomuto(low, pi - 1); // rekursywne sortowanie lewej cz�ci
        quickSortLomuto(pi + 1, high); // rekursywne sortowanie prawej cz�ci
    }
}


int cTablica::partitionLomuto(int low, int high) {
    int pivot = tablica[high]; // wyb�r pivota
    int i = low - 1; // indeks mniejszego elementu
    for (int j = low; j < high; j++) {
        porownania++;
        if (tablica[j] <= pivot) { // por�wnanie elementu z pivotem
            i++;
            std::swap(tablica[i], tablica[j]); // zamiana element�w
            przestawienia++;
        }
    }
    std::swap(tablica[i + 1], tablica[high]); // zamiana pivota na w�a�ciwe miejsce
    przestawienia++;
    return i + 1; // zwr�cenie indeksu podzia�u
}


void cTablica::quickSortHoare(int low, int high) {
    if (low < high) {
        int pi = partitionHoare(low, high); // uzyskanie indeksu podzia�u
        quickSortHoare(low, pi); // rekursywne sortowanie lewej cz�ci
        quickSortHoare(pi + 1, high); // rekursywne sortowanie prawej cz�ci
    }
}


int cTablica::partitionHoare(int low, int high) {
    int pivot = tablica[low]; // wyb�r pivota
    int i = low - 1; // indeks mniejszego elementu
    int j = high + 1; // indeks wi�kszego elementu
    while (true) {
        do {
            i++;
            porownania++;
        } while (tablica[i] < pivot); // znajdowanie elementu wi�kszego od pivota

        do {
            j--;
            porownania++;
        } while (tablica[j] > pivot); // znajdowanie elementu mniejszego od pivota

        if (i >= j)
            return j; // zwr�cenie indeksu podzia�u

        std::swap(tablica[i], tablica[j]); // zamiana element�w
        przestawienia++;
    }
}


void cTablica::heapify(int n, int i) {
    int largest = i; // ustawienie najwi�kszego elementu jako korze�
    int left = 2 * i + 1; // lewy li��
    int right = 2 * i + 2; // prawy li��

    porownania++;
    if (left < n && tablica[left] > tablica[largest])
        largest = left; // ustawienie najwi�kszego elementu

    porownania++;
    if (right < n && tablica[right] > tablica[largest])
        largest = right; // ustawienie najwi�kszego elementu

    if (largest != i) {
        std::swap(tablica[i], tablica[largest]); // zamiana element�w
        przestawienia++;
        heapify(n, largest); // rekursywne wywo�anie kopcowania dla poddrzewa
    }
}


void cTablica::heapSort() {
    resetCounts(); // resetowanie licznik�w por�wna� i przestawie�
    int n = tablica.size();

    // tworzenie kopca
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    // wyci�ganie element�w z kopca
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
        std::cout << i << " "; // wy�wietlenie elementu tablicy
    }
    std::cout << std::endl; // zako�czenie linii
}

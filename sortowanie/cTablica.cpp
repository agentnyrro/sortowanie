#include "cTablica.h"

void cTablica::resetCounts() {
    porownania = 0;
    przestawienia = 0;
}

void cTablica::shakerSort() {
    resetCounts();
    bool swapped = true;
    int start = 0;
    int end = tablica.size() - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            porownania++;
            if (tablica[i] > tablica[i + 1]) {
                std::swap(tablica[i], tablica[i + 1]);
                przestawienia++;
                swapped = true;
            }
        }
        if (!swapped) break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            porownania++;
            if (tablica[i] > tablica[i + 1]) {
                std::swap(tablica[i], tablica[i + 1]);
                przestawienia++;
                swapped = true;
            }
        }
        ++start;
    }
}

void cTablica::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int cTablica::partition(int low, int high) {
    int pivot = tablica[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        porownania++;
        if (tablica[j] < pivot) {
            i++;
            std::swap(tablica[i], tablica[j]);
            przestawienia++;
        }
    }
    std::swap(tablica[i + 1], tablica[high]);
    przestawienia++;
    return (i + 1);
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
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
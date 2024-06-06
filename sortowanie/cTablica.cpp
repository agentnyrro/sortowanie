#include "cTablica.h"
#include <algorithm>

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

void cTablica::quickSortLomuto(int low, int high) {
    if (low < high) {
        int pi = partitionLomuto(low, high);
        quickSortLomuto(low, pi - 1);
        quickSortLomuto(pi + 1, high);
    }
}

int cTablica::partitionLomuto(int low, int high) {
    int pivot = tablica[high];
    int i = low - 1;
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
    return i + 1;
}

void cTablica::quickSortHoare(int low, int high) {
    if (low < high) {
        int pi = partitionHoare(low, high);
        quickSortHoare(low, pi);
        quickSortHoare(pi + 1, high);
    }
}

int cTablica::partitionHoare(int low, int high) {
    int pivot = tablica[low];
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do {
            i++;
            porownania++;
        } while (tablica[i] < pivot);

        do {
            j--;
            porownania++;
        } while (tablica[j] > pivot);

        if (i >= j)
            return j;

        std::swap(tablica[i], tablica[j]);
        przestawienia++;
    }
}

void cTablica::heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    porownania++;
    if (left < n && tablica[left] > tablica[largest])
        largest = left;

    porownania++;
    if (right < n && tablica[right] > tablica[largest])
        largest = right;

    if (largest != i) {
        std::swap(tablica[i], tablica[largest]);
        przestawienia++;
        heapify(n, largest);
    }
}

void cTablica::heapSort() {
    resetCounts();
    int n = tablica.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(tablica[0], tablica[i]);
        przestawienia++;
        heapify(i, 0);
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
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

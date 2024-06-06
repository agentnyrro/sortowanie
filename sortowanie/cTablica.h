#ifndef CTABLICA_H
#define CTABLICA_H

#include <vector>
#include <iostream>

class cTablica {
private:
    std::vector<int> tablica;
    int porownania;
    int przestawienia;

    void resetCounts();
    int partitionLomuto(int low, int high);
    int partitionHoare(int low, int high);
    void heapify(int n, int i);

public:
    cTablica(const std::vector<int>& tab) : tablica(tab), porownania(0), przestawienia(0) {}

    void shakerSort();
    void quickSortLomuto(int low, int high);
    void quickSortHoare(int low, int high);
    void heapSort();
    std::vector<int> getElements() const;

    int getPorownania() const;
    int getPrzestawienia() const;
    int size() const;
    void print() const;
};

#endif // CTABLICA_H

#pragma once
#include <iostream>
#include <vector>

class cTablica {
private:
    std::vector<int> tablica;
    int porownania;
    int przestawienia;

public:
    cTablica(const std::vector<int>& tab) : tablica(tab), porownania(0), przestawienia(0) {}

    void resetCounts();

    void shakerSort();

    void quickSort(int low, int high);

    int partition(int low, int high);

    int getPorownania() const;

    int getPrzestawienia() const;

    int size() const;

    void print() const;
};
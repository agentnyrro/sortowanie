#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "cTablica.h"
#include "cSortTablicy.h"

int main() {
    cSortTablicy sortowanie;

    try {
        // Losowanie elementow do tablicy
        sortowanie.losujElementy(100);
        sortowanie.sortujShakerSort();
        sortowanie.pokazWyniki();

        // Sortowanie szybkie
        sortowanie.losujElementy(100);
        sortowanie.sortujQuickSort();
        sortowanie.pokazWyniki();
    }
    catch (const std::exception& e) {
        std::cerr << "Blad: " << e.what() << std::endl;
    }

    return 0;
}

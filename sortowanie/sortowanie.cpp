#include <stdexcept>
#include "cTablica.h"
#include "cSortTablicy.h"

void testSorting(cSortTablicy& sortowanie, const std::vector<int>& tab) {
    try {
        sortowanie.ustawElementy(tab);

        std::cout << "Shaker Sort:" << std::endl;
        sortowanie.sortujShakerSort();
        sortowanie.pokazWyniki();

        sortowanie.ustawElementy(tab);
        std::cout << "Quick Sort Lomuto:" << std::endl;
        sortowanie.sortujQuickSortLomuto();
        sortowanie.pokazWyniki();

        sortowanie.ustawElementy(tab);
        std::cout << "Quick Sort Hoare:" << std::endl;
        sortowanie.sortujQuickSortHoare();
        sortowanie.pokazWyniki();

        sortowanie.ustawElementy(tab);
        std::cout << "Heap Sort:" << std::endl;
        sortowanie.sortujHeapSort();
        sortowanie.pokazWyniki();
    }
    catch (const std::exception& e) {
        std::cerr << "Blad: " << e.what() << std::endl;
    }
}

int main() {
    /*
    * // Test with random elements
    sortowanie.losujElementy(100);
    testSorting(sortowanie, sortowanie.getElements());
    */
    cSortTablicy sortowanie;

    

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class cTablica {
private:
    std::vector<int> tablica;
    int porownania;
    int przestawienia;

public:
    cTablica(const std::vector<int>& tab) : tablica(tab), porownania(0), przestawienia(0) {}

    void resetCounts() {
        porownania = 0;
        przestawienia = 0;
    }

    void shakerSort() {
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

    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    int partition(int low, int high) {
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

    int getPorownania() const {
        return porownania;
    }

    int getPrzestawienia() const {
        return przestawienia;
    }

    int size() const {
        return tablica.size();
    }

    void print() const {
        for (int i : tablica) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

class cSortTablicy {
private:
    cTablica* tablica;

public:
    cSortTablicy() : tablica(nullptr) {}

    ~cSortTablicy() {
        delete tablica;
    }

    void wprowadzZKlawiatury(int n) {
        std::vector<int> tab(n);
        std::cout << "Wprowadz " << n << " elementow: ";
        for (int i = 0; i < n; ++i) {
            std::cin >> tab[i];
        }
        tablica = new cTablica(tab);
    }

    void losujElementy(int n) {
        std::vector<int> tab(n);
        std::srand(std::time(0));
        for (int i = 0; i < n; ++i) {
            tab[i] = std::rand() % 1000; // losowe liczby od 0 do 999
        }
        tablica = new cTablica(tab);
    }

    void sortujShakerSort() {
        if (tablica == nullptr) throw std::runtime_error("Tablica jest pusta");
        tablica->shakerSort();
    }

    void sortujQuickSort() {
        if (tablica == nullptr) throw std::runtime_error("Tablica jest pusta");
        tablica->quickSort(0, tablica->size() - 1);
    }

    void pokazWyniki() const {
        if (tablica == nullptr) throw std::runtime_error("Tablica jest pusta");
        std::cout << "Tablica po sortowaniu: ";
        tablica->print();
        std::cout << "Liczba porownan: " << tablica->getPorownania() << std::endl;
        std::cout << "Liczba przestawien: " << tablica->getPrzestawienia() << std::endl;
    }
};

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

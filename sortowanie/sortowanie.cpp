#include <stdexcept>
#include "cTablica.h"
#include "cSortTablicy.h"
#include "myExceptions.h"

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

void testAll(cSortTablicy& sortowanie, ofstream& write) {
    int dlugosci[2] = { 100, 1000 };
    vector<cSortTablicy::algorytm> algs = { cSortTablicy::algorytm::shaker, cSortTablicy::algorytm::qHoare, 
        cSortTablicy::algorytm::qLomuto, cSortTablicy::algorytm::heap };
    vector<cSortTablicy::rodzajTab> rodzaje = { cSortTablicy::rodzajTab::los, cSortTablicy::rodzajTab::uporz,
    cSortTablicy::rodzajTab::odwr, cSortTablicy::rodzajTab::prawie };
    
    try
    {
        for (int dl : dlugosci) {
            for (auto r : rodzaje) {
                for (auto alg : algs) {
                    sortowanie.rTab = r;
                    sortowanie.alg = alg;
                    sortowanie.losujElementy(dl);
                    switch (alg)
                    {
                    case cSortTablicy::algorytm::shaker:
                        sortowanie.sortujShakerSort();
                        break;
                    case cSortTablicy::algorytm::qHoare:
                        sortowanie.sortujQuickSortHoare();
                        break;
                    case cSortTablicy::algorytm::qLomuto:
                        sortowanie.sortujQuickSortLomuto();
                        break;
                    case cSortTablicy::algorytm::heap:
                        sortowanie.sortujHeapSort();
                        break;
                    default:
                        break;
                    }
                    sortowanie.wypiszWyniki(write);
                }
            }
        }
        
    }
    catch (const std::exception& e)
    {
        cerr << e.what();
    }
}

int main() {
    /*
    * // Test with random elements
    sortowanie.losujElementy(100);
    testSorting(sortowanie, sortowanie.getElements());
    */
    cSortTablicy sortowanie;

    ofstream write;
    cout << "Wpisz nazwe pliku, do ktorego checsz zapisac wyniki:\t ";
    string fnazwa; cin >> fnazwa;
    try
    {
        write.open(fnazwa);
        if (!write.good())
            throw MyExceptions("Nie dalo sie otworzyc pliku");
    }
    catch (const std::exception& e)
    {
        cerr << e.what();
        exit(0);
    }
    
    system("cls");

    try
    {
        write << "Nazwa metody sortowania \tDlugosc tablicy \tRodzaj tablicy \t\tLiczba porownan \tLiczba przestawien\n";
        while (true)
        {
            cout << "1. Nowa tablica \n2. Automatycznie przetestuj wszystkie kombinacje \n3. Wyjdz\n";
            int optNowa;
            cin >> optNowa;
            if (optNowa == 3)
                break;
            if (optNowa == 2) {
                testAll(sortowanie, write);
                system("cls");
                continue;
            }
            if (optNowa != 1) {
                cout << "Niewiadoma opcja\n";
                system("cls");
                continue;
            }
            system("cls");

            cout << "Wprowadz dlugosc tablicy:\t";
            int n; cin >> n;

            system("cls");
            cout << "Wybierz sposob wypelninia tablicy\n\t1. Recznie \n\t2. Wygeneruj automatycznie\n";
            int optKlawGen; cin >> optKlawGen;
            if (optKlawGen != 1 && optKlawGen != 2)
                throw MyExceptions("Niewiadoma opcja\n");

            system("cls");
            cout << "Wybierz rodzaj tablicy\n\t1. tablica uzupelniona losowymi liczbami \n\t2. tablica uzupelniona liczbami posortowanymi rosnaco\n\
        3. tablica uzupelniona liczbami posortowanymi malejaco \n\t4. tablica czesciowo uporzadkowana (10 % elementow jest na zlej pozycji)\n";
            int optRodzaj; cin >> optRodzaj;
            if (optRodzaj == 1)
                sortowanie.rTab = cSortTablicy::rodzajTab::los;
            else if (optRodzaj == 2)
                sortowanie.rTab = cSortTablicy::rodzajTab::uporz;
            else if (optRodzaj == 3)
                sortowanie.rTab = cSortTablicy::rodzajTab::odwr;
            else if (optRodzaj == 4)
                sortowanie.rTab = cSortTablicy::rodzajTab::prawie;
            else
                throw MyExceptions("Niewiadoma opcja\n");

            system("cls");

            if (optKlawGen == 1) {
                sortowanie.wprowadzZKlawiatury(n);
                system("cls");
            }
            else
                sortowanie.losujElementy(n);

            cout << "Wybierz algorytm sortowania \n\t1.Shaker sort \n\t2. Quick sort z podzialem Hoare'a\n\
        3. Quick sort z podzialem Lomuto \n\t4. Sortowanie przez kopcowanie\n";
            int optAlg; cin >> optAlg;
            if (optAlg == 1)
            {
                sortowanie.alg = cSortTablicy::algorytm::shaker;
                sortowanie.sortujShakerSort();
            }
            else if (optAlg == 2)
            {
                sortowanie.alg = cSortTablicy::algorytm::qHoare;
                sortowanie.sortujQuickSortHoare();
            }
            else if (optAlg == 3)
            {
                sortowanie.alg = cSortTablicy::algorytm::qLomuto;
                sortowanie.sortujQuickSortLomuto();
            }
            else if (optAlg == 4)
            {
                sortowanie.alg = cSortTablicy::algorytm::heap;
                sortowanie.sortujHeapSort();
            }
            else
                throw MyExceptions("Niewiadoma opcja\n");

            sortowanie.wypiszWyniki(write);
            system("cls");
        }

    }
    catch (const std::exception& e) {
        cerr << e.what();
        exit(0);
    }

    write.close();
    return 0;
}

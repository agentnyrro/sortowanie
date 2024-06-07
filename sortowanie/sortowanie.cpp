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


    write << "Nazwa metody sortowania \tDlugosc tablicy \tRodzaj tablicy \t\tLiczba porownan \tLiczba przestawien\n";
    while (true)
    {
        cout << "1. Nowa tablica \n2. Wyjdz\n";
        int optNowa;
        cin >> optNowa;
        if (optNowa == 2)
            break;
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
    

    write.close();
    return 0;
}

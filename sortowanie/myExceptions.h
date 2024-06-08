#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <exception>
#include <string>

/**
 * Klasa reprezentujaca wlasne wyjatki
 */
class MyExceptions : public std::exception {
public:
    /**
     * konstruktor klasy MyExceptions
     * @param message - wiadomosc opisujaca wyjatek
     */
    explicit MyExceptions(const std::string& message);

    /**
     * zwraca opis wyjatku
     * @return - opis wyjatku
     */
    const char* what() const noexcept override;

private:
    std::string message; // opis wyjatku
};

#endif // MYEXCEPTIONS_H

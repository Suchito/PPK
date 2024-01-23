#include <iostream>
#include <string>
#include "organizer.h"

/**
 * @brief Funkcja wyœwietlaj¹ca menu g³ówne programu.
 */
void wyswietlMenu();

/**
 * @brief Funkcja wykonuj¹ca akcje zwi¹zane z wyborem u¿ytkownika.
 *
 * @param organizator Obiekt klasy Organizator, na którym bêd¹ wykonywane operacje.
 */
void wykonajAkcje(Organizator& organizator);

/**
 * @brief G³ówna funkcja programu.
 *
 * @return Kod zakoñczenia programu.
 */
int main() {
    Organizator organizator;

    do {
        wyswietlMenu();
        wykonajAkcje(organizator);
    } while (true);

    return 0;
}

void wyswietlMenu() {
    std::cout << "===== MENU GLOWNE =====\n";
    std::cout << "1. Dodaj nowego kontaktu\n";
    std::cout << "2. Usun istniejacego kontaktu\n";
    std::cout << "3. Dodaj nowe zadanie\n";
    std::cout << "4. Usun istniejace zadanie\n";
    std::cout << "5. Wyswietl liste kontaktow (posortowana wg wszystkich kryteriow)\n";
    std::cout << "6. Filtrowanie listy kontaktow (wg wszystkich kryteriow)\n";
    std::cout << "7. Wyswietl liste zadan\n";
    std::cout << "8. Zmien status zadania\n";
    std::cout << "9. Wyswietl liste zadan (posortowana wg wszystkich kryteriow)\n";
    std::cout << "10. Filtrowanie listy zadan (wg wszystkich kryteriow)\n";
    std::cout << "0. Zakoncz program\n";
}

void wykonajAkcje(Organizator& organizator) {
    int wybor;
    std::cout << "Wybierz akcje: ";
    std::cin >> wybor;

    switch (wybor) {
    case 1: {
        std::string imie, nazwisko, email;
        std::cout << "Podaj imie: ";
        std::cin >> imie;
        std::cout << "Podaj nazwisko: ";
        std::cin >> nazwisko;
        std::cout << "Podaj adres email: ";
        std::cin >> email;

        organizator.dodajOsobe(imie, nazwisko, email);
        break;
    }
    case 2: {
        std::string email;
        std::cout << "Podaj adres email kontaktu do usuniecia: ";
        std::cin >> email;

        organizator.usunOsobe(email);
        break;
    }
    case 3: {
        std::string data, typ, status, opis;
        std::cout << "Podaj date zadania (format: RRRR.MM.DD HH:MM): ";
        std::cin >> data;
        std::cout << "Podaj typ zadania: ";
        std::cin >> typ;
        std::cout << "Podaj status zadania: ";
        std::cin >> status;
        std::cout << "Podaj opis zadania: ";
        std::cin.ignore();
        std::getline(std::cin, opis);

        organizator.dodajZadanie(data, typ, status, opis);
        break;
    }
    case 4: {
        int numer;
        std::cout << "Podaj numer zadania do usuniecia: ";
        std::cin >> numer;

        organizator.usunZadanie(numer);
        break;
    }
    case 5: {
        int numer;
        std::string nowyStatus;
        std::cout << "Podaj numer zadania do zmiany statusu: ";
        std::cin >> numer;
        std::cout << "Podaj nowy status zadania: ";
        std::cin >> nowyStatus;

        organizator.zmienStatusZadania(numer, nowyStatus);
        break;
    }
    case 6: {
        organizator.wyswietlPosortowaneOsoby();
        break;
    }
    case 7: {
        // Obs³uga filtrowania kontaktów
        // ...
        break;
    }
    case 8: {
        // Obs³uga wyœwietlania posortowanych zadañ
        organizator.wyswietlPosortowaneZadania();
        break;
    }
    case 9: {
        // Obs³uga filtrowania zadañ
        // ...
        break;
    }
    case 10: {
        organizator.wyswietlZadania();
        break;
    }
    case 0: {
        std::cout << "Zakonczono program.\n";
        exit(0);
    }
    default: {
        std::cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
        break;
    }
    }
}

#include "organizer.h"
#include <algorithm>
#include <iostream>
#include <fstream>

/**
 * @brief Konstruktor klasy Osoba.
 * @param imie Imię osoby.
 * @param nazwisko Nazwisko osoby.
 * @param email Adres email osoby.
 */
Osoba::Osoba(const std::string& imie, const std::string& nazwisko, const std::string& email)
    : imie(imie), nazwisko(nazwisko), email(email) {}

/**
 * @brief Zwraca pełne informacje o osobie.
 * @return Pełne informacje o osobie.
 */
std::string Osoba::pelneInfo() const {
    return imie + " " + nazwisko;
}

/**
 * @brief Zwraca adres email osoby.
 * @return Adres email osoby.
 */
std::string Osoba::getEmail() const {
    return email;
}



/**
 * @brief Konstruktor klasy Zadanie.
 * @param numer Numer zadania.
 * @param data Data zadania.
 * @param typ Typ zadania.
 * @param status Status zadania.
 * @param opis Opis zadania.
 */
Zadanie::Zadanie(const std::string& data, const std::string& typ, const std::string& status, const std::string& opis)
    : numer(-1), data(data), typ(typ), status(status), opis(opis) {}


/**
 * @brief Zwraca pełne informacje o zadaniu.
 * @return Pełne informacje o zadaniu.
 */
int Zadanie::getNumer() const {
    return numer;
}

/**
 * @brief Ustawia numer zadania.
 * @param nowyNumer Nowy numer zadania.
 */
void Zadanie::setNumer(int numer) {
    this->numer = numer;
}

/**
 * @brief Zwraca pełne informacje o zadaniu.
 * @return Pełne informacje o zadaniu.
 */
std::string Zadanie::pelneInfo() const {
    return "Zadanie #" + std::to_string(numer) + " [" + data + "]: " + typ + " - " + status + "\nOpis: " + opis;
}

/**
 * @brief Zwraca datę zadania.
 * @return Data zadania.
 */
std::string Zadanie::getData() const {
    return data;
}

/**
 * @brief Zwraca typ zadania.
 * @return Typ zadania.
 */
std::string Zadanie::getTyp() const {
    return typ;
}

/**
 * @brief Zwraca status zadania.
 * @return Status zadania.
 */
std::string Zadanie::getStatus() const {
    return status;
}

/**
 * @brief Ustawia status zadania.
 * @param nowyStatus Nowy status zadania.
 */
void Zadanie::setStatus(const std::string& status) {
    this->status = status;
}


Organizator::Organizator() {}

/**
 * @brief Dodaje nową osobę do listy kontaktów.
 * @param osoba Obiekt klasy Osoba reprezentujący nową osobę.
 */
void Organizator::dodajOsobe(const std::string& imie, const std::string& nazwisko, const std::string& email) {
    Osoba osoba(imie, nazwisko, email);
    kontakty.push_back(osoba);
}

/**
 * @brief Usuwa osobę z listy kontaktów.
 * @param email Adres email osoby do usunięcia.
 */
void Organizator::usunOsobe(const std::string& email) {
    auto it = std::remove_if(kontakty.begin(), kontakty.end(),
        [email](const Osoba& osoba) { return osoba.getEmail() == email; });
    kontakty.erase(it, kontakty.end());
}

/**
 * @brief Dodaje nowe zadanie do listy zadań.
 * @param zadanie Obiekt klasy Zadanie reprezentujący nowe zadanie.
 */
void Organizator::dodajZadanie(const std::string& data, const std::string& typ, const std::string& status, const std::string& opis) {
    Zadanie zadanie(data, typ, status, opis);
    zadania.push_back(zadanie);
}

/**
 * @brief Usuwa zadanie z listy zadań.
 * @param numer Numer zadania do usunięcia.
 */
void Organizator::usunZadanie(int numer) {
    auto it = std::remove_if(zadania.begin(), zadania.end(),
        [numer](const Zadanie& zadanie) { return zadanie.getNumer() == numer; });
    zadania.erase(it, zadania.end());
}

/**
 * @brief Zmienia status zadania.
 * @param numer Numer zadania, którego status ma być zmieniony.
 * @param nowyStatus Nowy status zadania.
 */
void Organizator::zmienStatusZadania(int numer, const std::string& nowyStatus) {
    auto it = std::find_if(zadania.begin(), zadania.end(),
        [numer](const Zadanie& zadanie) { return zadanie.getNumer() == numer; });
    if (it != zadania.end()) {
        it->setStatus(nowyStatus);
    }
}

/**
 * @brief Wyswietla posortowaną listę osób.
 */
void Organizator::wyswietlPosortowaneOsoby() const {
    // wyświetlanie posortowanych kontaktów
}

/**
 * @brief Filtrowanie listy kontaktów według różnych kryteriów.
 * @param kryterium Kryterium, według którego ma być wykonane filtrowanie.
 */
void Organizator::filtrujKontakty(const std::string& kryterium) {
    //filtrowanie kontaktów
}

/**
 * @brief Wyswietla posortowaną listę zadań według różnych kryteriów.
 */
void Organizator::wyswietlPosortowaneZadania() const {
    //wyświetlanie posortowanych zadań
}

void Organizator::filtrujZadania(const std::string& kryterium) {
    //filtrowanie zadań
}

/**
 * @brief Wyswietla listę zadań.
 */

void Organizator::dodajZadanie(const std::string& task) {
    tasks.push_back(task);
}

void Organizator::wyswietlZadania() const {
    for (const auto& task : tasks) {
        std::cout << task << std::endl;
    }
}

void Organizator::zapiszZadaniaDoPliku(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << task << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Nie można otworzyć pliku: " << filename << std::endl;
    }
}

void Organizator::wczytajZadaniaZPliku(const std::string& filename) {
    tasks.clear(); // Wczytując z pliku czyści aktualną listę zadań
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string task;
        while (std::getline(file, task)) {
            tasks.push_back(task);
        }
        file.close();
    }
    else {
        std::cerr << "Nie można otworzyć pliku: " << filename << std::endl;
    }
}

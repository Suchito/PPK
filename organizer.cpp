#include "organizer.h"
#include <algorithm>
#include <iostream>

// Implementacja klasy Osoba

/**
 * @brief Konstruktor klasy Osoba.
 * @param imie Imi� osoby.
 * @param nazwisko Nazwisko osoby.
 * @param email Adres email osoby.
 */
Osoba::Osoba(const std::string& imie, const std::string& nazwisko, const std::string& email)
    : imie(imie), nazwisko(nazwisko), email(email) {}

/**
 * @brief Zwraca pe�ne informacje o osobie.
 * @return Pe�ne informacje o osobie.
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

// Implementacja klasy Zadanie

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
 * @brief Zwraca pe�ne informacje o zadaniu.
 * @return Pe�ne informacje o zadaniu.
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
 * @brief Zwraca pe�ne informacje o zadaniu.
 * @return Pe�ne informacje o zadaniu.
 */
std::string Zadanie::pelneInfo() const {
    return "Zadanie #" + std::to_string(numer) + " [" + data + "]: " + typ + " - " + status + "\nOpis: " + opis;
}

/**
 * @brief Zwraca dat� zadania.
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

// Implementacja klasy Organizator

/**
 * @brief Dodaje now� osob� do listy kontakt�w.
 * @param osoba Obiekt klasy Osoba reprezentuj�cy now� osob�.
 */
void Organizator::dodajOsobe(const std::string& imie, const std::string& nazwisko, const std::string& email) {
    Osoba osoba(imie, nazwisko, email);
    kontakty.push_back(osoba);
}

/**
 * @brief Usuwa osob� z listy kontakt�w.
 * @param email Adres email osoby do usuni�cia.
 */
void Organizator::usunOsobe(const std::string& email) {
    auto it = std::remove_if(kontakty.begin(), kontakty.end(),
        [email](const Osoba& osoba) { return osoba.getEmail() == email; });
    kontakty.erase(it, kontakty.end());
}

/**
 * @brief Dodaje nowe zadanie do listy zada�.
 * @param zadanie Obiekt klasy Zadanie reprezentuj�cy nowe zadanie.
 */
void Organizator::dodajZadanie(const std::string& data, const std::string& typ, const std::string& status, const std::string& opis) {
    Zadanie zadanie(data, typ, status, opis);
    zadania.push_back(zadanie);
}

/**
 * @brief Usuwa zadanie z listy zada�.
 * @param numer Numer zadania do usuni�cia.
 */
void Organizator::usunZadanie(int numer) {
    auto it = std::remove_if(zadania.begin(), zadania.end(),
        [numer](const Zadanie& zadanie) { return zadanie.getNumer() == numer; });
    zadania.erase(it, zadania.end());
}

/**
 * @brief Zmienia status zadania.
 * @param numer Numer zadania, kt�rego status ma by� zmieniony.
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
 * @brief Wyswietla posortowan� list� os�b.
 */
void Organizator::wyswietlPosortowaneOsoby() const {
    // Implementacja wy�wietlania posortowanych kontakt�w
}

/**
 * @brief Filtrowanie listy kontakt�w wed�ug r�nych kryteri�w.
 * @param kryterium Kryterium, wed�ug kt�rego ma by� wykonane filtrowanie.
 */
void Organizator::filtrujKontakty(const std::string& kryterium) {
    // Implementacja filtrowania kontakt�w
}

/**
 * @brief Wyswietla posortowan� list� zada� wed�ug r�nych kryteri�w.
 */
void Organizator::wyswietlPosortowaneZadania() const {
    // Implementacja wy�wietlania posortowanych zada�
}

void Organizator::filtrujZadania(const std::string& kryterium) {
    // Implementacja filtrowania zada�
}

/**
 * @brief Wyswietla list� zada�.
 */
void Organizator::wyswietlZadania() const {
    for (const auto& zadanie : zadania) {
        std::cout << zadanie.pelneInfo() << "\n";
    }
}

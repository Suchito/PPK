#include "organizer.h"
#include <iostream>
#include <algorithm>
#include <string>

// Implementacja klasy Osoba

/**
 * @brief Konstruktor klasy Osoba.
 * @param imie Imiê osoby.
 * @param nazwisko Nazwisko osoby.
 * @param email Adres email osoby.
 */
Osoba::Osoba(const std::string& imie, const std::string& nazwisko, const std::string& email)
    : imie(imie), nazwisko(nazwisko), email(email) {}

/**
 * @brief Zwraca pe³ne informacje o osobie.
 * @return Pe³ne informacje o osobie.
 */
std::string Osoba::pelneInfo() const
{
    return imie + " " + nazwisko + " (" + email + ")";
}

/**
 * @brief Zwraca adres email osoby.
 * @return Adres email osoby.
 */
const std::string& Osoba::getEmail() const
{
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
    : data(data), typ(typ), status(status), opis(opis)
{
    static int numerGenerator = 1;
    numer = numerGenerator++;
}

/**
 * @brief Zwraca pe³ne informacje o zadaniu.
 * @return Pe³ne informacje o zadaniu.
 */
std::string Zadanie::pelneInfo() const
{
    return "Zadanie " + std::to_string(numer) + ": " + data + " - " + typ + " - " + status + " - " + opis;
}

/**
 * @brief Zwraca numer zadania.
 * @return Numer zadania.
 */
int Zadanie::getNumer() const
{
    return numer;
}

/**
 * @brief Ustawia numer zadania.
 * @param nowyNumer Nowy numer zadania.
 */
void Zadanie::setNumer(int numer)
{
    this->numer = numer;
}

/**
 * @brief Zwraca datê zadania.
 * @return Data zadania.
 */
const std::string& Zadanie::getData() const
{
    return data;
}

/**
 * @brief Zwraca typ zadania.
 * @return Typ zadania.
 */
const std::string& Zadanie::getTyp() const
{
    return typ;
}

/**
 * @brief Zwraca status zadania.
 * @return Status zadania.
 */
const std::string& Zadanie::getStatus() const
{
    return status;
}

/**
 * @brief Ustawia status zadania.
 * @param nowyStatus Nowy status zadania.
 */
void Zadanie::setStatus(const std::string& status)
{
    this->status = status;
}

// Implementacja klasy Organizator

/**
 * @brief Dodaje now¹ osobê do listy kontaktów.
 * @param osoba Obiekt klasy Osoba reprezentuj¹cy now¹ osobê.
 */
void Organizator::dodajOsobe(const std::string& imie, const std::string& nazwisko, const std::string& email)
{
    kontakty.emplace_back(imie, nazwisko, email);
}

/**
 * @brief Usuwa osobê z listy kontaktów.
 * @param email Adres email osoby do usuniêcia.
 */
void Organizator::usunOsobe(const std::string& email)
{
    auto it = std::remove_if(kontakty.begin(), kontakty.end(), [&](const Osoba& osoba) {
        return osoba.getEmail() == email;
        });

    kontakty.erase(it, kontakty.end());
}

/**
 * @brief Dodaje nowe zadanie do listy zadañ.
 * @param zadanie Obiekt klasy Zadanie reprezentuj¹cy nowe zadanie.
 */
void Organizator::dodajZadanie(const std::string& data, const std::string& typ, const std::string& status, const std::string& opis)
{
    zadania.emplace_back(data, typ, status, opis);
}

/**
 * @brief Usuwa zadanie z listy zadañ.
 * @param numer Numer zadania do usuniêcia.
 */
void Organizator::usunZadanie(int numer)
{
    auto it = std::remove_if(zadania.begin(), zadania.end(), [&](const Zadanie& zadanie) {
        return zadanie.getNumer() == numer;
        });

    zadania.erase(it, zadania.end());
}

/**
 * @brief Zmienia status zadania.
 * @param numer Numer zadania, którego status ma byæ zmieniony.
 * @param nowyStatus Nowy status zadania.
 */
void Organizator::zmienStatusZadania(int numer, const std::string& nowyStatus)
{
    auto it = std::find_if(zadania.begin(), zadania.end(), [&](const Zadanie& zadanie) {
        return zadanie.getNumer() == numer;
        });

    if (it != zadania.end())
    {
        it->setStatus(nowyStatus);
    }
}

/**
 * @brief Wyswietla posortowan¹ listê osób.
 */
void Organizator::wyswietlPosortowaneOsoby()
{
    std::sort(kontakty.begin(), kontakty.end(), [](const Osoba& a, const Osoba& b) {
        return a.pelneInfo() < b.pelneInfo();
        });

    for (const auto& osoba : kontakty)
    {
        std::cout << osoba.pelneInfo() << std::endl;
    }
}

/**
 * @brief Filtrowanie listy kontaktów wed³ug ró¿nych kryteriów.
 * @param kryterium Kryterium, wed³ug którego ma byæ wykonane filtrowanie.
 */
void Organizator::filtrujKontakty(const std::string& kryterium)
{
    auto it = std::remove_if(kontakty.begin(), kontakty.end(), [&](const Osoba& osoba) {
        return osoba.pelneInfo().find(kryterium) == std::string::npos;
        });

    kontakty.erase(it, kontakty.end());
}

/**
 * @brief Wyswietla listê zadañ.
 */
void Organizator::wyswietlZadania()
{
    for (const auto& zadanie : zadania)
    {
        std::cout << zadanie.pelneInfo() << std::endl;
    }
}

/**
 * @brief Wyswietla posortowan¹ listê zadañ wed³ug ró¿nych kryteriów.
 */
void Organizator::wyswietlPosortowaneZadania()
{
    std::sort(zadania.begin(), zadania.end(), [](const Zadanie& a, const Zadanie& b) {
        return a.getData() < b.getData();
        });

    for (const auto& zadanie : zadania)
    {
        std::cout << zadanie.pelneInfo() << std::endl;
    }
}

/**
 * @brief Filtrowanie listy zadañ wed³ug ró¿nych kryteriów.
 * @param kryterium Kryterium, wed³ug którego ma byæ wykonane filtrowanie.
 */
void Organizator::filtrujZadania(const std::string& kryterium)
{
    auto it = std::remove_if(zadania.begin(), zadania.end(), [&](const Zadanie& zadanie) {
        return zadanie.pelneInfo().find(kryterium) == std::string::npos;
        });

    zadania.erase(it, zadania.end());
}

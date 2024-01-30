#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Klasa reprezentująca osobę w organizerze.
 */
class Osoba {
public:

    /**
     * @brief Konstruktor klasy Osoba.
     *
     * @param imie Imię osoby.
     * @param nazwisko Nazwisko osoby.
     * @param email Adres email osoby.
     */
    Osoba(const std::string& imie, const std::string& nazwisko, const std::string& email);

    /**
     * @brief Pobiera pełne informacje o osobie.
     *
     * @return Pełne informacje o osobie.
     */
    std::string pelneInfo() const;

    /**
     * @brief Pobiera adres email osoby.
     *
     * @return Adres email osoby.
     */
    std::string getEmail() const;

private:
    std::string imie;
    std::string nazwisko;
    std::string email;
};

/**
 * @brief Klasa reprezentująca zadanie w organizerze.
 */
class Zadanie {
public:

    /**
     * @brief Konstruktor klasy Zadanie.
     *
     * @param data Data zadania.
     * @param typ Typ zadania.
     * @param status Status zadania.
     * @param opis Opis zadania.
     */
    Zadanie(const std::string& data, const std::string& typ, const std::string& status, const std::string& opis);

    /**
     * @brief Pobiera pełne informacje o zadaniu.
     *
     * @return Pełne informacje o zadaniu.
     */
    int getNumer() const;

    /**
     * @brief Pobiera numer zadania.
     *
     * @return Numer zadania.
     */
    void setNumer(int numer);

    /**
     * @brief Ustawia numer zadania.
     *
     * @param numer Nowy numer zadania.
     */
    std::string pelneInfo() const;

    /**
     * @brief Pobiera datę zadania.
     *
     * @return Data zadania.
     */
    std::string getData() const;

    /**
     * @brief Pobiera typ zadania.
     *
     * @return Typ zadania.
     */
    std::string getTyp() const;

    /**
     * @brief Pobiera status zadania.
     *
     * @return Status zadania.
     */
    std::string getStatus() const;

    /**
     * @brief Ustawia status zadania.
     *
     * @param status Nowy status zadania.
     */
    void setStatus(const std::string& status);

private:
    int numer;
    std::string data;
    std::string typ;
    std::string status;
    std::string opis;
};

/**
 * @brief Klasa reprezentująca organizer.
 */
class Organizator {
public:
    Organizator();

    /**
     * @brief Dodaje nową osobę do listy kontaktów.
     *
     * @param imie Imię osoby.
     * @param nazwisko Nazwisko osoby.
     * @param email Adres email osoby.
     */
    void dodajOsobe(const std::string& imie, const std::string& nazwisko, const std::string& email);

    /**
     * @brief Usuwa osobę z listy kontaktów na podstawie adresu email.
     *
     * @param email Adres email osoby do usunięcia.
     */
    void usunOsobe(const std::string& email);

    /**
     * @brief Dodaje nowe zadanie do listy zadań.
     *
     * @param data Data zadania.
     * @param typ Typ zadania.
     * @param status Status zadania.
     * @param opis Opis zadania.
     */
    void dodajZadanie(const std::string& data, const std::string& typ, const std::string& status, const std::string& opis);

    /**
     * @brief Usuwa zadanie z listy zadań na podstawie numeru.
     *
     * @param numer Numer zadania do usunięcia.
     */
    void usunZadanie(int numer);

    /**
     * @brief Zmienia status zadania na podstawie numeru.
     *
     * @param numer Numer zadania.
     * @param nowyStatus Nowy status zadania.
     */
    void zmienStatusZadania(int numer, const std::string& nowyStatus);

    /**
     * @brief Wyświetla posortowaną listę kontaktów.
     */
    void wyswietlPosortowaneOsoby() const;

    /**
     * @brief Filtrowanie listy kontaktów.
     *
     * @param kryterium Kryterium filtrowania.
     */
    void filtrujKontakty(const std::string& kryterium);

    /**
     * @brief Wyświetla posortowaną listę zadań.
     */
    void wyswietlPosortowaneZadania() const;

    /**
     * @brief Filtrowanie listy zadań.
     *
     * @param kryterium Kryterium filtrowania.
     */
    void filtrujZadania(const std::string& kryterium);

    /**
   * @brief Wyświetla listę zadań.
   */
    void wyswietlZadania() const;

    /**
     * @brief Wyświetla posortowaną listę zadań.
     */

    void dodajZadanie(const std::string& task);
    void zapiszZadaniaDoPliku(const std::string& filename) const;
    void wczytajZadaniaZPliku(const std::string& filename);

private:
    std::vector<Osoba> kontakty;
    std::vector<Zadanie> zadania;
    std::vector<std::string> tasks;
    std::vector<std::string> contacts;

    /**
     * @brief Funkcja pomocnicza do konwersji ciągu znaków na małe litery.
     *
     * @param str Ciąg znaków do konwersji.
     * @return Skonwertowany ciąg znaków.
     */
    std::string toLowerCase(const std::string& str);
};

#endif // ORGANIZER_H

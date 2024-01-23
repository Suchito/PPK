#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Klasa reprezentuj¹ca osobê w organizerze.
 */
class Osoba {
public:
    /**
     * @brief Konstruktor klasy Osoba.
     *
     * @param imie Imiê osoby.
     * @param nazwisko Nazwisko osoby.
     * @param email Adres email osoby.
     */
    Osoba(const std::string& imie, const std::string& nazwisko, const std::string& email);

    /**
     * @brief Pobiera pe³ne informacje o osobie.
     *
     * @return Pe³ne informacje o osobie.
     */
    std::string pelneInfo() const;

    /**
     * @brief Pobiera adres email osoby.
     *
     * @return Adres email osoby.
     */
    const std::string& getEmail() const;

private:
    std::string imie;
    std::string nazwisko;
    std::string email;
};

/**
 * @brief Klasa reprezentuj¹ca zadanie w organizerze.
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
     * @brief Pobiera pe³ne informacje o zadaniu.
     *
     * @return Pe³ne informacje o zadaniu.
     */
    std::string pelneInfo() const;

    /**
     * @brief Pobiera numer zadania.
     *
     * @return Numer zadania.
     */
    int getNumer() const;

    /**
     * @brief Ustawia numer zadania.
     *
     * @param numer Nowy numer zadania.
     */
    void setNumer(int numer);

    /**
     * @brief Pobiera datê zadania.
     *
     * @return Data zadania.
     */
    const std::string& getData() const;

    /**
     * @brief Pobiera typ zadania.
     *
     * @return Typ zadania.
     */
    const std::string& getTyp() const;

    /**
     * @brief Pobiera status zadania.
     *
     * @return Status zadania.
     */
    const std::string& getStatus() const;

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
 * @brief Klasa reprezentuj¹ca organizer.
 */
class Organizator {
public:
    /**
     * @brief Dodaje now¹ osobê do listy kontaktów.
     *
     * @param imie Imiê osoby.
     * @param nazwisko Nazwisko osoby.
     * @param email Adres email osoby.
     */
    void dodajOsobe(const std::string& imie, const std::string& nazwisko, const std::string& email);

    /**
     * @brief Usuwa osobê z listy kontaktów na podstawie adresu email.
     *
     * @param email Adres email osoby do usuniêcia.
     */
    void usunOsobe(const std::string& email);

    /**
     * @brief Dodaje nowe zadanie do listy zadañ.
     *
     * @param data Data zadania.
     * @param typ Typ zadania.
     * @param status Status zadania.
     * @param opis Opis zadania.
     */
    void dodajZadanie(const std::string& data, const std::string& typ, const std::string& status, const std::string& opis);

    /**
     * @brief Usuwa zadanie z listy zadañ na podstawie numeru.
     *
     * @param numer Numer zadania do usuniêcia.
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
     * @brief Wyœwietla posortowan¹ listê kontaktów.
     */
    void wyswietlPosortowaneOsoby();

    /**
     * @brief Filtrowanie listy kontaktów.
     *
     * @param kryterium Kryterium filtrowania.
     */
    void filtrujKontakty(const std::string& kryterium);

    /**
     * @brief Wyœwietla listê zadañ.
     */
    void wyswietlZadania();

    /**
     * @brief Wyœwietla posortowan¹ listê zadañ.
     */
    void wyswietlPosortowaneZadania();

    /**
     * @brief Filtrowanie listy zadañ.
     *
     * @param kryterium Kryterium filtrowania.
     */
    void filtrujZadania(const std::string& kryterium);

private:
    std::vector<Osoba> kontakty;
    std::vector<Zadanie> zadania;

    /**
     * @brief Funkcja pomocnicza do konwersji ci¹gu znaków na ma³e litery.
     *
     * @param str Ci¹g znaków do konwersji.
     * @return Skonwertowany ci¹g znaków.
     */
    std::string toLowerCase(const std::string& str);
};

#endif // ORGANIZER_H

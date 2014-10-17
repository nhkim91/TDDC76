#ifndef VARIABLE_TABLE_H
#define VARIABLE_TABLE_H

#include <map>
#include <string>
#include <stdexcept>
#include <iostream>

/**
 * variable_table_error: kastas om fel inträffar i en Expression- operation;
 * ett diagnostiskt meddelande ska skickas med.
 */

/*
 * Undantagsklass
 */
class variable_table_error: public std::logic_error
{
public:
    explicit variable_table_error(const std::string& what_arg) noexcept
: std::logic_error(what_arg) {}

    explicit variable_table_error(const char* what_arg) noexcept
: std::logic_error(what_arg) {}
};

class Variable_Table
{
public:
    //Default-konstruktor
    Variable_Table() = default;

    //Destruktor
    ~Variable_Table() = default;

    //Kopieringskonstruktor, flyttkonstruktor
    Variable_Table(const Variable_Table&) = default;

    /*
    Variable_Table(Variable_Table&&) noexcept = default;
    //Kopieringstilldelning, flytt-tilldelning
    Variable_Table& operator=(const Variable_Table&) &;
    Variable_Table& operator=(Variable_Table&&) &;
    */

    /*
     insert(namn, värde) ska lägga till en ny variabel och dess värde i tabellen.
    •remove(namn) ska ta bort en variabel och dess värde ur tabellen.
    •find(namn) ska returnera true om variabeln finns i tabellen, annars false.
    •set_value(namn, värde) ska ändra värdet för en variabel som finns i tabellen.
    •get_value(namn) ska returnera värdet för en variabel som finns i tabellen.
    •list(ostream) ska skiva ut alla variabler i tabellen på en utström. För varje variabel skrivs först dess namn ut, följt av ett kolon och ett mellanrum och sist på raden variabelns värde.
    •clear() ska tömma tabellen.
    •empty() ska returnera true om tabellen är tom, annars false.
    */

    void        insert(std::string, long double);
    void        remove(std::string);
    bool        find(std::string) const;
    void        set_value(std::string, long double);
    long double get_value(std::string) const;
    void        list(std::ostream&) const;
    void        clear();
    bool        empty() const;

private:
    std::map<std::string, long double> v_table;
};

#endif // VARIABLE_TABLE_H

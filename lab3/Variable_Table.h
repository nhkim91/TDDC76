/* FILNAMN:       Variable_Table.h
 * LABORATION:    lab3
 * PROGRAMMERARE:Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *               Kerstin Soderqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-10-17
 * BESKRIVNING: Filen innehåller deklarationer för klassen Variable_Table
 */
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

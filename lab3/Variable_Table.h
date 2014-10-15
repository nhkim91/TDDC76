#ifndef VARIABLE_TABLE_H
#define VARIABLE_TABLE_H
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>


/*
 *Undantagsklass
 */
class Variabel_Table_error: public std::logic_error
{
public:
    explicit Variabel_Table_error(const std::string& what_arg) noexcept
: std::logic_error(what_arg) {}

    explicit Variabel_Table_error(const char* what_arg) noexcept
: std::logic_error(what_arg) {}
};


class Variable_Table
{
public:
    //DefaultKonstruktor
    Variable_Table() = default;

    //Destruktor
    ~Variable_Table() = default;

    //Kopieringskonstruktor
    Variable_Table(const Variable_Table&) = default;

    void        insert(std::string name, long double value);
    void        remove(std::string name);
    bool        find(std::string name)                          const;
    void        list(std::ostream&) const;
    long double get_value(std::string name)                     const;
    void        set_value(std::string name, long double value);
    void        clear() noexcept;
    bool        empty()                                         const;


private:
   std::map<std::string, long double> v_table;
};

#endif // VARIABLE_TABLE_H

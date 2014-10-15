#ifndef VARIABLE_TABLE_H
#define VARIABLE_TABLE_H
#include <map>
#include <string>
#include <iostream>
class Variable_Table
{
public:
    Variable_Table() = default;
    ~Variable_Table() = default;
    Expression_Tree(const Variable_Table()&) = default;

   /*
    • insert(namn, värde) ska lägga till en ny variabel och dess värde i tabellen.
    • remove(namn) ska ta bort en variabel och dess värde ur tabellen.
    • find(namn) ska returnera true om variabeln finns i tabellen, annars false.
    • set_value(namn, värde) ska ändra värdet för en variabel som finns i tabellen.
    • get_value(namn) ska returnera värdet för en variabel som finns i tabellen.
    • list(ostream) ska skiva ut alla variabler i tabellen på en utström. För varje variabel skrivs först dess namn ut,
    följt av ett kolon och ett mellanrum och sist på raden variabelns värde.
    • clear() ska tömma tabellen.
    • empty() ska returnera true om tabellen är tom, annars false.
    */

    void insert(std::string name, long double value);
    void remove(std::string name);
    bool find(std::string name);
    void set_value(std::string name, value);
    long double get_value(std::string name);
    void list(std::ostream&);


private:


};

#endif // VARIABLE_TABLE_H

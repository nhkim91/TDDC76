#include "Variable_Table.h"
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>



using namespace std;

void Variable_Table::insert(string name, long double value)
{
    v_table.insert(pair <string, double> (name, value));
}

void Variable_Table::remove(std::string name)
{
    v_table.erase(name);
}

bool Variable_Table::find(std::string name) const
{
    return v_table.count(name);
}

void Variable_Table::list(ostream& os) const
{
    if (empty())
    {
        throw Variabel_Table_error("The variable don't exist!");
    }
    else
    {
        map<string, long double>::const_iterator it;
        for (it = v_table.begin(); it != v_table.end(); it++)
        {
            os << it->first << ": " << it->second << endl;
        }
    }
}

long double Variable_Table::get_value(string name) const
{
    return (v_table.find(name))->second;
}

void Variable_Table::set_value(std::string name, long double value)
{
    if (find(name))
    {
        v_table[name] = value;
    }
    else
    {
        throw Variabel_Table_error("The variable don't exist!");
    }
}

void Variable_Table::clear() noexcept
{
    v_table.clear();
}

//Empty
bool Variable_Table::empty() const
{
    return v_table.empty();
}

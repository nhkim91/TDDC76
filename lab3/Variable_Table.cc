#include "Variable_Table.h"
#include <map>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

void Variable_Table::insert(string name, long double value)
{
    v_table.insert(pair<string, double> (name, value));
}

//Vi ska inte ha "om variabeln inte finns"?
void Variable_Table::remove(string name)
{
    v_table.erase(name);
}

bool Variable_Table::find(string name) const
{
    return v_table.count(name);
}

void Variable_Table::set_value(string name, long double value)
{
    if(find(name))
    {
        v_table[name] = value;
    }
    else
        throw variable_table_error{"The variable doesn't exist!"};
}

//Vi ska inte ha "om variabeln inte finns"?
long double Variable_Table::get_value(string name) const
{
    return v_table.find(name)->second;
}


void Variable_Table::list(std::ostream &os) const
{
    if(empty())
    {
        throw variable_table_error{"The Variable_Table is empty!"};
    }
    else
    {
        map<string, long double>::const_iterator it;
        for(it = v_table.begin(); it != v_table.end(); it++)
        {
            os << it->first << ": " << it->second << endl;
        }
    }
}


void Variable_Table::clear()
{
    v_table.clear();
}


bool Variable_Table::empty() const
{
    return v_table.empty();
}


/* FILNAMN:       Variable_Table.cc
 * LABORATION:    lab3
 * PROGRAMMERARE:Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *               Kerstin Soderqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-10-17
 * BESKRIVNING: Filen innehåller definitioner för klassen Variable_Table
 */

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

long double Variable_Table::get_value(string name) const
{
    if(find(name))
    {
        return v_table.find(name)->second;
    }
    else
        throw variable_table_error{"The variable doesn't exist!"};
}

void Variable_Table::list(std::ostream &os) const
{
    if(empty())
    {
        os << "Empty list" << endl;
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


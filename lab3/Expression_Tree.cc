/* FILNAMN:       Expression.cc
 * LABORATION:    lab3
 * PROGRAMMERARE:Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *               Kerstin Soderqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-10-17
 * BESKRIVNING: Filen innehåller definitioner för klassen Expression_Tree som tar inkluderar Variable_Table
 */
 
#include "Expression_Tree.h"
#include "Variable_Table.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip> //setw

using namespace std;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//-*-*-*-*- Binary_Operator -*-*-*-*-
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

string Binary_Operator::get_postfix() const
{
    return left_val->get_postfix() + " " + right_val->get_postfix() + " " + _str;
}

string Binary_Operator::get_infix() const
{
    if(_str == "=" || _str == "+" || _str == "-")
    {
        return left_val->get_infix() + " " + _str + " " + right_val->get_infix();
    }
    else
        return "(" + left_val->get_infix() + " " + _str + " " + right_val->get_infix() + ")";
}

string Binary_Operator::str() const
{
    return _str;
}

void Binary_Operator::print(ostream& os, int depth = 0) const
{
    right_val->print(os, depth + 2);
    os << endl << string(depth + 1, ' ') << '/' << endl;
    os << string(depth, ' ') << _str << endl;
    os << string(depth + 1, ' ') << '\\' << endl;
    left_val->print(os, depth + 2);
}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//-*-*-*-*- Operand -*-*-*-*-
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

string Operand::get_postfix() const
{
    return str();
}

string Operand::get_infix() const
{
    return str();
}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//-*-*-*-*- Assign -*-*-*-*-
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

Assign::Assign(Expression_Tree* newleftNode, Expression_Tree* newrightNode)
    : Binary_Operator(newleftNode, newrightNode, "=")
{
    if (dynamic_cast<Variable*>(newleftNode) == nullptr)
    {
        throw expression_tree_error("You need to enter a variable to the left of = ");
    }
}

long double Assign::evaluate() const
{
    Variable* leftNode = dynamic_cast<Variable*>(left_val);
    leftNode->set_value(right_val->evaluate());

    return leftNode->get_value();
}

Expression_Tree* Assign::clone() const
{
    return new Assign(*this);
}

//-*-*-*-*-*-*-*-*-*-*-*-*-
//-*-*-*-*- Plus -*-*-*-*-
//-*-*-*-*-*-*-*-*-*-*-*-*-

long double Plus::evaluate() const
{
    return (left_val->evaluate() + right_val->evaluate());
}

Expression_Tree* Plus::clone() const
{
    return new Plus(*this);
}

//-*-*-*-*-*-*-*-*-*-*-*-*-
//-*-*-*-*- Minus -*-*-*-*-
//-*-*-*-*-*-*-*-*-*-*-*-*-

long double Minus::evaluate() const
{
    return (left_val->evaluate() - right_val->evaluate());
}

Expression_Tree* Minus::clone() const
{
    return (new Minus(*this));
}

//-*-*-*-*-*-*-*-*-*-*-*-*-
//-*-*-*-*- Times -*-*-*-*-
//-*-*-*-*-*-*-*-*-*-*-*-*-

long double Times::evaluate() const
{
    return (left_val->evaluate() * right_val->evaluate());
}

Expression_Tree* Times::clone() const
{
    return (new Times(*this));
}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//-*-*-*-*- Divide -*-*-*-*-
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

long double Divide::evaluate() const
{
    return (left_val->evaluate() / right_val->evaluate());
}

Expression_Tree* Divide::clone() const
{
    return (new Divide(*this));
}

//-*-*-*-*-*-*-*-*-*-*-*-*-
//-*-*-*-*- Power -*-*-*-*-
//-*-*-*-*-*-*-*-*-*-*-*-*-

long double Power::evaluate() const
{
    return pow(left_val->evaluate(), right_val->evaluate());
}

Expression_Tree* Power::clone() const
{
    return (new Power(*this));
}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//-*-*-*-*- Integer -*-*-*-*-
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

long double Integer::evaluate() const
{
    return _value;
}

string Integer::str() const
{
    return to_string(_value);
}

void Integer::print(ostream& os, int depth) const
{
    os << string(depth + 1, ' ') << _value;
}

Expression_Tree* Integer::clone() const
{
    return (new Integer(*this));
}

//-*-*-*-*-*-*-*-*-*-*-*-*-
//-*-*-*-*- Real -*-*-*-*-
//-*-*-*-*-*-*-*-*-*-*-*-*-

long double Real::evaluate() const
{
    return _value;
}

string Real::str() const
{
    return to_string(_value);
}

void Real::print(ostream& os, int depth) const
{
    os << string(depth + 1, ' ') << _value;
}

Expression_Tree* Real::clone() const
{
    return (new Real(*this));
}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//-*-*-*-*- Variable -*-*-*-*-
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

Variable::Variable(std::string str, Variable_Table* v_table)
{
    _str = str;
    ref_v_table = v_table;

    ref_v_table->insert(str, _value);
}

long double Variable::evaluate() const
{
    if(ref_v_table->find(_str))
    {
        return ref_v_table->get_value(_str);
    }
    else
        throw expression_tree_error{"Variable name doesn't exist!"};
}


string Variable::str() const
{
    return _str;
}

void Variable::print(ostream& os, int depth) const
{
    os << string(depth + 1, ' ') << _str;
}

Expression_Tree* Variable::clone() const
{
    return (new Variable(*this));
}

long double Variable::get_value() const
{
    return _value;
}

void Variable::set_value(long double new_val)
{   
    _value = new_val;
    if(ref_v_table->find(_str))
    {
        ref_v_table->set_value(_str, _value);
    }
    else
        throw expression_tree_error{"Variable name doesn't exist!"};
}

/*
 * Expression_Tree.cc
 */
#include "Expression_Tree.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>

using namespace std;

// TODO: Gör klart print, Assign, set_value och get_value.
// Fråga: Hur ska set_value, get_value och evaluate() Variable fungera?
// Tips på hur man gör print

//-*-*-*-*- Binary_Operator str() -*-*-*-*-
string Binary_Operator::get_postfix() const
{
    return left_val->get_postfix() + " " + right_val->get_postfix() + " " + _str;
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

//-*-*-*-*- Assign -*-*-*-*-
Assign::Assign(Expression_Tree* newleftNode, Expression_Tree* newrightNode)
    : Binary_Operator(newleftNode, newrightNode, "=")
{
    if (dynamic_cast<Variable*>(newleftNode) == nullptr)
    {
        throw expression_error("You need to enter a variable to the left of = ");
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

//-*-*-*-*- Plus -*-*-*-*-
long double Plus::evaluate() const
{
    return (left_val->evaluate() + right_val->evaluate());
}

Expression_Tree* Plus::clone() const
{
    return new Plus(*this);
}

//-*-*-*-*- Minus -*-*-*-*-
long double Minus::evaluate() const
{
    return (left_val->evaluate() - right_val->evaluate());
}

Expression_Tree* Minus::clone() const
{
    return (new Minus(*this));
}

//-*-*-*-*- Times -*-*-*-*-
long double Times::evaluate() const
{
    return (left_val->evaluate() * right_val->evaluate());
}

Expression_Tree* Times::clone() const
{
    return (new Times(*this));
}

//-*-*-*-*- Divide -*-*-*-*-
long double Divide::evaluate() const
{
    return (left_val->evaluate() / right_val->evaluate());
}

Expression_Tree* Divide::clone() const
{
    return (new Divide(*this));
}

//-*-*-*-*- Power -*-*-*-*-
long double Power::evaluate() const
{
    return pow(left_val->evaluate(), right_val->evaluate());
}

Expression_Tree* Power::clone() const
{
    return (new Power(*this));
}

//-*-*-*-*- Integer -*-*-*-*-

long double Integer::evaluate() const
{
    return _value;
}

string Integer::get_postfix() const
{
    return to_string(_value);
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

//-*-*-*-*- Real -*-*-*-*-
long double Real::evaluate() const
{
    return _value;
}

string Real::get_postfix() const
{
    return to_string(_value);
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

//-*-*-*-*- Variable -*-*-*-*-
long double Variable::evaluate() const
{
    return _value;
}

string Variable::get_postfix() const
{
    return _str;
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
}

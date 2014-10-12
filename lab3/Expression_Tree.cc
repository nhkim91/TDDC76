/*
 * Expression_Tree.cc
 */
#include "Expression_Tree.h"
#include <iostream>
#include <string>

// INKLUDERA FÖR DET SOM KOMMER ATT ANVÄNDAS I DENNA FIL!
using namespace std;


 

//-*-*-*-*-Plus-*-*-*-*-

long double Plus::evaluate() const
{
	return (left_val->evaluate() + right_val->evaluate());	
}

//-*-*-*-*-Integer-*-*-*-*-

long double Integer::evaluate() const
{
    return _value;
}

//-*-*-*-*-Real-*-*-*-*-
long double Real::evaluate() const
{
    return _value;
}


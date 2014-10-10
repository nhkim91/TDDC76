/*
 * Expression_Tree.cc
 */
#include "Expression_Tree.h"
#include <iostream>
#include <string>

// INKLUDERA FÖR DET SOM KOMMER ATT ANVÄNDAS I DENNA FIL!
using namespace std;

/*
 *Klassen Expression_Trees definitioner
 */ 

 

//Plus

long double Plus::evaluate() const
{
	return (left_val->evaluate() + right_val->evaluate());	
}


//Integer

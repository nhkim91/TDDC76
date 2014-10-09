/*
 * Expression_Tree.cc
 */
#include "Expression_Tree.h"
// INKLUDERA FÖR DET SOM KOMMER ATT ANVÄNDAS I DENNA FIL!
using namespace std;

//Plus
long double Plus::evaluate() const
{
	return left_val->evaluate() + right_val->evaluate();	
}
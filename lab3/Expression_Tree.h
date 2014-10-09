/*
 * Expression_Tree.h
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <iosfwd>
#include <string>
#include <stdexcept>

/*
 * expression_error: kastas om ett fel inträffar i en Expression-operation;
 * ett diagnostiskt meddelande ska skickas med.
 */
// ATT GÖRA!


// OBSERVERA: NEDANSTÅENDE ÄR ENDAST KODSKELETT - MODIFIERA OCH KOMPLETTERA!

/*
 * Expression_Tree: Abstrakt, polymorf basklass för alla trädnodklasser.
 */
class Expression_Tree
{
public:
	//Default-konstruktorer
	Expression_Tree() = default;
	virtual ~Expression_Tree() = default;
	Expression_Tree(const Expression_Tree&) = delete;
	
	virtual long double      evaluate() const = 0;
	
/*
	virtual std::string      get_postfix() const = 0;
	virtual std::string      str() const = 0;
	virtual void             print(std::ostream&) const = 0;
	virtual Expression_Tree* clone() const = 0;
*/	
};

/* Binary_Oparator
*
*/
class Binary_Operator : public Expression_Tree
{
public:	
	Binary_Operator(Expression_Tree* newleftNode, Expression_Tree* newrightNode)
		: Expression_Tree(), left_val{newleftNode}, right_val{newrightNode} {}

	virtual ~Binary_Operator()
	{
		delete left_val;
		delete right_val;
	}
	
protected: 	
	Expression_Tree* left_val;
	Expression_Tree* right_val;	

};

/* Operand
*
*/
class Operand : public Expression_Tree
{
public:	
	Operand(Expression_Tree* new_operand)
	{
		operand = new_operand; 
	}
	
	virtual ~Operand() = default; 

protected:
	Expression_Tree* operand;	
};

class Assign : public Binary_Operator
{ 
};

/* Plus
*
*/
class Plus : public Binary_Operator
{ 
public:
	Plus(Expression_Tree* newleftNode, Expression_Tree* newrightNode) : Binary_Operator(newleftNode, newrightNode) {}
	virtual ~Plus() = default;
	virtual long double      evaluate() const;
};

class Minus : public Binary_Operator 
{
};

class Times : public Binary_Operator
{
};

class Divide : public Binary_Operator
{
};

class Power: public Binary_Operator
{
};

class Integer : public Operand
{
public:	
	Integer(int value);
	virtual ~Integer() = default;
};

class Real : public Operand
{
};

class Variable : public Operand
{
};

#endif
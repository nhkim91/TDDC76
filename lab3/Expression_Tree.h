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


/*
 *Undantagsklass
 */
class tree_error: public std::logic_error
{
public:
    explicit tree_error(const std::string& what_arg) noexcept
: std::logic_error(what_arg) {}

    explicit tree_error(const char* what_arg) noexcept
: std::logic_error(what_arg) {}
};


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

//-*-*-*-*- Binary_Oparator -*-*-*-*-

class Binary_Operator : public Expression_Tree
{
public:
    virtual long double      evaluate() const override = 0;
    virtual ~Binary_Operator()
    {
        delete left_val;
        delete right_val;
    }

    Binary_Operator(Expression_Tree* newleftNode, Expression_Tree* newrightNode, std::string str)
        : Expression_Tree(), left_val {newleftNode}, right_val {newrightNode}, _str(str) {}

protected:
    Expression_Tree* left_val;
    Expression_Tree* right_val;
    std::string _str {""};
};

//-*-*-*-*- Operand -*-*-*-*-
class Operand : public Expression_Tree
{
public:
    Operand() = default;
    Operand(Expression_Tree* new_operand) : Expression_Tree(), operand {new_operand} {}
    virtual ~Operand() = default;
    virtual long double      evaluate() const override = 0;

protected:
    Expression_Tree* operand;
};

class Assign : public Binary_Operator
{
};

//-*-*-*-*- Plus -*-*-*-*-

class Plus : public Binary_Operator
{
public:
    Plus() = default;
    virtual ~Plus() = default;
    virtual long double evaluate() const override;
    Plus(Expression_Tree* newleftNode, Expression_Tree* newrightNode) : Binary_Operator(newleftNode, newrightNode, "+") {}
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
//-*-*-*-*- Integer -*-*-*-*-
class Integer : public Operand
{
public:
    Integer(long int value = 0) : Operand() , _value {value} {}
    virtual ~Integer() = default;
    virtual long double      evaluate() const override;

private:
    long int _value {0};
};

//-*-*-*-*- Real -*-*-*-*-
class Real : public Operand
{
public:
    Real(long double value = 0) : Operand(), _value {value} {}
    virtual ~Real() = default;
    virtual long double      evaluate() const override;

private:
    long double _value {0};
};

//-*-*-*-*- Variable -*-*-*-*-
class Variable : public Operand
{
public:
    Variable() = default;
    virtual ~Variable() = default;
    virtual long double      evaluate() const = 0 ;
    Variable(std::string str) : Operand(), _str {str} {}

private:
    std::string _str {""};
};

#endif

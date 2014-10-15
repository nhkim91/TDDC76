/*
 * Expression_Tree.h
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <iosfwd>
#include <string>
#include <stdexcept>

/*
 * expression_tree_error: kastas om ett fel inträffar i en Expression-operation;
 * ett diagnostiskt meddelande ska skickas med.
 */


/*
 *Undantagsklass
 */
class expression_tree_error: public std::logic_error
{
public:
    explicit expression_tree_error(const std::string& what_arg) noexcept
: std::logic_error(what_arg) {}

    explicit expression_tree_error(const char* what_arg) noexcept
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
    Expression_Tree(const Expression_Tree&) = default;

    virtual long double      evaluate() const = 0;
    virtual std::string      get_postfix() const = 0;
    virtual std::string      get_infix() const = 0;
    virtual std::string      str() const = 0;
    virtual void             print(std::ostream&, int depth = 3) const = 0;
    virtual Expression_Tree* clone() const = 0;



};

//-*-*-*-*- Binary_Oparator -*-*-*-*-

class Binary_Operator : public Expression_Tree
{
public:
    virtual ~Binary_Operator()
    {
        delete left_val;
        delete right_val;
    }

    virtual long double      evaluate() const override = 0;
    virtual std::string      get_postfix() const override;
    virtual std::string      get_infix() const override;
    virtual std::string      str() const override;
    virtual void             print(std::ostream&, int depth) const override;
    virtual Expression_Tree* clone() const override = 0;

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
    virtual ~Operand() = default;

    virtual long double evaluate() const override = 0;
    virtual std::string      get_postfix() const override = 0;
    virtual std::string      get_infix() const override = 0;
    virtual std::string      str() const override = 0;
    virtual void             print(std::ostream&, int) const override = 0;
    virtual Expression_Tree* clone() const override = 0;

    Operand(Expression_Tree* new_operand) : Expression_Tree(), operand {new_operand} {}

protected:
    Expression_Tree* operand;
};

//-*-*-*-*- Assign -*-*-*-*-
class Assign : public Binary_Operator
{
public:
    Assign() = default;
    virtual ~Assign() = default;
    virtual long double evaluate() const override;
    virtual Expression_Tree* clone() const override;

    Assign(Expression_Tree* newleftNode, Expression_Tree* newrightNode);
};

//-*-*-*-*- Plus -*-*-*-*-
class Plus : public Binary_Operator
{
public:
    Plus() = default;
    virtual ~Plus() = default;
    virtual long double evaluate() const override;
    virtual Expression_Tree* clone() const override;

    Plus(Expression_Tree* newleftNode, Expression_Tree* newrightNode) : Binary_Operator(newleftNode, newrightNode, "+") {}
};

//-*-*-*-*- Minus -*-*-*-*-
class Minus : public Binary_Operator
{
public:
    Minus() = default;
    virtual ~Minus() = default;
    virtual long double evaluate() const override;
    virtual Expression_Tree* clone() const override;

    Minus(Expression_Tree* newleftNode, Expression_Tree* newrightNode) : Binary_Operator(newleftNode, newrightNode, "-") {}
};

//-*-*-*-*- Times -*-*-*-*-
class Times : public Binary_Operator
{
public:
    Times() = default;
    virtual ~Times() = default;
    virtual long double evaluate() const override;
    virtual Expression_Tree* clone() const override;

    Times(Expression_Tree* newleftNode, Expression_Tree* newrightNode) : Binary_Operator(newleftNode, newrightNode, "*") {}
};

//-*-*-*-*- Divide -*-*-*-*-
class Divide : public Binary_Operator
{
public:
    Divide() = default;
    virtual ~Divide() = default;
    virtual long double evaluate() const override;
    virtual Expression_Tree* clone() const override;

    Divide(Expression_Tree* newleftNode, Expression_Tree* newrightNode) : Binary_Operator(newleftNode, newrightNode, "/") {}
};

//-*-*-*-*- Power -*-*-*-*-
class Power: public Binary_Operator
{
public:
    Power() = default;
    virtual ~Power() = default;
    virtual long double evaluate() const override;
    virtual Expression_Tree* clone() const override;

    Power(Expression_Tree* newleftNode, Expression_Tree* newrightNode) : Binary_Operator(newleftNode, newrightNode, "^") {}
};

//-*-*-*-*- Integer -*-*-*-*-
class Integer : public Operand
{
public:
    virtual ~Integer() = default;

    virtual long double      evaluate() const override;
    virtual std::string      get_postfix() const override;
    virtual std::string      get_infix() const override;
    virtual std::string      str() const override;
    virtual void             print(std::ostream& os, int depth = 0) const override;
    virtual Expression_Tree* clone() const override;

    Integer(long int value = 0) : Operand() , _value {value} {}

private:
    long int _value {0};
};

//-*-*-*-*- Real -*-*-*-*-
class Real : public Operand
{
public:
    virtual ~Real() = default;
    virtual long double      evaluate() const override;
    virtual std::string      get_postfix() const override;
    virtual std::string      get_infix() const override;
    virtual std::string      str() const override;
    virtual void             print(std::ostream& os, int depth = 0) const override;
    virtual Expression_Tree* clone() const override;

    Real(long double value = 0) : Operand(), _value {value} {}

private:
    long double _value {0};
};

//-*-*-*-*- Variable -*-*-*-*-
class Variable : public Operand
{
public:
    Variable() = default;
    virtual ~Variable() = default;

    virtual long double      evaluate() const override;
    virtual std::string      str() const override;
    virtual std::string      get_postfix() const override;
    virtual std::string      get_infix() const override;
    virtual void             print(std::ostream& os, int depth = 0) const override;
    virtual Expression_Tree* clone() const override;

    long double get_value() const;
    void set_value(long double new_val);

    Variable(std::string str) : Operand(), _str {str} {}

private:
    std::string _str {""};
    long double _value {0};
    Variable_Table* ref_v_table;
};

#endif

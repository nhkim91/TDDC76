/*
 * Expression.h
 */
#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iosfwd>
#include <stdexcept>
#include <string>

/**
 * expression_error: kastas om fel inträffar i en Expression- operation;
 * ett diagnostiskt meddelande ska skickas med.
 */

/*
 * Undantagsklass
 */
class expression_error: public std::logic_error
{
public:
    explicit expression_error(const std::string& what_arg) noexcept
        : std::logic_error(what_arg) {}

    explicit expression_error(const char* what_arg) noexcept
        : std::logic_error(what_arg) {}
};

/**
 * Expression: Klass för att representera ett enkelt aritmetiskt uttryck.
 */
class Expression
{
public:

    //Default-konstruktor
    Expression(class Expression_Tree* = nullptr);
    //Destruktor
    ~Expression();

    //Kopieringskonstruktor, flyttkonstruktor
    Expression(const Expression &e);
    Expression(Expression&&) noexcept;

    //Kopieringstilldelning, flytt-tilldelning
    Expression& operator=(const Expression&) &;
    Expression& operator=(Expression&&) &;

    long double evaluate() const;
    std::string get_postfix() const;
    bool        empty() const;
    void        print_tree(std::ostream&) const;
    void        swap(Expression&);

private:
    Expression_Tree* first_node{nullptr};
};

/**
 * swap: Byter innehåll på två Expression-objekt.
 */
void swap(Expression&, Expression&);

/**
 * make_expression: Hjälpfunktion för att skapa ett Expression-objekt, givet
 * ett infixuttryck i form av en sträng.
 */
Expression make_expression(const std::string& infix);

#endif

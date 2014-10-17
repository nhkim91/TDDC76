/* FILNAMN:       Calculator.h
 * LABORATION:    lab3
 * PROGRAMMERARE:Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *               Kerstin Soderqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-10-17
 * BESKRIVNING: Filen innehåller deklarationer för klassen Calculator
 */
 
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Expression.h"
#include "Variable_Table.h"
#include <vector>
#include <iosfwd>

/**
 * Calculator: klass för att läsa in, lagra och bearbeta enkla aritmetiska
 * uttryck. För att använda kalylatorn - skapa ett Calculator-objekt och 
 * anropa run().
 *
 * Anm: move-konstruktorn och move-illdelningsoperatorn genereras inte om
 * en destruktor, kopieringskonstruktor eller kopieringstilldelnings-
 * operator deklareras.
 */
class Calculator
{
public:
   Calculator() = default;
   ~Calculator() = default;

   Calculator(const Calculator&) = delete;
   Calculator& operator=(const Calculator&) = delete;

   void run();

private:
   static const std::string valid_cmds_;

   Expression current_expression_;
   std::vector<Expression> expressions;
   unsigned int n{0};

   char command_;

   static void print_help();

   void get_command();
   bool valid_command() const;
   void execute_command();

   void read_expression(std::istream&);
   void list_infix() const;

    Variable_Table* v_table = new Variable_Table;
};

#endif

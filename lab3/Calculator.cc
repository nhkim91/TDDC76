/*
 * Calculator.cc
 */
#include "Calculator.h"
#include "Expression.h"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

const string Calculator::valid_cmds_("?HUBPTS");

/**
 * run: Huvudfunktionen för kalkylatorn. Skriver ut hjälpinformation
 * och läser sedan sedan in ett kommando i taget och utför det.
 */
void
Calculator::
run()
{
   cout << "Välkommen till Kalkylatorn!\n\n";
   print_help();

   do 
   {
      try 
      {
	 get_command();
	 if (valid_command()) execute_command();
      }
      catch (const exception& e) 
      {
	 cout << e.what() << '\n';
      }
      // Oförutsedda undantag avbryter programkörningen, via main().
   }
   while (command_ != 'S');
}

/**
 * print_help: Skriver ut kommandorepertoaren.
 */
void
Calculator::
print_help()
{
   cout << "  H, ?  Skriv ut denna information\n";
   cout << "  U     Mata in ett nytt uttryck\n";
   cout << "  B     Beräkna aktuellt uttryck\n";
   cout << "  P     Visa aktuellt uttryck som postfix\n";
   cout << "  T     Visa aktuellt uttryck som träd\n";
   cout << "  S     Avsluta kalkylatorn\n";

}

/**
 * get_command: Läser ett kommando (ett tecken), gör om till versal och lagrar
 * kommandot i medlemmen command_, för vidare behandling av andra operationer. 
 * Ingen kontroll görs om det skrivits mer, i så fall skräp, på kommandoraden.
 */
void
Calculator::
get_command()
{
   cout << ">> ";
   cin >> command_;
   command_ = toupper(command_);
}

/**
 * valid_command: Kontrollerar om kommandot som finns i medlemmen command_
 * tillhör den tillåtna kommandorepertoraren och returnerar antingen true
 * (giltigt kommando) eller false (ogiltigt kommando).
 */
bool
Calculator::
valid_command() const
{
   if (valid_cmds_.find(command_) == string::npos)
   {
      cout << "Otillåtet kommando: " << command_ << "\n";
      return false;
   }
   return true;
}

/**
 * execute_command: Utför kommandot som finns i medlemmen command_. Kommandot
 * förutsätts ha kontrollerats med valid_command() och alltså är ett giltigt 
 * kommando.
 */
void
Calculator::
execute_command()
{
   if (command_ == 'H' || command_ == '?')
      print_help();
   else if (command_ == 'U')
      read_expression(cin);
   else if (command_ == 'B')
      cout << current_expression_.evaluate() << "\n";
   else if (command_ == 'P')
      cout << current_expression_.get_postfix() << "\n";
   else if (command_ == 'T')
      current_expression_.print_tree(cout);
   else if (command_ == 'S')
      cout << "Kalkylatorn avlutas, välkommen åter!\n";
   else
      cout << "Detta ska inte hända!\n";
}

/**
 * read_expression: läser ett infixuttryck från inströmmen is och ger detta 
 * till funktionen make_expression() som returnerar ett objekt av typen 
 * Expression, vilket lagras som "aktuellt uttryck" i current_expression_.
 */
void
Calculator::
read_expression(istream& is)
{
   string infix;

   is >> ws;

   if (getline(is, infix))
   {
      current_expression_ = make_expression(infix);
   }
   else
   {
      cout << "Felaktig inmatning!\n";
   }
}

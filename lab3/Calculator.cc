/* FILNAMN:       Calculator.cc
 * LABORATION:    lab3
 * PROGRAMMERARE:Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *               Kerstin Soderqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-11-13
 * BESKRIVNING: Filen innehåller definitioner för klassen Calculator och inkluderar klassen Expression
 */

#include "Calculator.h"
#include "Expression.h"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

const string Calculator::valid_cmds_("?HUBPTSILARVXN");

/**
 * run: Huvudfunktionen för kalkylatorn. Skriver ut hjälpinformation
 * och läser sedan sedan in ett kommando i taget och utför det.
 */
void Calculator::run()
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
void Calculator::print_help()
{
    cout << "  H, ?  Skriv ut denna information\n";
    cout << "  U     Mata in ett nytt uttryck\n";
    cout << "  B     Beräkna aktuellt uttryck\n";
    cout << "  B n   Beräkna uttryck n\n";
    cout << "  P     Visa aktuellt uttryck som postfix\n";
    cout << "  P n   Visa uttryck n som postfix\n";
    cout << "  I     Visa aktuellt uttryck som infix\n";
    cout << "  I n   Visa uttryck n som infix\n";
    cout << "  L     Lista alla uttryck som infix\n";
    cout << "  T     Visa aktuellt uttryck som träd\n";
    cout << "  T n   Visa uttryck n som ett träd\n";
    cout << "  N     Visa antal lagrade uttryck\n";
    cout << "  A n   Gör uttryck n till aktuellt uttryck\n";
    cout << "  R     Radera aktuellt uttryck\n";
    cout << "  R n   Radera uttryck n\n";
    cout << "  V     Lista alla variabler\n";
    cout << "  X     Radera alla variabler\n";
    cout << "  S     Avsluta kalkylatorn\n";

}

/**
 * get_command: Läser ett kommando (ett tecken), gör om till versal och lagrar
 * kommandot i medlemmen command_, för vidare behandling av andra operationer.
 * Ingen kontroll görs om det skrivits mer, i så fall skräp, på kommandoraden.
 */
void Calculator::get_command()
{
    cout << ">> ";
    cin >> command_;
    command_ = toupper(command_);

    if (cin.peek() != '\n') // Gör så att man kan läsa in t.ex R n.
    {
        cin >> ws;

        if (isdigit(cin.peek()))
        {
            cin >> n;
        }
    }
}

/**
 * valid_command: Kontrollerar om kommandot som finns i medlemmen command_
 * tillhör den tillåtna kommandorepertoraren och returnerar antingen true
 * (giltigt kommando) eller false (ogiltigt kommando).
 */
bool Calculator::valid_command() const
{
    if (valid_cmds_.find(command_) == string::npos)
    {
        cout << "Otillåtet kommando: " << command_ << "\n";
        return false;
    }
    return true;
}
/*Hjälpfunktin som kollar om n är giltigt
 */
bool Calculator::check_n() const
{
    if (n <= 0 || n > expressions.size())
    {
        cout  << "Uttryck på plats " << n << " finns inte! Finns inget aktuellt uttryck" << endl;
        return false;
    }
    return true;
}
/**
 * execute_command: Utför kommandot som finns i medlemmen command_. Kommandot
 * förutsätts ha kontrollerats med valid_command() och alltså är ett giltigt
 * kommando.
 */
void Calculator::execute_command()
{
    if (command_ == 'H' || command_ == '?')
        print_help();
    else if (command_ == 'U')
    {
        read_expression(cin);
        n = expressions.size();
    }
    else if (command_ == 'B')
    {
        if (check_n())
            cout << expressions[n - 1].evaluate() << endl;
    }
    else if (command_ == 'P')
    {
        if (check_n())
            cout << expressions[n - 1].get_postfix() << endl;
    }
    else if (command_ == 'I')
    {
        if (check_n())
            cout << expressions[n - 1].get_infix() << endl;
    }
    else if (command_ == 'L')
        list_infix();
    else if (command_ == 'T')
    {
        if (check_n())
            expressions[n - 1].print_tree(cout);
    }
    else if (command_ == 'N')
        cout << expressions.size() << endl;
    else if (command_ == 'A')
    {
        check_n(); //sätter n till aktuellt uttryck, behöver bara kontrollera om n > 0
    }
    else if (command_ == 'R')
    {
        if (check_n())
            expressions.erase(expressions.begin() + n - 1);
    }
    else if (command_ == 'V')
        v_table->list(cout);
    else if (command_ == 'X')
        v_table->clear();
    else if (command_ == 'S')
        cout << "Kalkylatorn avlutas, välkommen åter!" << endl;
    else
        cout << "Detta ska inte hända!" << endl;
}


/**
 * read_expression: läser ett infixuttryck från inströmmen is och ger detta
 * till funktionen make_expression() som returnerar ett objekt av typen
 */
void Calculator::read_expression(istream& is)
{
    string infix;

    is >> ws;

    if (getline(is, infix))
    {
        expressions.push_back(make_expression(infix, v_table));
    }
    else
    {
        cout << "Felaktig inmatning!\n";
    }
}

//Skriver alla uttryck som infix
void Calculator::list_infix() const
{

    for (unsigned int it = 0; it < expressions.size(); it++)
    {
        int i = it + 1;
        cout << i << ": " << expressions[it].get_infix() << endl;
    }
}

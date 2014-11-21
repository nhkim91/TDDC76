/* FILNAMN:       Expression.cc
 * LABORATION:    lab3
 * PROGRAMMERARE:Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *               Kerstin Soderqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-11-13
 * BESKRIVNING:
 *
 * kalkylator.cc
 *
 * Ett objekt av typen Calculator skapas i main() och Calculator::run()
 * körs. Om ett undantag kastas av Calculator::run() fångas detta och
 * programmet avslutas sedan efter att ett felmeddelande skrivits ut.
 * Alla förutsedda fel ska ha fångats och hanterats av Calculator::run().
 */
#include "Calculator.h"
#include <iostream>

using namespace std;

int main()
{
    Calculator calc;

    try
    {
        calc.run();
    }
    catch (...)
    {
        cout << "Ett okänt fel har inträffat.\n";
    }

    return 0;
}

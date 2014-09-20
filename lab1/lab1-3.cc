/*
 * FILNAMN:       lab1-3.cc
 * LABORATION:    lab1-3
 * PROGRAMMERARE: Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *                Kerstin Söderqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-09-16
 *
 * BESKRIVNING:
 * Programmet läser in en text från cin och räknar olika slags tecken
 */

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    char c;

    int sumalpha{0}; // räknare för bokstäver
    int sumdigit{0}; // räknare för siffror
    int sumpunct{0}; // räknare för interpunktionstecken
    int sumspace{0}; // räkanre för vita tecken
    int sumtotal{0}; // tecken totalt


    while (cin.get (c)) 
    {
        sumtotal++;

        if (isalpha(c)) //kontrollerar om c är en bokstav
        {
            sumalpha++;
        }
        else if (isdigit(c)) // kontrollerar om c är en siffra
        {
            sumdigit++;
        }
        else if (ispunct(c)) // kontrollerar om c är interpunktionstecken
        {
            sumpunct++;
        }
        else if (isspace(c)) // kontrollerar om c är ett vitt tecken
        {
            sumspace++;
        }
    }

    cout << "Input contained:" << endl;
    cout << sumalpha << " alphabetical characters" << endl;
    cout << sumdigit << " numeric characters" << endl;
    cout << sumpunct << " punctuation character" << endl;
    cout << sumspace << " white space" << endl;
    cout << sumtotal << " total characters" << endl;

    return 0;

}


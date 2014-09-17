/*
 * FILNAMN:       lab1-2.cc
 * LABORATION:    lab1-2
 * PROGRAMMERARE: Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *                Kerstin S�derqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-09-16
 *
 * BESKRIVNING:
 * G�r om antalet Kelvin grader till antalet grader Celsius och Fahrenheit.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    double Celsius, Fahrenheit, Kelvin; //double=2 float, dvs man kan skriva in dubbel s� m�nga decimaler

    do // utf�r detta s� l�nge kelvin inte �r 0
    {
        cout << "Please enter the temperature in Kelvin:";
        cin >> Kelvin;

        if (Kelvin < 0)
        {
            cout << "Negative Kelvin value are not allowed!" << endl;
        }
        else if (Kelvin == 0)
        {
            cout << "0.00 Kelvin is -273.15 degrees Celsius or -459.67 degrees Fahrenheit." << endl <<"End";
        }
        else
        {
            cout << setprecision(2) << fixed; //begr�nsar till tv� decimaler
			Celsius = Kelvin - 273.15;
            Fahrenheit = 1.8 * Kelvin - 459.67;

            cout << Kelvin << " Kelvin translates to "
                 << Celsius << " degrees Celsius or "
                 << Fahrenheit << " degrees Fahrenheit." << endl;

        }
    } while (Kelvin != 0);
    return 0;
}

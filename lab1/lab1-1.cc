/*
 * FILNAMN:       lab1-1.cc
 * LABORATION:    lab1-1
 * PROGRAMMERARE: Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *                Kerstin S�derqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-09-16
 *
 * BESKRIVNING: 
 * G�r en tabell av ett inmatet v�rde (i) 
 * fr�n dec. till oct och hex fr�n 1:i
 */

#include <iostream>
#include <iomanip>

using namespace std; //std:: (standard bibliotek, prefix)


int main()
{
    int i;
    cout << "Please enter a value (at least 1): "; //antar att man bara skriver in ett heltal
    cin >> i;

    while (i < 1)
    {
        cout << "Wrong value. Please enter a new value (at least 1):";
        cin >> i; 

    }
    cout << setw(3); //bredd p� tabellen
    cout << "DEC";
    cout.width(10);
    cout << "OCT";
    cout.width(10);
    cout << "HEX";
    cout << endl;

    for (int j=1; j<=i; j++) //loopen skriver ut det inmatade v�rden och fram�t tills j>i
    {
        cout << setw(3);
        cout << dec << j;
        cout.width(10); 
        cout << oct << j; 
        cout.width(10);
        cout << hex << j << endl; 
    }
    return 0;

}

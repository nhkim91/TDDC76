/*
 * FILNAMN:       lab1-5.cc
 * LABORATION:    lab1-5
 * PROGRAMMERARE: Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *                Kerstin Söderqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-09-20
 *
 * BESKRIVNING:
 * Program som gör om/skriver ut listor. T.ex vänder en lista eller raderar innehållet i en lista.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "list.h"

using namespace std;

using list = list_node*;

int main(int argc, char **argv)
{
   // Kontrollera att ett argument (filnamn) angivits på kommandoraden.
   // Om inte skriv ut ett felmeddelande och avsluta programmet.
	if (argc == 0)
	{
		cout << "Det finns inget argument!" << endl;
		return 0;
	}


	ifstream ifs; // infilström
	ifs.open(argv[1], ifstream::in);

	if(!ifs.is_open()) 
	{
		cout << "Filen kunde inte öppnas" << endl;
		return 0;
	}

	list list_1{nullptr}; //Tom lista
	list list_2{nullptr};

	if(empty(list_1) && empty(list_2))
	{
		cout << "Lista 1 och Lista 2 är tomma\n";
	}
	
	 build_lists(ifs, list_1, list_2); // Gör Lista 1 och Lista 2

   cout << "\nLista 1 efter inläsning av namn:\n";

   print(list_1, cout);
   
   cout << "\nLista 2 efter inläsning av namn:\n";

	print(list_2, cout);
   
   cout << "\nLista 1 utskriven i omvänd ordning:\n";

   print_reverse(list_1, cout); 
   
   cout << "\nLista 1 vänds.\n";

   reverse(list_1);
   
   cout << "\nLista 1 efter vändning:\n";

	print(list_1, cout);
	
   cout << "\nLista 2 raderas.\n";

   clear(list_2);
   
   if (empty(list_2))
      cout << "\nLista 2 är tom.\n";
   else
      cout << "\nLista 2 är inte tom.\n";

   cout << "\nLista 2 tilldelas en kopia av lista 1.\n";

   list_2 = copy(list_1);
   
   cout << "\nLista 2 innehåller:\n";

   print(list_2, cout);

   cout << "\nLista 2 raderas.\n";

   clear(list_2);
   
   cout << "\nLista 1 och 2 byter innehåller.\n";

   swap(list_1, list_2);
   
   if (empty(list_1))  
      cout << "\nLista 1 är tom.\n";
   else
      cout << "\nLista 1 är inte tom.\n";
	  
   cout << "\nLista 2 innehåller:\n";

   print(list_2, cout);

   cout << "\nLista 2 raderas.\n";

   clear(list_2);

   if( empty(list_1) && empty(list_2) )
   {
		cout << "\nLista 1 och Lista 2 är tomma.\n" << endl;
   }

   cout << "Programmet avslutas.\n";

   return 0;
}

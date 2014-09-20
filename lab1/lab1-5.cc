/*
 * FILNAMN:       lab1-5.cc
 * LABORATION:    lab1-5
 * PROGRAMMERARE: Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *                Kerstin S�derqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-09-20
 *
 * BESKRIVNING:
 * Program som g�r om/skriver ut listor. T.ex v�nder en lista eller raderar inneh�llet i en lista.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "list.h"

using namespace std;

using list = list_node*;

int main(int argc, char **argv)
{
   // Kontrollera att ett argument (filnamn) angivits p� kommandoraden.
   // Om inte skriv ut ett felmeddelande och avsluta programmet.
	if (argc == 0)
	{
		cout << "Det finns inget argument!" << endl;
		return 0;
	}


	ifstream ifs; // infilstr�m
	ifs.open(argv[1], ifstream::in);

	if(!ifs.is_open()) 
	{
		cout << "Filen kunde inte �ppnas" << endl;
		return 0;
	}

	list list_1{nullptr}; //Tom lista
	list list_2{nullptr};

	if(empty(list_1) && empty(list_2))
	{
		cout << "Lista 1 och Lista 2 �r tomma\n";
	}
	
	 build_lists(ifs, list_1, list_2); // G�r Lista 1 och Lista 2

   cout << "\nLista 1 efter inl�sning av namn:\n";

   print(list_1, cout);
   
   cout << "\nLista 2 efter inl�sning av namn:\n";

	print(list_2, cout);
   
   cout << "\nLista 1 utskriven i omv�nd ordning:\n";

   print_reverse(list_1, cout); 
   
   cout << "\nLista 1 v�nds.\n";

   reverse(list_1);
   
   cout << "\nLista 1 efter v�ndning:\n";

	print(list_1, cout);
	
   cout << "\nLista 2 raderas.\n";

   clear(list_2);
   
   if (empty(list_2))
      cout << "\nLista 2 �r tom.\n";
   else
      cout << "\nLista 2 �r inte tom.\n";

   cout << "\nLista 2 tilldelas en kopia av lista 1.\n";

   list_2 = copy(list_1);
   
   cout << "\nLista 2 inneh�ller:\n";

   print(list_2, cout);

   cout << "\nLista 2 raderas.\n";

   clear(list_2);
   
   cout << "\nLista 1 och 2 byter inneh�ller.\n";

   swap(list_1, list_2);
   
   if (empty(list_1))  
      cout << "\nLista 1 �r tom.\n";
   else
      cout << "\nLista 1 �r inte tom.\n";
	  
   cout << "\nLista 2 inneh�ller:\n";

   print(list_2, cout);

   cout << "\nLista 2 raderas.\n";

   clear(list_2);

   if( empty(list_1) && empty(list_2) )
   {
		cout << "\nLista 1 och Lista 2 �r tomma.\n" << endl;
   }

   cout << "Programmet avslutas.\n";

   return 0;
}

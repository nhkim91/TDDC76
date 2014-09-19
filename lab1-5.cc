#include <iostream>
#include <fstream>
#include <string>
#include "list.h"


using namespace std;

// Deklarera en funktion build_lists(instr�m, list_1, list_2) som l�ser namn
// fr�n instr�mmen och anv�nder insert() f�r att s�tta in i list_1 och append()
// f�r att s�tta in i list_2. build_lists() ska definieras efter main().

using list = list_node*;

// Komplettera och modifiera:

int main(int argc, char **argv)
{
   // Kontrollera att ett argument (filnamn) angivits p� kommandoraden.
   // Om inte skriv ut ett felmeddelande och avsluta programmet.
	if (argc == 0)
	{
		cout << "There is no file argument!" << endl;
		return 0;
	}

    // �ppna en infilstr�m f�r den fil vars namn givits p� kommandoraden.
    // Kontrollera att �ppningen lyckas, om inte ska ett felmeddelande
    // skrivas ut och programmet avslutas.
	ifstream ifs;
	ifs.open(argv[1], ifstream::in);

	if(!ifs.is_open())
	{
		cout << "Could not open file!" << endl;
		return 0;
	}

   // Deklarera tv� tomma listor, list_1 och list_2
	list list_1{nullptr};
	list list_2{nullptr};

   // Kontrollera med empty() att listorna �r tomma och skriv ut det.

	if(empty(list_1) && empty(list_2))
	{
		cout << "list_1 and list_2 is empty." << endl;
	}

   // Anropa build_lists() f�r att l�sa namn fr�n indata och s�tta in i namnen
   // i list_1 och list_2, enligt vad som sagts om build_lists() ovan.

	 build_lists(ifs, list_1, list_2);

   cout << "Lista 1 efter inl�sning av namn:\n";
   // Skriv ut list_1 med print()
   cout << "Lista 2 efter inl�sning av namn:\n";
   // Skriv ut list_2 med print()

   cout << "Lista 1 utskriven i omv�nd ordning:\n";
   // Skriv ut list_1 med print_reversed()

   cout << "Lista 1 v�nds.\n";
   // V�nd inneh�llet i list_1 med reverse();
   cout << "Lista 1 efter v�ndning:\n";
   // Skriv ut list_1 med print()

   cout << "Lista 2 raderas.\n";
   // Radera list_2 med clear()
   if (empty(list_2))
      cout << "Lista 2 �r tom.\n";
   else
      cout << "Lista 2 �r inte tom.\n";

   cout << "Lista 2 tilldelas en kopia av lista 1.\n";
   // Anv�nd copy() f�r att kopiera list_1
   cout << "Lista 2 inneh�ller:\n";
   // Skriv ut list_2 med print()

   cout << "Lista 2 raderas.\n";
   // Radera list_2 med clear()
   cout << "Lista 1 och 2 byter inneh�ller.\n";
   // Anv�nd swap()
   if (empty(list_1))
      cout << "Lista 1 �r tom.\n";
   else
      cout << "Lista 1 �r inte tom.\n";
   cout << "Lista 2 inneh�ller:\n";
   // Skriv ut list_2 med print()

   cout << "Lista 2 raderas.\n";
   // Radera list_2 med clear()

   // Kontrollera med empty() att listorna �r tomma och skriv ut det.

   cout << "Programmet avslutas.\n";

   return 0;
}

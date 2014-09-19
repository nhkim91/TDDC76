#include <iostream>
#include <fstream>
#include <string>
#include "list.h"


using namespace std;

// Deklarera en funktion build_lists(inström, list_1, list_2) som läser namn
// från inströmmen och använder insert() för att sätta in i list_1 och append()
// för att sätta in i list_2. build_lists() ska definieras efter main().

using list = list_node*;

// Komplettera och modifiera:

int main(int argc, char **argv)
{
   // Kontrollera att ett argument (filnamn) angivits på kommandoraden.
   // Om inte skriv ut ett felmeddelande och avsluta programmet.
	if (argc == 0)
	{
		cout << "There is no file argument!" << endl;
		return 0;
	}

    // Öppna en infilström för den fil vars namn givits på kommandoraden.
    // Kontrollera att öppningen lyckas, om inte ska ett felmeddelande
    // skrivas ut och programmet avslutas.
	ifstream ifs;
	ifs.open(argv[1], ifstream::in);

	if(!ifs.is_open())
	{
		cout << "Could not open file!" << endl;
		return 0;
	}

   // Deklarera två tomma listor, list_1 och list_2
	list list_1{nullptr};
	list list_2{nullptr};

   // Kontrollera med empty() att listorna är tomma och skriv ut det.

	if(empty(list_1) && empty(list_2))
	{
		cout << "list_1 and list_2 is empty." << endl;
	}

   // Anropa build_lists() för att läsa namn från indata och sätta in i namnen
   // i list_1 och list_2, enligt vad som sagts om build_lists() ovan.

	 build_lists(ifs, list_1, list_2);

   cout << "Lista 1 efter inläsning av namn:\n";
   // Skriv ut list_1 med print()
   cout << "Lista 2 efter inläsning av namn:\n";
   // Skriv ut list_2 med print()

   cout << "Lista 1 utskriven i omvänd ordning:\n";
   // Skriv ut list_1 med print_reversed()

   cout << "Lista 1 vänds.\n";
   // Vänd innehållet i list_1 med reverse();
   cout << "Lista 1 efter vändning:\n";
   // Skriv ut list_1 med print()

   cout << "Lista 2 raderas.\n";
   // Radera list_2 med clear()
   if (empty(list_2))
      cout << "Lista 2 är tom.\n";
   else
      cout << "Lista 2 är inte tom.\n";

   cout << "Lista 2 tilldelas en kopia av lista 1.\n";
   // Använd copy() för att kopiera list_1
   cout << "Lista 2 innehåller:\n";
   // Skriv ut list_2 med print()

   cout << "Lista 2 raderas.\n";
   // Radera list_2 med clear()
   cout << "Lista 1 och 2 byter innehåller.\n";
   // Använd swap()
   if (empty(list_1))
      cout << "Lista 1 är tom.\n";
   else
      cout << "Lista 1 är inte tom.\n";
   cout << "Lista 2 innehåller:\n";
   // Skriv ut list_2 med print()

   cout << "Lista 2 raderas.\n";
   // Radera list_2 med clear()

   // Kontrollera med empty() att listorna är tomma och skriv ut det.

   cout << "Programmet avslutas.\n";

   return 0;
}

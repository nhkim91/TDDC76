#include <iostream>
#include <string>
#include <stdexcept>
//#include "monetary.h"
#include "monetary.cc"

using namespace std;
using namespace monetary;

int main()
{
    Money m1;
    Money m2 {100};
    Money m3 {10, 50};
    Money m4 {"SEK"};
    Money m5 {"SEK",10};
    Money m6 {"FFR", 100, 50};
    Money m7 {m6};
    Money m8 {m1};
    Money m9 {"SEK", 99, 99};

    //Test av direktinitiering:
    /*
    cout << m1 << endl << m2 << endl << m3 << endl << m4 << endl;
    cout << m5 << endl << m6 << endl << m7 << endl << m8 << endl << m9 << endl;
    */
    
    //Test av print() och operator<<:
    /*        
        m5.print(cout); // Utskrift: SEK 10.00 (utan efterföljande ny rad)
        cout << m5 << endl; // Utskrift: SEK 10.00
        cout << m3 << endl; // Utskrift: 10.50
    */

    //Test av (kopierings)tilldelning (operator=):
    /*    
        cout << "Borde bli 'SEK 10.00': ";
        m4 = m5; // Okej, samma valuta
        cout << m4 << endl << endl;

        cout << "Borde bli 'SEK 10.50': ";
        m4 = m3; // Okej, m3 är av ospecificerad valuta (m4 behåller aktuell valutaenhet)
        cout << m4 << endl << endl;

        cout << "Borde bli 'FFR 100.50': ";
        m1 = m6; // Okej, m1, som var ospecificerad, erhåller FFR som valutaenhet, förutom beloppet
        cout << m1 << endl << endl;

        cout << "Borde bli ett felmeddelande: ";
        m4 = m6; // Fel, en specificerad valuta får ej ändras! (m4 är SEK, m6 är FFR)
        cout << m4 << endl << endl;

        cout << "Flera '=' på rad. Borde bli... 'SEK 10.50': ";
        m2 = m3 = m4;
        cout << m2 << endl << endl;
    */

    //Test av operator+:
    /*
    cout << "SEK 10.00: " <<  m4 + m5 << endl << m4 << " " << m5 << endl;
    cout << "SEK 0.00: " << m4 + m1 << endl << m4 << " " << m1 << endl;
    cout << "FFR 100.50: " << m1 + m6 << endl << m1 << " " << m6 << endl;
    cout << "Felmeddelande: " << m4 + m6 << endl << m4 << " " << m6 << endl;
    */
    
    //Test av jämförelser:
    /*   
    if(m4 < m5)
      {
	cout << "Rätt svar!" << endl;
      }
    else
      cout << "Fel svar!" << endl;

    if(m4 != m3)
      {
	cout << "Rätt svar!" << endl;
      }
    else
      {
	cout << "Fel svar!" << endl;
      }

    if(m4 <= m6)
      {
	cout << "Öhm...?" << endl;
      }
    else
      {
	cout << "Öhm...?" << endl;
      }
    */
    
    //Test av stegning ++:
    /*        
	      cout << "Borde bli 'FFR 100.51': " << ++m6 << endl;
	      cout << "Borde bli 'SEK 99.99': " << m9++ << endl << "Borde bli 'SEK 100.00': " << m9 << endl;
    */
    
    //Test av currency():
    /*
    string valuta{m4.get_currency()};
    cout << valuta << endl;
    */
    
    //Test av operator+=:
    /*    
      cout << "m4: " << m4 << " och m5: " << m5 << endl;
      m4 += m5;
      cout << "m4 efter +=: " << m4 << " och m5 efter +=: " << m5 << endl;
      
      cout << "m3: " << m3 << " och m5: " << m5 << endl;
      m3 += m5;
      cout << "m3 efter +=: " << m3 << " och m5 efter +=: " << m5 << endl;
    */
    
    //Test av stegning --:
    /*    
      cout << "Borde bli '10.49': " << --m3 << endl;
      cout << "Borde bli '100.00': " << m2-- << endl << "Borde bli '99.99': " << m2 << endl;
      cout << "Borde ge felmeddelande: " << --m1 << endl;
    */
    
    
    //Test av sammansatt tilldelning, operator-=:
    /*
    //Borde ge error::
    cout << "m4: " << m4 << " och m5: " << m5 << endl;
    m4 -= m5;
    */
    /*
    //Borde ge error::
    cout << "m6: " << m6 << " och m4: " << m4 << endl;
    m6 -= m4;
    cout << "m6 efter -=: " << m6 << " och m4: " << m4 << endl;
    */
    /*
    cout << "m6: " << m6 << " och m3: " << m3 << endl;
    m6 -= m3;
    cout << "m6 efter -=: " << m6 << " och m3: " << m3 << endl;
    */

    //Test av operator-:
    /*
    cout << "m3: " << m3 << " och m5: " << m5 << " m3-m5: " << m3 - m5 << endl;
    cout << "m3 efter op.: " << m3 << " och m5: " << m5 << endl << endl;
    */
    /*
    //Borde ge error:
    cout << "m3: " << m3 << " och m6: " << m6 << " m3-m6: " << m3 - m6 << endl;
    */
    /*    
    //Borde ger error:
    cout << "m6: " << m6 << " och m5: " << m5 << " m6-m5: " << m6 - m5 << endl;
    */





    return 0;
}

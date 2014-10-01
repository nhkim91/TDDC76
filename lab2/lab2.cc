#include <iostream>
#include <string>
#include <stdexcept>
#include "monetary.cc"

using namespace std;
using namespace monetary;

int main()
{
    Money m;
	Money m1;
    Money m2 {100};
    Money m3 {10, 50};
    Money m4 {"SEK"};
    Money m5 {"SEK",10};
    Money m6 {"FFR", 100, 50};
    Money m7 {m6};
    Money m8 {m1};
    Money m9 {"SEK", 99, 99};
	Money m10 {10, 50};
	Money m11 {"SEK", 10, 10};
	Money m12 {"FFR", 10};
	Money m13;

    cout << "Test av print() och operator<<:" << endl;
        m5.print(cout); // Utskrift: SEK 10.00 (utan efterf�ljande ny rad)
        cout << endl << m5 << endl; // Utskrift: SEK 10.00
        cout << m3 << endl << endl; // Utskrift: 10.50

    cout << "Test av (kopierings)tilldelning (operator=):" << endl;

        cout << "Borde bli 'SEK 10.00': ";
        m4 = m5; // Okej, samma valuta
        cout << m4 << endl ;

        cout << "Borde bli 'SEK 10.50': ";
        m4 = m3; // Okej, m3 �r av ospecificerad valuta (m4 beh�ller aktuell valutaenhet)
        cout << m4 << endl << endl;

        cout << "Borde bli 'FFR 100.50': ";
        m1 = m6; // Okej, m1, som var ospecificerad, erh�ller FFR som valutaenhet, f�rutom beloppet
        cout << m1 << endl;

		try
        {
			m4 = m6; // Fel, en specificerad valuta f�r ej �ndras! (m4 �r SEK, m6 �r FFR)
		}
		catch (const monetary_error& e)
		{
			cout<< e.what() << endl << endl;
		}

    cout << "Test av operator+:" << endl;

    cout  <<  m4 << " + " << m5 << " = " << m4+m5 << endl;
    cout  <<  m4 << " + " << m10 << " = " << m4+m10 << endl;

	try
	{
	 m4 + m6;
	}
	catch(const monetary_error& e)
	{
		cout<< e.what() << endl << endl;
	}

    cout << "Test av j�mf�relser:" << endl;

	cout  <<  m4 << " < " << m5 << " -> ";
    if(m4 < m5)
      {
	cout << "true" << endl;
      }
    else
      cout << "False" << endl;

	cout  <<  m4 << " != " << m3 << " -> ";
    if(m4 != m3)
      {
	cout << "True" << endl;
      }
    else
      {
	cout << "False" << endl;
      }

    try
	{
		m4 <= m6;
    }
	catch(const monetary_error& e)
	{
		cout<< e.what() << endl << endl;
	}

    cout << "Test av stegning ++" << endl;

	cout << "m6 �r: " << m6 << ", ++m6 ger: " << ++m6 << endl;
	cout << "m9 �r: " << m9 << ", m9++ ger: " << m9++
		<< ". Efter�t �r m9: " << m9 << endl << endl;

    cout<< "Test av currency()" <<endl;

    string valuta{m4.get_currency()};
    cout << "m4 har valutan: " << valuta << endl << endl;

	cout << "Test av operator+=" << endl;

      cout << "m4: " << m4 << " och m5: " << m5 << endl;
      m4 += m5;
      cout << "m4 efter +=: " << m4 << " och m5 efter +=: " << m5 << endl;

      cout << "m3: " << m3 << " och m5: " << m5 << endl;
      m3 += m5;
      cout << "m3 efter +=: " << m3 << " och m5 efter +=: " << m5 << endl;

	  try
	  {
		m11+=m12;
	  }
	  catch(const monetary_error& e)
	{
		cout<< e.what() << endl << endl;
	}

    cout << "Test av stegning --" << endl;

	cout << "m6 �r: " << m6 << ", --m6 ger: " << --m6 << endl;
	cout << "m9 �r: " << m9 << ", m9-- ger: " << m9--
		<< ". Efter�t �r m9: " << m9 << endl << endl;

    cout << "Test av sammansatt tilldelning, operator-=" << endl;

    try
	{
		m13 -= m5;
	}
	catch(const monetary_error& e)
	{
		cout<< e.what() << endl << endl;
	}


    cout << "m3: " << m3 << " och m5: " << m5 << endl;
    m3 -= m5;
    cout << "m3 efter -=: " << m3 << " och m5: " << m5 << endl << endl;

	cout << "Test av operator-" << endl;

    cout << "m3: " << m3 << " och m5: " << m5 << " m3-m5: " << m3 - m5 << endl;

   try
	{
		m3 - m6;
	}
		catch(const monetary_error& e)
	{
		cout<< e.what() << endl << endl;
	}

	cout << "Test operator>>" << endl;
	try
	{
		cin >> m;
	}
	catch(const monetary_error& e)
	{
		cout<< e.what() << endl << endl;
	}

	cout << m << endl;

    return 0;
}



#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include "monetary.h"

using namespace std;

namespace monetary
{
	/*Hjälpfunktion som kollar, om valutan har tre bokstäver eller tom.
	 *Kollar om enhetsvärdet är mindre än noll
	 *Kollar om hundradelsvärdet är mindre än noll eller större än 99
	 */
	void Money::check(const string& c, const int u, const int h)
	{
		if(!(c == "" || c.size() == 3))
		{
			throw monetary_error{"Can't create money if currency doesn't have 3 characters e.g SEK!"};
		}
		else if( u < 0 || h < 0)
		{
			throw monetary_error{"You can't create money with a negative value!"};
		}
		else if(h > 99)
		{
			throw monetary_error{"Cent must be less then 100!"};
		}

		currency = c;
		unit = u;
		h_unit = h;
	}

	// Initiering
    Money::Money(const int u, const int h)
    {
        check("",u ,h);
    }

    Money::Money(const string& c, const int u, const int h)
    {
        check(c, u, h);
    }

    // Hjälpfunktion: Swap
    void Money::swap(Money& rhs) noexcept
    {
        std::swap(currency, rhs.currency);
        std::swap(unit, rhs.unit);
        std::swap(h_unit, rhs.h_unit);
    }

    //Kopieringskonstruktor
    Money::Money(const Money &m): currency(m.currency), unit(m.unit), h_unit(m.h_unit){}

    //Flyttkonstruktor
    Money::Money(Money&& m) noexcept
    {
        swap(m);
    }

    //Kopieringstilldelning
	//Denna funktion gör nästan samma sak som flytt-tilldelning varpå vi inte har med den. 
    Money& Money::operator=(const Money& rhs) &
    {
        if(currency == "" || currency == rhs.currency)
        {
            currency = rhs.currency;
            unit = rhs.unit;
            h_unit = rhs.h_unit;
        }
        else if(rhs.currency == "")
        {
            unit = rhs.unit;
            h_unit = rhs.h_unit;
        }
        else
        {
            throw monetary_error{"Different currency!"};
        }
        return *this;
    }

	//Sammansatt tilldelning
	// operator+=
    Money& Money::operator+=(const Money& rhs)
    {
        if(!(currency == "" || currency == rhs.currency || rhs.currency == ""))
        {
            throw monetary_error {"Different currency!"};
            // return *this;
        }
        else if(currency == "")
        {
            currency = rhs.currency;
        }
        unit = unit + rhs.unit;
        h_unit = h_unit + rhs.h_unit;

        if(h_unit > 99)
        {
            unit++;
            h_unit = h_unit - 100;
        }
        return *this;
    }

	//operator-=
    Money& Money::operator-=(const Money& rhs)
    {
        if(!(currency == "" || currency == rhs.currency || rhs.currency == ""))
        {
            throw monetary_error {"Different currency!"};
        }
        else if(currency == "")
        {
            currency == rhs.currency;
        }
        unit = unit - rhs.unit;
        h_unit = h_unit - rhs.h_unit;

        if(h_unit < 0)
        {
            unit--;
            h_unit = h_unit + 100;
        }
        if(unit < 0)
        {
            throw monetary_error {"Can't operate to a value less than zero!"};
        }
        return *this;
    }

    //operator+
    Money operator+(const Money& lhs, const Money& rhs)
    {
        return Money {lhs}.operator+=(rhs);
    }

	//operator-
    Money operator-(const Money &lhs, const Money &rhs)
    {
        return Money {lhs}.operator-=(rhs);
    }

    //Jämförelser
    //operator==
    bool Money::operator==(const Money& rhs) const
    {
        if(currency == "" || rhs.currency == "" || currency == rhs.currency)
        {
            if(unit == rhs.unit && h_unit == rhs.h_unit)
            {
                return true;
            }
            return false;
        }
        throw monetary_error {"Different currency!"};
    }

    //operator<
    bool Money::operator<(const Money& rhs) const
    {
        if(currency == "" || rhs.currency == "" || currency == rhs.currency)
        {
            if(unit < rhs.unit || (unit == rhs.unit && h_unit < rhs.h_unit))
            {
                return true;
            }
            return false;
        }
        throw monetary_error {"Different currency!"};
    }

    //In- och utmatning
    //print()
    ostream& Money::print(ostream& os) const
    {
        if(h_unit < 10)
        {
            return os << currency << " " << unit << ".0" << h_unit;
        }
        return os << currency << " " << unit << "." << h_unit;
    }

    //operator<<
    ostream& operator<<(ostream& os, const Money& rhs)
    {
        return rhs.print(os);
    }

	// Hjälpfunktion: tar bort alla vita tecken
	void ignore_space(istream& is)
	{
		char c = is.peek();

		//while(c = is.peek() && isspace(c) && c != 10 && c != 13)
		while(c == ' ' || c == '\t')
		{
			is.ignore(1);
			c = is.peek();
		}
	}

	bool newline(std::istream& is)
	{
		char c = is.peek();
		return (c == '\n' || c == '\r');
	}
	
	//operator>>
	std::istream& operator>>(std::istream& is, Money& m)
	{
		char c;
		string new_currency{""};
		int new_unit{0};
		int new_h_unit{0};

		while(is.good())
		{
			ignore_space(is);

			c = is.peek();
			
			while(isalpha(c))
			{
				new_currency += toupper(c); // Sätter in bokstäver sist i stringen
				is.ignore(1);
				c = is.peek();
			}

			c = is.peek();
			
			if(c != ' ' && !new_currency.empty()) // fortsätter om det är ett mellanrum, annars avslutas programmet.
			{	
				break;
			}
			else
			{
				ignore_space(is);
			}

			{	c = is.peek();
			
				while(isdigit(c)) // kör så länge det är en siffra
				{
					new_unit = new_unit * 10 + c - 48; // -48 konventerar från ascci till decimal
					is.ignore(1);
					c = is.peek();
				}
			}
			
			c = is.peek();
			
			if(c == '.')
			{
				is.ignore (1);

				c = is.peek();
				
				if(isdigit(c))	// kör så länge det är en siffra
				{
					for(int i = 0; i < 2; ++i) // Ser till att det bara är två decimaler
					{
						new_h_unit = new_h_unit * 10 + c -48; // -48 konventerar från ascci till decimal
						is.ignore(1);
						c = is.peek();
						if(!isdigit(c))
						{
							new_h_unit = 0;
						}
					}
				}
			}
			else
			{
				break;
			}
			break;
		}
		m.check(new_currency, new_unit, new_h_unit); // Ser till att det är 3 bokstäver 

		return is;
	}

    //Stegning ++
    //++m
    Money& Money::operator++()
    {
        ++h_unit;

        if(h_unit > 99)
        {
            ++unit;
            h_unit = h_unit - 100;
        }
        return *this;
    }

    //m++
    Money Money::operator++(int)
    {
        Money temp = *this;
        operator++();
        return temp;
    }

	//--m
    Money& Money::operator--()
    {
        --h_unit;

        if(h_unit < 0)
        {
            --unit;
            h_unit = h_unit + 100;
            if(unit < 0)
            {
                throw monetary_error {"Can't operate to a value less than zero!"};
            }
        }
        return *this;
    }

    //m--
    Money Money::operator--(int)
    {
        Money temp = *this;
        operator--();
        return temp;
    }

    //Labbeskrivningens currency(), som vi namngett get_currency p.g.a. att vi använder 'currency' som variabel. Tar fram 'currency'.
    string Money::get_currency() const
    {
        return currency;
    }
} //namespace monetary


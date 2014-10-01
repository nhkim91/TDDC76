#include <iostream>
#include <string>
#include <stdexcept>
#include "monetary.h"

using namespace std;

namespace monetary
{
  void Money::swap(Money &rhs) noexcept
  {
    std::swap(currency, rhs.currency);
    std::swap(unit, rhs.unit);
    std::swap(h_unit, rhs.h_unit);
  }


  //Kopieringskonstruktor
  Money::Money(const Money &m):
    currency(m.currency),
    unit(m.unit),
    h_unit(m.h_unit)
  {}

  //Flyttkonstruktor
  Money::Money(Money &&m) noexcept
  {
    swap(m);
  }

  //Kopieringstilldelning
  Money& Money::operator=(const Money &rhs) &
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

  //Flytt-tilldelning kanske ska vara som kopieringstilldelningen?:
  Money& Money::operator=(Money &&rhs) &
  {
    if(currency == "" || currency == rhs.currency)
      {
	swap(rhs);
      }
    else if(rhs.currency == "")
      {
	std::swap(unit, rhs.unit);
	std::swap(h_unit, rhs.h_unit);
      }
    else
      {
	throw monetary_error{"Different currency!"};
      }
    return *this;
  }

  //Flytt-tilldelning - Vad ska den göra och när ska detta ske? std::move(m2)
  /*
  Money& Money::operator=(Money &&rhs)
  {
    swap(rhs);
    return *this;
  }
  */

  //Sammansättning
  //operator+= (I t.ex. m1 + m4 får m1 summan.)
  Money& Money::operator+=(const Money &rhs)
  {
    if(!(currency == "" || currency == rhs.currency || rhs.currency == ""))
      {
	throw monetary_error{"Different currency!"};
	// return *this;
      }
    else if(currency == "") // Behöver inte ha andra statement:et.
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

  //operator+
  Money operator+(const Money &lhs, const Money &rhs)
  {
    return Money{lhs}.operator+=(rhs);
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
    throw monetary_error{"Different currency!"};
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
    throw monetary_error{"Different currency!"};
  }

  //Utmatning
  //print()
  ostream& Money::print(ostream &os) const
  {
    if(h_unit < 10)
      {
	return os << currency << " " << unit << ".0" << h_unit;
      }
    return os << currency << " " << unit << "." << h_unit;
  }

  //operator<<
  ostream& operator<<(ostream &os, const Money &rhs)
  {
    return rhs.print(os);
  }

  //Stegning ++
  //++m
  Money& Money::operator++()
    {
      ++h_unit; //Måste ha plustecknen före.
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
    //++*this; Borde göra samma sak som den undre, förutom att jag inte är helt säker på vad i *this som den räknar upp, och dessutom kollar den nog inte om h_unit blir större än 99 etc.
    operator++();
    return temp;
  }

  //Labbeskrivningens currency(), som vi namngett get_currency p.g.a. att vi använder 'currency' som variabel. Tar fram 'currency'.
  string Money::get_currency() const
  {
    return currency;
  }

  /////////////////////////////////////////////////////////////
  //VG-delen

  //Sammansatt tilldelning, operator+=, används av operator+ (hittas därför ovan)

  //Stegning --
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
	    throw monetary_error{"Can't operate to a value less than zero!"};
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

  //Sammansatt tilldelning, operator-=
  Money& Money::operator-=(const Money &rhs)
  {
    if(!(currency == "" || currency == rhs.currency || rhs.currency == ""))
      {
	throw monetary_error{"Different currency!"};
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
	throw monetary_error{"Can't operate to a value less than zero!"};
      }
    return *this;
  }

  //operator-
  Money operator-(const Money &lhs, const Money &rhs)
  {
    return Money{lhs}.operator-=(rhs);
  }

} //namespace monetary

#include "monetary.h"
#include <string>
#include <ostream>
#include <iomanip>

namespace monetary
{
    // Kopierings-konstruktor
    money::money(const money& other)
    {
        currency = other.currency;
        unit = other.unit;
        h_unit = other.h_unit;
    }

    void money::swap(money& rhs) noexcept
    {
        std::swap(currency,rhs.currency);
        std::swap(unit, rhs.unit);
        std::swap(h_unit, rhs.h_unit);
    }

    // Flytt-konstruktor
    money::money(money&& m) noexcept
    {
        swap(m);
    }


//Kopieringstilldelning
	money& money::operator = (const money& rhs) &
	{
		if(currency == "" || currency == rhs.currency)
		{
			currency = rhs.currency;
			unit = rhs.unit;
			h_unit = rhs.unit;
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

	//Flyttilldelning
	money& money::operator = (money&& rhs) & noexcept
	{
		swap(rhs);
		return *this;
	}

	//Sammansättning +
	money money::operator+(const money& rhs)
	{
		if(!(currency == "" || currency == rhs.currency || rhs.currency == ""))
		{
			throw monetary_error{"You can't add two different currency!"};
			return *this;
		}
		else if(currency == "" || currency == rhs.currency) // Kollar om man behöver ändra currency
		{
			currency = rhs.currency;
		}
		unit = unit + rhs.unit;
		h_unit = h_unit + rhs.h_unit;
		if (h_unit > 99)
		{
			unit++;
			h_unit = h_unit - 100;
		}
		return *this;
	}

	//Stegning 
	//++m
	money& operator++()
	{
		h_unit = hunit++;
		if (h_unit >99)
		{
			unit++;
			h_unit = h_unit -100
		}
		return *this;
	}

	//m++
	money operator++(int)
	{
		money temp = *this;
		++*this;
		operator++();
		return temp;	
	}	

	// Jämförelse
	//Lika med
	bool money::operator == (const money& rhs) const
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

	// Mindre än
	bool money::operator < (const money& rhs) const
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
	// Med print
	std::ostream& money::print(std::ostream& os) const
	{
		if(h_unit <10)
		{
			os << currency << " " << unit << ".0" << h_unit << std::endl;
		}
		else
		{
			os << currency << " " << unit << "." << h_unit << std::endl;
		}	
    
		return os;
	}

	//Med operator<<
	std::ostream& operator<< (std::ostream& os, const monetary::money& rhs)
		{
			return rhs.print(os);
		}	
}


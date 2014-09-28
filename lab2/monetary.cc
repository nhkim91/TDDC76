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
    if(currency == "" || currency == rhs.currency)
    {
        currency = rhs.currency;
        unit = unit + rhs.unit;
        h_unit = h_unit + rhs.h_unit;
    }
    else if(rhs.currency == "")
    {
        unit = unit + rhs.unit;
        h_unit = h_unit + rhs.h_unit;
    }
    else
    {
        throw monetary_error{"You can't add two different currency!"};
    }
    return *this;
}

//Utmatning
std::ostream& money::print(std::ostream& os) const
{
    double value;
    value = unit + h_unit/100; // sätter ihop hundradelar med heltalet. ex 100.00

    os << std::setprecision(2) << std::fixed << currency << " " << value << std::endl;
    return os;
}

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

}

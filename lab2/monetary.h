#ifndef MONETARY_H
#define MONETARY_H

#include <iostream>
#include <string>
#include <stdexcept>

namespace monetary
{
//Undantagsklass
class monetary_error: public std::logic_error
{
public:
    explicit monetary_error(const std::string& what_arg) noexcept
: std::logic_error(what_arg) {}

    explicit monetary_error(const char* what_arg) noexcept
: std::logic_error(what_arg) {}
};

class Money
{
private:
    std::string currency {""};
    int unit {0};
    int h_unit {0};

    void swap(Money&) noexcept;
    void check(const std::string&, const int, const int); //Kollar att allt står rätt till, ex Att currency har tre bokstäver
    void ignore_space(std::istream&); // Tar bort vita tecken

public:
    //Default-konstruktor
    Money() = default;
    Money(const int u, const int h = 0);
    Money(const std::string &c, const int u = 0, const int h = 0);

    //Kopieringskonstruktor.
    Money(const Money&) = default;

    //Flyttkonstruktor.
    Money(Money&&) noexcept = default;

    //Destruktor.
    ~Money() = default;

    //Kopieringstilldelning.
    Money& operator=(const Money&) &;

    //Flytt-tilldelning.
    Money& operator=(Money &&) &;

    //Jämförelser
    bool operator==(const Money&) const;
    bool operator!=(const Money &rhs) const
    {
        return !(*this == rhs);
    }
    bool operator<(const Money&) const;
    bool operator>(const Money &rhs) const
    {
        return !(*this < rhs || *this == rhs);
    }
    bool operator<=(const Money &rhs) const
    {
        return (*this < rhs || *this == rhs);
    }
    bool operator>=(const Money &rhs) const
    {
        return !(*this < rhs);
    }

    //In- och utmatning
    std::ostream& print(std::ostream&) const;
    friend std::istream& operator>>(std::istream&, Money&);

    //Sammansatt tilldelning
    Money& operator-=(const Money&);
    Money& operator+=(const Money&);

    //Stegning ++
    Money& operator++(); //++m
    Money operator++(int); //m++

    //currency(), fast vår heter get_currency() eftersom vår variabel heter 'currency'.
    std::string get_currency() const;

    //Stegning --
    Money& operator--(); //--m
    Money operator--(int); //m--

};

//operator+
Money operator+(const Money&, const Money&);

//operator-
Money operator-(const Money&, const Money&);

//Utmatning
std::ostream& operator<<(std::ostream&, const Money&);
} //namespace monetary

#endif

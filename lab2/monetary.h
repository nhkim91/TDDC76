#ifndef MONETARY_H
#define MONETARY_H
#include <string>
#include <ostream>

using namespace std;

namespace monetary
{


    class money
    {
    public:

        //Konstruktur och destruktor
        money() = default; // default-konstruktor
        money(const money&); // kopierings-konstruktor
        money(money&&) noexcept; // flytt-konstruktor
        money(const string &c = nullptr, const int u = 0, const int h_u = 0): currency(c), unit(u), h_unit(h_u) {} // typ-konstruktor
        ~money() = default; //destruktor

        //Tildelning
        money& operator = (const money&) &;
        money& operator = (money&&) & noexcept;


        //Utmatning
        //std::ostream& operator << (std::ostream&, const money&);

    private:

        string currency;
        int unit, h_unit;


    };

void swap(money&, money&) noexcept;

void copy(money&);

} //namespace monetary

#endif




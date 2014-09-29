#ifndef MONETARY_H
#define MONETARY_H

#include <string>
#include <ostream>
#include <stdexcept>

namespace monetary
{
    class monetary_error : public std::logic_error
    {
    public:
        explicit monetary_error(const std::string& what_arg) noexcept :
            std::logic_error {what_arg} {}

        explicit monetary_error(const char* what_arg) noexcept :
            std::logic_error {what_arg} {}
    };

    class money
    {
    public:
        //Konstruktur och destruktor
        money() = default; // default-konstruktor
        money(const money&); // kopierings-konstruktor
        money(money&&) noexcept; // flytt-konstruktor
        money(const std::string &c = nullptr, const int u = 0, const int h_u = 0): currency(c), unit(u), h_unit(h_u) {} // typ-konstruktor
        ~money() = default; //destruktor

        //Tildelning
        money& operator = (const money&) &; //kopieringstilldelning
        money& operator = (money&&) & noexcept; //flyttilldelning

        //Sammansättning +
        money operator+ (const money&);
		
		//Stegning 
		money& operator++(); //++m
		money operator++(int); //m++	

        //jämförelser
        bool operator == (const money&) const;
        bool operator != (const money& rhs) const {return !(*this == rhs);}
        bool operator < (const money&) const;
        bool operator > (const money& rhs) const {return (*this > rhs);}
        bool operator <= (const money& rhs) const {return !(*this > rhs);}
        bool operator >= (const money& rhs) const {return !(*this < rhs);}


        //Utmatning
        std::ostream& print(std::ostream&) const;
		//friend std::ostream& operator<< (std::ostream& os, const monetary::money& rhs);

    private:

        std::string currency;
        int unit, h_unit;

        // Interna hjälpfunktioner
        void swap(money&) noexcept;
		
    };
	
	std::ostream& operator<< (std::ostream& os, const monetary::money& rhs);
	

} //namespace monetary
#endif




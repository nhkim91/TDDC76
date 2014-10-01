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
      : std::logic_error(what_arg){}

    explicit monetary_error(const char* what_arg) noexcept
      : std::logic_error(what_arg){}
  };


  class Money
  {
  private:
    std::string currency {""};
    int unit{0};
    int h_unit{0};

    void swap(Money&) noexcept;

  public:
    //Default-konstruktor
    //Jag läste i labbeskrivningen att vi kanske ska ha med ifall u eller h anges negativt: felmeddelande. Eventuellt här eller när man tar in dessa från en inström.
    Money() = default;
  Money(const int u, const int h=0): unit {u}, h_unit {h} {}
  Money(const std::string &c, const int u=0, const int h=0): currency {c}, unit {u}, h_unit {h} {}

    //Kopieringskonstruktor.
    Money(const Money&);

    //Flyttkonstruktor.
    Money(Money&&) noexcept;

    //Destruktor.
    ~Money() = default;

    //Kopieringstilldelning.
    Money& operator=(const Money&) &;

    //Flytt-tilldelning.
    Money& operator=(Money&&) &;

    //Jämförelser
    //Vi definierade ju inte >, men använde det, så jag ändrade.
    bool operator==(const Money&) const;
    bool operator!=(const Money &rhs) const {return !(*this == rhs);}
    bool operator<(const Money&) const;
    bool operator>(const Money &rhs) const {return !(*this < rhs);}
    bool operator<=(const Money &rhs) const {return (*this < rhs || *this == rhs);}
    bool operator>=(const Money &rhs) const {return !(*this < rhs);}

    //print()
    std::ostream& print(std::ostream&) const;

    //Hjälpfunktion till operator+ i klassen, eftersom det första värdet annars antar summan, vilket jag antar att det inte ska... MEN! I VG-delen ska vi ha en sådan funktion.
    Money& operator+=(const Money&);

    //Stegning ++
    Money& operator++(); //++m
    Money operator++(int); //m++

    //currency(), fast jag namngav den get_currency() eftersom vår variabel heter 'currency'.
    std::string get_currency() const;

    //////////////////////////////////////////////////////////////
    //VG-delen

    //Sammansatt tilldelning
    //operator+= använde vi som hjälpfunktion till operator+ och hittas därför ovan.
    Money& operator-=(const Money&);

    //Stegning --
    Money& operator--(); //--m
    Money operator--(int); //m--



  };

  //operator+ (Kan ligga utanför klassen eftersom den anropar hjälpfunktionen operator+=() inuti klassen.
  Money operator+(const Money&, const Money&);

  //operator<< (Kan ligga utanför klassen eftersom den anropar print() inuti.)
  std::ostream& operator<<(std::ostream&, const Money&);

  //operator-
  Money operator-(const Money&, const Money&);

} //namespace monetary

#endif

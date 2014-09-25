

class money
{
public:

    //Konstruktur och destruktor
    money() = default;
    //money(const money&);
    //oney(moneey&&) noexcept;
    ~money()

    //Tildelning
    //money& operator = (const money&) &;
    //money& operator = (money&&) & noexecpt;

private:

    //Utmatning
    //std::ostream& operator << (std::ostream&, const money&);


    void swap(money& value);
}



#endif // MONETARY_H


/*
 * expression-test.cc
 */
#include "Expression.h"
#include "Expression_Tree.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    Expression e1;  // defaultkonstruktor

    Expression_Tree* a{new Integer{9}};
    Expression_Tree* b{new Real{5.5}};
    Expression_Tree* c{new Real{2}};
    Expression_Tree* d{new Integer{2}};
    Expression_Tree* x{new Variable{"x"}};
    Expression_Tree* y{new Variable{"y"}};

    Expression_Tree* t1{ new Assign{x, new Plus{ new Minus{a, b}, new Power{c, d}}}};
    Expression_Tree* t2{ new Assign{y, new Times{ new Divide{a, c}, b}}};

    Expression e2(t1);
    Expression e3(t2);

    cout << "e2: " << e2.evaluate() << endl;
    cout << "e3: " << e3.evaluate() << endl;

    /*
    cout << e2.get_postfix() << endl;
    */

    //Testar Expression::empty() för e1 och e2.
    /*
    if(e1.empty())
        cout << "e1 är tom!" << endl;
    else
        cout << "e1 innehåller ett träd!" << endl;

    if(e2.empty())
        cout << "e2 är tom!" << endl;
    else
        cout << "e2 innehåller ett träd!" << endl;
    */

    //Testar Expression::print_tree() för e2.
    /*
    cout << "e1:" << endl;
    e1.print_tree(cout);
    cout << endl << endl << "e2:" << endl;
    e2.print_tree(cout);
    cout << endl << endl;
    */

    //Testar Expression::swap() för e2 och e3.
    /*
    e2.swap(e3);
    cout << "e2: " << e2.evaluate() << endl;
    e2.print_tree(cout);
    cout << endl << endl << "e3: " << e3.evaluate() << endl;
    e3.print_tree(cout);
    cout << endl;
    */

    //Test av swap().
    /*
    swap(e2, e3);
    cout << "e2: " << e2.evaluate() << endl << "e3: " << e3.evaluate() << endl;
    */















    /*
    if (e1.empty())
        cout << "Tomt uttryck!\n";
    else
        cout << "e1.evaluate() = " << e1.evaluate() << '\n';

    cout << "e1.get_postfix() = " << e1.get_postfix() << '\n';
    cout << boolalpha << "e1.empty() = " << e1.empty() << "\n\n";

    Expression e2{e1};  // kopieringskonstruktor

    try
    {
        cout << "e2.evaluate() = " << e2.evaluate() << '\n';
    }
    catch (const exception& e)
    {
        cout << "undantag fångat: " << e.what() << '\n';
    }

    cout << "e2.get_postfix() = " << e2.get_postfix() << '\n';
    cout << "e2.empty() = " << e2.empty() << "\n\n";

    e2.swap(e1);  // swap

    // Resten kräver implementering av Expression_Tree-klasserna.


    Expression_Tree* t{new Plus{new Integer{7}, new Real{3.14}}};

    Expression e3{t};  // konstruktor som tar ett länkat uttrycksträd

    cout << "e3.evaluate() = " << e3.evaluate() << '\n';
    cout << "e3.get_postfix() = " << e3.get_postfix() << '\n';
    cout << "e3.empty() = " << e3.empty() << "\n\n";

    e2.swap(e3);  // swap

    cout << "e2.evaluate() = " << e2.evaluate() << '\n';
    cout << "e2.get_postfix() = " << e2.get_postfix() << '\n';
    cout << "e2.empty() = " << e2.empty() << "\n\n";

    Expression e4{e2};  // kopieringskonstruktor

    try
    {
        cout << "e4.evaluate() = " << e4.evaluate() << '\n';
    }
    catch (const exception& e)
    {
        cout << "Undantag fångat: " << e.what() << '\n';
    }
    cout << "e4.get_postfix() = " << e4.get_postfix() << '\n';
    cout << "e4.empty() = " << e4.empty() << "\n\n";

    Expression e5{std::move(e2)};  // move-konstruktor

    cout << "e5.evaluate() = " << e5.evaluate() << '\n';
    cout << "e5.get_postfix() = " << e5.get_postfix() << '\n';
    cout << "e5.empty() = " << e5.empty() << '\n';
    cout << "e2.empty() = " << e2.empty() << "\n\n";

    e2 = std::move(e5);  // move-tilldelning

    cout << "e2.evaluate() = " << e2.evaluate() << '\n';
    cout << "e2.get_postfix() = " << e2.get_postfix() << '\n';
    cout << "e2.empty() = " << e2.empty() << '\n';
    cout << "e5.empty() = " << e5.empty() << "\n\n";

    */

    return 0;
}

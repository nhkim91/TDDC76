/*
 * expression_tree-test.cc
 */
#include "Expression_Tree.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    // Ska inte vara möjligt - Expression_Tree ska vara abstrakt:
    // Expression_Tree* t0{new Expression_Tree};
    //Variable* var = new Variable("x");


    Expression_Tree* t1 {new Plus{ new Integer{7}, new Real{3.14} } };
    //Expression_Tree* t3{new Assign{var->str(), new Plus{t1, new Real{1} } } };
    //t3->print(cout);

    Expression_Tree* seven_p = new Integer {7};
    Expression_Tree* x = new Variable {"x"};
    Expression_Tree* eq = new Assign(x, seven_p);

    //cout << "TEST Variable/Assign: "
         //<< var->str() << " " << var->get_value() << endl;


    //cout << "=" << t1->evaluate();
    cout << endl;
    try

    {
        cout << "t1->evaluate() = " << t1->evaluate() << '\n';
    }
    catch (const exception& e)
    {
        cout << "Undantag fångat: " << e.what() << '\n';
    }

    cout << "t1->get_postfix() = " << t1->get_postfix() << '\n';
    cout << "t1->str() = " << t1->str() << "\n\n";

    Expression_Tree* t2 { t1->clone() };

    try
    {
        cout << "t2->evaluate() = " << t2->evaluate() << '\n';
    }
    catch (const exception& e)
    {
        cout << "Undantag fångat: " << e.what() << '\n';
    }
    cout << "t2->get_postfix() = " << t2->get_postfix() << '\n';
    cout << "t2->str() = " << t2->str() << "\n\n";



    return 0;
}

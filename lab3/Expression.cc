/*
 * Expression.cc
 */
#include "Expression.h"
#include "Expression_Tree.h"
#include "Variable_Table.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

//Default-konstruktor
Expression::Expression(class Expression_Tree* tree)
    : first_node{tree}
{
    //delete first_node;
    //first_node = tree;
}

//Expression::Expression(std::string infix, Variable_Table* vt)
//{
//    first_node = make_expression_tree(infix, vt);
//}

//Destruktor
/*Expression::~Expression()
{
    if (first_node != nullptr)
    {
        delete first_node;
        first_node = nullptr;
    }
    else
    {
        throw
    }
}
*/

//Kopieringskonstruktor, flyttkonstruktor
Expression::Expression(const Expression &e)
{
    if(e.empty())
        throw expression_error{"The Expression-object doesn't have an Expression_Tree-object!"};
    else
    {
        first_node = e.first_node->clone();
    }
}


Expression::Expression(Expression&& e) noexcept
{
    swap(e);
}


//Kopieringstilldelning, flytt-tilldelning
Expression& Expression::operator=(const Expression &rhs) &
{
    delete first_node;
    first_node = rhs.first_node->clone();
    return *this;
}

Expression& Expression::operator=(Expression&& rhs) &
{
    delete first_node;
    first_node = nullptr;
    swap(rhs);
    return *this;
}

/*
 * evaluate()
 */
long double Expression::evaluate() const
{
    if(empty())
    {
        throw expression_error{"The Expression-object doesn't have an Expression_Tree-object!"};
    }
    else
        return first_node->evaluate();
}

/*
 * get_postfix()
 */
std::string Expression::get_postfix() const
{
    if(first_node == nullptr)
    {
        return "";
    }
    else
        return first_node->get_postfix();
}

/*
 * empty()
 */
bool Expression::empty() const
{
    if(first_node == nullptr)
    {
        return true;
    }
    else
        return false;
}

/*
 * print_tree()
 */
//Ska vi ha med något om first_node == nullptr? Felhantering?
void Expression::print_tree(std::ostream &os) const
{
    if(first_node == nullptr)
    {
        return;
    }
    else
        first_node->print(os);
}

/*
 * swap(other)
 */
void Expression::swap(Expression &rhs)
{
    std::swap(first_node, rhs.first_node);
}

/*
 * swap(x, y)
 */
void swap(Expression &lhs, Expression &rhs)
{
    lhs.swap(rhs);
}

/*
 * make_expression() definieras efter namnrymden nedan.
 */
//Expression make_expression(const string& infix, Variable_Table* v_table);

// Namrymden nedan innehåller intern kod för infix-till-postfix-omvandling
// och generering av uttrycksträd. En anonym namnrymd begränsar användningen
// av medlemmarna till denna fil.
namespace
{
using std::vector;
using std::map;
using std::make_pair;
using std::string;

// Teckenuppsättningar för operander. Används av make_expression_tree().
const string letters{"abcdefghijklmnopqrstuvwxyz"};
const string digits{"0123456789"};
const string integer_chars{digits};
const string real_chars{digits + '.'};
const string variable_chars{letters};
const string operand_chars{letters + digits + '.'};

// Tillåtna operatorer. Används av make_postfix() och make_expression_tree().
// Prioritetstabeller, en för inkommandeprioritet och en för stackprioritet.
// Högre värde inom input_prio respektive stack_prio anger inbördes prioritetsordning.
// Högre värde i input_prio jämfört med motsvarande position i stack_prio innebär
// högerassociativitet, det motsatta vänsterassociativitet. Används av make_postfix().
using priority_table = map<string, int>;

const vector<string> operators{ "^", "*", "/", "+", "-", "=" };
const priority_table input_priority{ {"^", 8}, {"*", 5}, {"/", 5}, {"+", 3}, {"-", 3}, {"=", 2} };
const priority_table stack_priority{ {"^", 7}, {"*", 6}, {"/", 6}, {"+", 4}, {"-", 4}, {"=", 1} };

// Hjälpfunktioner för att kategorisera lexikala element.
bool is_operator(char token)
{
    return find(begin(operators), end(operators), string{token}) != end(operators);
}

bool is_operator(const string& token)
{
    return find(begin(operators), end(operators), token) != end(operators);
}

bool is_operand(const string& token)
{
    return token.find_first_not_of(operand_chars) == string::npos;
}

bool is_integer(const string& token)
{
    return token.find_first_not_of(integer_chars) == string::npos;
}

bool is_real(const string& token)
{
    return token.find_first_not_of(real_chars) == string::npos;
}

bool is_identifier(const string& token)
{
    return token.find_first_not_of(letters) == string::npos;
}

// format_infix tar en sträng med ett infixuttryck och formaterar med ett
// mellanrum mellan varje symbol; underlättar vid bearbetningen i make_postfix.
std::string format_infix(const std::string& infix)
{
    auto bos = begin(infix);
    auto eos = end(infix);
    string formated;

    for (auto it = bos; it != eos; ++it)
    {
        if (is_operator(*it) || *it == '(' || *it == ')')
        {
            // Se till att det är ett mellanrum före en operator eller parentes
            if (it != bos && *(it - 1) != ' ' && *(formated.end() - 1) != ' ')
                formated.append(1, ' ');
            formated.append(1, *it);
            // Se till att det är ett mellanrum efter en operator eller parentes
            if ((it + 1) != eos && *(it + 1) != ' ')
                formated.append(1, ' ');
        }
        else
        {
            if (*it != ' ')
                formated.append(1, *it);
            else if (it != bos && *(it - 1) != ' ')
                formated.append(1, *it);
        }
    }
    return formated;
}

// make_postfix tar en infixsträng och returnerar motsvarande postfixsträng.
std::string make_postfix(const std::string& infix)
{
    using std::stack;
    using std::string;
    using std::istringstream;
    using std::find;

    stack<string> operator_stack;
    string        token;
    string        previous_token;
    bool          last_was_operand{false};
    bool          assignment{false};
    int           paren_count{0};

    istringstream is{format_infix(infix)};
    string        postfix;

    while (is >> token)
    {
        if (is_operator(token))
        {
            if (!last_was_operand || postfix.empty() || previous_token == "(")
            {
                throw expression_error{"Operator when an operand is expected!"};
            }

            if (token == "=")
            {
                if (assignment)
                {
                    throw expression_error{"Multiple assignment!"};
                }
                else
                {
                    assignment = true;
                }
            }

            while (!operator_stack.empty() && operator_stack.top() != "(" &&
                   input_priority.find(token)->second <=
                   stack_priority.find(operator_stack.top())->second)
            {
                postfix += operator_stack.top() + ' ';
                operator_stack.pop();
            }
            operator_stack.push(token);
            last_was_operand = false;
        }
        else if (token == "(")
        {
            operator_stack.push(token);
            ++paren_count;
        }
        else if (token == ")")
        {
            if (paren_count == 0)
            {
                throw expression_error{"Left parenthesis is missing!"};
            }

            if (previous_token == "(" && !postfix.empty())
            {
                throw expression_error{"Empty parenthesis!"};
            }

            while (!operator_stack.empty() && operator_stack.top() != "(")
            {
                postfix += operator_stack.top() + ' ';
                operator_stack.pop();
            }

            if (operator_stack.empty())
            {
                throw expression_error{"Right parenthesis misses left parenthesis!"};
            }
            // Det finns en vänsterparentes på stacken
            operator_stack.pop();
            --paren_count;
        }
        else if (is_operand(token))
        {
            if (last_was_operand || previous_token == ")")
            {
                throw expression_error{"Operand when an operator is expected!"};
            }

            postfix += token + ' ';
            last_was_operand = true;
        }
        else
        {
            throw expression_error{"Unallowable symbol!"};
        }

        previous_token = token;
    }

    if (postfix == "")
    {
        throw expression_error{"Empty infix-expression!"};
    }

    if (!last_was_operand && !postfix.empty())
    {
        throw expression_error{"Operator ends!"};
    }

    if (paren_count > 0)
    {
        throw expression_error{"Right parenthesis is missing!"};
    }

    while (!operator_stack.empty())
    {
        postfix += operator_stack.top() + ' ';
        operator_stack.pop();
    }

    if (!postfix.empty())
    {
        postfix.erase(postfix.size() - 1);
    }

    return postfix;
}

// make_expression_tree tar en postfixsträng och returnerar ett motsvarande
// länkat träd av Expression_Tree-noder.
Expression_Tree* make_expression_tree(const std::string& postfix, Variable_Table* v_table)
{
    using std::stack;
    using std::string;
    using std::istringstream;

    stack<Expression_Tree*> tree_stack;
    string                  token;
    istringstream           ps{postfix};

    while (ps >> token)
    {
        if (is_operator(token))
        {
            if (tree_stack.empty())
            {
                throw expression_error{"Wrong postfix!"};
            }
            Expression_Tree* rhs{tree_stack.top()};
            tree_stack.pop();

            if (tree_stack.empty())
            {
                throw expression_error{"Wrong postfix!"};
            }
            Expression_Tree* lhs{tree_stack.top()};
            tree_stack.pop();

            if (token == "^")
            {
                tree_stack.push(new Power{lhs, rhs});
            }
            else if (token == "*")
            {
                tree_stack.push(new Times{lhs, rhs});
            }
            else if (token == "/")
            {
                tree_stack.push(new Divide{lhs, rhs});
            }
            else if (token == "+")
            {
                tree_stack.push(new Plus{lhs, rhs});
            }
            else if (token == "-")
            {
                tree_stack.push(new Minus{lhs, rhs});
            }
            else if (token == "=")
            {
                tree_stack.push(new Assign{lhs, rhs});
            }
        }
        else if (is_integer(token))
        {
            tree_stack.push(new Integer{std::stol(token.c_str())});
        }
        else if (is_real(token))
        {
            tree_stack.push(new Real{std::stold(token.c_str())});
        }
        else if (is_identifier(token))
        {
            tree_stack.push(new Variable{token, std::stold(token.c_str()), v_table});
        }
        else
        {
            throw expression_error{"Wrong postfix!"};
        }
    }
    // Det ska bara finnas ett träd på stacken om korrekt postfix.

    if (tree_stack.empty())
    {
        throw expression_error{"No postfix is given!"};
    }

    if (tree_stack.size() > 1)
    {
        while (!tree_stack.empty())
        {
            delete tree_stack.top();
            tree_stack.pop();
        }
        throw expression_error{"Incorrect postfix!"};
    }

    // Returnera trädet.
    return tree_stack.top();
}
} // namespace

//Expression make_expression(const string& infix)
//{
//   return Expression{make_expression_tree(make_postfix(infix))};
//}

Expression make_expression(const string& infix, Variable_Table* v_table)
{
    return Expression{make_expression_tree(make_postfix(infix), v_table)};
}


#include <istream>
#include <ostream>
#include <string>

#ifndef _INC_LIST_GUARD_
#define _INC_LIST_GUARD_

using namespace std;

struct list_node
{
	string name;
	int age;
	list_node* next;
};

// kan man använda list iställer för List?
using list = list_node*;

void build_lists(istream& is, list list_1, list list_2); //Spelar det någon roll i vilken ordning roll?

void append(list& list_2, const string& name, int age);

void insert(list& list_1, const string& name, int age);

void clear(list& list_);

bool empty(const list& list_);

list copy(const list& list_);

void reverse(list& list_);

void print_reverse(const list& list_, ostream& os);

void swap(list& list_1, list& list_2);


#endif

#include "list.h"


//Spelar ordning roll?


void build_lists(istream& is, list list_1, list list_2)
{
	// hur tar man in saker från inströmmen?
}

void append(list& list_, const string& name, int age)
{
	auto p = new list_node{name, age, nullptr}; // typ list_node*
	if (list_ == nullptr) // tom lista
	{
		list_ = p;
		return;
	}	
}

void insert(list& list_, const string& name, int age)
{
	p = new list_node(name, age, nullptr); //typ list_node*
	if (list_ == nullptr)
	{
		list_ = p;
		return;
	}
	else
	{
		//p = new list(name, age, list_node)
		p->next = list_; // pekar på början av listan
		list_ = p;
	}
}

void clear(list& list_)
{
	delete[] list_; //tar bort alla noder
	list_ = nullptr; 
}

bool empty(const list& list_)
{
	if (list_ == nullptr) // tom lista?
	{
		return true;
	}
	return false;
}

list copy(const list& list_)
{
	for (auto it = list_;
}

void print(const list& list_, ostream& os)
{
	for (auto it = list_; !empty(it); it = it->next)
	{
		os << it->name << " (" << it->age << ")" << endl;
	}
}



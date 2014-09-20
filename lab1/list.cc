#include <string>
#include <istream>
#include <iostream>
#include "list.h"

void build_lists(istream& is, list& list_1, list& list_2)
{
	string name;
	int age;
	
	while (is >> name)
	{
		is >> age;
		
		insert(list_1, name, age);
		append(list_2, name, age);
	}
}	

void append(list& list_, const string& name, int age)
{
    auto p = new list_node{name, age, nullptr}; // typ list_node*
    if (list_ == nullptr) // tom lista
    {
        list_ = p;
        return;
    }
    // Det finns minst en nod i listan, sök upp den sista noden och länka in den nya noden efter den sista
    auto last = list_; // typ List_Node*
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = p;
}


void insert(list& list_, const string& name, int age)
{
    auto p = new list_node {name, age, nullptr}; //typ list_node*
    if (list_ == nullptr)
    {
        list_ = p;
        return;
    }
    p->next = list_; // pekar på början av listan
    list_ = p;
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
    
	if(empty(list_))
    {
        list new_list {nullptr};
        return new_list;
    }
    auto p = new list_node{list_->name, list_->age, copy(list_->next)};
    list new_list = p;
    return new_list;
}




void print(const list& list_, ostream& os)
{
    for (auto it = list_; !empty(it); it = it->next)
    {
        os << it->name << " (" << it->age << ")" << endl;
    }
}

void reverse(list& list_)
{
    if(empty(list_) || empty(list_->next))
    {
        return;
    }

    list prev = list_;
    list current = list_->next;
    list next_node = current->next;

    while(!empty(next_node))
    {
        current->next = prev; // Ändrar håll på pekaren i listan.
        prev = current;
        current = next_node;
        next_node = next_node->next;
    }

    current->next = prev;
    list_->next = {nullptr};
    list_ = current;
}

void print_reverse(const list& list_, ostream& os) //Har inte testat ostream-grejen, bara med cout.
{
    if(empty(list_))
    {
        return;
    }

    print_reverse(list_->next, os);
    os << list_->name << " (" << list_->age << ")" << endl;
}

//Är det verkligen så enkelt?
void swap(list& list_1, list& list_2)
{
    list temp = list_1;
    list_1 = list_2;
    list_2 = temp;
}

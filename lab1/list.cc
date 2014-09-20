/*
 * FILNAMN:       list.cc
 * LABORATION:    lab1-5
 * PROGRAMMERARE: Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *                Kerstin Söderqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-09-20
 *
 * BESKRIVNING:
 * Deffinitionsfil för alla funktioner som används i lab1-5
 */

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
		
		insert(list_1, name, age); // Sätter in namn och ålder först i listan
		append(list_2, name, age); // Sätter in namn och ålder sist i listan
	}
}	

//Sätter in namn och ålder sist i listan
void append(list& list_, const string& name, int age) 
{
    auto p = new list_node{name, age, nullptr}; // typ list_node*
    if (list_ == nullptr) // tom lista
    {
        list_ = p;
        return;
    }
	
    auto last = list_; // typ list_node*
    while (last->next != nullptr) 
    {
        last = last->next;
    }
    last->next = p;
}

// Sätter in namn och åler först i listan
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

// Radera innehållet i en lista
void clear(list& list_)
{
    delete[] list_; //tar bort alla noder
    list_ = nullptr;
}

// Kollar om en lista är tom
bool empty(const list& list_)
{
    if (list_ == nullptr) // tom lista?
    {
        return true;
    }
    return false;
}

// Kopierar en lista
list copy(const list& list_) // Kopierar en lista
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

// Skriver ut en lista
void print(const list& list_, ostream& os) 
{
    for (auto it = list_; !empty(it); it = it->next)
    {
        os << it->name << " (" << it->age << ")" << endl;
    }
}

// Vänder på en lista 
void reverse(list& list_)
{
    if(empty(list_) || empty(list_->next))
    {
        return;
    }

    // Hjälp-pekare
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
    list_->next = {nullptr}; // Sätter sista pekaren till nollpekare
    list_ = current;
}

// Skriver ut i omvänd ordning
void print_reverse(const list& list_, ostream& os)
{
    if(empty(list_))
    {
        return;
    }

    print_reverse(list_->next, os);
    os << list_->name << " (" << list_->age << ")" << endl;
}

// Byter innehåll på två listor
void swap(list& list_1, list& list_2) 
{
    list temp = list_1;
    list_1 = list_2;
    list_2 = temp;
}

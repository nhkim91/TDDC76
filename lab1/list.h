/*
 * FILNAMN:       list.h
 * LABORATION:    lab1-5
 * PROGRAMMERARE: Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *                Kerstin Söderqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-09-20
 *
 * BESKRIVNING:
 * Deklarationsfil för alla funktioner i list.cc
 */

#include <istream>
#include <ostream>
#include <string>

// Gard för att klassen inte ska inkluderas flera gånger i ett programm
#ifndef _INC_LIST_GUARD_ 
#define _INC_LIST_GUARD_

using namespace std;

struct list_node
{
	string name;
	int age;
	list_node* next;
};

using list = list_node*;

void build_lists(istream& is, list& list_1, list& list_2); 

void append(list& list_2, const string& name, int age);

void insert(list& list_1, const string& name, int age);

void clear(list& list_);

bool empty(const list& list_);

list copy(const list& list_);

void reverse(list& list_);

void print(const list& list_, ostream& os);

void print_reverse(const list& list_, ostream& os);

void swap(list& list_1, list& list_2);

#endif

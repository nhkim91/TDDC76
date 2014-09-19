#include "list.h"

void build_lists(istream& is, list list_1, list list_2)
{

}

void append(list& list_, const string& name, int age)
{
    auto p = new list_node {name, age, nullptr}; // typ list_node*
    if (list_ == nullptr) // tom lista
    {
        list_ = p;
        return;
    }
    // Det finns minst en nod i listan, sök upp den sista noden och länka in den nya noden efter den sista
    auto last = list; // typ List_Node*
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = p;
}


void insert(list& list_, const string& name, int age)
{
    p = new list_node {name, age, nullptr}; //typ list_node*
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

List copy(const List& list_)
{
    if(empty(list_))
    {
<<<<<<< HEAD
        List new_list{nullptr};
        return new_list;
=======
        if (result == nullptr)
        {
            result = new list_node {name, age, nullptr};
        }
        else
        {
            result = new list_node {node->name, node->age, nullptr};
        }

>>>>>>> origin/master
    }

    auto p = new person{list_->name, list_->age, copy(list_->next)};
    List new_list = p;
    return new_list;
}

void print(const list& list_, ostream& os)
{
    for (auto it = list_; !empty(it); it = it->next)
    {
        os << it->name << " (" << it->age << ")" << endl;
    }
}



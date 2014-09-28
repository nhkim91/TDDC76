/*
 * FILNAMN:       lab1-4.cc
 * LABORATION:    lab1-4
 * PROGRAMMERARE: Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *                Kerstin S�derqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-09-29
 *
 * BESKRIVNING:
 * Programmet g�r en ordlista och h�ller koll p� antalet g�nger ordet f�rekommer.
 * Om ordet finns r�knas det upp ett annars l�ggs det till, till ordlistan.
 */

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct word_entry
{
    string word;
    int counter;
};

// exists returnerar antingen true eller false beroende p� om ordet finns i ordlistan eller ej.
bool exists(const string& word, const vector<word_entry>& word_list)
{
    for(int i = 0; i < word_list.size(); i++)
    {
        if(word == word_list[i].word)
        {
            return true;
        }
    }
    return false;
}

//S�tter in ord
void insert_word(const string& word, vector<word_entry>& word_list)
{
    if (word_list.empty())
    {
        word_list.push_back(word_entry {word,1}); //l�gg till ordet i ordlistan om den �r tom
    }
    else
    {
        for (auto it = word_list.begin(); it < word_list.end(); it++)
        {
            if(word == it->word)
            {
                it->counter++;
                return;
            }

            else if( word < it->word) //kollar om ordet finns i listan, om inte l�gg det p� r�tt plats
            {
                word_entry entry {word,1}; //s�tter antal till 1
                word_list.insert (it, entry);
                return;
            }
        }
        word_list.push_back(word_entry {word,1}); //l�gger ordet i listan
    }
    return;
}

// Ordlistan skrivs ut med antal av varje ord.
void print_list (const vector<word_entry>& word_list)
{
    cout << setw(20) << "word:" << setw(14) << "Quantity:"<< endl << endl;
    for(int i {0}; i < word_list.size(); i++)
    {
        cout << right << setw(20) << word_list[i].word << setw(5) << word_list[i].counter << endl;
    }
}

int main()
{
    string word;
    vector<word_entry> word_list;
    int length = 0;

    cout << "Please, enter some words: ";

    while(cin >> word)  // Forts�tter till filslut. !cin.eof(), cin >> word.
    {

        int i=0;

        while (word[i]) //G�r om stora bokst�ver till sm� bokst�ver
        {
            char c = word[i];
            word[i] = tolower(c);
            i++;
        }
        insert_word (word, word_list);
    }
    print_list (word_list);
    return 0;
}

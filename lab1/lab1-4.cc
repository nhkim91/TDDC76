/*
 * FILNAMN:       lab1-4.cc
 * LABORATION:    lab1-4
 * PROGRAMMERARE: Kim Nguyen Hoang 910112-0260 Y3.c kimng797
 *                Kerstin Söderqvist 911006-0309 Y3.c kerso255
 * DATUM:         2014-09-dd
 *
 * BESKRIVNING:
 * Programmet gör en ordlista och håller koll på antalet gånger ordet förekommer. 
 * Om ordet finns räknas det upp ett annars läggs det till, till ordlistan.
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

// exists returnerar antingen true eller false beroende på om ordet finns i ordlistan eller ej.
bool exists(string word, vector<word_entry> word_list)
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

//
vector<word_entry> insert_word(string word, vector<word_entry> word_list)
{
    vector<word_entry>::iterator it;

    if (word_list.empty())
    {
        word_list.push_back(word_entry {word,1}); //lägg till ordet i ordlistan om den är tom

    }
    else
    {
        for (it = word_list.begin(); it < word_list.end(); it++)
        {
            if( word < it->word) //kollar om ordet finns i listan, om inte lägg det på rätt plats
            {
                word_entry entry {word,1};
                word_list.insert (it, entry);
                return word_list;
            }
        }
        word_list.push_back(word_entry {word,1}); //lägger ordet i listan
    }
    return word_list;
}



int main()
{
    string word;
    vector<word_entry> word_list;
    int length = 0;

    cout << "Please, enter some words: ";

    while(cin >> word)  // Fortsätter till filslut. !cin.eof(), cin >> word.
    {

        int i=0;

        while (word[i]) //Gör om stora bokstäver till små bokstäver
        {
            char c = word[i];
            word[i] = tolower(c);
            i++;
        }

        bool exist {exists(word, word_list)}; // Kollar om ordet finns i listan sedan tidigare.

        if(exist == true)
        {
            // Om ordet finns räknas counter upp.

            for(int i = 0; i < word_list.size(); i++)
            {
                if(word == word_list[i].word)
                {
                    word_list[i].counter++;
                }
            }
        }
        else
        {
            // Om ordet inte finns läggs det till
            word_list = insert_word (word, word_list);

        }
    }

    // Ordlistan skrivs ut med antal av varje ord.

    cout << setw(20) << "word:" << setw(14) << "Quantity:"<< endl << endl;
    for(int i {0}; i < word_list.size(); i++)
    {
        cout << right << setw(20) << word_list[i].word << setw(5) << word_list[i].counter << endl;
    }

    return 0;
}

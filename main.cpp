#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "Deck.hpp"

using namespace std;

void print_deck(Deck<int> deck)
{
    std::for_each(deck.begin(), deck.end(), [](int &n) { cout << ' ' << n; });
    cout << endl;
}

 
int main()
{
    Deck<int> deck;

    for(int iter = 0; iter < 52; ++iter)
    {
        deck.add(iter);
    }

    print_deck(deck);

    deck.shuffle();

    print_deck(deck);

    size_t size = deck.size();

    cout << "Container size is " << size << endl;

    auto top = deck.top();

    cout << "Container top value is " << top << endl;

    top = deck.draw();

    cout << "Container top value is " << top << endl;

    size = deck.size();

    cout << "Container size is " << size << endl;

    deck.add(43);

    cout << "Container top value is " << top << endl;

    size = deck.size();

    cout << "Container size is " << size << endl;
    
}


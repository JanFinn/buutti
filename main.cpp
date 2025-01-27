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
    cout << "Creating deck..." << endl;
    Deck<int> deck;
    cout << "Deck size is " << deck.size() << endl;

    for(int iter = 0; iter < 52; ++iter)
    {
        deck.add(iter);
    }
    cout << "Full deck size is " << deck.size() << endl;

    cout << "Deck before shuffle: " << endl;
    print_deck(deck);

    deck.shuffle();

    cout << "Deck after shuffle: " << endl;
    print_deck(deck);

    cout << "Deck top value is " << deck.top() << endl;

    cout << "Deck bottom value is " << deck.bottom() << endl;

    cout << "Drew card " << deck.draw() << endl;

    cout << "Deck top value after draw is " << deck.top() << endl;

    cout << "Deck size after draw is " << deck.size() << endl;

    int newTop = 42;

    cout << "Adding new card " << newTop << " to deck..." << endl;

    deck.add(42);

    cout << "Deck top value is " << deck.top() << endl;

    cout << "Deck size after adding is " << deck.size() << endl;    
}


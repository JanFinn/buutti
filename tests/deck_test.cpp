#include "../Deck.hpp"
#include <gtest/gtest.h>

class DeckTest : public testing::Test {
 protected:
  DeckTest() {
  }

  Deck<int> deck;
};

TEST_F(DeckTest, ShouldAddAndReturnCorrectSize) {
  
  EXPECT_EQ(0, deck.size());

  const int expectedSize = 52;

  for(int i = 0; i < expectedSize; ++i)
  {
    deck.add(i);
  }

  EXPECT_EQ(expectedSize, deck.size());
}

TEST_F(DeckTest, ShouldReturnCorrectSizeAfterDraw) {

  const int expectedSize = 52;
  const int expectedTopCard = 51;
  
  // Test deck is empty
  EXPECT_EQ(0, deck.size());

  for(int i = 0; i < expectedSize; ++i)
  {
    deck.add(i);
  }

  int topCard = deck.draw();
  EXPECT_EQ(expectedTopCard, topCard);
  EXPECT_EQ(expectedSize - 1, deck.size());
}

TEST_F(DeckTest, ShouldReturnCorrectTopAndBottomValues) {
  // Add 15 "cards", check the top and bottom cards for correctness
  const int expectedBottomCard = 0;
  const int expectedTopCard = 14;
  const int cardCount = 15;

  for(int i = 0; i < cardCount; ++i)
  {
    deck.add(i);
  }

  int bottomCard = deck.bottom();
  EXPECT_EQ(expectedBottomCard, bottomCard);

  int topCard = deck.top();
  EXPECT_EQ(expectedTopCard, topCard);
}

TEST_F(DeckTest, ShouldShuffleDeckWithoutSeed) {
  const int cardCount = 52;
  Deck<int> shuffledDeck;
  
  // Test decks are empty
  EXPECT_EQ(0, deck.size());
  EXPECT_EQ(0, shuffledDeck.size());

  // Add equal amount fo cards to decks
  for(int i = 0; i < cardCount; ++i)
  {
    deck.add(i);
    shuffledDeck.add(i);
  }

  // Decks should be identical
  EXPECT_EQ(cardCount, deck.size());
  EXPECT_EQ(cardCount, shuffledDeck.size());
  for(int i = 0; i < cardCount; ++i)
  {
    EXPECT_EQ(deck[i], shuffledDeck[i]);
  }

  shuffledDeck.shuffle();

  bool equal = true;
  EXPECT_EQ(cardCount, deck.size());
  EXPECT_EQ(cardCount, shuffledDeck.size());
  for(int i = 0; i < cardCount; ++i)
  {
    if(deck[i] != shuffledDeck[i])
    {
      equal = false;
    }
  }

  EXPECT_FALSE(equal);
}

TEST_F(DeckTest, ShouldShuffleDeckWithSeed) {
  const int cardCount = 52;
  Deck<int> shuffledDeck;
  
  // Test decks are empty
  EXPECT_EQ(0, deck.size());
  EXPECT_EQ(0, shuffledDeck.size());

  // Add equal amount fo cards to decks
  for(int i = 0; i < cardCount; ++i)
  {
    deck.add(i);
    shuffledDeck.add(i);
  }

  // Decks should be identical
  EXPECT_EQ(cardCount, deck.size());
  EXPECT_EQ(cardCount, shuffledDeck.size());
  for(int i = 0; i < cardCount; ++i)
  {
    EXPECT_EQ(deck[i], shuffledDeck[i]);
  }

  shuffledDeck.shuffle(42);

  bool equal = true;
  EXPECT_EQ(cardCount, deck.size());
  EXPECT_EQ(cardCount, shuffledDeck.size());
  for(int i = 0; i < cardCount; ++i)
  {
    if(deck[i] != shuffledDeck[i])
    {
      equal = false;
    }
  }

  EXPECT_FALSE(equal);
}


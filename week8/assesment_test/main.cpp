#include "includes/game21.hpp"

int main() {
    std::cout << "*** Game of Twenty-One ***\n";
    Player player;
    Player dealer(true);
    Deck<Card> deck;
    deck.shuffle();

    std::cout << "The player's first card is: ";
    draw_and_get_score(deck, player);
    std::cout << "The dealer's first card is: ";
    draw_and_get_score(deck, dealer);
    players_rounds(deck, player);
    return 0;
}

#ifndef GAME21_HPP
#define GAME21_HPP
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

// Helper type to hold the card details
struct Card {
    int value;
    std::string suit;
};

template <typename T>
class Deck {

    public:
        using storage_type = std::vector<T>;  
        using value_type = typename storage_type::value_type;
        using reference = typename storage_type::reference;
        using const_reference = typename storage_type::const_reference;
        using iterator = typename storage_type::iterator;
        using const_iterator = typename storage_type::const_iterator;
        using difference_type = typename storage_type::difference_type;
        using size_type = typename storage_type::size_type;

        // Creates deck (not suffled)
        Deck() {
            std::string suit{};
            for (int j = 0; j < 4; j++) {
                if (j == 0) {
                    suit = "diamond";
                } else if (j == 1) {
                    suit = "club";
                } else if (j == 2) {
                    suit = "heart";
                } else if (j == 3) {
                    suit = "spade";
                }
                for (int i = 1; i < 14; i++) {
                    card = {i, suit};
                    deck.push_back(card);
                }
            }
        }

        ~Deck() = default;

        iterator begin() {
            return deck.begin();
        }

        const iterator begin() const {
            return deck.begin();
        } 

        iterator end() {
            return deck.end();
        }

        const iterator end() const {
            return deck.end();
        }

        const_iterator cbegin() {
            return deck.begin();
        }

        const_iterator cend() {
            return deck.end();
        }

        int size() {
            return deck.size();
        }

        bool empty() {
            return deck.begin() == deck.end();
        }

        // Access
        Card& at(int index) {
            return deck[index];
        }

        // member function to shuffle the elements contained in the Deck container
        void shuffle() {
            std::shuffle(deck.begin(), deck.end(), std::mt19937{std::random_device{}()});
        }

        // member function to return the top card (and remove it from the Deck)
        Card draw() {
            Card drawn_card{deck.front()};
            deck.erase(deck.begin());
            return drawn_card;
        }

        // member functions to get a reference to top/bottom of the deck.
        Card& top() {
            return deck.front();
        }

        Card& bottom() {
            return deck.back();
        }

    private:
        storage_type deck;
        Card card;
};

struct Player {
    bool is_dealer{false};
    int score{0};
    Player() = default;
    Player(bool dealer) {
        is_dealer = dealer;
    }
};

void draw_and_get_score(Deck<Card>& deck, Player& player) {
    Card card{deck.draw()};
    if (card.value == 1) {
        if (14 + player.score <= 21) {
            card.value = 14;
    }}
    std::cout << card.suit << " " << card.value << "\n";
    player.score += card.value;
}

void players_rounds(Deck<Card>& deck, Player& player) {
    bool player_continues{true};
    while (player_continues) {
        if (player.score > 21) {
            std::cout << "Your score is " << player.score << ". Game over! You lose!\n";
            break;
        } else if (player.score == 21) {
            std::cout << "Exellent! Your score is 21! Let's see next what score the dealer gets.\n";
            break;
        }
        std::cout << "Your score is now " << player.score << ", do you want to continue? (y/n) ";
        char choice{};
        std::cin >> choice;
        switch (choice)
        {
            case 'y':
                draw_and_get_score(deck, player);
                break;
            
            case 'n':
                player_continues = false;
                break;
            
            default:
                std::cout << "Please choose 'y' as yes or 'n' as no\n";
                break;
            }
    }
}

#endif
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

void print_hello() {
    std::cout << "Hello, ";
}

void print_world() {
    std::cout << "world!\n";
}

static int g_sum{0};
//std::atomic_int g_sum{0};   // EXERCISE 4
static int g_sum_ex3{0};
static std::mutex add_mutex;

void add_ex2(int increment, int times) {
    for (int i = 0; i < times; i++) {
        g_sum += increment;
    }
}

void add_ex3(int increment, int times) {
    std::lock_guard add_lock{add_mutex};
    for (int i = 0; i < times; i++) {
        g_sum_ex3 += increment;
    }
}

int main() {
    // EXERCISE 1  -> threadit ajetaan rinnakkain, joten 'world' saattaa tulostua ennen 'hello':a
    std::jthread thr_hello(print_hello);
    std::jthread thr_world(print_world);
    std::cout << "\n";

    // EXERCISE 2 -> threadit saavat muuttaa samaa muistipaikan arvoa samaan aikaan ja siksi summa on vajaa
    {  // thredaus pitää olla eri scopessa kuin tulostus, koska muuten se ei ole välttämättä tapahtunut loppuun ennen tulostusta
        std::vector<std::jthread> threads;
        for (int i = 0; i < 100; i++) {
            threads.push_back(std::jthread(add_ex2, 500, 500));
        }
    }
    std::cout << "Exercise 2 (using multithreading): " << g_sum << "\n";
    
    // "Normi" tulostus
    g_sum = 0;
    for (int i = 0; i < 100; i++) {
        add_ex2(500, 500);
    }
    std::cout << "Exercise 2 (straight-up calculation): " << g_sum << "\n";

    // EXERCISE 3
    {
        std::vector<std::jthread> threads2;
        for (int i = 0; i < 100; i++) {
            threads2.push_back(std::jthread(add_ex3, 500, 500));
        }
    }
    
    std::cout << "Exercise 3 (using multithreading with mutex): " << g_sum_ex3 << "\n";


    return 0;
}
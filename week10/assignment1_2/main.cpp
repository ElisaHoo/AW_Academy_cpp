#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>

static std::vector<std::string> log;
// to exit second thread when user wants to quit
std::atomic<bool> exit_thread_flag{false};
static std::mutex add_mutex;

void add_to_log(std::string msg) {
    std::lock_guard add_lock{add_mutex};
    log.emplace_back(msg);
}

void add_log_message_every_second() {
    while (!exit_thread_flag) {
        add_to_log("One second passed");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void print_log() {
    for (auto& element : log) {
        std::cout << element << "\n";
    }
}

void get_user_inputs() {
    while (true) {
        std::cout << "Please enter a log entry or 'quit' to exit or 'log' to print the records.";
        std::string input{};
        std::getline(std::cin >> std::ws, input);
        if (input == "quit") {
            exit_thread_flag = true;
            break;
        } else if (input == "log") {
            print_log();
            continue;
        } else {
            add_to_log(input);
        }
    }
}

int main() {
    std::jthread logmsg_jthr(add_log_message_every_second);
    std::jthread input_jthr(get_user_inputs);
    return 0;
}
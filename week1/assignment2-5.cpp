#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

/* You have been tasked with developing a Book Management System 
 * for a library. The system should allow users to manage books 
 * in the library. Books in the library have the following information. 
 * Title, Author, ISBN, Year, Quantity. The information will be stored 
 * with proper data types. There should be a function to display a book, 
 * add a book and remove a book, see if the book has been loaned or not. 
 */

struct Book {
    std::string title;
    std::string author;
    std::string isbn;
    int year;
    int quantity;
};

// Forward declarations of functions
void display_books(std::vector<Book> library_database);
Book add_book();
void remove_book(std::vector<Book> library_database);
void show_if_book_is_loaned(std::vector<Book>);

int main() {
    // Make database for the book-structs
    std::vector<Book> library_database; 

    // Create couple of example books
    struct Book book1 = {.title = "Make Ink", .author = "Jason Logan", 
                        .isbn = "9781419732430", .year = 2018, .quantity = 2};
    struct Book book2 = {.title = "Lady With A Black Umbrella", 
                         .author = "Mary Balogh", .isbn = "9780996756099", 
                         .year = 2016, .quantity = 0};
    
    // Push example books in the db
    library_database.push_back(book1);
    library_database.push_back(book2);

    // Call a function to display the books in the database
    display_books(library_database);

    // Call a function to add one book in the database
    library_database.push_back(add_book());
    std::cout << "\nThe book is added successfully!\nThe books in the library are now:\n\n";
    display_books(library_database);

    // Call a function to remove one book from the library
    remove_book(library_database);

    // Call a function to check if the book is loaned
    show_if_book_is_loaned(library_database);

    return 0;
}

// a function to display the books
void display_books(std::vector<Book> library_database) {
    for (int i = 0; i < library_database.size(); ++i) {
        std::cout << "Title:\t" << library_database[i].title << "\n"
                  << "Author:\t" << library_database[i].author << "\n"
                  << "ISBN:\t" << library_database[i].isbn << "\n"
                  << "Year:\t" << library_database[i].year << "\n"
                  << "Quantity: " << library_database[i].quantity << "\n\n";
    }
}

// a function to add a book
Book add_book() {
    // Get the book's information from a user
    std::cout << "To add the book in the library, please enter the following:\n";
    std::cout << "Title: ";
    std::string title{};
    std::getline(std::cin, title);
    std::cout << "Author: ";
    std::string author{};
    std::getline(std::cin, author);
    std::cout << "ISBN: ";
    std::string isbn{};
    std::getline(std::cin, isbn);
    std::cout << "Year: ";
    int year{};
    std::cin >> year;
    std::cout << "Quantity: ";
    int quantity{};
    std::cin >> quantity;

    struct Book book3 = {.title = title, .author = author, .isbn = isbn, .year = year, .quantity = quantity};

    return book3;
}

// A function to check if the book is loaned
void show_if_book_is_loaned(std::vector<Book> library_database) {
    std::cout << "Please enter the title of the book which " 
                 "availability you want to check: ";
    std::string titl_e{};
    std::getline(std::cin, titl_e);

    for (auto it = library_database.begin(); it != library_database.end(); ++it) {
        // It points to to the memory location of the book that is the subject of iteration
        if (it -> title == titl_e) {   // Check if the book name matches the user input
            if (it -> quantity < 1) {  // When the right book is found, check the book's availability
                std::cout << "\nSorry, but the book is loaned!\n\n";
            } else {
                std::cout << "\nThe book is free to loan!\n\n";
            }
        }
    }
}

// a function to remove a book
void remove_book(std::vector<Book> library_database) {
    std::cout << "Please enter the title of the book(s) you want to " 
                 "remove from the library: ";
    std::string t_itle{};
    if (!std::cin) {   // For checking if there is "some rubbish in the cin" to avoid program act weirdly
        std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin, t_itle);

    // Removes the book from the db according to the title of the book
    for (auto it = library_database.begin(); it != library_database.end(); ++it) {
        if (it -> title == t_itle) {
            library_database.erase(it);  // Erares the whole book-struct from the db
        }
    }
    std::cout << "\nThe book is removed successfully!\nThe books in the library are now:\n\n";
    display_books(library_database);
}
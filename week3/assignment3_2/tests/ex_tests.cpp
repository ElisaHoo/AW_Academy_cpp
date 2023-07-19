#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../includes/doctest.h"
#include "../includes/ex1.h"
#include "../includes/ex2.h"
#include "../includes/ex3.hpp"

// Exercise 1 tests
TEST_CASE("Tests for math functions") {
    CHECK(addition(5.3, 5.0) == 10.3);
    CHECK(subtraction(4.0, 2.0) == 2.0);
    CHECK(multiplication(3.0, 2.0) == 6.0);
    CHECK(division(8.0, 2.0) == 4.0);
    CHECK_THROWS_AS(division(6.0, 0), std::runtime_error);
}

// Exercise 2 tests
TEST_CASE("Tests for string conversions") {
    CHECK(convert_to_uppercase("hello") == "HELLO");
    CHECK(convert_to_lowercase("HELLO") == "hello");
    CHECK(check_if_palindrome("saippuakauppias") == true);
}

// Exercise 3 tests
TEST_CASE("Tests for the banking system") {
    Customer test_customer = {"Erkki Example", "Example Street 1", "12345", {}};
    Account test_account{20};
    test_customer.accounts[account_number] = test_account;
    bank[customer_number] = test_customer;

    SUBCASE("Customer number is valid") {
        CHECK((customer_number_is_used(4000)) == false);
        CHECK((customer_number_is_used(customer_number)) == true);
        CHECK((get_valid_customer_number(customer_number)) == 0);
    }
    SUBCASE("Account number is valid") {
        CHECK((account_number_is_used(4000, customer_number)) == false);
        CHECK((account_number_is_used(account_number, customer_number)) == true);
        CHECK((check_account_number_is_valid(account_number, customer_number)) == account_number);
    }
    SUBCASE("Deposit works") {
        CHECK(get_valid_input_value_type_for_deposit(20) == 20);
        CHECK(get_valid_input_value_type_for_deposit(20.02) == 20.02);
        test_customer = deposit_money(test_customer, account_number, get_valid_input_value_type_for_deposit(44.44));
        CHECK(test_customer.accounts[account_number].balance == 64.44);
    }
    SUBCASE("Withdrawal works") {
        CHECK(get_valid_withdrawal(test_customer, account_number, 5.5) == 5.5);
        test_customer = withdraw_money(test_customer, account_number, 15.0);
        CHECK(test_customer.accounts[account_number].balance == 5);
    }
    SUBCASE("Create a new account works") {
        int new_acc_num{create_new_account(customer_number, 350.50)};
        CHECK(bank[customer_number].accounts[new_acc_num].balance == 350.5);
        int new_acc_num2{create_new_account(customer_number, 45500.69)};
        CHECK(bank[customer_number].accounts[new_acc_num2].balance == 45500.69);
    }
    SUBCASE("Create a new customer works") {
        std::vector<int> v{create_new_customer("Testi Pirkko", "Pirkontie 3", "+358 123 456", 350)};
        CHECK(v[0] == account_number +3);
        CHECK(v[1] == customer_number +1);
        CHECK(bank[customer_number +1].accounts[account_number +3].balance == 350);
        CHECK(bank[account_number +1].name == "Testi Pirkko");
        CHECK(bank[customer_number +1].address == "Pirkontie 3");
        CHECK(bank[customer_number +1].phone == "+358 123 456");
    }
    SUBCASE ("Saving customer data to file works") {
        CHECK_NOTHROW(save_customer_data("customer_data.csv", test_customer));
    }
}
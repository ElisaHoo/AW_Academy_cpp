#ifndef WIDGET_HPP
#define WIDGET_HPP
#include <iostream>
#include <vector>

struct Position {
    int x_coord{0};
    int y_coord{0};
};

class Widget {
    public:
        virtual void on_click() const = 0;
        virtual void on_focus()  const = 0;
        Position pos;
        virtual void get_position() const = 0;
        virtual Position move_position(const int& x, const int& y) = 0;
        // Children stuff will be changed more reasonable next week
        virtual std::vector<int> children() = 0;
        virtual void add_child() = 0;
        virtual void remove_child() = 0;
        virtual void list_children() = 0;
        ~Widget() = default;
    
    private:    
};

class Button : public Widget {
    public:
        void on_click() const override {
            std::cout << "CLICK!\n";
        }
        void on_focus() const override {
            std::cout << "The button is focused!\n";
        }
        void get_position() const override {
            std::cout << "Position x = " << pos.x_coord << " and y = " << pos.y_coord << "\n";
        }
        Position move_position(const int& x, const int& y) override {
            pos.x_coord = x;
            pos.y_coord = y;
            return pos;
        }
        std::vector<int> children() override {}
        virtual void add_child() override {};
        virtual void remove_child() override {};
        virtual void list_children() override {};
        ~Button() = default;
    
    private:
};

class Mock : public Widget {
    public:
        void on_click() const override {
            std::cout << "MOCK CLICK!\n";
        }
        void on_focus() const override {
            std::cout << "The MOCK button is focused!\n";
        }
        void get_position() const override {
            std::cout << "Position x = " << pos.x_coord << " and y = " << pos.y_coord << "\n";
        }
        Position move_position(const int& x, const int& y) override {
            pos.x_coord = x;
            pos.y_coord = y;
            return pos;
        }
        std::vector<int> children() override {}
        virtual void add_child() override {};
        virtual void remove_child() override {};
        virtual void list_children() override {};
        ~Mock() = default;
    
    private:
};

#endif
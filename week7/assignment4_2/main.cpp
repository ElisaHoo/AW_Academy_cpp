/* Exercise 1.
 * Here we will create an interface for an UI element (these are usually called widgets).  
 * It should have require functionality such as reacting to user actions "on_click()", 
 * "on_focus()", etc.  In addition it should have a way to move and get position of 
 * the UI element.  In addition, UI elements usually have child elements (that also 
 * fulfill the interface), you should require functionality to add / remove / list those 
 * as well.  (These will not work properly without pointers, so you'll get a better way to 
 * handle them next week, don't try too much to make them work yet)
 * 
 * Exercise 2.
 * Make some mock class that inherits the interface.  It does not need to be a real UI 
 * or anything, just something that implements the UI interface.*/

#include "widget.hpp"

int main() {
    // EXERCISE 1
    Button btn;
    btn.on_click();
    btn.on_focus();
    btn.get_position();
    btn.move_position(25, 58);
    btn.get_position();

    // EXERCISE 2
    Mock mock;
    mock.on_click();
    mock.on_focus();
    mock.get_position();
    mock.move_position(3, 76);
    mock.get_position();

    return 0;
}
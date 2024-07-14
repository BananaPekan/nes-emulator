#include <iostream>
#include "display.cpp"

Display* display;

int main()
{
    display = new Display(800, 800);
    display->init();
    display->updateDisplay();
    display->killDisplay();
    return 0;
}
#include <iostream>
#include "display.cpp"
#include "cpu.cpp"

CPU* cpu;
Display* display;

int main()
{
    cpu = new CPU();
    display = new Display(256, 240);
    display->init();
    display->updateDisplay();
    display->killDisplay();
    return 0;
}
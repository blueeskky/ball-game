#include <iostream>
#include <string>
#include <Windows.h>


int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Press escape to leave" << std::endl;
    while (true) {
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            std::cout << "Exiting" << std::endl;
            break;
        }
    return 0;
}

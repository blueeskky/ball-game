#include <iostream>
#include <string>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif


int getKeyInput() {
    #ifdef _WIN32
        if (_kbhit()) {
            return _getch();
        }
        return -1;
    #else
        struct termios old_settings, new_settings;
        tcgetattr(STDIN_FILENO, &old_settings);
        new_settings = old_settings;
        new_settings.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
        
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
        unsigned char c;
        int result = read(STDIN_FILENO, &c, 1);
        
        tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
        
        if (result > 0) {
            return (int)c;
        }
        return -1;
    #endif
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Press escape to leave" << std::endl;
    
    while (true) {
        int key = getKeyInput();
        if (key == 27) {  // 27 is Escape key
            std::cout << "Exiting" << std::endl;
            break;
        }
    }
    
    return 0;
}

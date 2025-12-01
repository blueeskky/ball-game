#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif


void clearScreen() {
    // Print 50 newlines to clear the screen
    for (int i = 0; i < 50; i++) {
        std::cout << std::endl;
    }
}

class entity {
    public:
        int x = 1;
        int y = 1;
        void move(int key) {
            int new_x = x;
            int new_y = y;
            
            // WASD keys
            if (key == 'w' || key == 'W') {
                new_x -= 1;  // Move up
            }
            else if (key == 's' || key == 'S') {
                new_x += 1;  // Move down
            }
            else if (key == 'a' || key == 'A') {
                new_y -= 1;  // Move left
            }
            else if (key == 'd' || key == 'D') {
                new_y += 1;  // Move right
            }
            // Arrow keys (Windows)
            #ifdef _WIN32
            else if (key == 72) {  // Up arrow
                new_x -= 1;
            }
            else if (key == 80) {  // Down arrow
                new_x += 1;
            }
            else if (key == 75) {  // Left arrow
                new_y -= 1;
            }
            else if (key == 77) {  // Right arrow
                new_y += 1;
            }
            #endif
            
            // Keep player within bounds (0-3)
            if (new_x >= 0 && new_x < 4 && new_y >= 0 && new_y < 4) {
                x = new_x;
                y = new_y;
            }
        }
};

int main() {
    char game[4][4] = {
        {'@', '@', '@', '@'},
        {'@', '@', '@', '@'},
        {'@', '@', '@', '@'},
        {'@', '@', '@', '@'}
    }; // game initialization
    entity player;

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Press Enter to start the game" << std::endl;
    
    std::string start;
    std::getline(std::cin, start);
    
    clearScreen();
    std::cout << "Game started! Use w/a/s/d to move, q to quit" << std::endl;
    
    while (true)
    {
        // Clear the game board
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                game[i][j] = '@';
            }
        }
        
        // Draw player
        game[player.x][player.y] = 'O';
        
        // Display the game board
        std::cout << "\nGame Board:" << std::endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                std::cout << game[i][j] << " ";
            }
            std::cout << std::endl;
        }
        
        std::cout << "Enter move (w/a/s/d or q to quit): ";
        
        std::string input;
        std::getline(std::cin, input);
        
        if (!input.empty()) {
            char key = input[0];
            if (key == 'q' || key == 'Q') {  // Quit game
                std::cout << "Thanks for playing!" << std::endl;
                break;
            }
            player.move(key);
        }
    }
    
    return 0;
}

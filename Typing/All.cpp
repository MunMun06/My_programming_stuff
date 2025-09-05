#include <iostream>
#include <ctime>

char generateParagraph();

int main() {
    srand(time(0)); // Seed for the random number generator 

    int round = 2; // Number of rounds
    int length = 30; // Length of each sequence
    int totalWrongCount = 0; // Total wrong count across all rounds

    for (int r = 1; r <= round; ++r) {
        char correct[length + 1]; // Increase the size to accommodate the null terminator (last character of the string)

        // Generate the correct sequence
        do {
            // Generate the sequence
            for (int i = 0; i < length; ++i) {
                correct[i] = generateParagraph();
            }
            correct[length] = '\0'; // Add null terminator
        } while (correct[0] == ' ' || correct[length - 1] == ' '); // Regenerate if the first or last character is a space

        // Output the correct sequence
        std::cout << correct << std::endl;

        // Prompt the user 
        char input[length + 1];
        std::cin.getline(input, length + 1); // Read up to 100 characters (including null terminator)

        // Compare the user input with the correct sequence and highlight differences
        int wrongCount = 0; // Wrong count for this round
        for (int i = 0; i < length; ++i) {
            if (correct[i] != input[i]) {
                std::cout << "^";
                ++wrongCount;
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;

        // Update total wrong count
        totalWrongCount += wrongCount;

        // Display total wrong count on the last round
        if (r == round) {
            if (totalWrongCount == 0) {
                std::cout << "You're correct!" << '\n';
            } else {
                std::cout << "Total wrong count across all rounds: " << totalWrongCount << std::endl;
            }
        }
    }

    return 0;
}

char generateParagraph() {
    int ran = rand() % 74 + 1;

    switch (ran) {
        case 1: return ' ';    
        case 2: return 'z';
        case 3: return 'x';
        case 4: return 'c';
        case 5: return 'v';
        case 6: return 'b';
        case 7: return 'n';
        case 8: return 'm';
        case 9: return ',';
        case 10: return '.';
        case 11: return '/';
        case 12: return '<';
        case 13: return '>';
        case 14: return '?';
        case 15: return 'd';
        case 16: return 'f';
        case 17: return 'j';
        case 18: return 'k';
        case 19: return 's';
        case 20: return 'l';
        case 21: return 'a';
        case 22: return ';';
        case 23: return 'g';
        case 24: return 'h';
        case 25: return '"';
        case 26: return ':';
        case 27: return 'q';
        case 28: return 'w';
        case 29: return 'e';
        case 30: return 'r';
        case 31: return 't';
        case 32: return 'y';
        case 33: return 'u';
        case 34: return 'i';
        case 35: return 'o';
        case 36: return 'p';
        case 37: return '[';
        case 38: return ']';
        case 73: return '{';
        case 74: return '}';
        case 39: return '1';
        case 40: return '2';
        case 41: return '3';
        case 52: return '4';
        case 53: return '5';
        case 54: return '6';
        case 55: return '7';
        case 56: return '8';
        case 57: return '9';
        case 58: return '0';
        case 59: return '-';
        case 60: return '=';
        case 61: return '!';
        case 62: return '@';
        case 63: return '#';
        case 64: return '$';
        case 65: return '%';
        case 66: return '^';
        case 67: return '&';
        case 68: return '*';
        case 69: return '(';
        case 70: return ')';
        case 71: return '_';
        case 72: return '+';
        default: return ' ';       
    }
}

// Make this into a game one day called "Oh you think you're good at typing"
// default 150 charater per line 
// each line is one level
// start with 1 minute
// every level clear give less and less time
// must have above 90% accuracy to pass
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main() {
    std::ifstream input("input.txt");
    
    int sum = 0;
    std::string line;
    
    while (std::getline(input, line)) {
        std::string first;
        std::string last;
        std::string number;

        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                first = line[i];
                break;
            }
        }

        for (int i = line.length() - 1; i >= 0; i--) {
            if (isdigit(line[i])) {
                last = line[i];
                break;
            }
        }

        number = first + last;
        sum += stoi(number);
    }

    std::cout << sum << std::endl;

    return 0;
}

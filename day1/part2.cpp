#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

using std::string;

int main() {
    std::ifstream input("input.txt");

    std::map<string, string> map = {
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"},
    };

    int sum = 0;
    string line;

    while (std::getline(input, line)) {
        string first;
        string last;
        string token;

        for (int i = 0; i < line.length(); i++) {
            for (int j = 3; j <= 5; j++) {
                token = line.substr(i, j);
                if (isdigit(token[0])) {
                    first = token.substr(0, 1);
                    break;
                } else if (map.find(token) != map.end()) {
                    first = map[token];
                    break;
                }
            }
        }

        for (int i = line.length() - 1; i >= 0; i--) {
            for (int j = 3; j <= 5; j++) {
                token = line.substr(i, j);
                if (isdigit(token[0])) {
                    last = token.substr(0, 1);
                    break;
                } else if (map.find(token) != map.end()) {
                    last = map[token];
                    break;
                }
            }
        }

        std::cout << first << " " << last << std::endl;
        sum += stoi(last + first);  // wtf???
    }

    std::cout << sum << std::endl;

    return 0;
}

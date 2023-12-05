#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

using std::string;
using std::min;
using std::max;

int main() {
    int sum = 0;
    
    // initialize 2D array [row][col]
    char** map = new char*[140];
    for (int i = 0; i < 140; i++) {
        map[i] = new char[140];
    }

    // read file into 2D array
    std::ifstream input("input.txt");
    for (int i = 0; i < 140; i++) {
        for (int j = 0; j < 140; j++) {
            input >> map[i][j];
        }
    }
    input.close();

    // identify start and end indicies of numbers
    struct number {
        int x0;
        int y0;
        int xf;
    };

    std::vector<number> numbers;

    for (int i = 0; i < 140; i++) {
        for (int j = 0; j < 140; j++) {
            if (isdigit(map[i][j])) {
                number n;
                n.x0 = j;
                n.y0 = i;
                
                // determine length of number
                int k = j;
                while (isdigit(map[i][k])) {
                    k++;
                }
                n.xf = k - 1;

                numbers.push_back(n);
                j = k;
            }
        }
    }

    // search for symbols
    string symbols = "!@#$%^&*()_+{}|:\"<>?`-=[]\\;',/~";
    for (int i = 0; i < numbers.size(); i++) {
        int x0 = numbers[i].x0;
        int y0 = numbers[i].y0;
        int xf = numbers[i].xf;

        bool found = false;
        for (int j = max(0, y0 - 1); j <= min(139, y0 + 1); j++) {
            for (int k = max(0, x0 - 1); k <= min(139, xf + 1); k++) {
                if (symbols.find(map[j][k]) != string::npos) {
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            string num = "";
            for (int j = x0; j <= xf; j++) {
                num += map[y0][j];
            }
            sum += stoi(num);
            std::cout << num << std::endl;
        }
    }

    // deallocate 2D array
    for (int i = 0; i < 140; i++) {
        delete [] map[i];
    }
    delete [] map;

    std::cout << sum << std::endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <set>

using std::string, std::max, std::min;

// read file as 2D array
// go through array
// skip periods until a number is found
// determine length of number
// search radius of 1 for a symbol
// if symbol is found, add number to sum

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

    // start processing
    string symbols = "!@#$%^&*()_+-=[]{}\\|;':\",./<>?`~";

    for (int i = 0; i < 140; i++) {
        for (int j = 0; j < 140; j++) {
            if (isdigit(map[i][j])) {
                // find the entire number
                string num = "";
                while (isdigit(map[i][j])) {
                    num += map[i][j];
                    j++;
                }
                j -= num.length() + 1;

                // search neighbors for symbols
                int row = max(0, i - 1);
                int col = max(0, j - 1);
                int rowMax = min(139, i + 1);
                int colMax = min(139, j + 1);

                bool found = false;
                for (int r = row; r <= rowMax; r++) {
                    for (int c = col; c <= colMax; c++) {
                        if (symbols.find(map[r][c]) != string::npos) {
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                }

                if (found) {
                    sum += stoi(num);
                }

                // skip to end of number
                j += num.length();
            }
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

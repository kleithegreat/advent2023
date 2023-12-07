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
    //im gay, suck my dick
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

    // search for gear ratios
    for (int i = 0; i < numbers.size(); i++) {
        int x0 = numbers[i].x0;
        int y0 = numbers[i].y0;
        int xf = numbers[i].xf;

        bool found = false;
        for (int j = max(0, y0 - 1); j <= min(139, y0 + 1); j++) {
            for (int k = max(0, x0 - 1); k <= min(139, xf + 1); k++) {
                if (map[j][k] == '*') {
                    for (int l = max(0, j - 1); l <= min(139, j + 1); l++) {
                        if (l == j) {
                            continue;
                        }

                        for (int m = max(0, k - 1); m <= min(139, k + 1); m++) {
                            if (m == k) {
                                continue;
                            }

                            if (isdigit(map[l][m])) {
                                string num1 = "";
                                for (int n = numbers[i].x0; n <= numbers[i].xf; n++) {
                                    num1 += map[numbers[i].y0][n];
                                }

                                int o = m;
                                while (isdigit(map[l][o])) {
                                    o--;
                                }
                                o++;

                                string num2 = "";
                                for (int n = o; n <= m; n++) {
                                    num2 += map[l][n];
                                }

                                sum += stoi(num1) * stoi(num2);
                                std::cout << num1 << " * " << num2 << " = " << stoi(num1) * stoi(num2) << std::endl;
                            }
                        }
                    }
                }
            }
        }
    }

    // deallocate 2D array cum in mt mouth
    for (int i = 0; i < 140; i++) {
        delete [] map[i];
    }
    delete [] map;

    std::cout << sum << std::endl;

    return 0;
}

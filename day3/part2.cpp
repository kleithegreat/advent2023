#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

using std::string;
using std::vector;
using std::min;
using std::max;

int main() {    
    // initialize 2D array [row][col]
    // down is positive y, right is positive x
    char** map = new char*[140];
    for (int i = 0; i < 140; i++) {
        map[i] = new char[140];
    }

    // read file into 2D array
    std::ifstream input("input.txt");
    for (size_t i = 0; i < 140; i++) {
        for (size_t j = 0; j < 140; j++) {
            input >> map[i][j];
        }
    }
    input.close();

    // find all potential gear ratios
    struct starPos {
        int x;
        int y;
    };

    vector<starPos> stars;
    for (size_t row = 0; row < 140; row++) {
        for (size_t col = 0; col < 140; col++) {
            if (map[row][col] == '*') {
                starPos star;
                star.x = col;
                star.y = row;
                stars.push_back(star);
            }
        }
    }

    // a gear ratio is a * character adjacent to exactly two numbers
    struct gearRatio {
        int num1;
        int num2;
    };

    // find all gear ratios
    vector<gearRatio> ratios;
    for (size_t i = 0; i < stars.size(); i++) {
        std::cout << "checking star at " << stars[i].x << ", " << stars[i].y << std::endl;
        int firstNum = 0;
        int secondNum = 0;

        // check all adjacent cells for numbers
        vector<int> adjacentNums;
        for (size_t row = max(0, stars[i].y - 1); row <= min(139, stars[i].y + 1); row++) {
            for (size_t col = max(0, stars[i].x - 1); col < min(139, stars[i].x + 2); col++) {
                std::cout << "checking cell at " << col << ", " << row << " has value " << map[row][col] << std::endl;
                if (isdigit(map[row][col])) {
                    std::cout << "star at " << stars[i].x << ", " << stars[i].y << " has adjacent number at " << col << ", " << row << std::endl;
                    // figure out entire number
                    int startCol = col;
                    while (startCol > 0 && isdigit(map[row][startCol - 1])) {
                        startCol--;
                    }
                    int endCol = col;
                    while (endCol < 139 && isdigit(map[row][endCol + 1])) {
                        endCol++;
                    }

                    string numStr = "";
                    for (size_t j = startCol; j <= endCol; j++) {
                        numStr += map[row][j];
                    }

                    // check if number is already in adjacentNums
                    bool isDuplicate = false;
                    for (size_t j = 0; j < adjacentNums.size(); j++) {
                        if (adjacentNums[j] == std::stoi(numStr)) {
                            isDuplicate = true;
                            break;
                        }
                    }

                    if (!isDuplicate) {
                        adjacentNums.push_back(std::stoi(numStr));
                        std::cout << "added " << std::stoi(numStr) << " to adjacentNums" << std::endl;
                    }
                }
            }
        }

        // check if gear ratio
        if (adjacentNums.size() == 2) {
            gearRatio ratio;
            ratio.num1 = adjacentNums[0];
            ratio.num2 = adjacentNums[1];
            ratios.push_back(ratio);
        }
    }

    // sum all gear ratios
    int sum = 0;
    for (size_t i = 0; i < ratios.size(); i++) {
        sum += ratios[i].num1 * ratios[i].num2;
    }

    // deallocate 2D array
    for (size_t i = 0; i < 140; i++) {
        delete [] map[i];
    }
    delete [] map;

    std::cout << sum << std::endl;

    return 0;
}

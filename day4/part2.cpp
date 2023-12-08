#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
    // read file
    vector<string> input;
    string line;
    std::ifstream file("input.txt");

    while (getline(file, line)) {
        input.push_back(line);
    }
    file.close();

    // parse input
    struct Card {
        vector<int> winners;
        vector<int> given;
    };

    vector<Card> cards;

    for (int i = 0; i < input.size(); i++) {
        int COLON_POS = 8;
        int PIPE_POS = 40;

        string winners = input[i].substr(COLON_POS + 1, PIPE_POS);
        string given = input[i].substr(PIPE_POS + 1);

        // read into vectors
        Card card;
        std::stringstream ss(winners);
        int buffer;
        while (ss >> buffer) {
            card.winners.push_back(buffer);
        }
        ss.clear();
        ss.str(given);
        while (ss >> buffer) {
            card.given.push_back(buffer);
        }

        cards.push_back(card);
    }

    int totalCards = 0;

    for (int i = 0; i < cards.size(); i++) {
        totalCards++;

        int matchingCards = 0;
        for (int j = 0; j < cards[i].winners.size(); j++) {
            if (std::find(cards[i].given.begin(), cards[i].given.end(), cards[i].winners[j]) != cards[i].given.end()) {
                matchingCards++;
            }
        }

        // must implement some recursion here?

        cout << "Card " << i + 1 << ": " << matchingCards << endl;
    }
    

    cout << "Total cards: " << totalCards << endl;

    return 0;
}

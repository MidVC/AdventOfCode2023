#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Card {
  public:
    vector<int> winNumbers;
    vector<int> myNumbers;
    int getNumbersWon() {
        int count = 0;
        for ( auto &n : myNumbers ) {
            auto it = find(winNumbers.begin(), winNumbers.end(), n);
            if (it != winNumbers.end()) ++count;
        }
        return count;
    }
};

int main() {
    vector<Card> allCards;
    vector<int> cardCount;
    cardCount.resize(202, 1);
    string line;
    while (getline(cin, line)) {
        istringstream iss{line};
        string garbage;
        iss >> garbage >> garbage;
        Card c;
        int value;
        for (int i = 0; i < 10; ++i) {
            iss >> value;
            c.winNumbers.push_back(value);
        }
        iss >> garbage;
        for (int i = 0; i < 25; ++i) {
            iss >> value;
            c.myNumbers.push_back(value);
        }
        allCards.push_back(c);
    }

    // output
    int sum = 0;
    for (int i = 0; i < 202; ++i) {
        int thisCardCount = cardCount[i];
        Card thisCard = allCards[i];
        int point = thisCard.getNumbersWon();
        for (int j = 1; j <= point; ++j) {
            cardCount[i+j] += thisCardCount;
        }
        sum += thisCardCount;
    }
    cout << sum << endl;
}

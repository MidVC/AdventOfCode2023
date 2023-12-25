#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

enum class HandType{ FIVE = 6, FOUR = 5, FH = 4, THREE = 3, TWO = 2, ONE = 1, HC = 0 };

class Hand;

HandType extractHandType(const Hand &h);

int getCharValue(const char c) {
    if (c <= '9' && c >= '2') return c - '2';
    else if (c == 'T') return 8;
    else if (c == 'J') return 9;
    else if (c == 'Q') return 10;
    else if (c== 'K') return 11;
    else if (c == 'A') return 12;
    else throw runtime_error("huh");
}

class Hand {
    string cards;
    int value;
  public:
    explicit Hand(string cards, int value): cards{cards}, value{value} {}
    friend HandType extractHandType(const Hand &h);
    bool operator<(const Hand &other) {
        HandType ht1 = extractHandType(*this);
        HandType ht2 = extractHandType(other);

        // compare handtype
        if (ht1 < ht2) return true;
        else if (ht1 > ht2) return false;
        
        // same handtype, compare each char
        for (int i = 0; i < 5; ++i) {
            if (getCharValue(cards[i]) < getCharValue(other.cards[i])) return true;
            else if (getCharValue(cards[i]) > getCharValue(other.cards[i])) return false;
        }

        return false;
    }
    int getValue() { return value; }
};

HandType extractHandType(const Hand &h) {
    bool haveTriple = false;
    bool haveDouble = false;
    char firstDouble = 0;

    for (int i = 0; i < 5; ++i) {
        int count = 0;
        for (int j = 0; j < 5; ++j) {
            if (h.cards[i] == h.cards[j]) ++count;
        }
        if (count == 5) return HandType::FIVE;
        else if (count == 4) return HandType::FOUR;
        else if (count == 3) haveTriple = true;
        else if (count == 2) {
            if (firstDouble == 0) {
                haveDouble = true;
                firstDouble = h.cards[i];
            }
            else if (h.cards[i] != firstDouble) return HandType::TWO;
        }
    }

    if (haveTriple) {
        if (haveDouble) return HandType::FH;
        else return HandType::THREE;
    }
    else if (haveDouble) return HandType::ONE;
    else return HandType::HC;
}

void merge(std::vector<Hand>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<Hand> left_half;
    std::vector<Hand> right_half;

    // Copy data to temporary arrays left_half[] and right_half[]
    for (int i = 0; i < n1; i++)
        left_half.push_back(arr[left + i]);
    for (int j = 0; j < n2; j++)
        right_half.push_back(arr[mid + 1 + j]);

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (left_half[i] < right_half[j]) {
            arr[k] = left_half[i];
            i++;
        } else {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_half[], if there are any
    while (i < n1) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_half[], if there are any
    while (j < n2) {
        arr[k] = right_half[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<Hand>& arr, int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Recursively sort both halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<Hand> hands;
    string line;
    while (getline(cin, line)) {
        string hand;
        int value;
        istringstream iss{line};
        iss >> hand >> value;
        hands.push_back(Hand(hand, value));
    }

    int len = hands.size();

    merge_sort(hands, 0, len-1);

    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += hands[i].getValue() * (i+1);
    }

    cout << sum << endl;

}

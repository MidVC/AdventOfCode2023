#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

int main() {
    int sum = 0;
    string line;
    while(getline(cin, line)) {
        string garbage;
        int value;
        vector<int> winNumbers;
        istringstream iss{line};
        iss >> garbage >> garbage;
        for (int i = 0; i < 10; ++i) {
            iss >> value;
            winNumbers.push_back(value);
        }
        iss >> garbage;
        int point = 0;
        for (int i = 0; i < 25; ++i) {
            iss >> value;
            auto it = find(winNumbers.begin(), winNumbers.end(), value);
            if (it != winNumbers.end()) {
                if (point == 0) point = 1;
                else point *= 2;
            }
        }
        sum += point;
    }
    cout << sum << endl;
}



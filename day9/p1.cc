#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string line;
    long int sum = 0;
    while (getline(cin, line)) {

        vector<vector<int>> pyramid;
        istringstream iss{line};
        int value;
        vector<int> top;
        while (iss >> value) { top.push_back(value); }
        pyramid.push_back(top);

        while (true) {
            bool finish = true;
            vector<int> back = pyramid.back();
            vector<int> bottom;
            int sizeBack = back.size();
            for (int i = 1; i < sizeBack; ++i) {
                bottom.push_back(back[i] - back[i-1]);
                if (back[i] - back[i-1] != 0) finish = false;
            }
            pyramid.push_back(bottom);
            if (finish) break;
        }

        pyramid.back().push_back(0);

        for (int i = pyramid.size() - 2; i >= 0; --i) {
            pyramid[i].push_back(pyramid[i].back() + pyramid[i+1].back());
        }

        sum += pyramid[0].back();

    }

    cout << sum << endl;
}

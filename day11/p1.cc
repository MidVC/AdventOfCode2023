#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    // read map, expand vertical
    vector<vector<char>> map;
    char c;
    vector<char> pushThis;
    bool needHorizontalExpand = true;
    vector<bool> needVerticalExpand;
    bool firstLine = true;
    int charIndex = 0;
    while (cin.get(c)) {
        if (c == '\n') {
            map.push_back(pushThis);
            if (needHorizontalExpand) {
                map.push_back(pushThis);
            }
            pushThis.clear();
            needHorizontalExpand = true;
            firstLine = false;
            charIndex = 0;
        }
        else {
            pushThis.push_back(c);
            if (firstLine) {
                needVerticalExpand.push_back(true);
            }
            if (c != '.') {
                needHorizontalExpand = false;
                needVerticalExpand[charIndex] = false;
            }
            ++charIndex;
        }
    }

    // expand vertical
    int offset = 0;
    for (int i = 0; i+offset < needVerticalExpand.size(); ++i) {
        if (needVerticalExpand[i+offset]) {
            for (int j = 0; j < map.size(); ++j) {
                map[j].insert(map[j].begin()+i, '.');
            }
            --offset;
            ++i;
        }
    }


    // get all star poses
    vector<pair<int, int>> starPoses;
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[0].size(); ++j) {
            if (map[i][j] == '#') starPoses.push_back(make_pair(i, j));
        }
    }

    // calculate poses
    int sum = 0;
    for (int i = 0; i < starPoses.size(); ++i) {
        for (int j = i+1; j < starPoses.size(); ++j) {
            sum += abs(starPoses[i].first - starPoses[j].first) + abs(starPoses[i].second - starPoses[j].second);
        }
    }

    cout << sum << endl;
}

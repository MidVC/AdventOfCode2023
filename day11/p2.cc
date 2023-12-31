#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    // read map, expand vertical
    vector<vector<char>> map;
    char c;
    vector<char> pushThis;
    vector<bool> needHorizontalExpand;
    vector<bool> needVerticalExpand;
    int lineIndex = 0;
    int charIndex = 0;
    while (cin.get(c)) {
        if (c == '\n') {
            map.push_back(pushThis);
            pushThis.clear();
            ++lineIndex;
            charIndex = 0;
        }
        else {
            pushThis.push_back(c);
            if (charIndex == 0) needHorizontalExpand.push_back(true);
            if (lineIndex == 0) needVerticalExpand.push_back(true);
            if (c != '.') {
                needHorizontalExpand[lineIndex] = false;
                needVerticalExpand[charIndex] = false;
            }
            ++charIndex;
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
    long int sum = 0;
    for (int i = 0; i < starPoses.size(); ++i) {
        for (int j = i+1; j < starPoses.size(); ++j) {
            // calculate horizontal distance
            int distance = 0;

            int horiMin = min(starPoses[i].first, starPoses[j].first);
            int horiMax = max(starPoses[i].first, starPoses[j].first);
            if (horiMin != horiMax) distance += 1;
            for (int k = horiMin + 1; k < horiMax; ++k) {
                if (needHorizontalExpand[k]) distance += 1000000;
                else distance += 1;
            }

            // calculate vertical distance
            int verMin = min(starPoses[i].second, starPoses[j].second);
            int verMax = max(starPoses[i].second, starPoses[j].second);
            if (verMax != verMin) distance += 1;
            for (int k = verMin + 1; k < verMax; ++k) {
                if (needVerticalExpand[k]) distance += 1000000;
                else distance += 1;
            }

            // cout << i << ' ' << j << ' ' << distance << endl;
            sum += distance;
        }
    }

    cout << sum << endl;
}

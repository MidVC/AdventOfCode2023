#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    string instruction;
    getline(cin, instruction);

    string line;
    getline(cin, line);
    map<string, pair<string, string>> network;
    vector<string> curPoses;
    while (getline(cin, line)) {
        string cur = line.substr(0, 3);
        string left = line.substr(7, 3);
        string right = line.substr(12, 3);
        network.insert(make_pair(cur, make_pair(left, right)));
        if (cur.back() == 'A') curPoses.push_back(cur);
    }

    vector<int> cycles;
    int len = instruction.length();
    for ( auto &p : curPoses ) {
        string curPose = p;
        int step = 0, i = 0;
        while (i < len) {
            char instr = instruction[i];
            auto it = network.find(curPose);
            if (instr == 'L') curPose = it->second.first;
            else if (instr == 'R') curPose = it->second.second;
            else throw runtime_error("huh\n");
            ++step;
            if (curPose.back() == 'Z') break;
            ++i;
            if (i == len) i = 0;
        }
        cycles.push_back(step);
    }

    // for (auto &c : cycles) { cout << c << endl; }

    long long lcm = cycles[0];
    int cycleLen = cycles.size();
    for (int i = 1; i < cycleLen; ++i) {
        long long next = cycles[i];
        lcm = (lcm * next) / gcd(lcm, next);
    }

    cout << lcm << endl;
}

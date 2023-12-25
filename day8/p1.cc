#include <sstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string instruction;
    getline(cin, instruction);

    string line;
    getline(cin, line);
    map<string, pair<string, string>> network;
    while (getline(cin, line)) {
        string cur = line.substr(0, 3);
        string left = line.substr(7, 3);
        string right = line.substr(12, 3);
        network.insert(make_pair(cur, make_pair(left, right)));
    }

    int len = instruction.length();
    int steps = 0;
    int i = 0;
    string curPos = "AAA";
    while (i < len) {
        char instr = instruction[i];
        auto it = network.find(curPos);
        if (instr == 'L') curPos = it->second.first;
        else if (instr == 'R') curPos = it->second.second;
        else throw runtime_error("huh\n");
        ++steps;
        if (curPos == "ZZZ") break;
        ++i;
        if (i == len) i = 0;
    }

    cout << steps << endl;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> pipes;
    string line;
    while (getline(cin, line)) { pipes.push_back(line); }

    int x = 0, y = 0;
    int xLen = pipes[0].length();
    int yLen = pipes.size();
    for (int i = 0; i < yLen; ++i) {
        for (int j = 0; j < xLen; ++j) {
            if (pipes[i][j] == 'S') {
                y = i;
                x = j;
            }
        }
    }

    int loopLen = 1;
    int preX = x, preY = y;
    x += 1;
    while (pipes[y][x] != 'S') {
        if (pipes[y][x] == '|') {
            if (preY > y) {
                preY = y;
                --y;
            } else {
                preY = y;
                ++y;
            }
        }
        else if (pipes[y][x] == '-') {
            if (preX > x) {
                preX = x;
                --x;
            } else {
                preX = x;
                ++x;
            }
        }
        else if (pipes[y][x] == 'L') {
            if (preY < y) {
                preY = y;
                ++x;
            } else {
                preX = x;
                --y;
            }
        }
        else if (pipes[y][x] == 'J') {
            if (preY < y) {
                preY = y;
                --x;
            } else {
                preX = x;
                --y;
            }
        }
        else if (pipes[y][x] == '7') {
            if (preY > y) {
                preY = y;
                --x;
            } else {
                preX = x;
                ++y;
            }
        }
        else if (pipes[y][x] == 'F') {
            if (preY > y) {
                preY = y;
                ++x;
            } else {
                preX = x;
                ++y;
            }
        }
        else throw runtime_error("huh");
        ++loopLen;
    }

    cout << loopLen/2 << endl;
    
}

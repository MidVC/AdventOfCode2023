#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> pipes;
    string line;
    while (getline(cin, line)) { pipes.push_back(line); }

    // create a vector that only contains our loop
    vector<vector<char>> myLoop;
    myLoop.resize(pipes.size(), vector<char>(pipes[0].length(), '.'));

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

    int preX = x, preY = y;
    myLoop[y][x] = pipes[y][x];
    x += 1;
    while (pipes[y][x] != 'S') {
        myLoop[y][x] = pipes[y][x];
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
    }

    for (int i = 0; i < myLoop.size(); ++i) {
        for (int j = 0; j < myLoop[0].size(); ++j) {
            cout << myLoop[i][j];
        }
        cout << endl;
    }
    
    int count = 0;

    for (int i = 0; i < pipes.size(); ++i) {
        for (int j = 0; j < pipes[0].length(); ++j) {
            if (myLoop[i][j] == '.') {
                bool enclosed = false;
                char previous = 0;
                for (int k = 0; k < j; ++k) {
                    if (myLoop[i][k] == '|') enclosed = !enclosed;
                    else if (myLoop[i][k] == 'F') previous = 'F';
                    else if (myLoop[i][k] == 'L') previous = 'L';
                    else if (myLoop[i][k] == 'J' && previous != 'L') enclosed = !enclosed;
                    else if (myLoop[i][k] == '7' && previous != 'F') enclosed = !enclosed;
                    else if (myLoop[i][k] == 'S') previous = 'F';
                }
                if (enclosed) {
                    ++count;
                }
            }
        }
    }

    cout << count << endl;
    
}

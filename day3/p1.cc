#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Num {
  public:
    int row;
    int colStart;
    int colEnd;
    int value;
    explicit Num(int r, int cs, int ce, int v): row{r}, colStart{cs}, colEnd{ce}, value{v} {}
};

int main() {
    string line;
    map<pair<int, int>, char> symbolMap;
    vector<Num> nums;
    // read nums and symbols
    int rowCount = 0;
    while (getline(cin, line)) {
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] <= '9' && line[i] >= '0') {
                int num = line[i] - '0';
                int colStart = i;
                int colEnd = i;
                ++i;
                while (line[i] <= '9' && line[i] >= '0') {
                    num *= 10;
                    num += line[i] - '0';
                    colEnd = i;
                    ++i;
                }
                nums.push_back(Num(rowCount, colStart, colEnd, num));
                --i;
            }
            else if (line[i] != '.') {
                symbolMap.insert(make_pair(make_pair(rowCount, i), line[i]));
            }
        }
        ++rowCount;
    }

    // calculate sum
    int sum = 0;
    for ( auto &n : nums ) {
        for (int i = n.colStart-1; i <= n.colEnd+1; ++i) {
            auto it = symbolMap.find(make_pair(n.row-1, i));
            if (it != symbolMap.end()) {
                sum += n.value;
                break;
            }
            it = symbolMap.find(make_pair(n.row+1, i));
            if (it != symbolMap.end()) {
                sum += n.value;
                break;
            }
            if (i == n.colStart-1 || i == n.colEnd+1) {
                it = symbolMap.find(make_pair(n.row, i));
                if (it != symbolMap.end()) {
                    sum += n.value;
                    break;
                }
            }
        }
    }

    cout << sum << endl;
}

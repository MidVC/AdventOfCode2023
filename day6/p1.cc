#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Race {
  public:
    int time = 0;
    int distance = 0;
};

int main() {
    vector<Race> allRaces;
    string line;
    string garbage;

    // times
    getline(cin, line);
    istringstream times{line};
    times >> garbage;
    int value;
    while (times >> value) {
        allRaces.push_back(Race());
        allRaces.back().time = value;
    }

    // distances
    getline(cin, line);
    istringstream distances{line};
    distances >> garbage;
    for ( auto &r : allRaces ) {
        distances >> value;
        r.distance = value;
    }

    int mult = 1;
    for ( auto &r : allRaces ) {
        // binary search
        int left = 0;
        int right = r.time / 2;

        while (left <= right) {
            // if (left == right) {
            //     if (left * (r.time - left) > r.distance) {
            //         int ways = r.time - 2*(left-1);
            //         mult *= ways;
            //     }
            // }
            if (left == right - 1) {
                if (right * (r.time - right) > r.distance) {
                    int ways = r.time - 2*left - 1;
                    mult *= ways;
                    // cout << ways << endl;
                    break;
                }
                else {
                    mult = 0;
                    cout << mult << endl;
                    return 0;
                }
            }
            else {
                int middle = (left+right) / 2;
                if (middle * (r.time - middle) > r.distance) {
                    right = middle;
                }
                else {
                    left = middle;
                }
            }
        }

    }

    cout << mult << endl;

}

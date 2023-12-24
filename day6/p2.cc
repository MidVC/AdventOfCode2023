#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Race {
  public:
    long int time = 0;
    long int distance = 0;
};

int main() {
    Race theRace;
    string line;
    string garbage;

    // times
    getline(cin, line);
    istringstream times{line};
    times >> garbage;
    string value;
    while (times >> value) {
        for (int i = 0; i < value.length(); ++i) {
            theRace.time *= 10;
            theRace.time += value[i] - '0';
        }
    }

    // distances
    getline(cin, line);
    istringstream distances{line};
    distances >> garbage;
    while (distances >> value) {
        for (int i = 0; i < value.length(); ++i) {
            theRace.distance *= 10;
            theRace.distance += value[i] - '0';
        }
    }

    int mult = 1;
    auto &r = theRace;
    // cout << r.time << " " << r.distance << endl;
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
                if (r.time - right > r.distance / right) {
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
                if (r.time - middle > r.distance / middle) {
                    right = middle;
                }
                else {
                    left = middle;
                }
            }
        }


    cout << mult << endl;

}

#include <string>
#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int firstDigit = 0;
    int secondDigit = 0;
    string line;
    while (getline(cin, line)) {
        int len = line.length();

        // find the first string
        for (int i = 0; i < len; ++i) {
            if (line[i] >= '0' && line[i] <= '9') {
                firstDigit = line[i] - '0';
                break;
            }
        }

        // find the second digit
        for (int i = len-1; i >= 0; --i) {
            if (line[i] >= '0' && line[i] <= '9') {
                secondDigit = line[i] - '0';
                break;
            }
        }

        int thisNumber = firstDigit * 10 + secondDigit;
        sum += thisNumber;
        firstDigit = 0;
        secondDigit = 0;
    }

    cout << sum << endl;
}

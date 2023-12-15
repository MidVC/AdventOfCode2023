#include <string>
#include <iostream>
using namespace std;

int main() {
    char c;
    int sum = 0;

    while (cin >> c) {
        string s;
        s += c;
        while (cin >> c) {
            if (c == '\n') continue;
            if (c == ',') break;
            s += c;
        }

        // hash algorithm
        int hash = 0;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            hash += s[i];
            hash *= 17;
            hash %= 256;
        }
        sum += hash;
    }
    cout << sum << endl;
}

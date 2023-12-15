#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

int main() {
    char c;
    vector<vector<pair<string, int>>> hashmap;
    hashmap.resize(256);

    while (cin >> c) {
        string s;
        s += c;
        while (cin >> c) {
            if (c == '\n') continue;
            if (c == '=' || c == '-') break;
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

        if (c == '-') {
            int len = hashmap[hash].size();
            for (int i = 0; i < len; ++i) {
                if (hashmap[hash][i].first == s) {
                    hashmap[hash].erase(hashmap[hash].begin() + i);
                    i -= 1;
                    len = hashmap[hash].size();
                }
            }
        }
        else {
            cin >> c;
            if (c == '\n') cin >> c;
            int value = c - '0';
            bool flag = false;
            int thisLen = hashmap[hash].size();
            for (int i = 0; i < thisLen; ++i) {
                if (hashmap[hash][i].first == s) {
                    hashmap[hash][i].second = value;
                    flag = true;
                }
            }
            if (!flag) hashmap[hash].emplace_back(make_pair(s, value));
        }
        // consume ','
        cin >> c;
        if (c == '\n') cin >> c;
    }

    int sum = 0;
    for (int i = 0; i < 256; ++i) {
        int len = hashmap[i].size();
        for (int j = 0; j < len; ++j) {
            sum += (i+1) * (j+1) * hashmap[i][j].second;
        }
    }

    cout << sum << endl;
}

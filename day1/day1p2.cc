#include <string>
#include <iostream>
#include <vector>

using namespace std;

const string ONE = "one";
const string TWO = "two";
const string THREE = "three";
const string FOUR = "four";
const string FIVE = "five";
const string SIX = "six";
const string SEVEN = "seven";
const string EIGHT = "eight";
const string NINE = "nine";

int isLetterNumber(string s) {
    if (s == ONE) return 1;
    else if (s == TWO) return 2;
    else if (s == THREE) return 3;
    else if (s == FOUR) return 4;
    else if (s == FIVE) return 5;
    else if (s == SIX) return 6;
    else if (s == SEVEN) return 7;
    else if (s == EIGHT) return 8;
    else if (s == NINE) return 9;
    return -1;
}

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
            if (i >= 2) {
                string len3; 
                len3 = line[i-2];
                len3 += line[i-1];
                len3 += line[i];
                int letterNum = isLetterNumber(len3);
                if (letterNum != -1) {
                    firstDigit = letterNum;
                    break;
                }
            }
            if (i >= 3) {
                string len4; 
                len4 = line[i-3];
                len4 += line[i-2];
                len4 += line[i-1];
                len4 += line[i];
                int letterNum = isLetterNumber(len4);
                if (letterNum != -1) {
                    firstDigit = letterNum;
                    break;
                }
            }
            if (i >= 4) {
                string len5; 
                len5 = line[i-4];
                len5 += line[i-3];
                len5 += line[i-2];
                len5 += line[i-1];
                len5 += line[i];
                int letterNum = isLetterNumber(len5);
                if (letterNum != -1) {
                    firstDigit = letterNum;
                    break;
                }
            }
        }

        // find the second digit
        for (int i = len-1; i >= 0; --i) {
            if (line[i] >= '0' && line[i] <= '9') {
                secondDigit = line[i] - '0';
                break;
            }
            if (i >= 2) {
                string len3; 
                len3 = line[i-2];
                len3 += line[i-1];
                len3 += line[i];
                int letterNum = isLetterNumber(len3);
                if (letterNum != -1) {
                    secondDigit = letterNum;
                    break;
                }
            }
            if (i >= 3) {
                string len4; 
                len4 = line[i-3];
                len4 += line[i-2];
                len4 += line[i-1];
                len4 += line[i];
                int letterNum = isLetterNumber(len4);
                if (letterNum != -1) {
                    secondDigit = letterNum;
                    break;
                }
            }
            if (i >= 4) {
                string len5; 
                len5 = line[i-4];
                len5 += line[i-3];
                len5 += line[i-2];
                len5 += line[i-1];
                len5 += line[i];
                int letterNum = isLetterNumber(len5);
                if (letterNum != -1) {
                    secondDigit = letterNum;
                    break;
                }
            }
        }

        int thisNumber = firstDigit * 10 + secondDigit;
        sum += thisNumber;
        firstDigit = 0;
        secondDigit = 0;
        cout << thisNumber << endl;
    }

    cout << sum << endl;
}

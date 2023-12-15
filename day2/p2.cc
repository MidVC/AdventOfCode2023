#include <string>
#include <iostream>
#include <sstream>
using namespace std;

const string RED = "red";
const string BLUE = "blue";
const string GREEN = "green";

int main() {
    string line;
    int sum = 0;
    while (getline(cin, line)) {
        int nRed = 0;
        int nBlue = 0;
        int nGreen = 0;
        
        string garbage;
        istringstream iss{line};
        int gameIndex = 0;

        //read game index
        if (!(iss >> garbage >> gameIndex >> garbage)) break;
        

        // read number and color of cubes
        // bool wantedGame = true;
        int nCubes;
        string cubeColor;
        while (iss >> nCubes >> cubeColor) {

            char nextChar = cubeColor.back();
            if (nextChar == ',' || nextChar == ';') {
                cubeColor.pop_back();
            }
            
            if (cubeColor == "red" && nCubes > nRed) nRed = nCubes;
            else if (cubeColor == "blue" && nCubes > nBlue) nBlue = nCubes;
            else if (cubeColor == "green" && nCubes > nGreen) nGreen = nCubes;

            // if ( nextChar != ',') {
            //     // check if this game is wanted
            //     if (nRed > 12 || nGreen > 13 || nBlue > 14) {
            //         wantedGame = false;
            //         break;
            //     }
            //     nRed = 0;
            //     nBlue = 0;
            //     nGreen = 0;
            // }
        }

        int power = nRed * nBlue * nGreen;
        sum += power;

        // if (wantedGame) {
        //     sum += gameIndex;
        // }
    }
    cout << sum << endl;
}
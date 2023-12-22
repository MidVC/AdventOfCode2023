#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Triple {
    long int dStart, sStart, rLen;
    explicit Triple(long int d, long int s, long int r): dStart{d}, sStart{s}, rLen{r} {}
};

int main () {
    string line, garbage;

    // read seeds
    getline(cin, line);
    istringstream seeds{line};
    seeds >> garbage;
    long int number;
    vector<long int> seedNumbers;
    while (seeds >> number) {
        seedNumbers.push_back(number);
    }

    // read seed-to-soil map
    vector<Triple> seedToSoil;
    getline(cin, line);
    getline(cin, line);
    while (getline(cin, line)) {
        if (line.empty()) continue;
        if (line == "soil-to-fertilizer map:") break;
        long int dStart, sStart, rLen;
        istringstream iss{line};
        iss >> dStart >> sStart >> rLen;
        seedToSoil.push_back(Triple(dStart, sStart, rLen));
    }

    // read soil-to-fertilizer map
    vector<Triple> soilToFertilizer;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        if (line == "fertilizer-to-water map:") break;
        long int dStart, sStart, rLen;
        istringstream iss{line};
        iss >> dStart >> sStart >> rLen;
        soilToFertilizer.push_back(Triple(dStart, sStart, rLen));
    }

    // read fertilizer-to-water map
    vector<Triple> fertilizerToWater;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        if (line == "water-to-light map:") break;
        long int dStart, sStart, rLen;
        istringstream iss{line};
        iss >> dStart >> sStart >> rLen;
        fertilizerToWater.push_back(Triple(dStart, sStart, rLen));
    }

    // read water-to-light map
    vector<Triple> waterToLight;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        if (line == "light-to-temperature map:") break;
        long int dStart, sStart, rLen;
        istringstream iss{line};
        iss >> dStart >> sStart >> rLen;
        waterToLight.push_back(Triple(dStart, sStart, rLen));
    }

    // read light-to-temperature map
    vector<Triple> lightToTemperature;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        if (line == "temperature-to-humidity map:") break;
        long int dStart, sStart, rLen;
        istringstream iss{line};
        iss >> dStart >> sStart >> rLen;
        lightToTemperature.push_back(Triple(dStart, sStart, rLen));
    }

    // read temperature-to-humidity map
    vector<Triple> temperatureToHumidity;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        if (line == "humidity-to-location map:") break;
        long int dStart, sStart, rLen;
        istringstream iss{line};
        iss >> dStart >> sStart >> rLen;
        temperatureToHumidity.push_back(Triple(dStart, sStart, rLen));
    }

    // read humidity-to-location map: map
    vector<Triple> humidityToLocation;
    while (getline(cin, line)) {
        if (line.empty()) break;
        long int dStart, sStart, rLen;
        istringstream iss{line};
        iss >> dStart >> sStart >> rLen;
        humidityToLocation.push_back(Triple(dStart, sStart, rLen));
    }

    // find smallest location number
    long int minLocation = 9223372036854775807;
    for ( auto &n : seedNumbers ) {

        long int curNumber = n;

        {// seed to soil
        for ( auto &t : seedToSoil ) {
            if (curNumber >= t.sStart && curNumber <= t.sStart+t.rLen) {
                curNumber = t.dStart + (curNumber - t.sStart);
                break;
            }
        }
        // auto soil = seedToSoil.find(n);
        // if (soil == seedToSoil.end()) nSoil = n;
        // else nSoil = soil->second;
        }

        {// soil to fert
        for ( auto &t : soilToFertilizer ) {
            if (curNumber >= t.sStart && curNumber <= t.sStart+t.rLen) {
                curNumber = t.dStart + (curNumber - t.sStart);
                break;
            }
        }
        }

        {// fert to water
        for ( auto &t : fertilizerToWater ) {
            if (curNumber >= t.sStart && curNumber <= t.sStart+t.rLen) {
                curNumber = t.dStart + (curNumber - t.sStart);
                break;
            }
        }
        }

        {// water to light
        for ( auto &t : waterToLight ) {
            if (curNumber >= t.sStart && curNumber <= t.sStart+t.rLen) {
                curNumber = t.dStart + (curNumber - t.sStart);
                break;
            }
        }
        }

        {// light to temp
        for ( auto &t : lightToTemperature ) {
            if (curNumber >= t.sStart && curNumber <= t.sStart+t.rLen) {
                curNumber = t.dStart + (curNumber - t.sStart);
                break;
            }
        }
        }

        {// temp to humid
        for ( auto &t : temperatureToHumidity ) {
            if (curNumber >= t.sStart && curNumber <= t.sStart+t.rLen) {
                curNumber = t.dStart + (curNumber - t.sStart);
                break;
            }
        }
        }

        {// humid to location
        for ( auto &t : humidityToLocation ) {
            if (curNumber >= t.sStart && curNumber <= t.sStart+t.rLen) {
                curNumber = t.dStart + (curNumber - t.sStart);
                break;
            }
        }
        }

        if (curNumber < minLocation) minLocation = curNumber;
    }

    cout << minLocation << endl;

}

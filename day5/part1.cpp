// list of linked lists for seeds and their paths
// maps are lists of mapEntry structs
// function to convert between categories
    // args: conversion type, input num
    // return: converted num

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <utility>

using std::vector;
using std::string;
using std::stringstream;
using std::getline;
using std::cout;
using std::endl;

struct mapEntry {
    long long destStart;
    long long sourceStart;
    long long range;
};

string categories[] = {"sts", "stf", "ftw", "wtl", "ltt", "tth", "htl"};

std::map<string, vector<mapEntry>> maps;

long long categoryConvert(string type, long long inputNum) {
    vector<mapEntry> conversionMap = maps[type];

    for (size_t i = 0; i < conversionMap.size(); i++) {
        if (inputNum >= conversionMap[i].sourceStart && inputNum <= conversionMap[i].sourceStart + conversionMap[i].range - 1) {
            return conversionMap[i].destStart + inputNum - conversionMap[i].sourceStart;
        }
    }

    return inputNum;
}

int main() {
    // read in file
    std::ifstream inputFile("input.txt");
    string line;
    vector<string> rawInput;
    while (getline(inputFile, line)) {
        rawInput.push_back(line);
    }
    inputFile.close();

    // start seed paths by reading first line
    stringstream ss(rawInput[0]);
    string token;

    getline(ss, token, ' ');

    vector<std::list<long long>> seedPaths;
    while (getline(ss, token, ' ')) {
        seedPaths.push_back({std::stoll(token)});
    }

    // read in conversion maps
    vector<vector<mapEntry>> conversionMaps;
    vector<std::pair<size_t, size_t>> mapIndices = {
        {3, 40},    // seedToSoil
        {42, 72},   // soilToFertilizer
        {74, 113},  // fertilizerToWater
        {115, 140}, // waterToLight
        {142, 159}, // lightToTemperature
        {161, 192}, // temperatureToHumidity
        {194, 237}  // humidityToLocation
    };

    for (const auto& indices : mapIndices) {
        vector<mapEntry> conversionMap;
        for (size_t i = indices.first; i < indices.second; i++) {
            stringstream ss(rawInput[i]);
            mapEntry entry;

            getline(ss, token, ' ');
            entry.destStart = std::stoll(token);
            getline(ss, token, ' ');
            entry.sourceStart = std::stoll(token);
            getline(ss, token, ' ');
            entry.range = std::stoll(token);

            conversionMap.push_back(entry);
        }
        conversionMaps.push_back(conversionMap);
    }

    maps = {
        {categories[0], conversionMaps[0]},
        {categories[1], conversionMaps[1]},
        {categories[2], conversionMaps[2]},
        {categories[3], conversionMaps[3]},
        {categories[4], conversionMaps[4]},
        {categories[5], conversionMaps[5]},
        {categories[6], conversionMaps[6]}
    };

    // convert each seed through all categories
    for (size_t i = 0; i < seedPaths.size(); i++) {
        for (size_t j = 0; j < categories->size(); j++) {
            seedPaths[i].push_back(categoryConvert(categories[j], seedPaths[i].back()));
        }
    }

    // print out seed paths for debugging
    for (size_t i = 0; i < seedPaths.size(); i++) {
        cout << "Seed " << i << ": ";
        for (auto it = seedPaths[i].begin(); it != seedPaths[i].end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    // why is seed path only 4???

    return 0;
}

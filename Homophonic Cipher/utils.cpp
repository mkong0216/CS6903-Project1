//
// Created by hvoid on 10/8/18.
//

#include "utils.hpp"
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Finding the letter frequency for the given plaintext
vector<int> getLetterFrequency (const string& text, int num_symbols) {
    vector<int> freqTable(num_symbols);
    for (size_t i = 0; i < text.length(); i++) {
        int index = (int)text[i];
        // If character is a space, set it to 0. Otherwise, set it to value between 1 and 26;
        index = (index == 32) ? 0 : index - 97 + 1;
        freqTable[index] += 1;
    }

    return freqTable;
}

// Finding the symbol frequency for the given ciphertext
vector<int> getSymbolFrequency(const vector<int>& ciphertext, int num_symbols) {
    vector<int> freqTable(num_symbols);
    for (size_t i = 0; i < ciphertext.size(); i++) {
        int index = ciphertext[i];
        freqTable[index] += 1;
    }

    return freqTable;
}

// Reading text file for Test One and inserting each plaintext into vector
vector<string> readTestOneFile () {
    ifstream file;
    file.open("test1_candidate_5_plaintexts.txt");

    vector<string> candidates;
    string line;

    if (!file) {
        cerr << "Unable to open file\n";
        exit(1);
    }

    while (getline(file, line)) {
        if (line.find("Candidate plaintext") == string::npos && line.length() != 1) {
            candidates.push_back(line);
        }
    }

    file.close();
    return candidates;
}


// Converting text file in one string of all 70 dictionary words
string readTestTwoFile () {
    ifstream file;
    string dictionary;
    string word;
    file.open("test2_candidate_70_english_words.txt");

    if (!file) {
        cerr << "Unable to openfile\n";
        exit(1);
    }

    while (file >> word) {
        dictionary += word + " ";
    }

    file.close();
    return dictionary;
}


// Ciphertext is made up of comma separated numbers between 0 and 105.
// This function parses ciphertext into a vector containing the numbers found in the ciphertext.
vector<int> parseCiphertext(const string& s) {
    vector<int> cipherSymbols;
    char delimiter = ',';
    string symbol;
    std::istringstream tokenStream(s);
    while (getline(tokenStream, symbol, delimiter)) {
        cipherSymbols.push_back(stoi(symbol));
    }
    return cipherSymbols;
}



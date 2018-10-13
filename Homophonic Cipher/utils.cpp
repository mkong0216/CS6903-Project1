//
// Created by hvoid on 10/8/18.
//

#include "utils.hpp"
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
    file.open("./test1_candidate_5_plaintexts.txt");

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
vector<int> parseCiphertext(string cipher_msg){
    vector<int> ciphertext;
    string tmp = "";
    for(int i = 0; i <= cipher_msg.length(); i++){
        if(cipher_msg[i] != ',' && cipher_msg[i] != '\0'){
            tmp += cipher_msg[i];
        }else{
            ciphertext.push_back(stoi(tmp));
            tmp = "";
        }
    }
    return ciphertext;
}

vector<string> getInputs(){
    return {"dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu",
            "rereads predestines equippers cavitation bimolecular lucubrations cabin bettas quiverer prussians cosigner dressier bended dethronement inveigled davenport establish ganges rebroadcast supered bastiles willable abetted motionlessness demonic flatter bunyan securely tippiest tongue aw cotyledonal roomettes underlies miffs inducement overintellectually fertilize spasmodic bacchanal birdbrains decoct snakebite galliard boson headmistress unextended provence weakling pirana fiend lairds argils comma",
            "trawling responsiveness tastiest pulsed restamps telescoping pneuma lampoonist divas theosophists pustules checkrowed compactor conditionals envy hairball footslogs wasteful conjures deadfall stagnantly procure barked balmier bowery vagary beaten capitalized undersized towpath envisages thermoplastic rationalizers professions workbench underarm trudger icicled incisive oilbirds citrins chambrays ungainliness weazands prehardened dims determinants fishskin cleanable henceforward misarranges fine ",
            "dean iller playbooks resource anesthetic credibilities nonplus tzetzes incursions stooged envelopments girdling risibility thrum repeaters catheterizing misbestowed cursing malingerers ensconces lippiest accost superannuate slush opinionated rememberer councils mishandling drivels juryless slashers tangent roistering scathing apprenticing fleabite sault achier quantize registrable nobbler sheaf natantly kashmirs dittoes scanned emissivity iodize dually refunded portliest setbacks eureka needines",
            "mammate punners octette asylum nonclinically trotters slant collocation cardiology enchants ledge deregulated bottommost capsulate biotechnologies subtended cloddiest training joneses catafalque fieldmice hostels affect shrimper differentiations metacarpus amebas sweeter shiatsu oncoming tubeless menu professing apostatizing moreover eumorphic casked euphemistically programmability campaniles chickpea inactivates crossing defoggers reassures tableland doze reassembled striate precocious noncomba"
    };
}




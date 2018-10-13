//
// Created by hvoid on 10/9/18.
//

// Testing ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``
#include "HomophonicCipherMatrix.hpp"
#include "RandomKeyInit.hpp"
#include "utils.hpp"

void do_test_one();

int main(void){
    bool done = false;

    while(!done){
        string test_num = "";

        cout << "Which test is being run? Enter 1 for test 1, 2 for test 2, or 0 for no more tests. \n";
        getline(cin, test_num);
        cin.ignore();

        if(test_num == "1"){
            do_test_one();
        }else if(test_num == "2"){

        }else{
            done = true;
        }
    }
    return 0;
}


void do_test_one(void){
    Encryption enc_test;
    Encryption enc;

    enc.setPermutation();
    enc_test.setKeyPermutation();

    string cipher_str;
    string ciphertext_file;
    vector<int> freqSymbolTable;
    RandomKeyInit keyGen;


    cout << "Enter the ciphertext:\n";
    getline(cin, cipher_str);
    vector<int> cipher_parsed = parseCiphertext(cipher_str);
    freqSymbolTable = getSymbolFrequency(cipher_parsed, 106);


    DigramFreqMatrix plain_matrix_1(27, 27, 0);
    DigramFreqMatrix plain_matrix_2(27, 27, 0);
    DigramFreqMatrix plain_matrix_3(27, 27, 0);
    DigramFreqMatrix plain_matrix_4(27, 27, 0);
    DigramFreqMatrix plain_matrix_5(27, 27, 0);


    string plain_1 = "dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu";
    string plain_2 = "rereads predestines equippers cavitation bimolecular lucubrations cabin bettas quiverer prussians cosigner dressier bended dethronement inveigled davenport establish ganges rebroadcast supered bastiles willable abetted motionlessness demonic flatter bunyan securely tippiest tongue aw cotyledonal roomettes underlies miffs inducement overintellectually fertilize spasmodic bacchanal birdbrains decoct snakebite galliard boson headmistress unextended provence weakling pirana fiend lairds argils comma";
    string plain_3 = "trawling responsiveness tastiest pulsed restamps telescoping pneuma lampoonist divas theosophists pustules checkrowed compactor conditionals envy hairball footslogs wasteful conjures deadfall stagnantly procure barked balmier bowery vagary beaten capitalized undersized towpath envisages thermoplastic rationalizers professions workbench underarm trudger icicled incisive oilbirds citrins chambrays ungainliness weazands prehardened dims determinants fishskin cleanable henceforward misarranges fine";
    string plain_4 = "dean iller playbooks resource anesthetic credibilities nonplus tzetzes incursions stooged envelopments girdling risibility thrum repeaters catheterizing misbestowed cursing malingerers ensconces lippiest accost superannuate slush opinionated rememberer councils mishandling drivels juryless slashers tangent roistering scathing apprenticing fleabite sault achier quantize registrable nobbler sheaf natantly kashmirs dittoes scanned emissivity iodize dually refunded portliest setbacks eureka needines";
    string plain_5 = "mammate punners octette asylum nonclinically trotters slant collocation cardiology enchants ledge deregulated bottommost capsulate biotechnologies subtended cloddiest training joneses catafalque fieldmice hostels affect shrimper differentiations metacarpus amebas sweeter shiatsu oncoming tubeless menu professing apostatizing moreover eumorphic casked euphemistically programmability campaniles chickpea inactivates crossing defoggers reassures tableland doze reassembled striate precocious noncomba";

    plain_matrix_1.setFrequencyValues(plain_1);
    plain_matrix_2.setFrequencyValues(plain_2);
    plain_matrix_3.setFrequencyValues(plain_3);
    plain_matrix_4.setFrequencyValues(plain_4);
    plain_matrix_5.setFrequencyValues(plain_5);
    vector<DigramFreqMatrix> plain_matrix_vec;

    plain_matrix_vec.push_back(plain_matrix_1);
    plain_matrix_vec.push_back(plain_matrix_2);
    plain_matrix_vec.push_back(plain_matrix_3);
    plain_matrix_vec.push_back(plain_matrix_4);
    plain_matrix_vec.push_back(plain_matrix_5);


    HomophonicCipherMatrix cipher_matrix;
    cipher_matrix.update_cipher_bigram_matrix(cipher_parsed);


    int final_score = 100000;
    int final_index = -1;
    for(int n = 0; n < plain_matrix_vec.size(); n++){
        int temp_final = 100000;
        for(int i = 0; i < 6000; i++){
            enc_test.setKeyPermutation();
            int score = cipher_matrix.inner_climb_hill(plain_matrix_vec[n], enc_test.putative_key);
            if(score < temp_final){
                temp_final = score;
                cout << score << endl;
            }
        }
        if(final_score > temp_final){
            final_score = temp_final;
            final_index = n;
        }
    }
    cout << endl << final_score << " " << final_index << endl;
}




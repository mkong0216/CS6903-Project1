//
// Created by hvoid on 10/9/18.
//

// Testing ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``
#include "HomophonicCipherMatrix.hpp"
//#include "RandomKeyInit.hpp"
#include "utils.hpp"


int main(void){
    string cipher_str;
    string ciphertext_file;
    Encryption enc;
    Encryption enc_test;
    enc_test.setPermutation();
    enc.setPermutation();

    cout << "Enter the ciphertext:\n";
    getline(cin, ciphertext_file);
    ifstream cipher_file(ciphertext_file);
    getline(cipher_file, cipher_str);
    vector<int> cipher_parsed = parseCiphertext(cipher_str);

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

    //vector<int> cipher = enc.Encrypt(plain_2, 13);
    //enc.output_cipher_to_file();
    vector<int> cipher = {83,74,18,64,48,39,30,57,63,18,40,39,98,30,76,29,17,59,60,33,45,102,86,78,63,75,66,65,60,2,42,9,22,103,62,15,62,103,96,20,89,43,19,51,91,26,40,12,86,49,88,18,2,24,86,12,86,43,83,69,81,103,91,53,27,61,42,69,43,29,37,47,43,41,62,14,88,30,89,102,86,29,22,41,65,59,44,61,63,83,86,73,60,29,48,94,27,57,42,92,54,103,84,53,40,82,58,39,18,74,54,54,35,59,65,25,43,41,37,39,45,39,58,39,40,97,1,44,91,53,45,51,98,53,76,25,35,94,22,74,35,105,49,59,72,57,72,48,22,74,50,75,91,82,14,36,40,27,81,48,43,26,38,27,1,68,84,69,37,105,40,60,4,44,40,43,65,92,48,39,42,15,60,97,104,73,86,75,93,44,98,39,68,43,48,27,6,29,49,74,60,58,11,78,26,26,9,43,24,74,21,88,43,64,14,76,45,39,104,51,96,95,19,85,37,24,45,54,73,20,45,60,73,68,72,41,34,85,37,29,42,77,28,49,32,76,6,64,82,52,43,70,50,8,48,20,25,54,66,12,86,65,93,26,46,5,81,29,63,75,35,59,30,76,47,81,91,53,84,70,93,47,32,10,36,12,80,62,46,24,93,39,80,94,48,26,47,83,91,85,34,41,97,97,98,30,33,70,50,39,98,44,49,78,98,60,21,51,38,3,28,27,61,103,37,39,86,12,40,51,93,20,95,77,91,22,93,83,35,94,95,64,26,26,93,12,81,70,69,49,49,8,52,3,93,18,81,29,24,103,79,64,31,30,63,15,27,51,91,39,35,12,13,43,88,12,42,0,32,53,71,24,89,43,38,82,72,43,18,69,19,53,60,21,72,59,42,92,42,97,4,54,37,71,7,41,43,103,81,74,25,105,32,24,26,103,9,65,72,47,43,92,60,87,37,89,1,64,32,39,34,29,73,95,83,41,54,27,5,70,37,74,23,6,98,94,72,16,72,68,63,65,80,22,45,94,42,16,2,10,93,32,7,26,19,53,84,36,63,103,18,69,50,48,77,3,19,74,50,39,36,26,48,29,82,39,60,2,69,65,84,29,24,60,89,12,91,51,34,9};

    plain_matrix_1.setFrequencyValues(plain_1);
    plain_matrix_2.setFrequencyValues(plain_2);
    plain_matrix_3.setFrequencyValues(plain_3);
    plain_matrix_4.setFrequencyValues(plain_4);
    plain_matrix_5.setFrequencyValues(plain_5);


    HomophonicCipherMatrix cipher_matrix;

    cout << "Here\n";
    cipher_matrix.update_cipher_bigram_matrix(cipher);

    int final_score_1 = 100000;
    for(int i = 0; i < 6000; i++){
        enc_test.setPermutation();
        int score = cipher_matrix.inner_climb_hill(plain_matrix_2, enc_test.putative_key);
        if(score < final_score_1){
            final_score_1 = score;
            cout << score << endl;
        }
    }
    cout << endl << final_score_1;
    return 0;
}
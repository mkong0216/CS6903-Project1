//
// Created by hvoid on 10/9/18.
//

// Testing ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``
#include "HomophonicCipherMatrix.hpp"

//#include "utils.hpp"


int main(void){
    Encryption enc;
    enc.setPermutation();
    int **matrix_tmp = new int*[27];
    int *final_key = new int[106];

    for(int i = 0; i < 27; i++){
        matrix_tmp[i] = new int[27];
        for(int j = 0; j < 27; j++){
            matrix_tmp[i][j] = 0;
        }
    }


    DigramFreqMatrix plain_matrix(27, 27, 0);
    string plain = "dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu";

    vector<int> cipher = enc.Encrypt(plain, 5);
    plain_matrix.setFrequencyValues(plain);
    HomophonicCipherMatrix cipher_matrix;

    cout << "Here\n";
    cipher_matrix.update_cipher_bigram_matrix(cipher);

    cipher_matrix.decrypt_cipher_to_matrix(enc.putative_key, matrix_tmp);

    cout << "here 2\n";
    int final_score = 10000;
    for(int i = 0; i < 50000; i++){
        enc.setPermutation();
        int score = cipher_matrix.inner_climb_hill(plain_matrix, enc.putative_key);
        if(score < final_score){
            for(int j = 0; j < 106; j++){
                final_key[j] = enc.putative_key[j];
            }
            final_score = score;
        }
    }
    cipher_matrix.display_decrypt_text(cipher, final_key);
    cout << endl << final_score;

    for(int i = 0; i < 27; i++){
        delete[] matrix_tmp[i];
    }
    enc.display_final_key();
    delete[] matrix_tmp;
    delete[] final_key;
    return 0;
}
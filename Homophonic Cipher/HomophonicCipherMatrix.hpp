//
// Created by hvoid on 10/8/18.
//

#ifndef PROJ_WORK_SPACE_HOMOPHONIC_CIPHER_MATRIX_HPP
#define PROJ_WORK_SPACE_HOMOPHONIC_CIPHER_MATRIX_HPP

#include <iostream>

#include "DigramFreqMatrix.hpp"
using namespace std;

class HomophonicCipherMatrix: protected DigramFreqMatrix {
private:
    int *putative_key;
    int **matrix;
    const int CIPHER_COUNT = 106;

public:

    HomophonicCipherMatrix();
    ~HomophonicCipherMatrix();

    //do inner climb hill and return new least matrix score
    int inner_climb_hill(DigramFreqMatrix &plain_matrix, int *putative_key_in);

    //freq_out, index 0 is space, index 1-26 is a-z
    void get_letter_freq_from_matrix(int freq_out[27]);
    void update_cipher_bigram_matrix(vector<int> cipher_text);
    void attack_cipher(const DigramFreqMatrix &plain_matrix, vector<int> cipher_text);


};
#endif //PROJ_WORK_SPACE_HOMOPHONIC_CIPHER_MATRIX_HPP

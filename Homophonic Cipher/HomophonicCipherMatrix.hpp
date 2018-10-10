//
// Created by hvoid on 10/8/18.
//

#ifndef PROJ_WORK_SPACE_HOMOPHONIC_CIPHER_MATRIX_HPP
#define PROJ_WORK_SPACE_HOMOPHONIC_CIPHER_MATRIX_HPP

#include <iostream>
#include "DigramFreqMatrix.hpp"
#include "utils.hpp"

using namespace std;

class HomophonicCipherMatrix {
private:
    int *putative_key;
    //this matrix is to store bigram of cipher text
    int **matrix;
    const int CIPHER_COUNT = 106;

    //determine which two keys should be swapped
    //void locate_swap(vector<int> plain_freq, int matrix_decrypt[27][27]);

    //modify cur putative key and corresponding decrypt matrix
    void swap_putative_key(int swap_i, int swap_j, int* cur_putative_key, int** matrix_decrypt);

public:

    HomophonicCipherMatrix();
    ~HomophonicCipherMatrix();

    //do inner climb hill and return new least matrix score
    int inner_climb_hill(DigramFreqMatrix &plain_matrix, int *putative_key_in);

    //freq_out, index 0 is space, index 1-26 is a-z
    void get_letter_freq_from_matrix(int** matrix_in, int freq_out[27]);

    //calculate bigram of cipher text
    void update_cipher_bigram_matrix(vector<int> cipher_text);

    //convert cipher text freq to plain text freq with cur putative key
    //the matrix_decrypt_out should be 27 by 27.
    void decrypt_cipher_to_matrix(int* cur_putative_key, int** matrix_decrypt_out);

    void attack_cipher(const DigramFreqMatrix &plain_matrix, vector<int> cipher_text);

    void display_decrypt_text(const vector<int>& cipher_text, int* final_key);


};
#endif //PROJ_WORK_SPACE_HOMOPHONIC_CIPHER_MATRIX_HPP

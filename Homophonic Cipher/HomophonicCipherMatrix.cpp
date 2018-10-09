//
// Created by hvoid on 10/8/18.
//

#include "HomophonicCipherMatrix.hpp"

HomophonicCipherMatrix::HomophonicCipherMatrix() {
    //the cipher count is the distinct cipher symbol
    putative_key = new int[CIPHER_COUNT];

    if(!putative_key){
        cout << "Error: Failed to new putative key\n";
    }

    matrix = new int*[CIPHER_COUNT];
    if(matrix){
        for(int i = 0; i < CIPHER_COUNT; i++){
            matrix[i] = new int[CIPHER_COUNT];
            if(matrix[i] == NULL){
                cout << "Error: Failed to new matrix\n";
                delete[] putative_key;
                for(int j = 0; j < i; j++){
                    delete[] matrix[j];
                }
                delete[] matrix;
                return;
            }
        }
    }else {
        cout << "Error: Failed to new matrix pointer\n";
        delete[] putative_key;
        return;
    }

    //initialize matrix and key
    for(int i= 0; i< CIPHER_COUNT; i++){
        putative_key[i] = -1;
        for(int j = 0; j < CIPHER_COUNT; j++){
            matrix[i][j] = 0;
        }
    }
}


HomophonicCipherMatrix::~HomophonicCipherMatrix() {
    for(int i = 0; i < cipher_count; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] putative_key;
}


void HomophonicCipherMatrix::get_letter_freq_from_matrix(int *freq_out) {
    //for(int i = 0; i < )
}


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
    for(int i = 0; i < CIPHER_COUNT; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] putative_key;
}


void HomophonicCipherMatrix::get_letter_freq_from_matrix(int** matrix_in, int *freq_out) {
    for(int i = 0; i < 27; i++){
        int row_sum = 0;
        for(int j = 0; j < 27; j++){
            row_sum += matrix_in[i][j];
        }
        freq_out[i] = row_sum;
    }
}

void HomophonicCipherMatrix::update_cipher_bigram_matrix(vector<int> cipher_text) {
    int prevSymbol, currSymbol;
    for (size_t i = 1; i < cipher_text.size(); i++) {
        prevSymbol = cipher_text[i-1];
        currSymbol = cipher_text[i];

        matrix[prevSymbol][currSymbol] += 1;
    }
}

void HomophonicCipherMatrix::decrypt_cipher_to_matrix(int *cur_putative_key, int** matrix_decrypt_out){
    if(!cur_putative_key){
        return;
    }

    for(int i = 0; i < 106; i++){
        for(int j = 0; j < 106; j++){
            matrix_decrypt_out[cur_putative_key[i]][cur_putative_key[j]] += matrix[i][j];
        }
    }
}
//
//void HomophonicCipherMatrix::locate_swap(vector<int> plain_freq, int **matrix_decrypt) {
//    int* decrypt_freq = new int[27];
//
//    if(!decrypt_freq){
//        cout << "Error: Failed to new int list in locate swap.\n";
//    }
//
//    get_letter_freq_from_matrix(matrix_decrypt, decrypt_freq);
//
//
//}



void HomophonicCipherMatrix::swap_putative_key(int swap_a, int swap_b, int* cur_putative_key, int** matrix_decrypt) {
    if (cur_putative_key == NULL){
        cout << "Error: Swapping putative key can not be null\n";
        return;
    }

    if(swap_a >= CIPHER_COUNT || swap_b >= CIPHER_COUNT || cur_putative_key[swap_a] == cur_putative_key[swap_b]){
        return;
    }

    //swap putative key
    int temp = cur_putative_key[swap_a];
    cur_putative_key[swap_a] = cur_putative_key[swap_b];
    cur_putative_key[swap_b] = temp;

    //update matrix decrypt with new key
    decrypt_cipher_to_matrix(cur_putative_key, matrix_decrypt);
}

int HomophonicCipherMatrix::inner_climb_hill(DigramFreqMatrix &plain_matrix, int *putative_key_in) {
    int** matrix_decrypt = new int*[27];
    int min_score = 100000, cur_score = 100000;
    if(!matrix_decrypt){
        cout << "Error: Failed to new matrix_decrypt\n";
        return -1;
    }

    for(int i=0; i < 27; i++){
        matrix_decrypt[i] = new int[27];
        if(matrix[i] == NULL) {
            cout << "Error: Failed to new matrix decrypt rows\n";
        }
    }

    if(putative_key_in == NULL) {
        cout << "Error: Invalid putative key in\n";
        return -1;
    }

    decrypt_cipher_to_matrix(putative_key_in, matrix_decrypt);
    cur_score = plain_matrix.computeMatrixScore(matrix_decrypt);

    if(cur_score > 1000) {
        //store cur putative key to temp one in case of undoing modification
        int *temp_key = new int[CIPHER_COUNT];
        if(temp_key == NULL){
            cout << "Error: Failed to new temp key\n";
            return -1;
        }

        for(int i = 0; i < CIPHER_COUNT; i++){
            temp_key[i] = putative_key_in[i];
        }

        min_score = cur_score;
        int old_matrix_decrypt[27][27];
        int changed = 1;
        int a = 0;
        int b = 0;

        for(int i = 1; i < CIPHER_COUNT; i++){
            for(int j = 0; (i+j) < CIPHER_COUNT; j++){
                if(changed){
                    //save changed matrix to old_matrix
                    for(int m = 0; m < 27; m++){
                        for(int n = 0; n < 27; n++){
                            old_matrix_decrypt[m][n] = matrix_decrypt[m][n];
                        }
                    }
                }

                //permutate putative key by swapping
                a = j;
                b = i+j;
                swap_putative_key(a, b, temp_key, matrix_decrypt);
                cur_score = plain_matrix.computeMatrixScore(matrix_decrypt);

                if(cur_score < min_score){
                    for(int num = 0; num < CIPHER_COUNT; num++){
                        putative_key_in[num] = temp_key[num];
                    }
                    min_score = cur_score;
                    changed = 1;
                }else{
                    //undo swapping
                    if(a >= CIPHER_COUNT || b >= CIPHER_COUNT || temp_key[a] == temp_key[b]){
                        continue;
                    }
                    int temp_val = temp_key[a];
                    temp_key[a] = temp_key[b];
                    temp_key[b] = temp_val;
                    changed = 0;
                    for(int i = 0; i < 27; i++){
                        for(int j = 0; j < 27; j++){
                            matrix_decrypt[i][j] = old_matrix_decrypt[i][j];
                        }
                    }
                }
            }
        }

    }

    return min_score;
}


void HomophonicCipherMatrix::display_decrypt_text(const vector<int>& cipher_text, int* final_key){
    for(int i = 0; i < cipher_text.size(); i++){
        int plain = final_key[cipher_text[i]];
        if(plain == 0){
            cout << " ";
        }else{
            cout << char(plain+96);
        }

    }
}




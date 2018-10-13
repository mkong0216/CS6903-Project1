//
// Created by hvoid on 10/8/18.
//

#ifndef PROJ_WORK_SPACE_UTILS_HPP
#define PROJ_WORK_SPACE_UTILS_HPP

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>


using namespace std;

vector<int> getSymbolFrequency(const vector<int>& ciphertext, int num_symbols);

vector<int> getLetterFrequency (const string& text, int num_symbols);

vector<string> readTestOneFile ();

string readTestTwoFile ();

vector<int> parseCiphertext(const string& str);

void display_decrypt_text(const vector<int>& cipher_text, int* final_key);

class Encryption{
    int* Table[27];
    vector<int> cipher;


    int schedule_func(int version, int j, int L){
        switch(version){
            case 15:
                return j * j / 10 + (j ^ L);
            case 14:
                return j * j * j;
            case 13:
                return (j * j) ^ 98347;
            case 12:
                return (j * j) ^ 12539;
            case 11:
                return (j * j) ^ 34519;
            case 10:
                return (j * j);
            case 9:
                return j ^ 499;
            case 8:
                return j ^ 373;
            case 7:
                return j ^ 251;
            case 6:
                return j ^ 137;
            case 5:
                return j ^ L ^ 499;
            case 4:
                return j ^ L ^ 137;
            case 3:
                return j ^ L ^ 251;
            case 2:
                return j ^ L ^ 373;
            case 1:
                return j ^ L;
            case 0:
            default:
                return j;
        }
    }


    void map_letter_key(){
        int S = 0;
        for(int i = 0; i < 27; i++){
            Table[i] = &putative_key[S];
            S += char_freq_freq[i];
        }
    }

public:
    int putative_key[106];
    char char_freq_char[27] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's','t', 'u', 'v', 'w', 'x', 'y', 'z'};
    int char_freq_freq[27] = {19, 7, 1, 2, 4, 10, 2, 2, 5, 6, 1, 1, 3, 2, 6, 6, 2, 1, 5, 5, 7, 2, 1, 2, 1, 2, 1};

    vector<int> Encrypt(string Msg, int version){
        int power = Msg.length();
        int putative_key[106];

        for(int i = 0; i < 106; i++){
            putative_key[i] = i;
        }

        setPermutation();
        map_letter_key();

        for(int i = 0; i < power; i++){
            char plain = Msg[i] == ' ' ? 0 : Msg[i] - 'a' + 1;
            int mod_num = schedule_func(version, i, power);
            mod_num = (mod_num % char_freq_freq[plain] + char_freq_freq[plain]) % char_freq_freq[plain];

            int cipher_tmp = Table[plain][mod_num];
            this->cipher.push_back(cipher_tmp);
        }
        cout << "Done Encryption.\n";
        return this->cipher;
    }

    void output_cipher_to_file(){
        ofstream cipher_file;
        cipher_file.open("ciphertext.txt");

        if(!cipher_file){
            cout << "Error: Unable to open ciphertext file.\n";
        }

        ostream_iterator<int> output_iterator(cipher_file, ",");
        copy(this->cipher.begin(), this->cipher.end(), output_iterator);
        cout << "Done Outputting Cipher.\n";
        cipher_file.close();
    }

    void setPermutation(){
        int count = 0;
        int char_index = 0;
        for(int i = 0 ; i < 106 ; ++i) {
            if(count == char_freq_freq[char_index]){
                count =0;
                char_index++;
            }
            putative_key[i] = char_index;
            count++;
        }
        int T = 5000;
        for(int i = 0 ; i < T ; ++i){
            int R = rand();
            int X = R % 106, Y = (R / 106) % 106;
            if(X != Y) swap(putative_key[X],putative_key[Y]);
        }
    }

    void display_final_key(){
        for(int i = 0; i < 106; i++){
            if(putative_key[i] == 0){
                cout << i << "-  -" << endl;
            }else{
                cout << i << " " << char(putative_key[i]+96) << endl;
            }
        }
    }
};



#endif //PROJ_WORK_SPACE_UTILS_HPP

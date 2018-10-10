//
// Created by hvoid on 10/9/18.
//
//compilation: g++ -o temp.out nathan_main.cpp utils.cpp RandomKeyInit.cpp
//to run: ./temp.out
//please compile and run when you finish a little bit

#include "RandomKeyInit.hpp"
#include "utils.hpp"

int main(void){
    string plain = "dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu";

    Encryption enc;
    enc.setPermutation();
    vector<int> cipher = enc.Encrypt(plain, 5);
    vector<int> cipher_freq = getSymbolFrequency(cipher, 106);

    RandomKeyInit key_gen;
    int* putative_key_out = new int[106];
    key_gen.GetPutativeKey(cipher, putative_key_out);

    for(int i = 0; i < 106; i++){
        if(putative_key_out[i] == 0){
            cout << i << " space" << endl;
        }else{
            cout << i << " " << char(putative_key_out[i]+96) << endl;
        }
    }
}
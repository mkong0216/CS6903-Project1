//
// Created by hvoid on 10/9/18.
//
//compilation: g++ -o temp.out nathan_main.cpp utils.cpp RandomKeyInit.cpp
//to run: ./temp.out
//please compile and run when you finish a little bit

#include "RandomKeyInit.hpp"
#include "utils.hpp"

using namespace std;

int main(void){
    string plain = "dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu";

    vector<int> cipher = {82,98,83,40,15,72,60,2,75,83,59,72,64,60,95,38,17,40,27,13,59,102,70,38,63,63,98,83,60,58,12,48,22,38,76,88,62,38,92,37,2,43,78,34,91,26,93,42,70,26,9,82,104,26,86,42,86,43,65,48,76,38,85,50,73,4,42,88,43,19,94,61,43,45,81,97,69,27,57,102,70,19,22,98,18,66,83,33,75,18,70,30,73,35,15,50,73,104,12,96,73,35,105,17,40,82,25,72,44,45,73,27,29,93,44,58,43,40,53,72,74,55,57,72,66,6,67,83,87,50,41,34,59,37,6,61,19,37,22,93,103,84,26,40,55,61,55,48,22,40,94,63,92,82,95,90,40,73,6,15,43,49,103,30,0,47,84,88,53,84,59,73,104,83,40,43,18,96,71,72,12,48,30,14,52,73,86,63,16,18,59,72,4,43,48,27,97,19,49,45,60,77,10,35,26,26,15,43,24,98,5,71,43,93,76,81,93,55,47,34,87,97,78,80,37,49,93,60,73,50,41,60,60,36,55,66,34,91,94,38,12,61,3,49,15,97,6,66,65,2,43,86,53,46,9,37,90,30,16,42,70,65,74,24,46,25,95,19,75,63,29,93,60,6,4,6,91,37,105,86,74,31,15,11,36,42,96,97,8,26,41,72,92,50,88,26,36,18,87,96,51,45,95,62,45,30,4,86,94,55,41,83,49,35,93,30,31,34,78,28,3,73,57,38,17,72,86,42,74,34,59,17,81,77,96,22,40,18,29,37,6,66,49,49,93,42,95,86,15,24,26,46,25,28,98,65,95,38,49,19,79,66,47,73,63,15,30,34,87,55,78,42,31,43,88,42,42,1,32,17,69,24,57,43,35,44,55,43,18,48,78,37,73,61,55,66,42,91,12,81,89,60,53,88,7,66,43,38,14,45,13,84,88,24,24,38,71,65,39,5,43,80,73,91,50,13,67,45,32,55,51,38,73,97,82,40,27,60,58,86,53,93,23,62,93,50,55,93,39,33,75,82,87,22,98,17,42,93,57,11,74,71,7,26,38,17,84,33,75,19,44,71,53,32,25,28,35,40,94,72,36,26,15,35,18,72,54,4,15,18,105,38,49,30,90,42,91,34,51,71};

    vector<int> cipher_freq = getSymbolFrequency(cipher, 106);

    RandomKeyInit key_gen;
    int* putative_key_out = new int[106];
    key_gen.GetPutativeKey(cipher_freq, putative_key_out);

    for(int i = 0; i < 106; i++){
        if(putative_key_out[i] == 0){
            cout << i << " space" << endl;
        }else{
            cout << i << " " << char(putative_key_out[i]+96) << endl;
        }
    }
}

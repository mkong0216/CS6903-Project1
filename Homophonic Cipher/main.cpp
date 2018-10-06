//
//  main.cpp
//  Homophonic Cipher
//
//  Created by Mandy Kong on 10/5/18.
//  Copyright © 2018 Mandy Kong. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    bool done = false;
    string ciphertext;
    string test_num;
    
    while (!done) {
        cout << "Enter the ciphertext:\n";
        getline(cin, ciphertext);
        cout << "Which test is being run? Enter 1 for test 1 and 2 for test 2. \n";
        getline(cin, test_num);
        
        if (test_num == "1") {
            cout << "Preparing candidate plaintexts.\n";
            done = true;
        } else if (test_num == "2") {
            cout << "Preparing dictionary words.\n";
            done = true;
        } else {
            cout << "That is an invalid test number. Please try again.\n";
            done = false;
        }
    }
    return 0;
}

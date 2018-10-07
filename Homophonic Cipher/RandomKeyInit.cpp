//
//  RandomKeyInit.cpp
//  CS6903 Project 1
//
//  Created by Nathan Mawby on 10/6/18.

#include "RandomKeyInit.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>
using namespace std;


// Constructor for getting an initial key
// Takes input of plaintext char frequency
RandomKeyInit::


int GetInitKey(std::vector<int> ciphertextFreq){
  //srand (time(NULL));
  //int randIndex;
  int initPutativeKey[106]={0};
  vector<float> ciphertextFreqPerc={0};
  float plaintextFreqPerc[27]={0};
  int sum=0;
  float tempPerc=0;
  int i=0;


  // hardcoded table of frequeny values given to us
  // na, nb, . . . , nz with na + nb + · · · + nz = n
  // array positioning: [<space>, a, b, c...y, z]
  int givenTableFreq[27] = {19,7,1,2,4,10,2,2,5,6,1,1,3,2,6,6,2,1,5,5,7,2,1,2,1,2,1};
  /*
  vector<pair<int,char>> charEngAvgFreq = {
    make_pair(19, char(32)),
    make_pair(7, 'a'),
    make_pair(1, 'b'),
    make_pair(2, 'c'),
    make_pair(4, 'd'),
    make_pair(10, 'e'),
    make_pair(2, 'f'),
    make_pair(2, 'g'),
    make_pair(5, 'h'),
    make_pair(6, 'i'),
    make_pair(1, 'j'),
    make_pair(1, 'k'),
    make_pair(3, 'l'),
    make_pair(2, 'm'),
    make_pair(6, 'n'),
    make_pair(6, 'o'),
    make_pair(2, 'p'),
    make_pair(1, 'q'),
    make_pair(5, 'r'),
    make_pair(5, 's'),
    make_pair(7, 't'),
    make_pair(2, 'u'),
    make_pair(1, 'v'),
    make_pair(2, 'w'),
    make_pair(1, 'x'),
    make_pair(2, 'y'),
    make_pair(1, 'z')
  }
  */

  //sort
  //stable_sort(charEngAvgFreq.begin(), charEngAvgFreq.end());

  //change table frequeny percentage
  for (i=0, i<givenTableFreq.length, i++){
    plaintextFreqPerc[i] = givenTableFreq[i] / 106;
  }

  //sum ciphertextFreq and change to percentages
  sum=0;
  for(i=0,i<ciphertextFreq.size,i++){
    sum = sum + array[i];
  }
  for (i=0, i<ciphertextFreq.size, i++){
    ciphertextFreqPerc[i] = ciphertextFreq[i] / sum;
  }

  //generate key
  for(i=0,i<plaintextFreqPerc.length,i++){
    for(j=0,j<givenTableFreq[i],j++){

    }
  }

  return initPutativeKey;
}

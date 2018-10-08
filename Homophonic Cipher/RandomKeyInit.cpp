//
//  RandomKeyInit.cpp
//  CS6903 Project 1
//
//  Created by nlm330 on 10/6/18.

#include "RandomKeyInit.hpp"
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
using namespace std;

int GetPutativeKey(int ciphertextFreq[106]){
  int putativeKey[106]={0};
  vector<float> ciphertextFreqPerc={0};
  float plaintextFreqPerc[27]={0};
  int sum=0;
  int i=0;
  float tempBest=10000;
  int tempBestPos=0;

  // hardcoded vecor of frequeny values given to us
  //tuple<char_letter, char_count, char_perc
  vector<tuple<int, char, float>> plaintextFreq;
  givenTableFreq.push_back(make_tuple(char(32), 19, 0);
  givenTableFreq.push_back(make_tuple('a', 7, 0);
  givenTableFreq.push_back(make_tuple('b', 1, 0);
  givenTableFreq.push_back(make_tuple('c', 2, 0);
  givenTableFreq.push_back(make_tuple('d', 4, 0);
  givenTableFreq.push_back(make_tuple('e', 10, 0);
  givenTableFreq.push_back(make_tuple('f', 2, 0);
  givenTableFreq.push_back(make_tuple('g', 2, 0);
  givenTableFreq.push_back(make_tuple('h', 5, 0);
  givenTableFreq.push_back(make_tuple('i', 6, 0);
  givenTableFreq.push_back(make_tuple('j', 1, 0);
  givenTableFreq.push_back(make_tuple('k', 1, 0);
  givenTableFreq.push_back(make_tuple('l', 3, 0);
  givenTableFreq.push_back(make_tuple('m', 2, 0);
  givenTableFreq.push_back(make_tuple('n', 6, 0);
  givenTableFreq.push_back(make_tuple('o', 6, 0);
  givenTableFreq.push_back(make_tuple('p', 2, 0);
  givenTableFreq.push_back(make_tuple('q', 1, 0);
  givenTableFreq.push_back(make_tuple('r', 5, 0);
  givenTableFreq.push_back(make_tuple('s', 5, 0);
  givenTableFreq.push_back(make_tuple('t', 7, 0);
  givenTableFreq.push_back(make_tuple('u', 2, 0);
  givenTableFreq.push_back(make_tuple('a', 7, 0);
  givenTableFreq.push_back(make_tuple('v', 1, 0);
  givenTableFreq.push_back(make_tuple('w', 2, 0);
  givenTableFreq.push_back(make_tuple('x', 1, 0);
  givenTableFreq.push_back(make_tuple('y', 2, 0);
  givenTableFreq.push_back(make_tuple('z', 1, 0);

  //set percentages to plaintextFreq
  cout << "printing given table frequency by letter: " << "\n";
  for(i=0,i<givenTableFreq.size(),i++){
    get<2>(givenTableFreq[i]) = get<1>(givenTableFreq[i]) / 106;
    cout << get<0>(givenTableFreq[i]) << " "
      << get<1>(givenTableFreq[i]) << " "
      << get<2>(givenTableFreq[i]) << "\n";
    }

  //sort plaintextFreq by percentage
  sort(givenTableFreq.begin(), givenTableFreq.end(), sortbyth);
  cout << "printing given table sorted by frequency: " << "\n";
  cout << get<0>(givenTableFreq[i]) << " "
    << get<1>(givenTableFreq[i]) << " "
    << get<2>(givenTableFreq[i]) << "\n";

  //sum ciphertextFreq and change to percentages
  sum=0;
  for(i=0,i<ciphertextFreq.length(),i++){
    sum = sum + ciphertextFreq[i];
  }
  for (i=0,i<ciphertextFreq.length(),i++){
    ciphertextFreqPerc[i] = ciphertextFreq[i] / sum;
  }

  //Prepare ciphtertext frequeny vector
  //<int cipher number, float cipher number freq perc
  vector<pair<int, float>> cipher_freq_search;
  for(i=0,i<ciphertextFreq.length(),i++){
    cipher_freq_search.push_back(make_pair(ciphertextFreq[i],ciphertextFreqPerc[i]));
  }

  //generate key
  for(i=0,i<givenTableFreq.size(),i++){
    float j = get<2>(plaintextFreq[i] / get<1>(plaintextFreq[i]);
    //int l = get<1>(plaintextFreq[i]);
    char k = get<0>(plaintextFreq[i]);
    for(int l=0,l<get<1>(plaintextFreq[i]),l++){

      //find the closest value to J in cipher text frequencies
      for(int m=0,m<cipher_freq_search.size(),m++){
        if(abs(J-get<1>(cipher_freq_search[m])<tempBest){
          tempBest=abs(J-get<1>(cipher_freq_search[m]);
          tempBestPos=get<0>(cipher_freq_search[m]);
        }

      //put value closest to J in the putativeKey array, remove vector position
      putativeKey[tempBestPos]=k;
      cipher_freq_search.erase(tempBestPos);
      }

      //reset tempBest
      tempBest=10000;
      tempBestPos=0;
    }


    //map_char_to_num_by_freq(&cipher_freq_search, l, j, k, &tempBest, int (&putativekey)[106]);
    //tempBest=10000;
  }

  //print putativeKey[]
  cout << "The putative key is: " << "\n";
  for (i=0,i<putativeKey.size(),i++){
    cout << i << " " << putativeKey[i] >> "\n";
  }
  return putativeKey;
}

/*
//will try and make this with just a for loop
//Recursive function to map character to number by frequency
map_char_to_num_by_freq(vector<pair<int, float>> &cipher_freq_search, int l, float j, char k, int &tempBest, int (&putativekey)[106]){
  //base case
  if (l == 0){
    return;
  }
  //recurse
  map_char_to_num_by_freq(&cipher_freq_search, l-1, j, k, &tempBest, int (&putativekey)[106]);

  //perform opations after returning from recusion depth
  //find percentage in cipher_freq_search closest to J
  tempBest=10000;
  if (cip)
}
*/

// Driver function to sort the vector elements
// by third element of tuple
// obtained from:https://www.geeksforgeeks.org/sorting-vector-tuple-c-ascending-order/
bool sortbyth(const tuple<int, char, float>& a, const tuple<int, char, float>& b) {
  return (get<2>(a) > get<2>(b));
}

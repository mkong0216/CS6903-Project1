//
//  RandomKeyInit.cpp
//  CS6903 Project 1
//
//  Created by nlm330 on 10/6/18.

#include "RandomKeyInit.hpp"
#include <tuple>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

//function to sort vector by third position, descending. used code from
//https://www.geeksforgeeks.org/sorting-vector-tuple-c-descending-order/
bool sortbyth(const tuple<int, char, float>& a, const tuple<int, char, float>& b) {
  return (get<2>(a) > get<2>(b));
}

//the putative key out is the output value
//the value inside the key should be 0-26
//0 stands for space, 1-26 stands for a-z
void RandomKeyInit::GetPutativeKey(vector<int> ciphertextFreq, int* putativeKeyOut){
  int putativeKey[106]={0};
  float ciphertextFreqPerc[106]={0};
  float plaintextFreqPerc[27]={0};
  int sum=0;
  int i=0;
  float tempBest=10000;
  int tempBestPos=0;
  float tempPerc=0;
  float j=0;
  int tempBestVectorPos=0;


  // hardcoded vecor of frequeny values given to us
  //tuple<char_letter, char_count, char_perc
  vector<tuple<int, int, float>> plaintextFreq;
  plaintextFreq.push_back(make_tuple(0, 19, 0));
  plaintextFreq.push_back(make_tuple(1, 7, 0));
  plaintextFreq.push_back(make_tuple(2, 1, 0));
  plaintextFreq.push_back(make_tuple(3, 2, 0));
  plaintextFreq.push_back(make_tuple(4, 4, 0));
  plaintextFreq.push_back(make_tuple(5, 10, 0));
  plaintextFreq.push_back(make_tuple(6, 2, 0));
  plaintextFreq.push_back(make_tuple(7, 2, 0));
  plaintextFreq.push_back(make_tuple(8, 5, 0));
  plaintextFreq.push_back(make_tuple(9, 6, 0));
  plaintextFreq.push_back(make_tuple(10, 1, 0));
  plaintextFreq.push_back(make_tuple(11, 1, 0));
  plaintextFreq.push_back(make_tuple(12, 3, 0));
  plaintextFreq.push_back(make_tuple(13, 2, 0));
  plaintextFreq.push_back(make_tuple(14, 6, 0));
  plaintextFreq.push_back(make_tuple(15, 6, 0));
  plaintextFreq.push_back(make_tuple(16, 2, 0));
  plaintextFreq.push_back(make_tuple(17, 1, 0));
  plaintextFreq.push_back(make_tuple(18, 5, 0));
  plaintextFreq.push_back(make_tuple(19, 5, 0));
  plaintextFreq.push_back(make_tuple(20, 7, 0));
  plaintextFreq.push_back(make_tuple(21, 2, 0));
  plaintextFreq.push_back(make_tuple(22, 1, 0));
  plaintextFreq.push_back(make_tuple(23, 2, 0));
  plaintextFreq.push_back(make_tuple(24, 1, 0));
  plaintextFreq.push_back(make_tuple(25, 2, 0));
  plaintextFreq.push_back(make_tuple(26, 1, 0));

  //set percentages to plaintextFreq
  cout << "printing given table frequency by letter: " << "\n";
  for(i=0;i<plaintextFreq.size();i++){
    tempPerc = get<1>(plaintextFreq[i]);
    tempPerc /= 500;
    get<2>(plaintextFreq[i]) = tempPerc;
    cout << get<0>(plaintextFreq[i]) << " "
      << get<1>(plaintextFreq[i]) << " "
      << get<2>(plaintextFreq[i]) << endl;
    }

  //sort plaintextFreq by percentage
  sort(plaintextFreq.begin(), plaintextFreq.end(), sortbyth);

  cout << "printing given table sorted by frequency: " << "\n";
  for(i=0;i<plaintextFreq.size();i++){
    cout << get<0>(plaintextFreq[i]) << " "
      << get<1>(plaintextFreq[i]) << " "
      << get<2>(plaintextFreq[i]) << endl;
}



  //sum ciphertextFreq and change to percentages
  sum=0;
  for(i=0;i<ciphertextFreq.size();i++){
    sum = sum + ciphertextFreq[i];
  }
  for (i=0;i<ciphertextFreq.size();i++){
    tempPerc = ciphertextFreq[i];
    tempPerc /= sum;
    ciphertextFreqPerc[i] = tempPerc;
  }



  //Prepare ciphtertext frequency vector
  //<int cipher number, float cipher number freq perc
  vector<pair<int, float>> cipher_freq_search;
  for(i=0;i<ciphertextFreq.size();i++){
    cipher_freq_search.push_back(make_pair(i,ciphertextFreqPerc[i]));
  }

  //generate key
  for(i=0;i<plaintextFreq.size();i++){
    j = get<2>(plaintextFreq[i]);
    int k = get<0>(plaintextFreq[i]);
    for(int l=0;l<get<1>(plaintextFreq[i]);l++){
      //find the closest value to J in cipher text frequencies
      for(int m=0;m<cipher_freq_search.size();m++){

        if(abs(j-cipher_freq_search[m].second<tempBest)){
          tempBest=abs(j-cipher_freq_search[m].second);
          tempBestPos=cipher_freq_search[m].first;
          tempBestVectorPos=m;
	        }
      }
      //put value closest to J in the putativeKey array, remove vector position
      putativeKeyOut[tempBestPos]=k;

      //cout << "putkeypos: " << putativeKeyOut << endl;
      cipher_freq_search.erase(cipher_freq_search.begin()+tempBestVectorPos);

      //reset tempBest
      tempBest=10000;
      tempBestPos=0;
      tempBestVectorPos=0;
    }
  }
  return;
}

//include all the files in this folder
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <regex>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include "DictofPhrases.cc"
#include "Decode.cc"
#include <ctime>
using namespace std;

int main() {
    // Start the clock
    clock_t start = clock();
  
  //clean the text
    ofstream out("outputClean.txt");
    string cleaned;
    cleaned = clean("books/HP1.txt");
    out << cleaned;
    cleaned = clean("books/HP2.txt");
    out << cleaned;
    cleaned = clean("books/HP3.txt");
    out << cleaned;
   cout << "Done cleaning 3 Harry Potter books." << endl;
  
  //create the dictionary
  cout<< "Choose the k most common words to be in the dictionary: ";
  int k;
  cin >> k;
    unordered_map<string, int> dict = dictionary(cleaned, k);
    cout << "Done creating dictionary." << endl;
    //find the common phrases
    ofstream output("phrases.txt");
    unordered_map<string, int> phrases;
    cout << "Choose the f most common phrases to be in the dictionary: ";
    int f;
    cin >> f;
     phrases = getSubstrings(cleaned, dict, f);
    for(auto i: phrases){
      output << i.first << ": " << i.second << endl;
    }
    cout << "Done finding common phrases." << endl;

  //  decode the phrases
    ofstream dec("decoded.txt");
    unordered_map<string, int> decoded = decoding(dict, phrases);
    for(auto i: decoded){
      dec << i.first << ": " << i.second << endl;
    }
    cout << "Done decoding phrases." << endl;


    // Stop the clock
    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    // Print the elapsed time
    cout << "Elapsed time: " << elapsed_time << " seconds" << endl;

  return 0;
}
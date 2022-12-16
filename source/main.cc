/*Get words from a book without punc and pick the common phrases

Count the # of books that has the phrases
Count all instances of the times the phrase is recorded as long as there is only 1 changing variable

Focus on one set of books!

Picks books from the same genre for the same dict
How do we deal with the proper nouns (Names)

Encode all parametric phrases
*/
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
    unordered_map<string, int> dict = dictionary(cleaned);
    cout << "Done creating dictionary." << endl;
    //find the common phrases
    ofstream output("phrases.txt");
    unordered_map<string, int> phrases;
     phrases = getSubstrings(cleaned, dict);
    for(auto i: phrases){
        if(i.second > 1)
            output << i.first << ": " << i.second << endl;
    }
    cout << "Done finding common phrases." << endl;

    // Stop the clock
    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    // Print the elapsed time
    cout << "Elapsed time: " << elapsed_time << " seconds" << endl;

  return 0;
}
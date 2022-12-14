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
#include "cleanText_Dict.cc"
#include "findPhrases.cc"
using namespace std;

int main() {
  
    ofstream out("outputClean.txt");
    string cleaned;
    cleaned = clean("books/HP1.txt");
    out << cleaned;
  cleaned = clean("books/HP2.txt");
  out << cleaned;
  cleaned = clean("books/HP3.txt");
  out << cleaned;
   cout << "Done cleaning a Harry Potter books." << endl;
  
  //making a dictionary of the most common words from the 3 books
    dictionary("outputClean.txt");
 
    // string book;
    // ifstream input2("outputClean.txt");
    // getline(input2, book);
    string lookAt = reWrite(cleaned, "nofrequency.txt");
    cout << "Rewrote book after ommiting non frequent words." << endl;
    
    map<string, int> wordCounts = findingPhrases(lookAt);
    ofstream output("phrases.txt");
    for (const auto& kvp : wordCounts) {
        if(kvp.second > 1)
            output << kvp.first << ": " << kvp.second << endl;
    }
    cout << "Done finding phrases." << endl;

     map<string, int> phraseFound = moreThanOne(wordCounts);
    ofstream outputFinal("phrasesFound.txt");
    for (const auto& p : phraseFound) {
        if(p.second > 3)
            outputFinal << p.first << ": " << p.second << endl;
    }
    cout << "Done cleaning data." << endl;



  return 0;
}
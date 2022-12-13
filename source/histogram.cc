//take input from cleaned.txt and compare the phrases with all the text from the book outputClean.txt count the frequency of the phrases and store it in a map then output it to a file

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <algorithm>
#include <vector>
using namespace std;

//
map<string, int> commonPhrases(const string& phrase, const string& book){
//    ifstream input(filename);
//    string phrase;
   string subject(book);
   map<string, int> wordCounts;
 
    // Template instantiations for
    // extracting the matching pattern.
    smatch match;
  // while(getline(input, phrase)){
        regex r(phrase);
        int i = 1;
        //cout<< phrase <<endl;
        
        while (regex_search(subject, match, r)) {
           // cout << match.str() << subject <<endl;
           // cout<<i<<": "<<match.str()<<endl;
            for (const auto& kvp : match) {
                ++wordCounts[kvp];
               // cout << kvp << endl;
            }
            i++;
            // suffix to find the rest of the string.
            subject = match.suffix().str();
        }
        //cout<< i <<endl;
   // }
    //print the map into a file
    ofstream output("hist.txt");
    for (const auto& kvp : wordCounts) {
        if(kvp.second > 3){
        output << kvp.first << ": " << kvp.second << endl;
        //cout << kvp.first << ": " << kvp.second << endl;
        }
    }
   return wordCounts;
}

int main(){
    string phrase;
    string book = "";
   ifstream input("outputs.txt");
    ifstream input2("outputClean.txt");
    while(getline(input2, book)){
        book+=book;
    }
   // cout << book;
    while(getline(input, phrase)){
            commonPhrases(phrase, book);
    }
    return 0;
    }
    

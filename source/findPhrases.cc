//take input from cleaned.txt and compare the phrases with all the text from the book outputClean.txt count the frequency of the phrases and store it in a map then output it to a file

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//
//map<string, int> 
string reWrite(string book, const string& frequentwords){

  ifstream input(frequentwords);
  if(!input.is_open()){
    cout << "Error opening file" << endl;
    exit(1);
  }
  ofstream out("newbook.txt");
  string subject(book);
 string phrase, output;
  // Template instantiations for
  // extracting the matching pattern.
  while(getline(input, phrase)){
    regex pattern(" " + phrase + " ");
    output = regex_replace(book, pattern, " 0 ");
    book = output;
    }
    out << output << endl;
    //cout << output << endl;
    return output;
  }
  
 map<string, int> findingPhrases(string lookAt){
    map<string, int> wordCounts;
    string phrase = "";
    int count = 0;

    for(char word : lookAt){
      
      if(word != '0'){
          phrase += word ;
          
      }else if(word == '0' && count < 1){
          phrase += word ;
          count++;
          
      }else{
        ++wordCounts[phrase];
        phrase = "";
        count = 0;
      }
      }
    
  return wordCounts;
 }

map<string, int> moreThanOne(map<string, int> wordCounts){
  map<string, int> newMap;
 //only add to the new map is each string has more than 2 words in it
  for (const auto& kvp : wordCounts) {
    stringstream ss(kvp.first);
    string word;
    int count = 0;
    while (ss >> word) {
      count++;
    }
    if(count > 2){
      newMap.insert({kvp.first, kvp.second});
    }
  }
  return newMap;
}



// int main(){
//     string phrase;
//     string book = "";
//     string pat = "";

//     ifstream input2("outputClean.txt");
//     getline(input2, book);
    
//    //cout << book;
   
//     string lookAt = commonPhrases(book, "nofrequency2.txt");
//     //for testing rn
   
//     map<string, int> wordCounts = findingPhrases(lookAt);
//     ofstream out("phrases.txt");
//     for (const auto& kvp : wordCounts) {
//     out << kvp.first << endl;
//     }

    
    
//     return 0;
//     }
    

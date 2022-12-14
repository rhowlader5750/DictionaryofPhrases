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
string commonPhrases(string book, const string& frequentwords){

  ifstream input(frequentwords);
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




int main(){
    string phrase;
    string book = "";
    string pat = "";

    ifstream input2("outputClean.txt");
    getline(input2, book);
    
   //cout << book;
   
    string lookAt = commonPhrases(book, "nofrequency2.txt");
    //for testing rn
   
    map<string, int> wordCounts = findingPhrases(lookAt);
    ofstream out("phrases.txt");
    for (const auto& kvp : wordCounts) {
    out << kvp.first << endl;
    }

    
    
    return 0;
    }
    

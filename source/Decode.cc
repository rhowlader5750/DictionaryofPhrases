#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <unordered_map>
using namespace std;

//given a dictionary of words mapped to unique ids and a dictionary of phrases encoded with the ids, return a new dictionary of phrases mapped to the words
unordered_map<string, int> decoding(unordered_map<string, int> dict, unordered_map<string, int> phrases){
  unordered_map<string, int> newMap;
  
    for(auto phrase: phrases){
      string newPhrase = "";
      stringstream ss(phrase.first);
      string word;
      while (ss >> word) {
        for(auto i: dict){
          if(i.second == stoi(word)){
            newPhrase += i.first + " ";
          }
        } 
        if(stoi(word) == 0){
            newPhrase += word + " ";
          }
      }
      newMap.insert({newPhrase, phrase.second});
    }
  return newMap;
}

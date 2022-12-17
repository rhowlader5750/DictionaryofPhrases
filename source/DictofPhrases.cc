// this file will take in the book and clean it up so that it has no pucntuation
// and is all lower case
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> moreThanOne(unordered_map<string, int> wordCounts){
  unordered_map<string, int> newMap;
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

unordered_map<string, int> encodingPhrases(vector<pair<string, int>>& phrases, unordered_map<string, int> dict){
  unordered_map<string, int> newMap;
  int count = dict.size();
  for(auto& i: phrases){
    string phrase = i.first;
    stringstream ss(phrase);
    string word;
    string newPhrase = "";
    while (ss >> word) {
      if(dict.find(word) != dict.end()){
        newPhrase += to_string(dict[word]) + " ";
      }else{
        newPhrase += "0 ";
      }
    }
    count++;
    newMap.insert({newPhrase, count});
  }
  return newMap;
}

unordered_map<string, int> encoding(vector<pair<string, int>>& dictionary, int k){
  int count = 0;
  ofstream out("dictionary.txt");
   vector<pair<string, int>> vec;
   //add the 500 most common words to the vector and assign their id
  for(auto& kvp : dictionary){
    count++;
    if(count <= k){
      vec.push_back({kvp.first, count});
    }    
  }
  unordered_map<string, int> newMap;
  //add the vector to the new map
  for(auto& i: vec){
    newMap.insert(i);
  }
  //write this in the new file
  for(auto& i: newMap){
    out << i.first << ": " << i.second << endl;
  }
  return newMap;

}

bool cmp(pair<string, int>& a, pair<string, int>& b) {
  return a.second > b.second;
}

vector<pair<string, int>> sort(unordered_map<string, int>& words){
  //sort the dictionary by the frequency of the words
 unordered_map<string, int> dictionary;
  vector<pair<string, int>> vec;
  for (const auto& kvp : words) {
    vec.push_back(kvp);
  }
  sort(vec.begin(), vec.end(), cmp);
  return vec;
}

unordered_map<string, int> getSubstrings(string str, unordered_map<string, int> words, int f){
  ofstream out("substrings.txt");
    unordered_map<string, int> substrings;
    int count = 0;
    // iterate through the string
    for (int i = 0; i < str.size(); i++)
    {
        string substring = "";
        // iterate through the string starting from the current character
        // and check if each word exists in the unordered map
        for (int j = i; j < str.size(); j++)
        {
            string word = "";
            // extract the word at the current position
            while (j < str.size() && str[j] != ' '){
                word += str[j++];
            }
            i = j;
            // if the word exists in the unordered map, add it to the substring
            if (words.find(word) != words.end()){
                substring += word + " ";
            }
            //if the word does not exist in the unordered map, but it is the first word in the substring, add it to the substring as a 0
            else if(!(words.find(word) != words.end()) && (count < 1)){
                count++;
                substring += "0 ";
            }
            //if the word does not exist in the unordered map, break the loop
            else{
                break;
            }
        }
        // add the substring to the list of substrings
        if (substring != ""){
            ++substrings[substring];
            count = 0;
        }
    }
    unordered_map<string, int> checkIfPhrase = moreThanOne(substrings);
    unordered_map<string, int> withFreq;
    for(auto& i: checkIfPhrase){
      if(i.second > f){
        withFreq.insert(i);
      }
    }
    vector<pair<string, int>> sorted = sort(withFreq);
    for(auto& i: sorted){
      out << i.first << ": " << i.second << endl;
    }
    checkIfPhrase = encodingPhrases(sorted, words);
    return checkIfPhrase;
}

unordered_map<string, int> dictionary(string book, int k) {
  unordered_map<string, int> wordCounts;
  // Read each word from the file and update its count in the map
  string word;
  istringstream text(book);
  while (text >> word) {
    ++wordCounts[word];
  }
  vector<pair<string, int>> sorted;
  //sort the dictionary by the frequency of the words
  sorted = sort(wordCounts);
  //assign the id to the words
  wordCounts = encoding(sorted, k);
  return wordCounts;
}

string clean_text(const string& text) {
  // Create regular expressions for matching punctuation, whitespace, and multiple spaces
  regex regex_punctuation("[^a-zA-Z0-9 ]");
  regex regex_whitespace("\\s+");
  regex pattern("[ \t\r\n]+");
  // Remove punctuation and convert to lowercase
  string cleaned = regex_replace(text, regex_punctuation, "");
  transform(cleaned.begin(), cleaned.end(), cleaned.begin(), ::tolower);
  // Remove multiple spaces
  cleaned = regex_replace(cleaned, regex_whitespace, " ");
  cleaned = regex_replace(cleaned, pattern, " ");
  // Return the cleaned text
  return cleaned;
}

string clean(const string& filename) {
  // Open the input file
  ifstream in(filename);
  if(!in.is_open()) {
    cout << "Error opening file" << endl;
    exit(1);
  }
  string output = "";
  regex regex_whitespace("\\s+");
  // Read the input file line by line
  string line;
  while (getline(in, line)) {
    // Clean the line
    string cleaned = clean_text(line);
    cleaned = regex_replace(cleaned, regex_whitespace, " ");
    // Write the cleaned line to the output file, replacing the end of line with
    // a space
    output += cleaned + " ";
  }
  //clean the output again
  string finalOutput = clean_text(output);
  finalOutput = regex_replace(finalOutput, regex_whitespace, " ");
  return finalOutput;
}
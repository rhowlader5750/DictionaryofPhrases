#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  // Create a map to store the word counts
  map<string, int> wordCounts;

  // Open the input file
  ifstream in("outputClean.txt");
  ofstream out("wordfrequency.txt");
  // Read each word from the file and update its count in the map
  string word;
  while (in >> word) {
    ++wordCounts[word];
  }
for (const auto& kvp : wordCounts) {
    if(kvp.second > 3){
    out << kvp.first << ": " << kvp.second << endl;
    }
  }
 

  return 0;
}
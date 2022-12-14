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
  ofstream out2("nofrequency2.txt");
  // Read each word from the file and update its count in the map
  string word;
  while (in >> word) {
    ++wordCounts[word];
  }
for (const auto& kvp : wordCounts) {
    if(kvp.second >= 9){
    out << kvp.first << endl;
    //<< ": " << kvp.second << endl;
    }
    else{
        out2 << kvp.first << endl;
    }
  }
 

  return 0;
}
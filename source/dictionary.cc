#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void saveMapToFile(const map<string, int>& m, const string& fileName) {
  // Open the output file
  ofstream out(fileName);

  // Write each key-value pair to the file
  for (const auto& kvp : m) {
    out << kvp.first << ": " << kvp.second << endl;
  }
}

int main() {
  // Create a map to store the word counts
  map<string, int> wordCounts;

  // Open the input file
  ifstream in("cleaned_book.txt");

  // Read each word from the file and update its count in the map
  string word;
  while (in >> word) {
    ++wordCounts[word];
  }

  // Print the results
  for (const auto& kvp : wordCounts) {
    cout << kvp.first << ": " << kvp.second << endl;
  }

  saveMapToFile(wordCounts, "wordfrequency.txt");

  return 0;
}
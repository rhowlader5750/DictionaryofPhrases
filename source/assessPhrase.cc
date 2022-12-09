#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

// Function that reads the input file and returns a set of all the words
// in the file.
set<string> readInputFile(const string& filename) {
  set<string> words;

  ifstream input(filename);
  string word;
  while (input >> word) {
    words.insert(word);
  }

  return words;
}

// Function that finds all the common phrases in the given set of words and
// stores them in a map, along with their frequency.
map<string, int> findCommonPhrases(const set<string>& words) {
  map<string, int> phrases;

  // Iterate over all words in the set and find all the common phrases
  // that contain the current word.
  for (const string& word : words) {
    // Find all the words that follow the current word.
    set<string> followingWords;
    auto it = words.find(word);
    while (++it != words.end()) {
      followingWords.insert(*it);
    }

    // Construct all the common phrases that contain the current word
    // and the words that follow it.
    for (const string& followingWord : followingWords) {
      string phrase = word + " " + followingWord;
      phrases[phrase]++;
    }
  }

  return phrases;
}

// Function that writes the common phrases and their frequencies to the
// output file.
void writeOutputFile(const map<string, int>& phrases, const string& filename) {
  ofstream output(filename);
  for (const auto& [phrase, frequency] : phrases) {
    output << phrase << ": " << frequency << endl;
  }
}

int main() {
  // Read the input file and find all the common phrases
  set<string> words = readInputFile("cleaned_book.txt");
  map<string, int> phrases = findCommonPhrases(words);

  // Write the common phrases and their frequencies to the output file
  writeOutputFile(phrases, "output.txt");

  return 0;
}

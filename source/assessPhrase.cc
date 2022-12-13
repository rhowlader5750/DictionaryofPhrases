#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <regex>
using namespace std;

string clean_text(const string& text)
{
    // Create regular expressions for matching punctuation, whitespace, and multiple spaces
    regex regex_punctuation("[^a-z]");
    regex regex_whitespace("\\s+");
   // regex pattern("[ \t\r\n]+");
       

    // Remove punctuation and convert to lowercase
    string cleaned = regex_replace(text, regex_punctuation, "");
    transform(cleaned.begin(), cleaned.end(), cleaned.begin(), ::tolower);

    // Remove multiple spaces
    cleaned = regex_replace(cleaned, regex_whitespace, " ");
    // cleaned = regex_replace(cleaned, pattern, " ");

    // Return the cleaned text
    return cleaned;
}
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
map<string, int> findPhrases(const set<string>& words) {
  map<string, int> phrases;

  // Iterate over all words in the set and find all the common phrases
  // that contain the current word.
  for (const string& word : words) {
    // Find all the words other than the current word.
    set<string> followingWords;
    for (const string& otherWord : words) {
      if (word != otherWord) {
        followingWords.insert(otherWord);
      }
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
    output << phrase << endl;
  }
}

int main() {
  // Read the input file and find all the common phrases
  
  //  ifstream input_file("wordfrequency.txt");
  //   ofstream output_file("cleaned.txt");
  //   regex regex_whitespace("\\s+");

  //   // Read the input file line by line
  //   string line;
  //   while (getline(input_file, line))
  //   {
  //       // Clean the line
  //       string cleaned = clean_text(line);
  //       cleaned = regex_replace(cleaned, regex_whitespace, " ");
       
  //       // Write the cleaned line to the output file, replacing the end of line with a space
  //       output_file << cleaned << " ";
  //   }
  set<string> words = readInputFile("cleaned.txt");
  cout << "The input file has been read and we have found " << words.size() << " words." << endl;
  map<string, int> phrases = findPhrases(words);
  cout << "Taking in the words from the input file, we have found " << phrases.size() << " common phrases." << endl;
  // Write the common phrases and their frequencies to the output file
  writeOutputFile(phrases, "outputs.txt");
  cout << "The common phrases and their frequencies have been written to the output file." << endl;

  return 0;
}

// this file will take in the book and clean it up so that it has no pucntuation
// and is all lower case
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
using namespace std;

void dictionary(const string& filename) {
  map<string, int> wordCounts;
  map<string, int> wordCountsone;

  // Open the input file
  ifstream in(filename);
  ofstream out("wordfrequency.txt");
  ofstream out2("nofrequency.txt");
  // Read each word from the file and update its count in the map
  string word;
  while (in >> word) {
    ++wordCounts[word];
  }
  for (const auto& kvp : wordCounts) {
    if (kvp.second > 150) {
      out << kvp.first << ": " << kvp.second << endl;
    }else{
      out2 << kvp.first << endl;
    }
  }
  cout << "Done making dictionary with words what appear more than 150 times." << endl;
}

string clean_text(const string& text) {
  // Create regular expressions for matching punctuation, whitespace, and
  // multiple spaces
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
// Open the input and output files
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
  string finalOutput = clean_text(output);
  finalOutput = regex_replace(finalOutput, regex_whitespace, " ");
  return finalOutput;
}

// int main() {
//   // Open the input and output files
//   ifstream input_file("PerfectStranger.txt");
//   ofstream output_file("output.txt");
//   regex regex_whitespace("\\s+");

//   // Read the input file line by line
//   string line;
//   while (getline(input_file, line)) {
//     // Clean the line
//     string cleaned = clean_text(line);
//     cleaned = regex_replace(cleaned, regex_whitespace, " ");

//     // Write the cleaned line to the output file, replacing the end of line with
//     // a space
//     output_file << cleaned << " ";
//   }

//   ifstream input("output.txt");
//   ofstream output("outputClean.txt");
//   // regex regex_whitespace("\\s+");

//   // Read the input file line by line
//   string text;
//   while (getline(input, text)) {
//     // Clean the line
//     string clean = clean_text(text);
//     clean = regex_replace(clean, regex_whitespace, " ");

//     // Write the cleaned line to the output file, replacing the end of line with
//     // a space
//     output << clean << " ";
//   }
//   dictionary("outputClean.txt");

//   return 0;
// }
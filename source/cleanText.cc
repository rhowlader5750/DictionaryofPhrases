#include <iostream>
#include <fstream>
#include <regex>
#include <string>
using namespace std;

string clean_text(const string& text)
{
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

int main()
{
    // Open the input and output files
    ifstream input_file("PerfectStranger.txt");
    ofstream output_file("output.txt");
    regex regex_whitespace("\\s+");

    // Read the input file line by line
    string line;
    while (getline(input_file, line))
    {
        // Clean the line
        string cleaned = clean_text(line);
        cleaned = regex_replace(cleaned, regex_whitespace, " ");
       
        // Write the cleaned line to the output file, replacing the end of line with a space
        output_file << cleaned << " ";
    }

     ifstream input("output.txt");
    ofstream output("outputClean.txt");
    //regex regex_whitespace("\\s+");

    // Read the input file line by line
    string text;
    while (getline(input, text))
    {
        // Clean the line
        string clean = clean_text(text);
        clean = regex_replace(clean, regex_whitespace, " ");
       
        // Write the cleaned line to the output file, replacing the end of line with a space
        output << clean << " ";
    }


    return 0;
}

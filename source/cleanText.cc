//this file will take in the book and clean it up so that it has no pucntuation and is all lower case
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>
#include <iterator>
#include <sstream>
using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("PerfectStranger.txt");
    outFile.open("cleanedBook.txt");
    if(inFile.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }

    string line;
    string word;
    string cleanWord;
    vector<string> words;
    map<string, int> wordCount;
    while(getline(inFile, line))
    {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        istringstream iss(line);
        while(iss >> word)
        {
            cleanWord = "";
            for(auto c : word)
            {
                if(isalpha(c))
                {
                    cleanWord += c;
                }
            }
            words.push_back(cleanWord);
        }
    }

    for(auto w : words)
    {
        wordCount[w]++;
    }

    for(auto w : wordCount)
    {
        outFile << w.first << " " << w.second << endl;
        cout << w.first << " " << w.second << endl;
    }

    inFile.close();
    outFile.close();
    return 0;
}

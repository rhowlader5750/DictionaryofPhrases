//this file will take in the book and clean it up so that it has no pucntuation and is all lower case
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



// Function to remove punctuation and make all characters lowercase
std::string clean_book(std::string book)
{
    std::string cleaned_book; // string to store the cleaned book
    bool last_char_was_letter = false; // flag to keep track of whether the previous character was a letter

    for (char c : book) // loop through each character in the book
    {
        if(c == '\r' || c == '\n' || c == '\t' || c == '\v' || c == '\f'){
            c = ' ';
        }
        if(!std::isalpha(c) && !std::isspace(c))
        {
            c = ' ';
        }
        if (std::isalpha(c) || c == ' ')
        {
         if(!last_char_was_letter && c == ' ') // If the previous character was not a letter and the current character is a space, move on to the next character
            {
                continue;
            }  
            cleaned_book += std::tolower(c); // add the lowercase version of the current character to the cleaned book
            last_char_was_letter = true; // update the flag to indicate that the last character was a letter
            
            // If the previous character was a space, move on to the next character
           
        }
        else
        {
            last_char_was_letter = false; // update the flag to indicate that the last character was not a letter
        }
    }

    return cleaned_book;
}

int main()
{
    std::ifstream book_file("PerfectStranger.txt"); // open the book file for reading
    std::ofstream cleaned_book_file("cleaned_book.txt"); // open the cleaned book file for writing
    std::string book; // string to store the book
    std::string cleaned_book; // string to store the cleaned book

    if (book_file.is_open()) // check if the book file was successfully opened
    {
        cout << "Cleaning book..." << endl;
        while (getline(book_file, book)) // read the book file line by line
        {
            cleaned_book += clean_book(book); // add the cleaned version of the current line to the cleaned book
        }

        book_file.close(); // close the book file

        if (cleaned_book_file.is_open()) // check if the cleaned book file was successfully opened
        {
            cout << "Writing cleaned book to file..." << endl;
            cleaned_book_file << cleaned_book; // write the cleaned book to the cleaned book file
            cleaned_book_file.close(); // close the cleaned book file
        }
        cout << "Done!" << endl;
    }

    return 0;
}

// int main()
// {
//     ifstream inFile;
//     ofstream outFile;
//     inFile.open("PerfectStranger.txt");
//     outFile.open("cleanedBook.txt");
//     if(inFile.fail())
//     {
//         cout << "Error opening file" << endl;
//         exit(1);
//     }

//     string line;
//     string word;
//     string cleanWord;
//     vector<string> words;
//     map<string, int> wordCount;
//     while(getline(inFile, line))
//     {
//         transform(line.begin(), line.end(), line.begin(), ::tolower);
//         istringstream iss(line);
//         while(iss >> word)
//         {
//             cleanWord = "";
//             for(auto c : word)
//             {
//                 if(isalpha(c))
//                 {
//                     cleanWord += c;
//                 }
//             }
//             words.push_back(cleanWord);
//         }
//     }

//     for(auto w : words)
//     {
//         wordCount[w]++;
//     }

//     for(auto w : wordCount)
//     {
//         outFile << w.first << " " << w.second << endl;
//         cout << w.first << " " << w.second << endl;
//     }

//     inFile.close();
//     outFile.close();
//     return 0;
// }

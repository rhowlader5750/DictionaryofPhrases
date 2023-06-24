# DictionaryofPhrases

This will be our final project for CPE 593. 

Members: Rayhan Howlader and Riya Shrestha 

This project was designed to serve as a way to assess the learning in the Applied Data Structures and Algorithm class. For this project, our task was to read several books from the same genre and author to find the most common phrases. The abundance of information but a limitation on storage due to environmental and economic reasons creates urgency in finding solutions to storing information more efficiently. Our Project aims to make books more compact by storing all phrases in the book to phrases that are used, this way it can create a significant impact in the storage used. 


To accomplish that, the first task was to read the text and clean it to get rid of all the punctuation and spacing. Following that, we created a dictionary of words where the k (500) most used words were stored in a hash table with their unique keys. Here all words are treated equally and no weight is assigned to them. Next, the task was to create a histogram of the most common phrases of the words found in the dictionary with the variation of only one word. After which all the phrases were encoded with keys of words from the dictionary and replaced all non-common words with the token 0. Lastly, the task was to create a data structure that stores all the phrases with a frequency higher than 1 and assigns a unique key to the phrase. Another program was also written to decode all the phrases. The books read in this project are the first 3 in the Harry Potter series authored by J.K. Rowling.

The Process we created to compress a book


![alt text](https://github.com/rhowlader5750/DictionaryofPhrases/blob/main/results/flowChart.svg)



The result of the Project:

By utilizing unordered maps we were able to accomplish our goal 


![alt text](https://github.com/rhowlader5750/DictionaryofPhrases/blob/main/results/textCleaning.PNG) ![alt text](https://github.com/rhowlader5750/DictionaryofPhrases/blob/main/results/outputtextwith0.png)


And here is the list of some of the phrases our code can capture:


 ![alt text](https://github.com/rhowlader5750/DictionaryofPhrases/blob/main/results/decodingPhrase.PNG)

And here it is fully encoded: 

![alt text](https://github.com/rhowlader5750/DictionaryofPhrases/blob/main/results/encodedPhrases.PNG)

To run this program, the main.cc file has to be compiled using the following command:
g++ main.cc
Once it is done compiling, it can be run using the following command:
.\a.exe
Note: When prompted for input please input integer values. The elapsed accounts for the time the user spends inputting the number as well. 

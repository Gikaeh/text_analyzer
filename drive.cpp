#include <iostream>
#include <fstream>
#include <string>
#include "word_analyzer.h"
using namespace std;

int getWords(int size, string words[], string fileName) { //function to grab words with 
    ifstream file(fileName);
    
    if (!file) {
        cout << "Sorry, could not open " << fileName << " for reading." << endl;
        return -1;
    }
    int w_p = 0; //w_p is variable words_pulled
    
    while (!file.eof()) { //eof: end of file; reads till the end
        file >> words[w_p];
        ++w_p;
    }
    return w_p;
}
string findMaxWord(int size, string words[]) {
    
    if (size == 0) {
        return "";
    }
    string largest = words[0];
    
    for (int i = 0; i < size; ++i) {
            if (words[i] > largest) {
                largest = words[i];
            }
    }
    return largest;
}
int main(int argv, char **argc) {
    const int FIRST_ARG = 1;
    const int MAX_WORDS = 100;
    
    if (argv != FIRST_ARG + 1) {
        cout << "Correct Usage: " << endl;
        cout << "./text_analyzer filename" << endl;
        return 0;
    }
    string filename = argc[FIRST_ARG];
    string words[MAX_WORDS];
    double letters = 0;
    double lowerCase = 0;
    double upperCase = 0;
    double vowels = 0;
    int words_pulled = getWords(MAX_WORDS, words, filename);

    if (words_pulled == -1) {
        return 0;
    }

    for (int i = 0; i < words_pulled; ++i) {
        letters += countLetters(words[i]);
        lowerCase += countLowerCase(words[i]);
        upperCase += countUpperCase(words[i]);
        vowels += countVowels(words[i]);
    }
    cout << "There are " << letters << " letters in your file." << endl;
    cout << "There are " << lowerCase << " lower case letters in your file." << endl;
    cout << "There are " << upperCase << " upper case letters in your file." << endl;
    cout << "There are " << vowels << " vowels in your file." << endl;
    cout << "The last word alphabetically is: " << findMaxWord(MAX_WORDS, words) << endl;
    return 0;
}
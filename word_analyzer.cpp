#include <iostream>
#include <string>
#include "word_analyzer.h"
using namespace std;

int countLetters(string s) { //string s designates all string information into char s
    int res = 0;
    for (char c : s) { //char c:s makes the char c hold all information contained in string s
        if (isalpha (c)) //checks all characters to see if they're letter in order to count
        ++res; //add the found number to the res variable before outputting (26+res(0)=26)
    }
    return res; //puts out res variable
}
int countLowerCase(string s) {
    int res = 0;
    for (char c : s) {
        if (islower (c))
        ++res;
    }
    return res;
}
int countUpperCase(string s) {
    int res = 0;
    for (char c : s) {
        if (isupper (c))
        ++res;
    }
    return res;
}
int countVowels(string s) {
    int res = 0;
    for (char c : s) {
        c = tolower (c);
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++res;
                break;
        }
    }
    return res;
}
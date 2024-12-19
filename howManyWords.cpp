#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

// Function to check if a character is part of a word
// A word character is either an alphabetic character or a hyphen
bool isWordChar(char c) {
    return isalpha(c) || c == '-';
}

// Function to validate a word
// A valid word must contain at least one alphabetic character and no digits
bool isValidWord(const string& word) {
    bool hasAlpha = false;
    for (char c : word) {
        if (isdigit(c)) {
            return false; // Invalid if any digit is found
        }
        if (isalpha(c)) {
            hasAlpha = true; // Mark that it contains an alphabetic character
        }
    }
    return hasAlpha; // Valid if it contains at least one alphabetic character
}

// Function to count the number of valid words in a sentence
int countWords(const string& sentence) {
    stringstream ss(sentence); // Create a stringstream from the sentence
    string word;
    int wordCount = 0;

    // Read each word from the stringstream
    while (ss >> word) {
        string cleanedWord;
        
        // Remove any non-word characters (excluding hyphens) from the word
        for (char c : word) {
            if (isWordChar(c)) {
                cleanedWord += c;
            }
        }
        
        // Check if the cleaned word is valid and increment the word count if it is
        if (!cleanedWord.empty() && isValidWord(cleanedWord)) {
            wordCount++;
        }
    }

    return wordCount; // Return the total count of valid words
}

int main() {
    string sentence;
    getline(cin, sentence); // Read the input sentence

    int numberOfWords = countWords(sentence); // Count the number of valid words
    cout << numberOfWords << endl; // Output the result

    return 0;
}

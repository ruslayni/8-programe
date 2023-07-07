#include <stdio.h>
#include <string.h>

// Recursive function to calculate factorial
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Recursive function to calculate the count of anagrams
int countAnagrams(char word[], int freq[], int wordLength) {
    if (wordLength <= 1) {
        // If word length <= 1, return 1
        return 1;
    }

    int totalAnagrams = factorial(wordLength);

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1) {
            totalAnagrams /= factorial(freq[i]);
        }
    }

    return totalAnagrams;
}

int main() {
    char word[15];
    int freq[26] = {0};
    int wordLength;

    printf("Enter a word: ");
    scanf("%s", word);

    wordLength = strlen(word);

    // Calculate the frequency of each letter in the word
    for (int i = 0; i < wordLength; i++) {
        freq[word[i] - 'A']++;
    }

    int anagramCount = countAnagrams(word, freq, wordLength) / 2; // Divide by 2 as 'S' and 's' are considered as one letter

    printf("Number of anagrams: %d\n", anagramCount);

    return 0;
}

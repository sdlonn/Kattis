#include <stdio.h>
#include <string.h>

int getAmountOfMovesInAWord(char currentWord[]);
int getMinimumAmountOfMovesToGetChar(char ch);
int findAndGetLastIndexOfNextGroupOfAIfNextCharIsA(char word[], int currentIndex, int wordLength);
int getLowestNumber(int a, int b, int c);

const char LOWEST_CHAR = 'A';
const char MID_CHAR = 'N';
const char HIGHEST_CHAR =  'Z';

int main() {
    int numberOfInputCases;
    scanf("%d", &numberOfInputCases);

    for(int i = 0; i < numberOfInputCases; i++) {
        char inputWord[1001];
        scanf("%s", inputWord);
        printf("%d\n", getAmountOfMovesInAWord(inputWord));
    }

    return 0;
}

int getAmountOfMovesInAWord(char currentWord[]) {
    int wordLength = strlen(currentWord);
    int tempMoves = wordLength - 1;
    int totalMoves = 0;

    for (int i = 0; i < wordLength; i++) {
        totalMoves += getMinimumAmountOfMovesToGetChar(currentWord[i]);
        int tmp = findAndGetLastIndexOfNextGroupOfAIfNextCharIsA(currentWord, i, wordLength);
        if(tmp > i){
            tempMoves = getLowestNumber(((i << 1) + ((wordLength - tmp) - 1)), ((((wordLength - tmp) - 1) << 1) + (i)), tempMoves);
            i = tmp;
        }
    }

    return (totalMoves + tempMoves);
}

int getMinimumAmountOfMovesToGetChar(char ch) {
    return (ch < MID_CHAR) ? (ch - LOWEST_CHAR): ((HIGHEST_CHAR + 1) - ch);
}

int getLowestNumber(int a, int b, int c){
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int findAndGetLastIndexOfNextGroupOfAIfNextCharIsA(char word[], int currentIndex, int wordLength){
    return (currentIndex < wordLength - 1) && (word[currentIndex + 1] == LOWEST_CHAR) ? findAndGetLastIndexOfNextGroupOfAIfNextCharIsA(
            word, currentIndex + 1, wordLength) : currentIndex;
}

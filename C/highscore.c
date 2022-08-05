#include <stdio.h>
#include <string.h>

int getAmountOfMovesInAWord(char currentWord[]);
int getMinimumAmountOfMovesToGetChar(char ch);
int getSideMoves(char word[]);
int getIndexOfNextA(char word[], int currentIndex, int wordLength);

const char LOWEST_CHAR = 'A';
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
    int totalMoves = 0;

    for (int j = 0; j < strlen(currentWord); j++) {
        char currentCharacter = currentWord[j];
        totalMoves += getMinimumAmountOfMovesToGetChar(currentCharacter);
    }

    totalMoves += getSideMoves(currentWord);
    return totalMoves;
}

int getMinimumAmountOfMovesToGetChar(char ch) {
    int tempMovesForward = ch - LOWEST_CHAR;
    int tempMovesBackwards = (HIGHEST_CHAR + 1) - ch;
    return (tempMovesForward < tempMovesBackwards) ? tempMovesForward : tempMovesBackwards;
}

int getSideMoves(char word[]){
    int wordLength = strlen(word);
    int tempMoves = wordLength - 1;

    for(int i = 0; i < wordLength; i++) {
        int tmp = getIndexOfNextA(word, i, wordLength);
        if(tmp > i){

            int forward = (i + i) + ((wordLength - tmp) - 1);
            int backWards = (((wordLength - tmp) - 1) * 2) + (i);

            if(forward < tempMoves) {
                tempMoves = forward;
            }

            if(backWards < tempMoves) {
                tempMoves = backWards;
            }
            i = tmp;
        }
    }
    return tempMoves;
}

int getIndexOfNextA(char word[], int currentIndex, int wordLength){
    int result = currentIndex;
    if(currentIndex >= wordLength){
        return wordLength;
    }

    if(word[currentIndex + 1] == LOWEST_CHAR){
        result = getIndexOfNextA(word, currentIndex + 1, wordLength);
    }

    return result;
}

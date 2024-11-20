#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q3 3
#define Q3 3

int transitions[4][2] = {
    {Q1, Q2},
    {Q0, Q3},
    {Q3, Q0},
    {Q2, Q1}
};

const int START_STATE = Q0;
const int ACCEPT_STATE = Q2;

int getInputIndex(char c) {
    switch (c) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        default:
            return -1;
    }
}

bool accepts(char input[]) {
    int currentState = START_STATE;
  //printf("%d" , currentState);
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        int inputIndex = getInputIndex(input[i]);

        if (inputIndex == -1) {
            printf("Invalid character '%c' encountered.\n", input[i]);
            return false;
        }

        printf("Current State: Q%d, Input: %c\n", currentState, input[i]);
        currentState = transitions[currentState][inputIndex];
        printf("New State: Q%d\n", currentState);
    }
    printf("Accepted: %s\n", (currentState == ACCEPT_STATE) ? "true" : "false");
    return currentState == ACCEPT_STATE;
}

int main() {
    char input[100];
    printf("Enter a string that contains characters 'a' or 'b' and starts with either 'a' or 'b'. The DFA will only accept strings with an even number of 'a's and an odd number of 'b's, where 'a's and 'b's occur consecutively -> ");
    scanf("%s", input);

    bool accepted = accepts(input);
    if (!accepted) {
        printf("The input should have an even number of 'a's and an odd number of 'b's.\n");
    }

    return 0;
}

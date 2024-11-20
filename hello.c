#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3



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

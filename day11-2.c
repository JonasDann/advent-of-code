//
// Created by Jonas on 22.12.2015.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void incPassword(char *password, int length) {
    int i = length - 1;
    password[i]++;
    while (password[i] > 'z' && i >= 1) {
        i--;
        password[i]++;
        password[i + 1] = 'a';
    }
}

int main(int argc, char *argv[]) {
    char input[] = "hepxcrrq";

    clock_t t1, t2;

    t1 = clock();

    int inputLength = strlen(input);
    int n, i, pairs;
    bool sequence, forbiddenLetter;
    char beforeBeforeLastChar, beforeLastChar, lastChar;
    for (n = 0; n < 2; n++) {
        if (n > 0) {
            incPassword(input, inputLength);
        }
        while (true) {
            sequence = false;
            forbiddenLetter = false;
            pairs = 0;
            beforeBeforeLastChar = -30;
            beforeLastChar = -20;
            lastChar = -10;
            for (i = 0; i < inputLength; i++) {
                if (input[i] == 'i' || input[i] == 'o' || input[i] == 'l') {
                    forbiddenLetter = true;
                    break;
                }
                if (lastChar == input[i] && (beforeLastChar != input[i] || (beforeBeforeLastChar == beforeLastChar)))
                    pairs++;
                else if (lastChar + 1 == input[i] && beforeLastChar + 2 == input[i])
                    sequence = true;
                beforeBeforeLastChar = beforeLastChar;
                beforeLastChar = lastChar;
                lastChar = input[i];
            }
            if (pairs > 1 && sequence && !forbiddenLetter) {
                break;
            }
            incPassword(input, inputLength);
        }
    }

    t2 = clock();
    int time = t2 - t1;
    printf("The answer was found in %i milliseconds\n", time);

    printf("The new password is %s.", input);

    free(input);
    return 0;
}


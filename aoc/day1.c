//
//  main.c
//  aoc
//
//  Created by Niklas Rotter on 01.12.23.
//

#include <stdio.h>
#include <string.h>

int is_string_numeral(int pos, char* str){
    int len = strlen(str);
    char* one = "one";
    char* two = "two";
    char* three = "three";
    char* four = "four";
    char* five = "five";
    char* six = "six";
    char* seven = "seven";
    char* eight = "eight";
    char* nine = "nine";
    int diff = strlen(str) - pos;
    
    //longest string numeral is 5 chars long
    if (diff > 2) {
        if (str[pos] == 'o' && str[pos+1] == 'n' && str[pos+2] == 'e') {
            return 1;
        } else if (str[pos] == 't' && str[pos+1] == 'w' && str[pos+2] == 'o') {
            return 2;
        } else if (str[pos] == 's' && str[pos+1] == 'i' && str[pos+2] == 'x') {
            return 6;
        }
    }
    
    if (str[pos] == 't' && str[pos+1] == 'h' && str[pos+2] == 'r'
               && str[pos+3] == 'e' && str[pos+4] == 'e') {
        return 3;
    }
    
    if (diff > 3) {
        if (str[pos] == 'f' && str[pos+1] == 'o' && str[pos+2] == 'u'
            && str[pos+3] == 'r') {
            return 4;
        } else if (str[pos] == 'f' && str[pos+1] == 'i' && str[pos+2] == 'v'
                   && str[pos+3] == 'e') {
            return 5;
        } else if (str[pos] == 'n' && str[pos+1] == 'i' && str[pos+2] == 'n'
                   && str[pos+3] == 'e') {
            return 9;
        }
    }
    
    if (diff > 4) {
        if (str[pos] == 's' && str[pos+1] == 'e' && str[pos+2] == 'v'
            && str[pos+3] == 'e' && str[pos+4] == 'n') {
            return 7;
        } else if (str[pos] == 'e' && str[pos+1] == 'i' && str[pos+2] == 'g'
                   && str[pos+3] == 'h' && str[pos+4] == 't') {
            return 8;
        }
    }
    
    return -1;
}

int decide_if_string_numeral_or_digit(char* str, int forwards) {
    int len = strlen(str);
    int i;
    if (forwards == 1) {
        i = 0;
    } else {
        i = len - 1;
    }
    for (; i < len;) {
        switch (str[i]) {
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
        }
        int numeral = is_string_numeral(i, str);
        if (numeral > 0) {
            return numeral;
        }
        if (forwards == 1) {
            i++;
        } else {
            i--;
        }
    }
    return -1;
}

int main(int argc, char** argv) {
    FILE* filePointer;
    int bufferLength = 255;
    char buffer[bufferLength];;

    printf(argv[1]);
    filePointer = fopen(argv[1], "r");

    int sum = 0;
    while(fgets(buffer, bufferLength, filePointer)) {
        int first_digit = decide_if_string_numeral_or_digit(buffer, 1);
        int last_digit = decide_if_string_numeral_or_digit(buffer, 0);
        if (first_digit < 0 || last_digit < 0 ) {
            printf("ERROR: No digits.");
            continue;
        }
        sum = sum + first_digit * 10 + last_digit;
    }

    printf("\nThe sum is: %d\n", sum);
    fclose(filePointer);
    return 0;
}

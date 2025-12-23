#include <stdio.h>
#include <string.h>

// Function to count occurrences of a pattern in a string
int countPatternOccurrences(const char *string, const char *pattern) {
    int count = 0;
    int stringLen = strlen(string);
    int patternLen = strlen(pattern);

    for (int i = 0; i <= stringLen - patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++) {
            if (string[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLen) {
            count++;
        }
    }

    return count;
}

int main() {
    char string[1000];
    char pattern[100];

    printf("Enter the string: ");
    scanf("%s", string);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    int result = countPatternOccurrences(string, pattern);
    printf("The pattern '%s' appears %d times in the string '%s'.\n", pattern, result, string);

    return 0;}
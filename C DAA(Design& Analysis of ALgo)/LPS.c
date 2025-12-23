#include <stdio.h>
#include <string.h>

// Function to compute the LPS array
void computeLPSArray(char pat[], int M, int lps[]) {
    int len = 0;  // length of the previous longest prefix suffix
    lps[0] = 0;   // lps[0] is always 0

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

}

int longestPrefixSuffixLength( char S[]) {
    int n = strlen(S);
    int lps[n];

    computeLPSArray(S, n, lps);

    // The last value of the LPS array is the length of the longest prefix which is also a suffix
    return lps[n - 1];
}

int main() {
    char str[20];
    printf("Enter the string");
   scanf("%[^\n]s",str);
   printf("String: %s\n",str);

//to print lps length
    printf("Output: %d\n", longestPrefixSuffixLength(str));

//to print lps
       int lpsLength=longestPrefixSuffixLength(str);
       for(int i=0;i<lpsLength;i++){
        printf("%c",str[i]);
       }

    return 0;
}

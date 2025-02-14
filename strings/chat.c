#include <stdio.h>
#include <string.h>

// Function to preprocess the LPS array
void computeLPSArray(char *pattern, int m, int *lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;

                i++;
            }
        }
    }

}


// KMP pattern search function
void KMPsearch(char *text, char *pattern) {
    int n = strlen(text);

    int m = strlen(pattern);
    int lps[m];

    computeLPSArray(pattern, m, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;

            j++;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char text[] = "aabaacaadaabaaba";
    char pattern[] = "aaba";
    KMPsearch(text, pattern);
    return 0;
}


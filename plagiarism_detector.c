#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Compute LPS (Longest Proper Prefix which is also Suffix) array */
void computeLPS(char *pattern, int m, int *lps) {
    int len = 0; // length of previous longest prefix suffix
    int i = 1;   // lps[0] is always 0
    lps[0] = 0;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
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

/* KMP Search Algorithm for Pattern Matching */
int kmpSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    // Allocate LPS array
    int *lps = (int *)malloc(m * sizeof(int));
    computeLPS(pattern, m, lps);
    
    int i = 0; // index for text
    int j = 0; // index for pattern
    int found = 0;
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            printf("Pattern found at index: %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    free(lps);
    return found;
}

int main() {
    char text[1000000];
    char pattern[100000];
    
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline
    
    printf("Enter pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = 0; // Remove newline
    
    int result = kmpSearch(text, pattern);
    
    if (!result) {
        printf("-1\n"); // Pattern not found
    }
    
    return 0;
}

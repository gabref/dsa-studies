#include <stdio.h>
#include <string.h>

// compute longest prefix suffix table
void compute_lps(char *pattern, int m, int *lps) {
	lps[0] = 0;
	int j = 0;
	int i = 1;
	while (i < m) {
		if (pattern[i] == pattern[j]) {
			j++;
			lps[i] = j;
			i++;
		} else {
			if (j != 0) {
				j = lps[j - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

void kmp_search(char *text, char *pattern) {
	int n = strlen(text);
	int m = strlen(pattern);
	int lps[m];
	compute_lps(pattern, m, lps);
	int i = 0;
	int j = 0;
	while (i < n) {
		if (text[i] == pattern[j]) {
			i++;
			j++;
		}
		if (j == m) {
			printf("found pattern at: %d - %s\n", i - j, text + i - j);
			j = lps[j - 1];
		} else if (i < n && text[i] != pattern[j]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}
}

int main(int ac, char **av) {
	if (ac != 3) {
		printf("usage: <name_program> \"hello world\" \"world\"\n");
		return (1);
	}
	kmp_search(av[1], av[2]);
	return (0);
}
